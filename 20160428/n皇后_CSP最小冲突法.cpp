#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int maxn=1005;
int queen[maxn];
int n;


void init()
{
    int i;
    for(i=0;i<n;i++)
    {
        queen[i]=rand()%n;
    }
}
void adjust(int c)//调整第c行
{
    int cnt,p;
    int i,j;
    int min_conflicts=maxn;
    for(i=0;i<n;i++)// 放在第i列
    {
        cnt=0;
        for(j=0;j<n;j++)
        {
            if(j==c)  continue;
            if(queen[j]==i)
            {
                cnt++;
                continue;
            }
            if(queen[j]-i==j-c||queen[j]-i==c-j)  cnt++;
        }
        if(cnt==min_conflicts)
        {
            int temp=rand()%2;
            if(temp==0)  p=i;
        }
        else if(cnt<min_conflicts)
        {
            min_conflicts=cnt;
            p=i;
        }
    }
    queen[c]=p;
}
int cal_conflicts()
{
    int i,j;
    int cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(queen[i]==queen[j])
            {
                return 1;
                //cnt++;
                //continue;
            }
            if(queen[i]-queen[j]==i-j||queen[i]-queen[j]==j-i)
            {
                return 1;
                //cnt++;
            }
        }
    }
    return 0;
}
int main()
{
    srand(time(NULL));
    scanf("%d",&n);
	clock_t cBegin = clock();
    init();
    int i,j,k;
    int c=0;
    int conflicts=cal_conflicts();
    while(cal_conflicts())
    {
        adjust(c);
        //conflicts=cal_conflicts();
        c=(c+1)%n;
        //cout<<c<<endl;
    }
    for(i=0;i<n;i++)  cout<<queen[i]<<"  ";
    cout<<endl;

    clock_t cEnd = clock();
    printf("execution time: %d ms\n", (cEnd - cBegin)*1000 / CLOCKS_PER_SEC);
    return 0;
}
