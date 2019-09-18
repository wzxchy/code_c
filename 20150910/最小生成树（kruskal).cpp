#include <iostream>
#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
const int maxn=5000;
int p[100];
struct edge
{
    int u,v,d;
}e[maxn];
bool cmp(edge a,edge b)
{
    return a.d<b.d;
}
int find(int x)
{
    if(p[x]!=x)   p[x]=find(p[x]);
    return p[x];
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int i,m=n*(n-1)/2;
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].d);
        }
        sort(e,e+m,cmp);
        for(i=1;i<=n;i++)   p[i]=i;
        int l=0;
        for(i=0;i<m;i++)
        {
            int x=find(e[i].u);
            int y=find(e[i].v);
            if(x!=y)
            {
                l+=e[i].d;
                p[x]=y;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}
