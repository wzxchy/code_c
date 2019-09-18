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

    ifile.open("e:\\LIST.txt");
    ofile.open("e:\\LIST1.txt");
    while(ifile>>s)
    {
        int len=s.length();
        ofile<<"add_library(";
        print(3,len-2);
        ofile<<" STATIC IMPORTED )"<<endl;
        ofile<<"set_target_properties(";
        print(3,len-2);
        ofile<<" PROPERTIES"<<endl;
        ofile<<"    IMPORTED_LOCATION ${EXT_PROJ_DIR}/OpenSceneGraph/build/${ANDROID_ABI}/lib/";
        print(0,len);
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
