#include <iostream>
#include "stdio.h"
#include "string.h"
#include <cmath>
#include <vector>
using namespace std;
const int maxn=105;
const double pi=3.14159265359;
double f(double x)
{
	return 0.05*sin(1000*x)+0.5*cos(pi*x)-0.4*sin(10*x);
}
void backward(double a[][8],double b[],double x[],int n)//a[][]:start from a[0][0],系数矩阵;
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
void GaussianElimination(double a[][8],double b[],int n)//a[][]:start from a[0][0],系数矩阵;
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
    double a[maxn][8],a1[8][maxn],c[8][8];//c:要求解的方程组系数
    double x[maxn],y[maxn],b[8],cn[8];//x:自变量 y:因变量    b:要求解的方程组b  cn:多项式系数(待求解未知数)
    int m=100,n=6;//m: the number of datas   n:degree of polynomial
    int i,j,k;
    x[0]=0;
    for(i=1;i<m;i++)  x[i]=x[i-1]+0.01;
    for(i=0;i<m;i++)  y[i]=f(x[i]);
    for(i=0;i<m;i++)
    {
        for(j=0;j<=n;j++)
        {
            a[i][j]=pow(x[i],j);
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<m;j++)
        {
            a1[i][j]=a[j][i];
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            double s=0;
            for(k=0;k<m;k++)
            {
                s+=a1[i][k]*a[k][j];
            }
            c[i][j]=s;
        }
    }
    for(i=0;i<=n;i++)
    {
        double s=0;
        for(j=0;j<m;j++)
        {
            s+=a1[i][j]*y[j];
        }
        b[i]=s;
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%.2lf ",c[i][j]);
        }
        printf("%.5lf",b[i]);
        printf("\n");
    }
    printf("\n");
    GaussianElimination(c,b,n+1);
    backward(c,b,cn,n+1);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("%.2lf ",c[i][j]);
        }
        printf("%.5lf",b[i]);
        printf("\n");
    }
    for(i=0;i<=n;i++)   printf("%.8lf\n",cn[i]);
    return 0;
}
/*


*/
