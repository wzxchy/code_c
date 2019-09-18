#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
void solve(char *s,int &a,int &b)
{
    int t1=1,t2,i,k;
    a=0;
    for(i=2;s[i]&&s[i]!='(';++i)
    {
        a=a*10+s[i]-'0';
        t1*=10;
    }
    b=a;
    t2=t1;
    if(s[i]!='(')
    {
        k=gcd(t1,a);
        a=a/k;
        b=t1/k;
        return;
    }
    for(++i;s[i]!=')';++i)
    {
        b=b*10+s[i]-'0';
        t2*=10;
    }
    a=b-a;
    b=t2-t1;
    k=gcd(a,b);
    a/=k;
    b/=k;
}
int main()
{
    char str[15];
    int a,b,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        solve(str,a,b);
        printf("%d/%d\n",a,b);
    }
    return 0;
}
