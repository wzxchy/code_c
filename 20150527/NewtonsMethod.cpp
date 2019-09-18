#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
double k;
double e;
double newtons()
{
    double x0=k+1,x1=k+1;
    double s;
    do
    {
        x0=x1;
        s=(x0-k/x0)/2;
        x1=x0-s;
        printf("%.8f\n",x1);
    }while(fabs(s)>e);
    return x1;
}
double f(double x)
{
    return x*x-k;
}
double secant()
{
    double x0=k+2,x1=k+1,x2;
    double s;
    do
    {
        s=f(x1)*(x1-x0)/(f(x1)-f(x0));
        x2=x1-s;
        printf("%.8f\n",x2);
        x0=x1;
        x1=x2;
    }while(fabs(s)>e);
    return x2;
}
double bisection()
{
    double a=0,b=k+1;
    double m;
    do
    {
        m=(a+b)/2;
        printf("%.8f\n",m);
        if(f(m)==0)  break;
        if(f(a)*f(m)<0)  b=m;
		else a=m;
    }while(fabs(b-a)>e);
    return m;
    /*
    double prem=(a+b)/2,m=prem;
	double pred=b-a,d;
	if(f(a)*f(m)<0)  b=m;
	else a=m;
	while((b-a)/2>e)
	{
		m=(a+b)/2;
		printf("%.8f\n",m);
		d=b-a;
		prem=m;
		pred=d;
		if(f(m)==0)  break;
		if(f(a)*f(m)<0)  b=m;
		else a=m;
	}
	*/
}
int main()
{
    scanf("%lf %lf",&k,&e);
    bisection();
    printf("\n");
    newtons();
    printf("\n");
    secant();
    return 0;
}
/*
10 0.0000001 115  0.000001
*/
