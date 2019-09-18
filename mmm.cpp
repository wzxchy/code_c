#include <iostream>
#include <stdio.h>
using namespace std;
int a[15];
int flag[101];
int cnt;
bool check(int n)
{
    int i;
    for(i=1; i<n; i++)
    {
        int tmp=a[n]-a[i];
        if(flag[tmp]==1)  return 1;
    }
    return 0;
}
void print()
{
    int i;
    for(i=1; i<=10; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void dfs(int d)
{
    int tmp=a[d-1];
    int j;
    for(j=tmp+1; j<=tmp*2 && j<=100; j++)
    {
        a[d]=j;
        flag[j]=1;
        if(check(d)==1)
        {
            if(d==10)
            {
                print();
                cnt++;
                return ;
            }
            else
            {
                dfs(d+1);
            }
        }
        flag[j]=0;
    }
}
int main()
{
    int i,j;
    a[1]=1;
    flag[1]=1;
    cnt=0;
    dfs(2);
    cout<<cnt<<endl;
    return 0;
}
/*
for(i=2;i<=10;i++)
    {
        int tmp=a[i-1];
        for(j=tmp+1;j<=tmp*2 && j<=100;j++)
        {
            a[i]=j;
            flag[j]=1;
            if(check(i)==0)  continue;
            if(i==10)
            {
              print();
              cnt++;
            }
            flag[j]=0;
        }
    }
    */
