#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int f(int n)//最大素因子（素因子分解）
{
    int i=2;
    while(i*i<=n)
    {
        if(n%i==0)
        {
            while(n%i==0)  n/=i;
        }
        i++;
    }
    if(n>1)  return n;
    return i;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0||n==1)
        {
            printf("0\n");
            continue;
        }
        int t=f(n);
        int ans=n/t;
        printf("%d\n",ans);
    }
    return 0;
}
