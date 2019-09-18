#include <iostream>
#include <string.h>
using namespace std;
typedef int DataType;
void InsertSort(DataType a[],int n)//直接插入
{
    int i,j;
    DataType temp;
    for(i=0;i<n-1;i++)
    {
        temp=a[i+1];
        j=i;
        while(j>-1&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
void ShellSort(DataType a[],int n,int d[],int numofd)//希尔
{
    int i,j,k,m,span;
    DataType temp;
    for(m=0;m<numofd;m++)
    {
        span=d[m];
        for(k=0;k<span;k++)
        {
            for(i=k;i<n-span;i+=span)
            {
                temp=a[i+span];
                j=i;
                while(j>-1&&a[j]>temp)
                {
                    a[j+span]=a[j];
                    j-=span;
                }
                a[j+span]=temp;
            }
        }
    }
}
void SelectSort(DataType a[],int n)//直接选择
{
    int i,j,small;
    DataType temp;
    for(i=0;i<n-1;i++)
    {
        small=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[small])   small=j;
        }
        if(small!=i)
        {
            temp=a[i];
            a[i]=a[small];
            a[small]=temp;
        }
    }
}
void BubbleSort(DataType a[],int n)//冒泡
{
    int i,j,flag=1;
    DataType temp;
    for(i=1;i<n&&flag==1;i++)
    {
        flag=0;
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                flag=1;
            }
        }
    }
}
void QuickSort(DataType a[],int low,int high)//快速排序
{
    int s[2000];
    int top=2;
    int i,j,l,h;
    DataType temp;
    s[0]=low;
    s[1]=high;
    while(top>0)
    {
        h=s[--top];
        l=s[--top];
		i=l;j=h;
        temp=a[i];
        while(i<j)
        {
            while(i<j&&temp<=a[j])   j--;
            if(i<j)
            {
                a[i]=a[j];
                i++;
            }
            while(i<j&&temp>=a[i])   i++;
            if(i<j)
            {
                a[j]=a[i];
                j--;
            }
        }
        a[i]=temp;
        if(l+1<i)
        {
            s[top++]=l;
            s[top++]=i-1;
        }
        if(i+1<h)
        {
            s[top++]=i+1;
            s[top++]=h;
        }
    }
}
void QuickSort2(int *a, int left, int right)
{
    if(left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return ;
    }
    int i = left;
    int j = right;
    int key = a[left];

    while(i < j)                               /*控制在当组内寻找一遍*/
    {
        while(i < j && key <= a[j])
        /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
        序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
        {
            j--;/*向前寻找*/
        }

        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[left]，那么就是给key）*/

        while(i < j && key >= a[i])
        /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
        因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }

        a[j] = a[i];
    }

    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    QuickSort2(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    QuickSort2(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
                       /*当然最后可能会出现很多分左右，直到每一组的i = j 为止*/
}
void CreatHeap(DataType a[],int n,int h)
{
    int i,j;
    DataType temp;
    temp=a[h];
    i=h;
    j=2*h+1;
    while(j<n)
    {
        if(j+1<n&&a[j+1]>a[j])   j++;
        if(a[j]<=temp)   break;
        a[i]=a[j];
        i=j;
        j=2*i+1;
    }
    a[i]=temp;
}
void HeapSort(DataType a[],int n)//堆排序
{
    int i;
    DataType temp;
    for(i=n/2-1;i>=0;i--)    CreatHeap(a,n,i);
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        CreatHeap(a,i,0);
    }
}
void RadixSort(DataType a[],int n,int m,int d)//基排序
{
    int i,j,k,power=1;
    DataType **q;
    q=new DataType* [d];
    for(i=0;i<d;i++)  q[i]=new DataType[n];
    int *front=new int[d];
    int *rear=new int[d];
    for(i=0;i<m;i++)
    {
        for(j=0;j<d;j++)
        {
            front[j]=0;
            rear[j]=0;
        }
        for(j=0;j<n;j++)
        {
            k=a[j]/power-(a[j]/(power*d))*d;
            q[k][rear[k]++]=a[j];
        }
        for(j=0,k=0;j<d;j++)
        {
            while(front[j]<rear[j])   a[k++]=q[j][front[j]++];
        }
        power*=d;
    }
    delete[] front;
    delete[] rear;
    for(i=0;i<d;i++)   delete[] q[i];
    delete[] q;
}
void Merge(DataType a[],int n,DataType swap[],int k)
{
    int l1=0,l2,u1,u2,i,j,m=0;
    while(l1+k<n)
    {
        l2=l1+k;
        u1=l2-1;
        u2=(l2+k-1<=n-1)? l2+k-1:n-1;
        i=l1;j=l2;
        while(i<=u1&&j<=u2)
        {
            while(i<=u1&&j<=u2&&a[i]<=a[j]) swap[m++]=a[i++];
            while(i<=u1&&j<=u2&&a[j]<=a[i]) swap[m++]=a[j++];
        }
        while(i<=u1)  swap[m++]=a[i++];
        while(j<=u2)  swap[m++]=a[j++];
        l1=u2+1;
    }
    for(i=l1;i<n;i++,m++)  swap[m]=a[i];
}
void MergeSort(DataType a[],int n)//归并
{
    int i,k=1;
    DataType* swap=new DataType[n];
    while(k<n)
    {
        Merge(a,n,swap,k);
        for(i=0;i<n;i++)   a[i]=swap[i];
        k*=2;
    }
    delete []swap;
}
int main()
{
    int a[10]={10,33,88,97,8,9,78,99,2,111};
    int i,j;
    int d[3]={6,3,1};
    MergeSort(a,10);
    for(i=0;i<10;i++)   cout<<a[i]<<"  ";
    cout<<endl;
    return 0;
}
//
