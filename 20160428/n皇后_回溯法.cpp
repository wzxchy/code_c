#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<time.h>
using namespace std;
const int maxn=55;
int vis[maxn];
int map[maxn][maxn];
int ans1[maxn];
int n;
bool judge(int d,int i)
{
    int p=d-1;
    int q=i+1;
    while(p>=0&&q<n)
    {
        if(map[p][q])   return 0;
        p--;q++;
    }
    p=d-1;
    q=i-1;
    while(p>=0&&q>=0)
    {
        if(map[p][q])    return 0;
        p--;q--;
    }
    return 1;
}
int ans;
bool solve(int d)
{
    int i,j;

    if(d==n)
    {

        ans++;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(map[i][j]==1)
                {
                    printf("%d ",j);
                    break;
                }
            }
        }
        printf("\n");

        return 1;
    }

    for(i=0;i<n;i++)
    {
        if(vis[i])   continue;
        if(judge(d,i)==0)   continue;
        vis[i]=1;
        map[d][i]=1;
        if(solve(d+1))  return 1;;
        vis[i]=0;
        map[d][i]=0;
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
	clock_t cBegin = clock();
    memset(vis,0,sizeof(vis));
    memset(map,0,sizeof(map));
    solve(0);
    clock_t cEnd = clock();
    printf("execution time: %d ms\n", (cEnd - cBegin)*1000 / CLOCKS_PER_SEC);
    return 0;
}


