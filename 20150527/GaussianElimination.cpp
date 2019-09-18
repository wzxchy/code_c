#include <iostream>
#include "stdio.h"
#include "string.h"
#include <cmath>
using namespace std;
const int maxn=20;
void backward(double a[][8],double b[],double x[],int n)//a[][]:start from a[0][0],ÏµÊý¾ØÕó;
{
    int i,j;
    for(i=n-1;i>=0;i--)
    {
        double s=0;
        for(j=i+1;j<n;j++)
        {
            s+=a[i][j]*x[j];
        }
        x[i]=(b[i]-s)/a[i][i];
    }
}
void GaussianElimination(double a[][8],double b[],int n)//a[][]:start from a[0][0];
{
     int i,j,k;
     for(i=0;i<n-1;i++)
     {
         for(j=i+1;j<n;j++)
         {
             double t=a[j][i]/a[i][i];
             for(k=i;k<n;k++)
             {
                 a[j][k]-=t*a[i][k];
             }
             b[j]-=t*b[i];
         }
     }
}
int main()
{
    double a[maxn][8];//start from a[0][0];
    double x[maxn],b[maxn];
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%lf",&a[i][j]);
    }
    for(i=0;i<n;i++)   scanf("%lf",&b[i]);
    GaussianElimination(a,b,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%.2lf ",a[i][j]);
        }
        printf("%.5lf",b[i]);
        printf("\n");
    }
    backward(a,b,x,n);
    for(i=0;i<n;i++)   printf("%.8lf\n",x[i]);
    for(i=0;i<n;i++)
    {
        double t=0;
        for(j=0;j<n;j++)   t+=a[i][j]*x[j];
        printf("%lf\n",t);
    }

    return 0;
}
/*
3
1 -1 3
1 1 0
3 -2 1

3 4 2
*/
