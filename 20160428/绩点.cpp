#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int n=0;
    double fen,dian;
    double sfen=0,sum=0;
    while(cin>>fen>>dian)
    {
        sfen+=fen;
        sum+=fen*dian;
    }
    cout<<sum/sfen<<endl;

    return 0;
}
/*
3.5   3.5
3.5  4
3    3.5
3.0   3.5
3   4
2.5  4
2   4
2   3.5
1.5  4

*/



