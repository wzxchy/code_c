#include <iostream>
#include "stdio.h"
#include "string.h"
#include <cmath>
using namespace std;
const int maxn=20;//max number of datas
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
double Poly_Horner(double a[],int n,double x)//a:coefficient of polynomial(a[0]-a[n] = coefficient of degree 0-n) n:degree
{
	double p=a[n];
	int i;
	for(i=n-1;i>=0;i--)
	{
		p=p*x+a[i];
	}
	return p;
}
int main()
{
    double a[maxn][8],a1[8][maxn],c[8][8];//c:要求解的方程组系数
    double x[maxn],y[maxn],b[maxn],cn[8];//x:自变量 y:因变量    b:要求解的方程组b  cn:多项式系数
    int m=8,n=2;//m: the number of all datas   n:degree of polynomial
    int i,j,k;
    for(i=0;i<m;i++)  scanf("%lf",&x[i]);
    for(i=0;i<m;i++)  scanf("%lf",&y[i]);
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
    GaussianElimination(c,b,n+1);
    backward(c,b,cn,n+1);
    for(i=0;i<=n;i++)   printf("%.8lf\n",cn[i]);
    printf("\n");
    for(i=0;i<m;i++)  printf("%.5f   ",Poly_Horner(cn,n,x[i]));
    return 0;
}
/*
250 260 270 280 290 300  310 320
200 190 176 150 139 125  110 100

0    60   120  180  240  300  360  420
1.00 1.40 1.70 1.85 1.95 2.00 1.95 1.80
*/
