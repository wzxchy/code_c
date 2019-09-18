#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include <vector>
using namespace std;
const int INF=1e8;
const int maxn=10005;
vector <int> g[maxn];//连接的顶点
vector <int> d[maxn];//与连接顶点对应的距离
int dis[3][maxn];
int visited[maxn];
struct node
{
    int u;//结点号
    int dis;
    bool operator < (node a)const//用于优先队列，f值小的结点在队列前
    {
        return a.dis<dis;
    }
};
void Dijkstra(int n,int x,int dis[])////顶点从1到n编号，x为起点
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
        int size=g[cur.u].size();
        for(j=0;j<size;j++)
        {
            int v=g[cur.u][j];
            if(!visited[v] && dis[cur.u]+d[cur.u][j]<dis[v])
            {
                dis[v]=dis[cur.u]+d[cur.u][j];
                nxt.u=v;
                nxt.dis=dis[v];
                pq.push(nxt);
            }
        }
    }
}

int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,i;
        int u,v,w;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            g[i].clear();
            d[i].clear();
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(v);
            g[v].push_back(u);
            d[u].push_back(w);
            d[v].push_back(w);
        }
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        Dijkstra(n,a,dis[0]);
        Dijkstra(n,b,dis[1]);
        Dijkstra(n,c,dis[2]);
        for(i=1;i<=n;i++)
        {
            //cout<<i<<"  "<<dis[0][i]<<endl;
        }
        int ans=INF;
        for(i=1;i<=n;i++)
        {
            ans=min(ans,dis[0][i]+dis[1][i]+dis[2][i]);
        }
        if(ans==INF)  printf("-1\n");
        else   printf("%d\n",ans);
    }
    return 0;
}
