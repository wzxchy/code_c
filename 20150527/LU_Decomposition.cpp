#include <iostream>
#include "stdio.h"
#include "string.h"
#include <cmath>
using namespace std;
const int maxn=20;
double a[maxn][maxn];
double x[maxn],b[maxn];
void backward(int n)
{
    int i,j;
    for(i=n;i>0;i--)
    {
        double s=0;
        for(j=i+1;j<=n;j++)
        {
            s+=a[i][j]*x[j];
        }
        x[i]=(b[i]-s)/a[i][i];
    }
}
void forward(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        double s=0;
        for(j=1;j<i;j++)
        {
            s+=a[i][j]*x[j];
        }
        x[i]=(b[i]-s)/a[i][i];
    }
}
void LU_Decomposition(int n)
{
    int i,j,k;
    for(k=1;k<n;k++)
    {
        for(i=k+1;i<=n;i++)
        {
            a[i][k]=a[i][k]/a[k][k];
            for(j=k+1;j<=n;j++)
            {
                a[i][j]=a[i][j]-a[i][k]*a[k][j];
            }
        }
    }
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%lf",&a[i][j]);
    }
    LU_Decomposition(n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%.2lf ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
3
1 -1 3
1 1 0
3 -2 1
*/
