#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<queue>
using namespace std;
const int INF=99999999;
int map[21][21],dis[21],vis[21];
int h[21];
string s_city[21];
int n_node;
struct state
{
    int v;//城市序号
    int g;//已走过路径长度
    int f;//f=g+h;
    string path;//已走过路径
    bool operator < (state a)const//用于优先队列，f值小的结点在队列前
    {
        return a.f<f;
    }
};
int A_star(int n,int u,int des)//x为起点  n为城市个数
{
    int i,p,j,min;
    for(i=0;i<n;i++)  dis[i]=INF;
    dis[u]=0;
    memset(vis,0,sizeof(vis));
    priority_queue<state>pq;
    state cur,nxt;
    cur.g=0;
    cur.v=u;
    cur.f=0;
    cur.path=s_city[u];
    pq.push(cur);
    while(!pq.empty())
    {
        cur=pq.top();
        pq.pop();
        int v=cur.v;
        int g=cur.g;
        string s=cur.path;
        if(vis[v]==1)  continue;
        vis[v]=1;
        if(v==des)
        {
            cout<<"路径: "<<s<<endl;
            return g;
        }
        for(i=0;i<n;i++)
        {
            if(g+map[v][i]<dis[i])
            {
                dis[i]=g+map[v][i];
                nxt.g=dis[i];
                nxt.f=nxt.g+h[i];
                nxt.v=i;
                nxt.path=s+"->"+s_city[i];
                n_node++;
                pq.push(nxt);
            }
        }
    }
    return -1;
}

int main()
{
    ifstream ifile;
    ifile.open("map_data.txt");
    int i,j;
    int n=20;
    for(i=0;i<n;i++)
    {
        ifile>>s_city[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ifile>>map[i][j];
            if(map[i][j]==1000)  map[i][j]=INF;
            //if(i==j)   map[i][j]=0;
        }
    }
    ifile.close();
    ifile.open("heuristic_data.txt");
    for(i=0;i<n;i++)
    {
        ifile>>s_city[i]>>h[i];
    }
    ifile.close();
    /////////////////////////
    n_node=1;
    cout<<"路径长度: "<<A_star(n,0,2)<<endl;
    cout<<"结点数目: "<<n_node<<endl;
    return 0;
}
