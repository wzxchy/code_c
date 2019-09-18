#include<iostream>
#include "stdio.h"
#include "string.h"
using namespace std;
const int MAXN=105;
int topo[MAXN];
int c[MAXN];
int G[MAXN][MAXN];
int n,m;
bool toposort()
{
    int t=n;
    memset(c,0,sizeof(c));
    int u;
    int s[2000];
    int top=0;
    for(u=0;u<n;u++)
       if(!c[u])
       {
           s[top++]=u;
           c[u]=-1;
           while(top>0)
           {
               int temp=s[top-1];
               int i;
               for(i=0;i<n;i++)
                   if(G[temp][i])
                   {
                       if(c[i]==-1)   return false;
                       if(c[i]==0)
                       {
                           s[top++]=i;
                           c[i]=-1;
                           break;
                       }
                   }
               if(i==n)
               {
                   c[temp]=1;
                   topo[--t]=s[--top];
               }
           }
       }
    return true;
}
int main()
{
    while(~scanf("%d %d",&n,&m)&&n)
    {
        int i;
        memset(G,0,sizeof(G));
        for(i=0;i<m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            G[u][v]=1;
        }
        if(toposort())   printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}

