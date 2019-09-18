#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=(1<<16)+10;
const int inf=1<<30;
int dp[16][maxn];
int dis[16][16];
int n;
int min(int a,int b)
{
    if(a<b)  return a;
    return b;
}
int f(int u,int s)
{
    if(dp[u][s]>=0)  return dp[u][s];
    if(s==0)  return dis[u][0];
    int i;
    int tmp=1;
    int ans=inf;
    for(i=0;i<n;i++)
    {
        if(s&tmp) ans=min(ans,dis[u][i]+f(i,s-tmp));
        tmp=tmp<<1;
    }
    dp[u][s]=ans;
    return ans;
}
int main()
{
    while(~scanf("%d",&n))
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&dis[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=f(0,(1<<n)-2);
        printf("%d\n",ans);
    }
    return 0;
}
/*


*/
