#include <iostream>
#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
const int INF=5000000;
const int maxn=155;
int g[maxn][maxn];
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        int i,j,k;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(i==j)  g[i][j]==0;
                else  g[i][j]=INF;
            }
        for(i=0;i<m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            g[u][v]=g[v][u]=1;
        }
        for(k=0;k<n;k++)
           for(i=0;i<n;i++)
              for(j=0;j<n;j++)
                  if(g[i][j]>g[i][k]+g[k][j])    g[i][j]=g[i][k]+g[k][j];
        int t=0;
        for(i=0;i<n;i++)
           for(j=0;j<n;j++)
               if(g[i][j]>7)  t++;
        if(t>0)   printf("No\n");
        else   printf("Yes\n");

    }
    return 0;
}
