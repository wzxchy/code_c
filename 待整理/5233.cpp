#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
struct node
{
    int h;//高度
    int i;//第i个
    int flag;
}b[maxn];
bool cmp(node x,node y)
{
    if(x.h<y.h||x.h==y.h&&x.i<y.i)  return 1;
    return 0;
}
int find(node a[],int high,int x)
{
    int low=1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x<a[mid].h)   high=mid-1;
        else if(a[mid].h<x)    low=mid+1;
        else
        {
            while(mid>1&&a[mid-1].h==a[mid].h&&a[mid-1].flag==0)   mid--;
            return mid;
        }
    }
    if(a[mid].h!=x)    return -1;
    while(mid>1&&a[mid-1].h==a[mid].h&&a[mid-1].flag==0)   mid--;
    return mid;
}
int main()
{
    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        int i,j;
        for(i=1;i<=n;i++)
        {
            int h0;
            scanf("%d",&h0);
            b[i].i=i;
            b[i].h=h0;
            b[i].flag=0;
        }
        sort(b+1,b+n+1,cmp);
        int q;
        for(i=0;i<m;i++)
        {
            scanf("%d",&q);
            int x=find(b,n,q);
            if(x==-1)   printf("0\n");
            else
            {
                int h0=b[x].h;
                while(x<=n&&b[x].h==h0&&b[x].flag==1)   x++;
                if(x>n||b[x].h!=h0)   printf("0\n");
                else
                {
                    printf("%d\n",b[x].i);
                    b[x].flag=1;
                }
            }
        }
    }
    return 0;
}
/*
10 111
3 9 6 5 4 4 9 6 3 3

*/
