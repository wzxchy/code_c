#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;
vector <int> g[maxn];
vector <int> val[maxn];
int fa[maxn];
long long ans;
long long dfs(int u)
{
    int size=g[u].size();
    int i;
    long long max1=0,max2=0;
    for(i=0;i<size;i++)
    {
        int v=g[u][i];
        if(fa[u]!=v)
        {
            fa[v]=u;
            long long tmp=dfs(v)+val[u][i];
            if(tmp>max1)
            {
                max2=max1;
                max1=tmp;
            }
            else if(tmp>max2)
            {
                max2=tmp;
            }
        }
    }
    if(max1+max2>ans)   ans=max2+max1;
    return max1;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int u,v,w;
        int i;
        long long sum=0;
        for(i=1;i<=n;i++)
        {
            g[i].clear();
            val[i].clear();
        }
        for(i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            g[u].push_back(v);
            g[v].push_back(u);
            val[u].push_back(w);
            val[v].push_back(w);
            sum+=w;
        }
        memset(fa,-1,sizeof(fa));
        ans=0;
        //cout<<"ss"<<endl;
        dfs(1);
        printf("%lld\n",2*sum-ans);
    }
    return 0;
}
/*


*/
