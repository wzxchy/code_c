#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1005;
const long long INF=1e15;
vector<int> G[maxn];
vector<int> D[maxn];
long long g[maxn][maxn];
int t[maxn],c[maxn];
int visited[maxn];
int x,y;
long long dis[maxn];
struct node
{
    int u;//结点号
    int dis;
    bool operator < (node a)const//用于优先队列，f值小的结点在队列前
    {
        return a.dis<dis;
    }
};
void Dijkstra(int n,int x,long long dis[])////顶点从1到n编号，x为起点
{
    int i,j,min;
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
        visited[i]=0;
    }
    dis[x]=0;
    priority_queue<node> pq;
    node cur,nxt;
    cur.u=x;
    cur.dis=0;
    pq.push(cur);
    while(!pq.empty())
    {
        cur=pq.top();
        pq.pop();
        if(cur.dis!=dis[cur.u])  continue;
        if(cur.dis==INF)  return;
        visited[cur.u]=1;
        for(j=1;j<=n;j++)
        {
            if(!visited[j] && dis[cur.u]+g[cur.u][j]<dis[j])
            {
                dis[j]=dis[cur.u]+g[cur.u][j];
                nxt.u=j;
                nxt.dis=dis[j];
                pq.push(nxt);
            }
        }
    }
}
void dfs1(int u,int anc,int len)
{
    int size=G[u].size();
    int i;
    for(i=0;i<size;i++)
    {
        int v=G[u][i];
        if(D[u][i]<=len)
        {
            if(c[anc]<g[anc][v])  g[anc][v]=c[anc];
            dfs1(v,anc,len-D[u][i]);
        }
    }
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        int i,j;
        int u,v,w;
        scanf("%d %d",&x,&y);
        for(i=1;i<=n;i++)
        {
            D[i].clear();
            G[i].clear();
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            G[u].push_back(v);
            G[v].push_back(u);
            D[u].push_back(w);
            D[v].push_back(w);
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&t[i],&c[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)  g[i][j]=INF;
        }
        for(i=1;i<=n;i++)
        {
            dfs1(i,i,t[i]);
        }
        Dijkstra(n,x,dis);
        if(dis[y]>=INF)  printf("-1\n");
        else  printf("%lld\n",dis[y]);
    }
    return 0;
}
