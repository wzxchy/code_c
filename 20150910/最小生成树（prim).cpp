#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=605;
const int maxlen=1<<30;
int g[maxn][maxn];
int lowcost[maxn];
int s[maxn];
int prim(int n)
{
    int i,j,k;
    for(i=2;i<=n;i++)   lowcost[i]=g[1][i];
    lowcost[1]=-1;
    int ans=0;
    for(i=0;i<n-1;i++)
    {
        int minlen=maxlen;
        for(j=1;j<=n;j++)
        {
            if(lowcost[j]<minlen&&lowcost[j]>=0)
            {
                minlen=lowcost[j];
                k=j;
            }
        }
        if(minlen==maxlen)    return -1;
        ans+=minlen;
        lowcost[k]=-1;
        for(j=2;j<=n;j++)
        {
            if(g[j][k]<lowcost[j]) lowcost[j]=g[j][k];
        }
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        int i,j,l;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)  g[i][j]=maxlen;
        }
        int u,v,c;
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            if(c<g[v][u])  g[v][u]=g[u][v]=c;
        }
        int t;
        for(i=0;i<k;i++)
        {
            scanf("%d",&t);
            for(j=0;j<t;j++)  scanf("%d",&s[j]);
            for(j=0;j<t;j++)
            {
                for(l=j+1;l<t;l++)
                {
                    g[s[j]][s[l]]=0;
                    g[s[l]][s[j]]=0;
                }
            }
        }
        printf("%d\n",prim(n));
    }
    return 0;
}
