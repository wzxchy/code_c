#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <ctime>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sstream>

using namespace std;
const int maxn = 1e6+5;

int main()
{
    timeval tStart,cTime;
    long long tPassed = 0;
    gettimeofday(&tStart, 0);

    /////////////////

    gettimeofday(&cTime, 0);
    cTime.tv_sec -= tStart.tv_sec;
    cTime.tv_usec -= tStart.tv_usec;
    tPassed = 1000000LL * cTime.tv_sec + cTime.tv_usec;
    tPassed /= 1000000;
    cout<<tPassed<<endl;

    stringstream stream;
    stream<<tPassed;
    string str=stream.str();
    cout<<str<<endl;
    return 0;
}
/*
s[i].image_name=image_name;
		s[i].f=f;
		s[i].qw=qw; s[i].qx=qx; s[i].qy=qy;s[i].qz=qz;
		s[i].cx=cx; s[i].cy=cy;s[i].cz=cz;
		s[i].dd=dd; s[i].zz=zz;

cout<<s[i].image_name<<" ";
        printf("%f ",s[i].f);
        printf("%f %f %f %f ",s[i].qw,s[i].qx,s[i].qy,s[i].qz);
        printf("%f %f %f ",s[i].cx,s[i].cy,s[i].cz);
        printf("%f %d\n",s[i].dd,s[i].zz);

        ofile<<image_name<<" "<<f<<" ";
        ofile<<qw<<" "<<qx<<" "<<qy<<" "<<qz<<" ";
        ofile<<cx<<" "<<cy<<" "<<cz<<" ";
        ofile<<dd<<" "<<zz<<endl;
*/
