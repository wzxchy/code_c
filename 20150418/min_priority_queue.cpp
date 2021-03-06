#include <iostream>
#include <stdio.h>
using namespace std;
typedef int DataType;//array starting from 0
void HeapIfy(DataType a[],int n,int h)//n:number of elements
{
    int i,j;
    DataType temp;
    temp=a[h];
    i=h;
    j=2*h+1;
    while(j<n)
    {
        if(j+1<n&&a[j+1]<a[j])   j++;
        if(a[j]>=temp)   break;
        a[i]=a[j];
        i=j;
        j=2*i+1;
    }
    a[i]=temp;
}
void HeapInsert(DataType a[],int n,int key)//key:element to be inserted   n:number of elements after inserting
{
    int i=n-1,j=(i-1)/2;
    while(i>0&&a[j]>key)
    {
        a[i]=a[j];
        i=j;
        j=(i-1)/2;
    }
    a[i]=key;
}
DataType ExtractMax(DataType a[],int n)//n:number of elements before extracting
{
    DataType temp=a[0];
    a[0]=a[n-1];
    HeapIfy(a,n-1,0);
    return temp;
}
int main()
{
    int b[10]={10,33,1,97,8,1111,78,99,2,1121};
    int a[20];
    int i,j;
    for(i=0;i<10;i++)
    {
        HeapInsert(a,i+1,b[i]);
        //printf("%d\n",a[0]);
    }
    for(i=10;i>0;i--)
    {
        printf("%d\n",ExtractMax(a,i));
    }

    return 0;
}
/*
struct point
{
    int x,y,dis;
}p[maxn][maxn];
typedef point DataType;//array starting from 0
void HeapIfy(DataType a[],int n,int h)//n:number of elements
{
    int i,j;
    DataType temp;
    temp=a[h];
    i=h;
    j=2*h+1;
    while(j<n)
    {
        if(j+1<n&&a[j+1].dis<a[j].dis)   j++;
        if(a[j].dis>=temp.dis)   break;
        a[i]=a[j];
        i=j;
        j=2*i+1;
    }
    a[i]=temp;
}
void HeapInsert(DataType a[],int n,DataType key)//key:element to be inserted   n:number of elements after inserting
{
    int i=n-1,j=(i-1)/2;
    while(i>0&&a[j].dis>key.dis)
    {
        a[i]=a[j];
        i=j;
        j=(i-1)/2;
    }
    a[i]=key;
}
DataType ExtractMax(DataType a[],int n)//n:number of elements before extracting
{
    DataType temp=a[0];
    a[0]=a[n-1];
    HeapIfy(a,n-1,0);
    return temp;
}
*/
/*
struct point
{
    int x,y,dis;
};
typedef point DataType;//array starting from 0
DataType queue[2000];
int size;//number of elements
void HeapIfy(DataType a[],int h)
{
    int i,j;
    DataType temp;
    temp=a[h];
    i=h;
    j=2*h+1;
    while(j<size)
    {
        if(j+1<size&&a[j+1].dis<a[j].dis)   j++;
        if(a[j].dis>=temp.dis)   break;
        a[i]=a[j];
        i=j;
        j=2*i+1;
    }
    a[i]=temp;
}
void HeapInsert(DataType a[],DataType key)//key:element to be inserted
{
    size++;
    int i=size-1,j=(i-1)/2;
    while(i>0&&a[j].dis>key.dis)
    {
        a[i]=a[j];
        i=j;
        j=(i-1)/2;
    }
    a[i]=key;
}
DataType ExtractMin(DataType a[])//n:number of elements before extracting
{
    DataType temp=a[0];
    a[0]=a[size-1];
    size--;
    HeapIfy(a,0);
    return temp;
}
*/
