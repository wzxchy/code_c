#include <iostream>
#include <cmath>
#include "stdio.h"
using namespace std;
double f(double x)//
{
    return 4/(1+x*x);
}
double midpoint(double a,double b,double e)//(a,b)interval   e:error
{
    double s1,s2=0;
    double h=b-a;//the length of interval
    s1=h*f((a+b)/2);
    int time=16;
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
        s1=s2;
    }
    return s2;
}
int main()
{
    double a=0;
    double b=1;
    double e=0.0001;
    printf("%.8lf\n",midpoint(a,b,e));
    return 0;
}
