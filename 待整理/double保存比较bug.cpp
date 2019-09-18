#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=10;
int main()
{
    double x=18.0;
    double a=17.95;
    double b=0.05;
    if(a+b<18.00)  cout<<1<<endl;
    if(a+b<x)   cout<<2<<endl;
    return 0;
}
