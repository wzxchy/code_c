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
ifstream ifile;
ofstream ofile;
string s;

void print(int a,int n)
{
    int i;
    for(i=a; i<n; i++)
    {
        ofile<<s[i];
    }
}

int main()
{

    ifile.open("C:\\Users\\wzx\\Desktop\\bbbb.txt");
    ofile.open("C:\\Users\\wzx\\Desktop\\cccc.txt");
    while(ifile>>s)
    {
        int len=s.length();
        ofile<<"add_library(";
        print(0,len);
        ofile<<" STATIC IMPORTED )"<<endl;
        ofile<<"set_target_properties(";
        print(0,len);
        ofile<<" PROPERTIES"<<endl;
        ofile<<"    IMPORTED_LOCATION F:/ARToolKit/android/obj/local/${ANDROID_ABI}/";
        print(0,len);
        ofile<<".a";
        ofile<<")"<<endl<<endl;
    }



    ifile.close();
    ofile.close();
    return 0;
}
/*
int len=s.length();
        ofile<<"add_library(";
        print(len-2);
        ofile<<" STATIC IMPORTED )"<<endl;
        ofile<<"set_target_properties(";
        print(len-2);
        ofile<<" PROPERTIES"<<endl;
        ofile<<"    IMPORTED_LOCATION \"${libs}/${ANDROID_ABI}/";
        print(len);
        ofile<<"\")"<<endl<<endl;
*/
