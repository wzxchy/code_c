#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn=105;
int a[maxn];
int main()
{
    ifstream ifile;
    ifile.open("F:\\Code\\HallucinationFree\\build\\HallucinationFree\\bin\\Release\\meshs3\\debug_dis_out1.txt");
    const int n=51;
    int cnt[n];
    float l[n];
    float r[n];
    float tmp=-10;
    for(int i=0;i<n;i++)
    {
        l[i]=tmp-0.2;
        r[i]=tmp;
        tmp+=0.2;
    }

    for(int i=0;i<n;i++)  cnt[i]=0;
    int cnt0=0;
    double x;
    while(ifile>>x)
    {
        cnt0++;
        double xx=log10(x);
        int flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(xx<=r[i])
            {
                cnt[i]++;
                flag=1;
                break;
            }
        }
        if(flag==0)  cnt[n-1]++;

    }
    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        cnt1+=cnt[i];
        printf("%.1lf  %.1lf:  %d\n",l[i],r[i],cnt[i]);
        //cout<<cnt[i]<<endl;
    }

    cout<<"数据总个数:"<<cnt0<<endl;
    cout<<"统计到的数据个数:"<<cnt1<<endl;
    ifile.close();

    return 0;
}
/*
*/
