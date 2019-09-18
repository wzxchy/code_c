#include <iostream>
#include <cmath>
#include "stdio.h"
using namespace std;
const int maxn=21;
double T[maxn][maxn];
double f(double x)//
{
    return 4/(1+x*x);
    //return sqrt(x);
}
double trapezoidal(double a,double b,double e)//(a,b)interval   e:error
{
    double s1,s2;
    double h=b-a;
    s1=h*(f(a)+f(b))/2;
    //printf("%.10lf\n",s1);
    int time=5;
    while(time--)
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
         //if(fabs(s1-s2)<e)   break;
         s1=s2;
         printf("%.10lf\n",s1);
    }
    return s2;
}
double midpoint(double a,double b,double e)//(a,b)interval   e:error
{
    double s1,s2=0;
    double h=b-a;//the length of interval
    s1=h*f((a+b)/2);
    //printf("%.10lf\n",s1);
    int time=5;
    while(time--)
    {
        h/=2;
        double tx=h/2;
        s2=0;
        while(tx<b)
        {
            s2+=f(tx);
            tx+=h;
        }
        s2*=h;
        //if(fabs(s1-s2)<e)   break;
        s1=s2;
        printf("%.10lf\n",s1);
    }
    return s2;
}
double simpson(double a,double b,double e)
{
    double s1,s2;
    double h=b-a;
    double t0=f(a)+f(b);//t0:区间端点函数值之和
    double t1=0;//t1:分区间端点函数值之和    t2:分区间中点函数值之和
    double t2=f((a+b)/2);
    s1=(t0+4*t2)*h/6;
    //printf("%.10lf\n",s1);
    int time=5;
    while(time--)
    {
         h/=2;
         t1=t1+t2;
         t2=0;
         double x=a+h/2;
         while(x<b)
         {
             t2+=f(x);
             x+=h;
         }
         s2=(t0+2*t1+4*t2)*h/6;
         //if(fabs(s1-s2)<e)   break;
         s1=s2;
         printf("%.10lf\n",s1);
    }
    return s2;
}
double romberg(double a,double b,double e)//(a,b)interval   e:error
{
    double s1,s2;
    double h=b-a;
    s1=h*(f(a)+f(b))/2;
    printf("%.10lf\n",s1);
    T[0][0]=s1;
    int i,k;
    for(k=1;k<=5;k++)
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
        //if(fabs(T[k][k]-T[k-1][k-1])<e||k==20)    break;
        printf("%.10lf\n",T[k][k]);
    }
    return T[k-1][k-1];
}
int main()
{
    double a=0,b=1;
    double e=0.00000001;
    printf("%.10f\n",trapezoidal(a,b,e));
    printf("\n");
    printf("%.10f\n",midpoint(a,b,e));
    printf("\n");
    printf("%.10f\n",simpson(a,b,e));
    printf("\n");
    printf("%.10f\n",romberg(a,b,e));
    return 0;
}
