#include <iostream>
#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
int fa[1005],a[1005];
int find(int x)
{
    if(fa[x]!=x)   fa[x]=find(fa[x]);
    return fa[x];
}
int main()
{
    int n,m;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        memset(a,0,sizeof(a));
        int i,u,v,k=0;
        for(i=1;i<=n;i++)  fa[i]=i;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            a[u]++;
            a[v]++;
            int x=find(u);
            int y=find(v);
            fa[x]=y;
        }
        for(i=1;i<=n;i++)
            if(fa[i]==i)   k++;
        for(i=1;i<=n;i++)
        {
            if(a[i]%2==1)   break;
        }
        if(k>1||i<=n)   printf("0\n");
        else   printf("1\n");
    }
    return 0;
}
