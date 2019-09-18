#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str1[110010],str2[110010*2];
int n,a[110010*2];
int min(int x,int y)
{
    return x>y?y:x;
}
void ini(int len)
{
    int i;
    n=1;
    str2[0]='$';
    for(i=0;i<len;i++)
    {
        str2[n++]='#';
        str2[n++]=str1[i];
    }
    str2[n]='#';
}
int solve()
{
    int max=-1;
    int i,k,p=0;
    for(i=1;i<n;i++)
    {
        if(i<p)   a[i]=min(a[k*2-i],p-i);
        else   a[i]=1;
        while(str2[i+a[i]]==str2[i-a[i]])
        {
            a[i]++;
        }
        if(i+a[i]>p)
        {
            k=i;
            p=i+a[i];
        }
        if(max<a[i])   max=a[i];
    }
    return max;
}
int main()
{
    int len,max;
    while(gets(str1))
    {
       len=strlen(str1);
       ini(len);
       max=solve();
       printf("%d\n",max-1);
    }
    return 0;
}
/*
aaaa

abab

aaaa

abab

aaaa

abab
*/
