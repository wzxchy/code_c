#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;
int main()
{
    //////read file
    ifstream ifile;
    ifile.open("d:\\myfile.txt");
    int i,j;
    int n=32;
    string s[33];
    int  dis[35][35];
    for(i=0;i<n;i++)
    {
        ifile>>s[i];
    }
    for(i=0;i<n;i++)
    {
        ifile>>s[i];
        for(j=0;j<n;j++)
        {
            ifile>>dis[i][j];
            if(dis[i][j]==10000)  dis[i][j]=999999999;
            if(i==j)   dis[i][j]=0;
        }
    }
    ifile.close();

    /////////write file
    ofstream ofile;
    ofile.open("d:\\myfile1.txt");
    ofile<<"            ";
    for(i=0;i<16;i++)   ofile<<setw(12)<<left<<s[i];
    ofile<<endl;
    for(i=0;i<16;i++)
    {
        ofile<<setw(12)<<left<<s[i];
        for(j=0;j<16;j++)
        {
            ofile<<setw(12)<<left<<dis[i][j];
        }
        ofile<<endl;
    }
    ofile.close();
    return 0;
}
/*

*/
