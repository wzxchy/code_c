#include <iostream>
#include "stdio.h"
#include <cmath>
using namespace std;
double f(double x)
{
    return 4/(1+x*x);
    //return sqrt(x);
}
double simpson(double a,double b,double e)
{
    double s1,s2;
    double h=b-a;
    double t0=f(a)+f(b);//t0:区间端点函数值之和
    double t1=0;//t1:分区间端点函数值之和    t2:分区间中点函数值之和
    double t2=f((a+b)/2);
    s1=(t0+4*t2)*h/6;
    while(1)
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
         if(fabs(s1-s2)<e)   break;
         s1=s2;
    }
    return s2;
}
int main()
{
    double a=0,b=1,e=0.0000001;
    printf("%.7f\n",simpson(a,b,e));
    return 0;
}
