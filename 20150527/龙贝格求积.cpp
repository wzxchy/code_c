#include <iostream>
#include <cmath>
#include "stdio.h"
using namespace std;
double f(double x)//
{
    return sqrt(x);
}
double trapezoidal(double a,double b,double e)//(a,b)interval   e:error
{
    double s1,s2;
    double h=b-a;
    s1=h*(f(a)+f(b))/2;
    while(1)
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
         if(fabs(s1-s2)<e)   break;
         s1=s2;
    }
    return s2;
}
int main()
{
    double a=0,b=1;
    printf("%.5f\n",trapezoidal(a,b,0.00001));
    return 0;
}
