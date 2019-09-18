#include <iostream>
#include "stdio.h"
#include "string.h"
#include <cmath>
using namespace std;
const int maxn=15;
double nest(double c[],double a[],double x,int n)//c:coefficient   a:x of datas  n:degree of polynomial
{
    double s=c[n];
    int i,j;
    for(i=n-1;i>=0;i--)
    {
        s=s*(x-a[i])+c[i];
    }
    return s;
}
int main()
{
    double x[maxn],y[maxn];//x:x of datas  y:y of datas
    double dd[maxn];//divided differences
    double c[maxn];//coefficient
    int i,j,n;//n: degree of polynomial
    scanf("%d",&n);
    for(i=0;i<=n;i++)  scanf("%lf",&x[i]);
    for(i=0;i<=n;i++)  scanf("%lf",&y[i]);
    for(i=0;i<=n;i++)  dd[i]=y[i];
    c[0]=dd[0];
    for(i=1;i<=n;i++)
    {
        for(j=n;j>=i;j--)
        {
            dd[j]=(dd[j]-dd[j-1])/(x[j]-x[j-i]);
        }
        c[i]=dd[i];
    }
    //for(i=0;i<=n;i++)   printf("%.5f  ",c[i]);
    //printf("\n");
    //for(i=0;i<=n;i++)   printf("%.5f  ",dd[i]);
    printf("%.5f",nest(c,x,0.1,n));

    return 0;
}
/*
5
0.40     0.55      0.65      0.80      0.90     1.05
0.41075  0.57815   0.69675   0.88811   1.02652  1.25382

2
1 2 4
1 3 3

3
1 2 4 5
1 3 3 4

*/
