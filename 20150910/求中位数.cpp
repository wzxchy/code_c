#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=100005;
double a[maxn];
void QuickSort(double *a, int left, int right, int pos)
{
    int i = left;
    int j = right;
    double key = a[left];
    while(i < j)
    {
        while(i < j && key <= a[j])   j--;
        a[i] = a[j];

        while(i < j && key >= a[i])   i++;
        a[j] = a[i];
    }
    a[i] = key;
    if(i==pos)   return ;
    if(pos<i)    QuickSort(a,left,i-1,pos);
    else    QuickSort(a,i+1,right,pos);
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
        }
        QuickSort(a,0,n-1,n/2);
        if(n%2==1)
        {
            printf("%.2f\n",a[n/2]);
        }
        else
        {
            int max=a[0];
            for(i=1;i<n/2;i++)
            {
                if(a[i]>max)   max=a[i];
            }
            double ans=(max+a[n/2])/2;
            printf("%.2f\n",ans);
        }
    }
    return 0;
}


