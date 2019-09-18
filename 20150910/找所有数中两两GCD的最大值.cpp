#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int d[maxn];
int main()
{
    int n,k,T;
    k=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(d,0,sizeof(d));
        for(i=0;i<n;i++)
        {
            for(j=1;j*j<=a[i];j++)
            {
                if(a[i]%j==0)
                {
                    d[j]++;
                    d[a[i]/j]++;
                }
            }
        }
        int ans;
        for(i=100000;i>=1;i--)
        {
            if(d[i]>=2)
            {
                ans=i;
                break;
            }
        }
        printf("Case #%d: %d\n",k++,ans);
    }
    return 0;
}
