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
    std::string path0="F:/Code/Texture/x64/Release/facedatas0.txt";
    FILE * fin0;
    fin0 = fopen(path0.c_str(), "rb");

    std::string path="F:/Code/Texture/x64/Release/facedatas.txt";
    FILE * fin;
    fin = fopen(path.c_str(), "rb");

    char str0[100024];
    char str[100024];
    for(int i=0; i<39246; i++)
    {

       // fscanf(fin0,"%s\n", &str0);
        //fscanf(fin,"%s\n", &str);

        fgets(str0,100024,fin0);
        fgets(str,100024,fin);
        if(strcmp(str0,str)!=0)
        {
            cout<<str0<<endl;
            cout<<str<<endl;
        }

    }
    cout<<str0<<endl;
    cout<<str<<endl;
    return 0;
}
/*
*/
