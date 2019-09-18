#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=1000005;
const string snumber[11]={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖"};
const string sunit[5]={"拾","佰","仟","万","亿"};
string f4(int n,bool flag)//deal with number smaller than 10000  flag为0：无前缀
{
    string s;
    if(n>=10&&n<20&&flag==0)
    {
        s="拾";
        int t=n%10;
        if(t!=0)   s+=snumber[t];
        return s;
    }
    int count=-1;
    int t0=0;
    while(n>0)
    {
        int t=n%10;
        if(t==0)
        {
            if(t0!=0)
            {
                string s1="零";
                s=s1+s;
            }
        }
        else
        {
            string s1=snumber[t];
            if(count>=0)  s1+=sunit[count];
            s=s1+s;
        }
        count++;
        t0=t;
        n=n/10;
    }
    return s;
}
string f8(int n,bool flag)//5-8位  deal with number smaller than 100000000 and biger than 9999
{
    string s;
    int n1=n/10000;//高四位
    s=f4(n1,flag);
    s+="万";
    int n2=n%10000;//低四位
    if(n2>0)
    {
        if(n1%10==0||n2<1000)   s+="零";
        s+=f4(n2,1);
    }
    return s;
}
string f16(double n)//9-16位
{
    int n1=n/(1e8);//高8位
    string s;
    if(n1>=10000)   s=f8(n1,0);
    else   s=f4(n1,0);
    s+="亿";
    int n2=n-n1*(1e8);//低8位
    if(n2>0)
    {
        if(n1%10==0||n2<10000000)   s+="零";
        if(n2>=10000)   s+=f8(n2,1);
        else s+=f4(n2,1);
    }
    return s;
}
string f0(double n)//纯小数<1
{
    string s;
    n*=10;
    int n1=n;
    if(n1!=0)
    {
        s=snumber[n1];
        s+="角";
    }
    n=n-(int)n;
    n*=10;
    int n2=n;
    if(n2!=0)
    {
        s+=snumber[n2];
        s+="分";
    }
    return s;
}
int main()
{
    double a;
    while(cin>>a)
    {
        if(a==0)
        {
            cout<<"零元"<<endl;
            continue;
        }
        if(a<1)
        {
            cout<<"零元";
            cout<<f0(a)<<endl;
            continue;
        }
        string s;
        if(a>=1e8)   s=f16(floor(a));
        else if(a>=1e4)   s=f8(a,0);
        else s=f4(a,0);

        double at=a*100;
        long long a100=at;
        double div100=a100%100;
        double div=div100/100;
        if(div==0)
        {
            cout<<s<<"元整"<<endl;
        }
        else
        {
            cout<<s<<"元";
            double t1=a-floor(a/10)*10;//a个位
            if(t1==0||div<0.1)   cout<<"零";
            cout<<f0(div)<<endl;
        }
    }
    return 0;
}
/*
1000000000010010
1000000000100010
0.04
0.4
4.4
5.05
3
4.44
1
10
100
1000
10000
100000
11000001
1100029.1
10003.3
100.03
*/

