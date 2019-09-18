#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;
const int maxn=50005;
int c[maxn];
int lowbit(int x)
{
    return x&(-x);
}
int sum(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=c[x];
        x-=lowbit(x);
    }
    return ret;
}
void add(int x,int d,int n)
{
    while(x<=n)
    {
        c[x]+=d;
        x+=lowbit(x);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int kase=1;
    while(T--)
    {
        printf("Case %d:\n",kase++);
        int n,i,j;
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        int t;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&t);
            add(i,t,n);
        }
        char s[8];
        while(1)
        {
            getchar();
            scanf("%s",s);
            if(strcmp(s,"End")==0)   break;
            int p,q;
            scanf("%d %d",&p,&q);
            if(strcmp(s,"Add")==0)
            {
                add(p,q,n);
            }
            else if(strcmp(s,"Sub")==0)
            {
                add(p,-q,n);
            }
            else
            {
                printf("%d\n",sum(q)-sum(p-1));
            }
        }
    }
    return 0;
}


