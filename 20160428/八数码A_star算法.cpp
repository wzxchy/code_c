#include <iostream>
#include "stdio.h"
#include "string.h"
#include <queue>
using namespace std;
const int MaxSize=1000000;
const int MaxHashSize=1000003;
int state[MaxSize][9];
int fa[MaxSize];
int move1[MaxSize];
int g[MaxSize];
int h[MaxSize];
int goal[9];
int head[MaxHashSize],next1[MaxSize];
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int hash1(int t)
{
    int i,s=0;
    for(i=0;i<9;i++)  s=s*10+state[t][i];
    return s%MaxHashSize;
}
int abs1(int a)
{
    if(a>0)  return a;
    else return -a;
}
int get_h(int a)
{
    int i;
    int s=0;
    for(i=0;i<9;i++)
    {
        if(state[a][i]==0)  continue;
        int x1=i/3;
        int y1=i%3;
        int x2=(state[a][i]-1)/3;
        int y2=(state[a][i]-1)%3;
        s+=abs1(x1-x2)+abs1(y1-y2);
    }
    return s;
}
bool insert(int a)
{
    int h=hash1(a);
    int u=head[h];
    while(u)
    {
        int i;
        for(i=0;i<9;i++)   if(state[u][i]!=state[a][i])   break;
        if(i==9)  return 0;
        //if(memcmp(state[u],state[a],sizeof(state[a]))==0)   return 0;
        u=next1[u];
    }
    next1[a]=head[h];
    head[h]=a;
    return 1;
}
void print(int x)
{
    if(x==1)  return ;
    print(fa[x]);
    switch(move1[x])
    {
        case 0:cout<<'u';break;
        case 1:cout<<'d';break;
        case 2:cout<<'l';break;
        case 3:cout<<'r';break;
    }
}
struct cmp
{
    bool operator() (const int a,const int b) const
    {
        return g[a]+h[a]>g[b]+h[b];
        //return a[h]==b[h]?a[g]>b[g]:a[h]>b[h];
    }
};
void bfs()
{
    int front,rear=2;
    memset(head,0,sizeof(head));
    memset(next1,0,sizeof(next1));
    fa[1]=0;
    g[1]=0;
    h[1]=get_h(1);
    insert(1);
    priority_queue<int,vector<int>,cmp>pq;
    pq.push(1);
    while(!pq.empty())
    {
        int i;
        //for(i=0;i<9;i++)  if(state[front][i]!=goal[i])   break;
        front=pq.top();
        /*
        for(i=0;i<9;i++)  cout<<state[front][i]<<"  ";
        cout<<endl;
        cout<<g[front]<<endl;
        cout<<h[front]<<endl;
        */
        pq.pop();
        for(i=0;i<9;i++)  if(!state[front][i])  break;
        int x=i/3,y=i%3;
        int d;
        for(d=0;d<4;d++)
        {
            int newx=x+dx[d];
            int newy=y+dy[d];
            int j=newx*3+newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3)
            {
                int k;
                //memcpy(state[rear],state[front],sizeof(state[front]));//
                for(k=0;k<9;k++)   state[rear][k]=state[front][k];
                state[rear][j]=state[front][i];
                state[rear][i]=state[front][j];
                if(insert(rear))
                {
                    fa[rear]=front;
                    move1[rear]=d;
                    for(k=0;k<9;k++)  if(state[rear][k]!=goal[k])   break;
                    if(k==9)
                    {
                        print(rear);
                        cout<<endl;
                        return  ;
                    }
                    g[rear]=g[front]+1;
                    h[rear]=get_h(rear);
                    pq.push(rear);
                    rear++;
                }
            }
        }
    }
    cout<<"unsolvable"<<endl;
}
int check(int s[])
{
    int i,j,cnt=0;
    for(i=0;i<9;i++)
    {
        if(s[i]==0) continue;
        for(j=0;j<i;j++)
        {
            if(s[j]==0) continue;
            if(s[j]>s[i]) cnt++;
        }
    }
    return cnt;
}
int main()
{
    /*
    priority_queue<int,vector<int>,cmp>pq;
    g[1]=1;h[1]=1;
    g[2]=2;h[2]=5;
    g[3]=3;h[3]=4;
    g[4]=6;h[4]=3;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    pq.pop();
    */
    int i;
    char t;
    for(i=0;i<8;i++)  goal[i]=i+1;
    goal[8]=0;
    while(cin>>t)
    {
        if(t=='x')  state[1][0]=0;
        else state[1][0]=t-'0';
        for(i=1;i<9;i++)
        {
            cin>>t;
            if(t=='x')  state[1][i]=0;
            else state[1][i]=t-'0';
        }
        if(memcmp(goal,state[1],sizeof(state[1]))==0)
        {
            cout<<endl;
            continue;
        }

        int ans=check(state[1]);
        if(ans%2)
        {
            cout<<"unsolvable"<<endl;
            continue;
        }

        bfs();
    }
    return 0;
}
