#include<iostream>
#include<cstdio>
#include<cstring>
#include <vector>
using namespace std;
const int INF=0x3f3f3f3;
const int maxn=10005;
vector <int> g[maxn];//连接的顶点
vector <int> d[maxn];//与连接顶点对应的距离
int dis[maxn];
int visited[maxn];
void Dijkstra(int n,int x)////顶点从1到n编号，x为起点
{
    int i,p,j,min;
    for(i=1;i<=n;i++)
    {
        dis[i]=INF;
        visited[i]=0;
    }
    dis[x]=0;
    for(i=1;i<=n;i++)
    {
        min=INF;
        for(j=1;j<=n;j++)
        {
            if(!visited[j] && dis[j]<min)
            {
                p=j;
                min=dis[j];
            }
        }
        if(min==INF)  return ;
        visited[p]=1;
        int size=g[p].size();
        for(j=0;j<size;j++)
        {
            int v=g[p][j];
            if(!visited[v] && dis[p]+d[p][j]<dis[v])
            {
                dis[v]=dis[p]+d[p][j];
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
        for(i=1;i<=n;i++)
        {
            g[i].clear();
            d[i].clear();
        }
        int u,v,w;
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(v);
            g[v].push_back(u);
            d[u].push_back(w);
            d[v].push_back(w);
        }

    }
    return 0;
}
