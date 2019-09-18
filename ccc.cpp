#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct node
{
    int x,y;
};
int main()
{
    while(1)
    {
        node t;
        cout<<t.x<<"  "<<t.y<<endl;
        int x,y;
        cin>>x>>y;
        t.x=x;
        t.y=y;
    }
    return 0;

}
/*
3 4728 4558 4734 6 0.939563 0.894337 0.936636 0.894554 0.940576 0.895641
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
