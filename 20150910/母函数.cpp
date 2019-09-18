#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[51],t[51],n[27];
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
        int i,j,k;
        for(i=1;i<27;i++)   scanf("%d",&n[i]);
        memset(a,0,sizeof(a));
        memset(t,0,sizeof(t));
        a[0]=1;t[0]=1;
        for(i=1;i<27;i++)
        {
            for(j=1;j<=n[i];j++)
                for(k=0;k+j*i<=50;k++)
                    t[k+j*i]+=a[k];
            for(j=0;j<=50;j++)  a[j]=t[j];
        }
        int s=0;
        for(i=1;i<=50;i++)  s+=a[i];
        printf("%d\n",s);
    }
    return 0;
}
