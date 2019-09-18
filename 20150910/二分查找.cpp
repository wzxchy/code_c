#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1005;
int a[maxn][maxn];
int find(int a[],int low,int high,int x)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x<a[mid])   high=mid-1;
        else if(a[mid]<x)    low=mid+1;
             else   return mid;
    }
    if(a[mid]!=x)    mid=-1;
    return mid;
}
int main()
{
    int m,n;
    while(~scanf("%d %d",&m,&n))
    {
        int t;
        scanf("%d",&t);
        int i,j;
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        int flag=0;
        for(i=0;i<m;i++)
        {
            if(a[i][0]>t)   break;
            if(find(a[i],0,n-1,t)>=0)
            {
                flag=1;
                break;
            }
        }
        if(flag)   printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
/*
8 9 0 7
6 8  9 7
 8 0 8 7
 7 9  0 8
     int b[10][10];
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)  scanf("%d",&a[i][j]);
    for(i=0;i<4;i++)  f(a[i],4);
 */

