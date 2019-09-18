#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=100005;
int a[maxn];
void swap(int *arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
long long merge(int* temp, int *arr, int x, int y, int m, int n)
{
    long long nOrder = 0;
    int i = x, j = m;
    for(i = x; i <= y; ++i)
    {
        while(j <= n && arr[i] > arr[j])
            ++j;
        nOrder += j-m;
    }
    int k = 0;
    i = x, j = m;
    while(i <= y && j <= n)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= y)
        temp[k++] = arr[i++];
    while(j <= n)
        temp[k++] = arr[j++];
    return nOrder;
}
long long inversion_number(int *arr, int i, int j)
{
    if(i < j)
    {
        int mid = i+((j-i)>>1);
        long long v1 = inversion_number(arr, i, mid);
        long long v2  = inversion_number(arr, mid+1, j);
        int temp[maxn];
        long long nValue = merge(temp, arr, i, mid, mid+1, j);
        memcpy(arr+i, temp, sizeof(int)*(j-i+1));
        return v1+v2+nValue;
    }
    else
        return 0;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        long long ans=inversion_number(a, 0, n-1);

        printf("%lld\n",ans);
    }
    return 0;
}
