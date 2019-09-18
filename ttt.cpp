//!!!!!!!!!ע�����Ŵ�0��ʼ���Ǵ�1��ʼ���޸�51��84��
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
    int p[N],num[N];//��Dinic�㷨�������������飬p�����Ǹ��׽�㣬num�����Ǿ���d[i]���ڼ���
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
        while(x!=s)//����С�Ĳ���ֵ
        {
            Edge&e=edges[p[x]];
            a=min(a,e.cap-e.flow);
            x=edges[p[x]].from;
        }
        x=t;
        while(x!=s)//����
        {
            edges[p[x]].flow+=a;
            edges[p[x]^1].flow-=a;//���·���ߡ�
            x=edges[p[x]].from;
        }
        return a;
    }
    void bfs()//�������bfs
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<=n;i++)  d[i]=n;//!!!!!!!!!ע�����Ŵ�0��ʼ���Ǵ�1��ʼ
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

    int Maxflow(int s,int t)//�������ǰ�����ߺ��ˣ��ߵ����ʱ����
    {
        this->s=s;
        this->t=t;
        int flow=0;
        bfs();

        memset(num,0,sizeof(num));
        for(int i=0; i<n; i++)//!!!!!!!!!ע�����Ŵ�0��ʼ���Ǵ�1��ʼ
            num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        memset(p,0,sizeof(p));
        while(d[s]<n)
        {
            if(x==t)//�ߵ��˻�㣬��������
            {
                flow+=Augumemt();
                x=s;//�����ص�Դ��
            }
            int ok=0;
            for(int i=cur[x]; i<G[x].size(); i++)
            {
                Edge&e=edges[G[x][i]];
                if(e.cap>e.flow&&d[x]==d[e.to]+1)
                {
                    ok=1;
                    p[e.to]=G[x][i];//��¼����ʱ���ߵıߣ�������
                    cur[x]=i;
                    x=e.to;//ǰ��
                    break;
                }
            }
            if(!ok)//�߲����ˣ�����
            {
                int m=n-1;//���û�л�����ôm+1����n����d[i]=n
                for(int i=0; i<G[x].size(); i++)
                {
                    Edge&e=edges[G[x][i]];
                    if(e.cap>e.flow)
                        m=min(m,d[e.to]);
                }
                if(--num[d[x]]==0)break;//����߲����ˣ����������ֵԭ��ֻ��һ������ôs-t����ͨ���������ν�ġ�gap�Ż���
                num[d[x]=m+1]++;
                cur[x]=0;
                if(x!=s)
                    x=edges[p[x]].from;//��һ�������Ÿ��߷���
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