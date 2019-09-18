#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INT_MAX 0x3fffffff
const int MAXN=210;
int map[MAXN][MAXN],n,p[MAXN];//map:邻接数组；n:点数；p:前驱数组;
int dis[MAXN];
bool bfs(int start,int end)//广度优先算法寻找增光路
{
    memset(dis,-1,sizeof(dis));
    queue<int> que;//广度优先搜索队列
    que.push(start);
    dis[start]=0;
    bool flag=0;
    while(!que.empty())
    {
        int e=que.front();
        if(e==end)  flag=1;
        que.pop();
        for(int i=1; i<=n; i++)
        {
            if(map[e][i]>0 && dis[i]==-1)
            {
                dis[i]=dis[e]+1;
                que.push(i);
            }
        }
    }
    return flag;
}
bool dfs(int start,int end)
{
    if(start==end)  return 1;
    for(int i=1;i<=n;i++)
    {
        if(map[start][i]>0 && dis[i]==dis[start]+1)
        {
            p[i]=start;
            if(dfs(i,end))  return 1;
        }
    }
    return 0;
}
int dinic(int start,int end)
{
    int u,flow_ans=0,mn;
    while(bfs(start,end))//假如能找到增广路，让水流从这条路上经过
    {
        memset(p,-1,sizeof(p));
        while(dfs(start,end))
        {
            mn=INT_MAX;
            u=end;
            while(p[u]!=-1)
            {
                mn=min(mn,map[p[u]][u]);
                u=p[u];
            }
            flow_ans+=mn;//总水流量增加
            u=end;
            while(p[u]!=-1)//增广路上的每一条边的可通过量减少
            {
                map[p[u]][u]-=mn;
                map[u][p[u]]+=mn;
                u=p[u];
            }
        }
    }
    return flow_ans;
}

int main()
{
    int m,t,iCase=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof(map));
        int u,v,cost;
        for(int i=0; i<m; i++) //本题中会有重边
        {
            scanf("%d%d%d",&u,&v,&cost);
            map[u][v]+=cost;
        }
        int ans=dinic(1,n);
        printf("Case %d: ",++iCase);
        printf("%d\n",ans);
    }
    return 0;
}
