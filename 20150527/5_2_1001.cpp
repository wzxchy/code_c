#include <iostream>
#include "stdio.h"
#include "string.h"
#include <algorithm>
using namespace std;
const int maxn=10000005;
struct node
{
    int a,b;
}s[maxn];
bool cmp(node x,node y)
{
    return x.b<y.b;
}
int main()
{
    int n;
    __int64 l1,r1,a,b,c,d;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %I64d %I64d %I64d %I64d %I64d %I64d",&n,&l1,&r1,&a,&b,&c,&d);
        int i,j;
        s[0].a=l1;
        s[0].b=r1;
        if(l1>r1)
        {
            __int64 t;
            t=s[0].a;
            s[0].a=s[0].b;
            s[0].b=t;
        }
        for(i=1;i<n;i++)
        {
            __int64 t1=s[i-1].a%4294967296;
            __int64 t2=a%4294967296;
            t1=(t1*t2)%4294967296;
            t2=b%4294967296;
            s[i].a=(t1+t2)%4294967296;

            t1=s[i-1].b%4294967296;
            t2=c%4294967296;
            t1=(t1*t2)%4294967296;
            t2=d%4294967296;
            s[i].b=(t1+t2)%4294967296;

            if(s[i].a>s[i].b)
            {
                int t;
                t=s[i].a;
                s[i].a=s[i].b;
                s[i].b=t;
            }
        }
        sort(s,s+n,cmp);
        int ans=1;
        int end=s[0].b;
        for(i=1;i<n;i++)
        {
           if(s[i].a>end)
           {
              ans++;
              if(ans>=3)  break;
              end=s[i].b;
           }
        }
        if(i<n)   printf("YES\n");
        else  printf("NO\n");
    }
    return 0;
}
