#include <iostream>
#include "stdio.h"
#include "string.h"
#include <cmath>
using namespace std;
const int maxn=20;//max number of datas
double lagrange(double x[],double y[],int n,double t)//x:x of datas(from 0 to n)  y:y of datas(from 0 to n)  n:degree of polynomial
{
    int i,j;
    double w[maxn],wy[maxn];
    for(i=0;i<=n;i++)
    {
        w[i]=1;
        for(j=0;j<=n;j++)
        {
            if(i!=j)   w[i]*=(x[i]-x[j]);
        }
        w[i]=1/w[i];
    }
    for(i=0;i<=n;i++)   wy[i]=w[i]*y[i];
    double s1=0,s2=0;
    for(i=0;i<=n;i++)
    {
        double temp=t-x[i];
        s1+=wy[i]/temp;
        s2+=w[i]/temp;
    }
    return s1/s2;
}
int main()
{
    double x[maxn],y[maxn];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<=n;i++)   scanf("%lf",&x[i]);
    for(i=0;i<=n;i++)   scanf("%lf",&y[i]);
    for(i=0;i<=n;i++)   printf("%lf   ",c[i]);
    printf("\n");
    double ans=lagrange(x,y,n,0.1);
    printf("%.5f\n",ans);
    return 0;
}
/*
1   2   4
1   3   3

0.40     0.55      0.65      0.80      0.90     1.05
0.41075  0.57815   0.69675   0.88811   1.02652  1.25382

2

1
7   14
98  101

0      7     14
100    98    101

7     14    21
98    101   50

 21      28     35
 50      51     50


 1
0.5 -0.5
20.5 -20.5
*/
