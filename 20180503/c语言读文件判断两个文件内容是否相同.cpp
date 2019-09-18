#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    std::string path0="F:/Code/Texture/x64/Release/textured.obj";
    FILE * fin0;
    fin0 = fopen(path0.c_str(), "rb");

    std::string path="F:/Code/Texture/x64/Release/textured2.obj";
    FILE * fin;
    fin = fopen(path.c_str(), "rb");

    char str0[100024];
    char str[100024];
    for(int i=1; i<=176633; i++)
    {

       // fscanf(fin0,"%s\n", &str0);
        //fscanf(fin,"%s\n", &str);

        fgets(str0,100024,fin0);
        fgets(str,100024,fin);
        if(strcmp(str0,str)!=0)
        {
            cout<<i<<endl;
            cout<<strlen(str0)<<" "<<strlen(str)<<endl;
           // cout<<strlen(str)<<endl;
            cout<<str0<<endl;
            cout<<str<<endl;
        }

    }
    //cout<<str0<<endl;
   // cout<<str<<endl;
    return 0;
}
/*
*/
