#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=1e5+1;
int Div[maxn][7];
void f(int n)//最大素因子（素因子分解）
{
    int i=2,count=0;
    int t=n;
    while(i*i<=n)
    {
        if(n%i==0)
        {
            while(n%i==0)  n/=i;
            Div[t][count++]=i;
        }
        i++;
    }
    if(n>1)  Div[t][count++]=n;
}
int phi[maxn];
long long sum[maxn];
void phi_table(int n)//n<=m
{
    int i,j;
    for(i=1;i<=n;i++)  phi[i]=i;
    for(i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(j=i;j<=n;j+=i)
            {
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
int counter,n,m;
void dfs(int d,int x,int b)
{
    if(Div[n][d]==0)
    {
        if(b==0)  return ;
        if(b%2==1)   counter-=m/x;
        else counter+=m/x;
        //cout<<b<<" "<<x<<" "<<c<<endl;
        return ;
    }
    dfs(d+1,x,b);
    dfs(d+1,x*Div[n][d],b+1);
}
int main()
{
    int T,a,b,c,d,k;
    int i,j;
    for(i=2;i<maxn;i++)   f(i);
    phi_table(100000);
    for(i=1;i<maxn;i++)   sum[i]=sum[i-1]+phi[i];
    int kase=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        if(k==0)
        {
            printf("Case %d: 0\n",kase++);
            continue;
        }
        if(b>d)
        {
            int t=b;
            b=d;
            d=t;
        }
        b/=k;
        d/=k;
        long long ans=0;
        ans+=sum[b];
        m=b;
        for(i=b+1;i<=d;i++)
        {
            counter=b;
            n=i;
            dfs(0,1,0);
            ans+=counter;
        }
        printf("Case %d: %lld\n",kase++,ans);
    }
    return 0;
}
/*
int phi[maxn];
void phi_table(int n,int m)//n<=m
{
    int i,j;
    for(i=1;i<=n;i++)  phi[i]=i;
    for(i=n+1;i<=m;i++)   phi[i]=n;
    for(i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            for(j=i;j<=m;j+=i)
            {
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}

*/
