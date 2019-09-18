//!!!!!!!!!注意结点编号从0开始还是从1开始，修改51，84行
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10005;
const int INF = (1<<30);
struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f) {}
};

struct ISAP
{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>G[N];
    bool vis[N];
    int d[N],cur[N];
    int p[N],num[N];//比Dinic算法多了这两个数组，p数组标记父亲结点，num数组标记距离d[i]存在几个
    void addedge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    int Augumemt()
    {
        int x=t,a=INF;
        while(x!=s)//找最小的残量值
        {
            Edge&e=edges[p[x]];
            a=min(a,e.cap-e.flow);
            x=edges[p[x]].from;
        }
        x=t;
        while(x!=s)//增广
        {
            edges[p[x]].flow+=a;
            edges[p[x]^1].flow-=a;//更新反向边。
            x=edges[p[x]].from;
        }
        return a;
    }
    void bfs()//逆向进行bfs
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<=n;i++)  d[i]=n;//!!!!!!!!!注意结点编号从0开始还是从1开始
        queue<int>q;
        q.push(t);
        d[t]=0;
        vis[t]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            int len=G[x].size();
            for(int i=0; i<len; i++)
            {
                Edge&e=edges[G[x][i]^1];
                if(!vis[e.from]&&e.cap>e.flow)
                {
                    vis[e.from]=1;
                    d[e.from]=d[x]+1;
                    q.push(e.from);
                }
            }
        }
    }

    int Maxflow(int s,int t)//根据情况前进或者后退，走到汇点时增广
    {
        this->s=s;
        this->t=t;
        int flow=0;
        bfs();

        memset(num,0,sizeof(num));
        for(int i=0; i<n; i++)//!!!!!!!!!注意结点编号从0开始还是从1开始
            num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        memset(p,0,sizeof(p));
        while(d[s]<n)
        {
            if(x==t)//走到了汇点，进行增广
            {
                flow+=Augumemt();
                x=s;//增广后回到源点
            }
            int ok=0;
            for(int i=cur[x]; i<G[x].size(); i++)
            {
                Edge&e=edges[G[x][i]];
                if(e.cap>e.flow&&d[x]==d[e.to]+1)
                {
                    ok=1;
                    p[e.to]=G[x][i];//记录来的时候走的边，即父边
                    cur[x]=i;
                    x=e.to;//前进
                    break;
                }
            }
            if(!ok)//走不动了，撤退
            {
                int m=n-1;//如果没有弧，那么m+1就是n，即d[i]=n
                for(int i=0; i<G[x].size(); i++)
                {
                    Edge&e=edges[G[x][i]];
                    if(e.cap>e.flow)
                        m=min(m,d[e.to]);
                }
                if(--num[d[x]]==0)break;//如果走不动了，且这个距离值原来只有一个，那么s-t不连通，这就是所谓的“gap优化”
                num[d[x]=m+1]++;
                cur[x]=0;
                if(x!=s)
                    x=edges[p[x]].from;//退一步，沿着父边返回
            }
        }
        return flow;
    }
};

int main()
{
    int T,iCase=0;
    scanf("%d",&T);
    while(T--)
    {
        ISAP isap;
        scanf("%d%d", &isap.n, &isap.m);

        int u, v, w;
        for(int i = 0; i < isap.m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            isap.addedge(u,v,w);
        }

        int ans=isap.Maxflow(1,isap.n);
        printf("Case %d: ",++iCase);
        printf("%d\n", ans);
    }
    return 0;
}
/*
4 5
4 2 30
4 3 20
2 3 20
2 1 30
1 3 40
*/
