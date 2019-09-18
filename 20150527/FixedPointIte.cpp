#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
double f1(double x)
{
    return x-(x*x-3)/4;
}
double f2(double x)
{
    return (x+3/x)/2;
}
int main()
{
    double x0,x1,e;
    scanf("%lf %lf",&x1,&e);
    do
    {
        x0=x1;
        x1=f1(x0);
        printf("%.8f\n",x1);
    }while(fabs(x1-x0)>e);
    printf("\n\n");
    scanf("%lf %lf",&x1,&e);
    do
    {
        x0=x1;
        x1=f2(x0);
        printf("%.8f\n",x1);
    }while(fabs(x1-x0)>e);
    return 0;
}
/*
2 0.0000001
*/
