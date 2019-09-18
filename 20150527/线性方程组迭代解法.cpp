#include <iostream>
#include "stdio.h"
#include "string.h"
#include <cmath>
#include <vector>
using namespace std;
const int maxn=2005;
double x0[maxn],x1[maxn];
double a[maxn][maxn];
double b[maxn];
double e0=1e-8;
double n=3;
double w=0.5;
int main()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%lf",&a[i][j]);
    }
    for(i=1;i<=n;i++)   scanf("%lf",&b[i]);
    for(i=1;i<=n;i++)   scanf("%lf",&x0[i]);
    double e=1;
    int  k=0;
    while(e>e0)
    {
        k++;
        for(i=1;i<=n;i++)
        {
            double s=0;
            for(j=1;j<=n;j++)
            {
                if(i!=j)  s+=a[i][j]*x1[j];
            }
            x1[i]=(b[i]-s)/a[i][i];
        }
        e=0;
        for(i=1;i<=n;i++)  e+=fabs(x1[i]-x0[i]);
        for(i=1;i<=n;i++)  x0[i]=x1[i];
    }
    printf("%d\n",k);
    for(i=1;i<=n;i++)   printf("%.8lf\n",x0[i]);
    for(i=1;i<=n;i++)
    {
        double t=0;
        for(j=1;j<=n;j++)   t+=a[i][j]*x0[j];
        printf("%lf\n",t);
    }
    return 0;
}
/*
7 10 1
-3 10 2
1 7 -15

3 4 2

1 2 3

*/
