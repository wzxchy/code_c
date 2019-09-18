#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INT_MAX 0x3fffffff
const int MAXN=210;
int map[MAXN][MAXN],n,p[MAXN];//map:邻接数组；n:点数；p:前驱数组;
bool EK_bfs(int start,int end)//广度优先算法寻找增光路
{
    queue<int>que;//广度优先搜索队列
    bool flag[MAXN];//标记数组
    memset(flag,false,sizeof(flag));
    memset(p,-1,sizeof(p));//初始化
    que.push(start);
    flag[start]=true;
    while(!que.empty())
    {
        int e=que.front();
        if(e==end)
        {
            return true;
        }
        que.pop();
        for(int i=1;i<=n;i++)
        {
            if(map[e][i]&&!flag[i])
            {
                flag[i]=true;
                p[i]=e;
                que.push(i);
            }
        }
    }
    return false;
}

int EK_Max_Flow(int start,int end)
{
    int u,flow_ans=0,mn;
    while(EK_bfs(start,end))//假如能找到增广路，让水流从这条路上经过
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
        while(p[u]!=-1)//增光路上的每一条边的可通过量减少
        {
            map[p[u]][u]-=mn;
            map[u][p[u]]+=mn;
            u=p[u];
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
        printf("Case %d: ",++iCase);
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof(map));
        int u,v,cost;
        for(int i=0;i<m;i++)//本题中会有重边
        {
            scanf("%d%d%d",&u,&v,&cost);
            map[u][v]+=cost;
        }
        int ans=EK_Max_Flow(1,n);
        printf("%d\n",ans);
    }
    return 0;
}
