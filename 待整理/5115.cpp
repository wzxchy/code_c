#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=205;
int dp[maxn][maxn];
int b[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n,t,ans=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&t);
            ans+=t;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        dp[0][0]=b[1];
        d[n-1][n-1]=b[n-2];
        for(i=1;i<n;i++)
        {
             dp[i][i]=b[i-1]+b[i+1];
        }
        for(i=2;i<=n;i++)//区间长度
        {
            for(j=0;j<=n-i;j++)//区间起点j  终点 i+j-1
            {
                for(k=j;k<=i+j-1;k++)
                {

                }
            }
        }


    }
    return 0;
}
