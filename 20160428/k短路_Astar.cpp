#include <iostream>
#include "stdio.h"
#include "string.h"
#include <queue>
using namespace std;
const int maxn=1005;
const int maxm=100005;
const int INF=1>>30;
int head1[maxn];
int head2[maxn];
int dis[maxn];
struct edge
{
   int v,c,nxt;
}e1[maxm],e2[maxm];
struct state
{
    int v;
    int g;
    int f;
    bool operator < (state a)const
    {
        return a.f<f;
        //if(a.f == f) return a.g < g;
        //return a.f < f;
    }
};
int vis[maxn];
void Dijkstra(int n,int x)
{
    int i,p,j,min;
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
        vis[i]=0;
    }
    //vis[x]=1;
    dis[x]=0;
    for(i=1;i<=n;i++)
    {
        min=INF;
        for(j=1;j<=n;j++)
        {
            if(!vis[j] && dis[j]<min)
            {
                p=j;
                min=dis[j];
            }
        }
        if(min==INF)  return ;
        vis[p]=1;
        for(j=head2[p];j!=-1;j=e2[j].nxt)
        {
            int t=e2[j].v;
            if(!vis[t] && dis[p]+e2[j].c<dis[t])
            {
                dis[t]=dis[p]+e2[j].c;
            }
        }
    }
}
int A_star(int u,int v,int k)
{
    priority_queue<state>pq;
    state cur,nxt;
    cur.g=0;
    cur.f=dis[u];
    cur.v=u;
    pq.push(cur);
    int cnt=0;
    //memset(cnt,0,sizeof(cnt));
    while(!pq.empty())
    {
        cur=pq.top();
        pq.pop();
        int t=cur.v;
        if(t==v)
        {
            cnt++;
            if(cnt==k)  return cur.g;
        }

        //if(cnt[t]>k)   continue;
        //if(cnt[v]==k)   return cur.g;
        int x=head1[t];
        while(x!=-1)
        {
            nxt.g=cur.g+e1[x].c;
            nxt.f=nxt.g+dis[e1[x].v];
            nxt.v=e1[x].v;
            pq.push(nxt);
            x=e1[x].nxt;
        }
    }
    return -1;
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        int i,j,u,v,c;
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        for(i=0;i<m;i++)
        {
             scanf("%d %d %d",&u,&v,&c);
             e1[i].v=v;
             e1[i].c=c;
             e1[i].nxt=head1[u];
             head1[u]=i;
             e2[i].v=u;
             e2[i].c=c;
             e2[i].nxt=head2[v];
             head2[v]=i;
        }
        int s,t,k;
        scanf("%d %d %d",&s,&t,&k);
        Dijkstra(n,t);
        //for(i=1;i<=n;i++)  cout<<dis[i]<<endl;
        if(s==t)  k++;
        printf("%d\n",A_star(s,t,k));
    }
    return 0;
}
/*
3 3
1 2 1
2 3 2
3 1 3
1 3 3
*/
