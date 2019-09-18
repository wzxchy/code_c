#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int q[maxn];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int i,j;
    for(i=0; i<n; i++)  scanf("%d",&a[i]);
    int front=0,rear=-1;
    for(i=0; i<k; i++)
    {
        while(front<=rear && a[q[rear]]>a[i])  rear--;
        rear++;
        q[rear]=i;
    }
    printf("%d",a[q[front]]);
    for(i=k; i<n; i++)
    {
        if(q[front]<i-k+1)  front++;
        while(front<=rear && a[q[rear]]>a[i])  rear--;
        rear++;
        q[rear]=i;
        printf(" %d",a[q[front]]);
    }
    printf("\n");
    ///////////////////////
    front=0;
    rear=-1;
    for(i=0; i<k; i++)
    {
        while(front<=rear && a[q[rear]]<a[i])  rear--;
        rear++;
        q[rear]=i;
    }
    printf("%d",a[q[front]]);
    for(i=k; i<n; i++)
    {
        if(q[front]<i-k+1)  front++;
        while(front<=rear && a[q[rear]]<a[i])  rear--;
        rear++;
        q[rear]=i;
        printf(" %d",a[q[front]]);
    }
    printf("\n");
    return 0;
}
