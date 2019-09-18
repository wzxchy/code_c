#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int maxn=2e5+5;
char s[maxn];//字符串
int sa[maxn];//后缀数组
int t[maxn],t2[maxn];
int c[maxn];//基数排序计数
int rank0[maxn],height[maxn];
void build_sa(int n,int m)//n为字符串长度+1 字符值为0~m-1
{
    int i,*x=t,*y=t2;
    for(i=0;i<m;i++)  c[i]=0;
    for(i=0;i<n;i++)  c[x[i]=s[i]]++;
    for(i=1;i<m;i++)  c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)   sa[--c[x[i]]]=i;
    for(int k=1;k<=n;k<<=1)
    {
        int p=0;
        //利用sa数组排序第二关键字
        for(i=n-k;i<n;i++)   y[p++]=i;
        for(i=0;i<n;i++)
        {
            if(sa[i]>=k)  y[p++]=sa[i]-k;
        }
        //基数排序第一关键字
        for(i=0;i<m;i++)  c[i]=0;
        for(i=0;i<n;i++)  c[x[y[i]]]++;
        for(i=0;i<m;i++)  c[i]+=c[i-1];
        for(i=n-1;i>=0;i--)  sa[--c[x[y[i]]]]=y[i];
        //计算新的x数组
        swap(x,y);
        p=1;
        x[sa[0]]=0;
        for(i=1;i<n;i++)
        {
            if(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])
            {
                x[sa[i]]=p-1;
            }
            else
            {
                x[sa[i]]=p++;
            }
        }
        if(p>=n)  break;
        m=p;
    }
}
void getHeight(int n)//n为字符串长度+1
{
    int i,j,k=0;
    for(i=0;i<n;i++)   rank0[sa[i]]=i;
    for(i=0;i<n;i++)
    {
        if(rank0[i]==0)  continue;
        if(k)  k--;
        int j=sa[rank0[i]-1];
        while(s[i+k]==s[j+k])  k++;
        height[rank0[i]]=k;
    }
}
int main()
{
    while(~scanf("%s",s))
    {
        int len1=strlen(s);
        s[len1]='#';
        scanf("%s",s+len1+1);
        int len=strlen(s);
        build_sa(len+1,200);
        getHeight(len+1);
        int i,ans=0;
        for(i=1;i<=len;i++)
        {
            if(height[i]>ans)
            {
                if(sa[i]>len1 && sa[i-1]<len1 || sa[i]<len1 && sa[i-1]>len1)  ans=height[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
