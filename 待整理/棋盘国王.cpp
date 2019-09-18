#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;
const int maxn=(1<<20)+5;
int map[21][21];
long long dp[maxn];
int n,m;
long long dfs(int d,int a)
{
    if(dp[a]!=-1)  return dp[a];
    int i,temp=1;
    for(i=0;i<n;i++)
    {
        if((a&temp)&&map[d][i]==0)
        {
            dp[a]+=dfs(d-1,a-temp);
        }
        temp<<=1;
    }
    return dp[a];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        memset(map,0,sizeof(map));
        dp[0]=1;
        int i;
        for(i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            map[x][y]=1;
        }
        int t=(1<<n)-1;
        printf("%lld\n",dfs(n-1,t));
    }
    return 0;
}
