#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=1e5+5;
const int mod=9973;
int a[maxn];
char s[maxn];
int gcd(int a,int b,int &d,int &x,int &y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
int inv(int a,int n)//求a在模n下逆元
{
    int d,x,y;
    gcd(a,n,d,x,y);
    return d==1 ? (x+n)%n : -1;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        scanf("%s",s);
        int len=strlen(s);
        a[0]=1;
        int i;
        for(i=1;i<=len;i++)
        {
            a[i]=(a[i-1]*(s[i-1]-28))%mod;
        }
        int x,y;
        while(n--)
        {
            scanf("%d %d",&x,&y);
            int tx=a[x-1],ty=a[y];
            int txx=inv(tx,mod);
            int ans=(ty*txx)%mod;
            printf("%d\n",ans);
        }
    }
    return 0;
}
