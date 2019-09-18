#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
const double pi=acos(-1);
const double e=1e-8;//误差
double f(double x)//将方程整理成y=f(x)的形式
{
    return x*x-10;
}
double f1(double x)//f1(x)为f(x)导函数
{
    return 2*x;
}
double bisection(double a,double b)//(a,b)初始区间
{
    double m=(a+b)/2;
    do
    {
        m=(a+b)/2;
        if(f(m)==0)  break;
        if(f(a)*f(m)<0)  b=m;
		else a=m;
    }while(fabs(b-a)>e);
    return m;
}
double newtons(double x0)//x0为初始迭代值
{
	double s=f(x0)/f1(x0);
	double x1=x0-s;
    do
    {
        x0=x1;
        s=f(x0)/f1(x0);
        x1=x0-s;
    }while(fabs(s)>e);
    return x1;
}
double secant(double x0,double x1)//x0,x1为初始迭代值
{
    double s=f(x1)*(x1-x0)/(f(x1)-f(x0));
	double x2=x1-s;
    do
    {
        s=f(x1)*(x1-x0)/(f(x1)-f(x0));
        x2=x1-s;
        x0=x1;
        x1=x2;
    }while(fabs(s)>e);
    return x2;
}
int main()
{
    printf("%.6lf\n",bisection(0,10));
    printf("%.6lf\n",newtons(10));
    printf("%.6lf\n",secant(6,5));
    return 0;
}


