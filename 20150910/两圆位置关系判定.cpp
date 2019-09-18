#include <iostream>
#include "stdio.h"
#include "string.h"
#include "math.h"
using namespace std;
const double pi=2*asin(1.0);
double xa,ya,r1;
double xb,yb,r2;
double f()//
{
    double d=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));//圆心距
    if(d>=r1+r2)  return 0;//相离或外相切
    if(d<=fabs(r1-r2))//在内或内相切
    {
        if(r1<r2)  return pi*r1*r1;
        else  return pi*r2*r2;
    }
    double s=0;
    double cosa1=(r1*r1+d*d-r2*r2)/(2*r1*d);
    double a1=acos(cosa1);
    s+=a1*r1*r1;
    double d1=r1*cosa1;
    double l=r1*sin(a1);
    s-=d1*l;
    double cosa2=(r2*r2+d*d-r1*r1)/(2*r2*d);
    double a2=acos(cosa2);
    s+=a2*r2*r2;
    double d2=r2*cosa2;
    s-=d2*l;
    return s;
}
int main()
{
    while(~scanf("%lf %lf %lf %lf %lf %lf",&xa,&ya,&r1,&xb,&yb,&r2))
    {
        printf("%.3f\n",f());
    }
    return 0;
}
