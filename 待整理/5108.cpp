#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=3e7+5;
bool prime[maxn];
void fun()
{
    memset(prime,true,sizeof(prime));

    prime[0]=false;
    prime[1]=false;
    int i;
    for(i=2;i*i<maxn;i++)
    {
        if(prime[i])
        {
            int j=2*i;
            while(j<maxn)
            {
                prime[j]=false;
                j+=i;
            }
        }
    }
}
bool isprime(int n)
{
    if(n<maxn)  return prime[n];
    int i;
    int k=sqrt((double)n);
    for(i=2;i<=k;i++)
    {
        if(n%i==0)  return 0;
    }
    return 1;
}
int f(int n)
{
    int i=2;
    while(1)
    {
        if(isprime(i))
        {
            while(n%i==0)  n/=i;
            if(n==1)   break;
        }
        i++;
    }
    return i;
}
int main()
{
    int n;
    fun();
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
/*
*/
