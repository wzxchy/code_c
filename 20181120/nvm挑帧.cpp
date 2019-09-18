#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 1e6+5;
int flag[maxn];
int cnt[maxn];

int main()
{
    memset(cnt,0,sizeof(cnt));
    ifstream ifile;
    ifile.open("E:\\data\\camoutput\\result.nvm");
    //ifile.open("C:\\Users\\wzx\\Desktop\\result.nvm");
    string file_name;
    int n_camera;
    string image_name;
    double f;
    double qw, qx, qy, qz;
    double cx,cy,cz;
    double dd;
    int zz;

    ifile >> file_name;
    ifile >> n_camera;

    FILE *fout_pmvsnvm;
	fout_pmvsnvm = fopen("E:\\data\\camoutput\\result1.nvm", "wb");
    fprintf(fout_pmvsnvm, "NVM_V3\n");
	fprintf(fout_pmvsnvm, "%d\n", n_camera/10);
    cout << file_name << endl;
    cout << n_camera << endl;
    for (int i = 0; i < n_camera; i++)
    {
        ifile >> image_name;
        ifile >> f;
        ifile >> qw >> qx >> qy >> qz;
        ifile >> cx >> cy >> cz;
        ifile >> dd >> zz;
        if(i%10 == 0)
        {
            fprintf(fout_pmvsnvm, "%s   ",image_name.c_str());
            fprintf(fout_pmvsnvm, " %lf", f);
            fprintf(fout_pmvsnvm, " %lf %lf %lf %lf", qw, qx, qy, qz);
            fprintf(fout_pmvsnvm, " %lf %lf %lf", cx, cy, cz);
            fprintf(fout_pmvsnvm, " %lf %d\n", dd, zz);
        }
    }

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
