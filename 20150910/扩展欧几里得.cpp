#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
typedef long long LL;
LL d,x,y;
void gcd(LL a,LL b,LL& d,LL& x,LL& y)
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
int main()
{
    long long a,b;
    while(~scanf("%lld %lld",&a,&b))
    {
        long long ta=a;
        long long tb=b;
        gcd(a,b,d,x,y);
        if(d==1)
        {
            int k;
            if(x<0)   k=ceil(-(double)x/b);
            else   k=-(x/b);
            //cout<<x<<endl<<y<<endl;
            //cout<<k<<endl;
            x+=k*tb;
            y-=k*ta;
            printf("%lld %lld\n",x,y);
        }
        else  printf("sorry\n");
    }
    return 0;
}
/*

*/
