#include<iostream>
#include<stdio.h>
#include<cmath>
#include<time.h>
#include <fstream>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include<algorithm>
using namespace std;
const int maxn=105;
int s[maxn];
int flag[maxn];
int main()
{
    srand(time(NULL));
    int n,m;
    int T=100;
    ofstream ofile;
    ofile.open("d:\\myfile1.txt");
    ofile<<T<<endl;
    int i,j;
    for(i=0;i<T;i++)
    {
        int n=rand()%101;
        int m=rand()%51;
        ofile<<n<<"  "<<m<<endl;

        memset(flag,0,sizeof(flag));
        for(j=0;j<n;j++)
        {
            int tmp=rand()%100+1;
            while(flag[tmp]==1)
            {
                tmp=rand()%n+1;
            }
            flag[tmp]=1;
            s[j]=tmp;
        }
        sort(s,s+n);
        for(j=0;j<n;j++)
        {
            ofile<<s[j]<<endl;
        }
    }
    ofile.close();
    return 0;
}
/*

*/

