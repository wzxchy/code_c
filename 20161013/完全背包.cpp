#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include <vector>
#include<algorithm>
using namespace std;
const int  V=1e5+5;
unsigned int f[V];//全局变量，自动初始化为0
unsigned int weight[505];
unsigned int value[505];
int main()
{

    int N,M;
    cin>>N;//物品个数
    cin>>M;//背包容量
    for (int i=1;i<=N; i++)
    {
        cin>>weight[i]>>value[i];
    }
    for (int i=1; i<=N; i++)
        for (int j=1; j<=M; j++)
        {
            if (weight[i]<=j)
            {
                f[j]=max(f[j],f[j-weight[i]]+value[i]);
            }
        }

    cout<<f[M]<<endl;//输出最优解

}  /*

*/
