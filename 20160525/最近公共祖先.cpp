#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int maxn=1e5+5;
vector<int> g[maxn];
map<string,int> msi;
string sname[maxn];
int anc[maxn][20];//i的2^j级祖先，anc[i][0]为其父
int fa[maxn];
int depth[maxn];
void init(int u,int dep)
{
    int i,j;
    depth[u]=dep;
    anc[u][0]=fa[u];
    for(i=1;(1<<i)<dep;i++)
    {
        int tmp=anc[u][i-1];
        anc[u][i]=anc[tmp][i-1];
    }
    //anc[u][i]=-1;
    int size=g[u].size();
    for(i=0;i<size;i++)
    {
        init(g[u][i],dep+1);
    }
}
int find(int t1,int t2)
{
    if(depth[t1]<depth[t2])   swap(t1,t2);
    int log=0;
    while((1<<log)<=t1)
    {
        log++;
    }
    log--;
    int i,j;
    for(i=log;i>=0;i--)
    {
        if(depth[t1]-(1<<i)>=depth[t2])
        {
            t1=anc[t1][i];
        }
    }
    if(t1==t2)  return t1;
    //cout<<t1<<" "<<t2<<endl;
    for(i=log;i>=0;i--)
    {
        if(depth[t1]-(1<<i)>=0 && anc[t1][i]!=anc[t2][i])
        {
            t1=anc[t1][i];
            t2=anc[t2][i];
        }
    }
    return fa[t1];
}
int main()
{
    int n,m;
    while(cin>>n)
    {
        string sfa,sson;
        int cnt=0;
        while(n--)
        {
            cin>>sfa>>sson;
            int tfa,tson;
            if(msi.find(sfa)==msi.end())
            {
                msi[sfa]=cnt;
                sname[cnt]=sfa;
                tfa=cnt;
                cnt++;
            }
            else
            {
                tfa=msi[sfa];
            }
            if(msi.find(sson)==msi.end())
            {
                msi[sson]=cnt;
                sname[cnt]=sson;
                tson=cnt;
                cnt++;
            }
            else
            {
                tson=msi[sson];
            }
            fa[tson]=tfa;
            g[tfa].push_back(tson);
        }
        fa[0]=-1;
        memset(anc,-1,sizeof(anc));
        init(0,0);
        cin>>m;
        string s1,s2;
        while(m--)
        {
            cin>>s1>>s2;
            int t1=msi[s1];
            int t2=msi[s2];
            int ans=find(t1,t2);
            cout<<sname[ans]<<endl;
        }
    }
    return 0;
}
