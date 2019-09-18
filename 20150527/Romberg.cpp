#include <iostream>
#include <cmath>
#include "stdio.h"
using namespace std;
const int maxn=21;
double T[maxn][maxn];
double f(double x)//
{
    return 4/(1+x*x);
}
double romberg(double a,double b,double e)//(a,b)interval   e:error
{
    double s1,s2;
    double h=b-a;
    s1=h*(f(a)+f(b))/2;
    T[0][0]=s1;
    int i,k;
    for(k=1;;k++)
    {
        h/=2;
        double x=a+h;
        double t=0;
        while(x<b)
        {
            t+=f(x);
            x+=2*h;
        }
        t=t*h;
        s2=s1/2+t;
        s1=s2;
        T[k][0]=s1;
        int m=4;
        for(i=1;i<=k;i++)
        {
            T[k][i]=(m*T[k][i-1]-T[k-1][i-1])/(m-1);
            m*=4;
        }
        if(fabs(T[k][k]-T[k-1][k-1])<e||k==20)    break;
    }
    return T[k][k];
}
int main()
{
    double a=0,b=1;
    int i,j;
    printf("%.5f\n",romberg(a,b,0.000001));
    for(i=0;i<6;i++)
    {
        for(j=0;j<=i;j++)
           printf("%.6lf  ",T[i][j]);
        printf("%\n");
    }
    return 0;
}
