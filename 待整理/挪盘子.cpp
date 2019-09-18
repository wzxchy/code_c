#include <iostream>
#include "stdio.h"
#include "string.h"
#include <queue>
using namespace std;
const int MaxSize=850000;
const int MaxHashSize=1000003;
struct node
{
    int s[7];
    int g;
    int h;
    int f;
    long long x;
}state[MaxSize];
int head[MaxHashSize],next1[MaxSize];
int n;
long long goal;
int a[8];
int hash1(int t)
{
    return state[t].x%MaxHashSize;
}
bool insert(int a)
{
    int h=hash1(a);
    int u=head[h];
    while(u)
    {
        if(state[u].x==state[a].x)   return 0;
        u=next1[u];
    }
    next1[a]=head[h];
    head[h]=a;
    return 1;
}
int abs1(int a)
{
    if(a>=0)  return a;
    return -a;
}
int get_h(int a)
{
    //return 0;
    int i;
    int sum=0;
    for(i=0;i<n;i++)
    {
        int temp=state[a].s[i];
        while(temp>0)
        {
            sum+=abs1(temp%10-i-1);
            temp/=10;
        }
    }
    return sum;
}
struct cmp
{
    bool operator() (const int a,const int b) const
    {
        return state[a].f>state[b].f;
    }
};
int bfs()
{
    int front=1,rear=2;
    memset(head,0,sizeof(head));
    memset(next1,0,sizeof(next1));
    state[1].g=0;
    state[1].h=get_h(1);
    insert(1);
    priority_queue<int,vector<int>,cmp>pq;
    pq.push(1);
    int cnt=0;
    while(!pq.empty())
    {
        cnt++;
        cout<<"aaa"<<endl;
        if(cnt>300)  break;
        front=pq.top();
        pq.pop();
        int i,d;
        for(i=0;i<n;i++)  cout<<state[front].s[i]<<"  ";
        cout<<endl;
        cout<<state[front].g<<"  "<<state[front].h<<endl;
        for(d=0;d<n;d++)
        {
            if(state[front].s[d]==0)   continue;
            if(d-1>=0&&(state[front].s[d-1]==0||state[front].s[d]%10<state[front].s[d-1]%10))
            {
                memcpy(state[rear].s,state[front].s,sizeof(state[front].s));
                state[rear].s[d-1]=state[rear].s[d-1]*10+state[front].s[d]%10;
                state[rear].s[d]=state[rear].s[d]/10;
                long long t=0;
                for(i=0;i<n;i++)
                {
                    int tx=state[rear].s[i];
                    if(tx==0)
                    {
                        t*=100;
                        continue;
                    }

                    while(tx>0)
                    {
                        t*=10;
                        tx/=10;
                    }
                    t+=state[rear].s[i];
                    t*=10;
                }
                if(t==goal)   return state[front].g+1;;
                state[rear].x=t;
                if(insert(rear))
                {
                    state[rear].g=state[front].g+1;
                    state[rear].h=get_h(rear);
                    state[rear].f=state[rear].g+state[rear].h;
                    pq.push(rear);
                    rear++;
                }
            }
            if(d+1<n&&(state[front].s[d+1]==0||state[front].s[d]%10<state[front].s[d+1]%10))
            {
                memcpy(state[rear].s,state[front].s,sizeof(state[front].s));
                state[rear].s[d+1]=state[rear].s[d+1]*10+state[front].s[d]%10;
                state[rear].s[d]=state[rear].s[d]/10;
                long long t=0;
                for(i=0;i<n;i++)
                {
                    int tx=state[rear].s[i];
                    if(tx==0)
                    {
                        t*=100;
                        continue;
                    }
                    while(tx>0)
                    {
                        t*=10;
                        tx/=10;
                    }
                    t+=state[rear].s[i];
                    t*=10;
                }
                if(t==goal)   return state[front].g+1;;
                state[rear].x=t;
                if(insert(rear))
                {
                    state[rear].g=state[front].g+1;
                    state[rear].h=get_h(rear);
                    state[rear].f=state[rear].g+state[rear].h;
                    pq.push(rear);
                    rear++;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j;
        scanf("%d",&n);
        for(i=0;i<n;i++)  scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        {
            int cnt=0;
            for(j=0;j<n;j++)
            {
                if(a[j]<=a[i])  cnt++;
            }
            state[1].s[i]=cnt;
        }
        state[1].x=0;
        for(i=0;i<n;i++)  state[1].x=(state[1].x*10+state[1].s[i])*10;
        goal=0;
        for(i=1;i<=n;i++)  goal=(goal*10+i)*10;
        if(goal==state[1].x)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",bfs());
    }
    return 0;
}
/*
10
7
7 6 5 4 3 2 1
6
6 5 4 3 2 1
*/
