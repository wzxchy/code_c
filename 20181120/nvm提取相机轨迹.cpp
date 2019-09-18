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
    //ifile.open("E:\\data\\camoutput\\result0.nvm");
    ifile.open("C:\\Users\\wzx\\Desktop\\result.nvm");
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
    //n_camera=360;
    FILE *fout_ply;
	fout_ply = fopen("C:\\Users\\wzx\\Desktop\\pose.ply", "wb");
    fprintf(fout_ply, "ply\n");
	fprintf(fout_ply, "format ascii 1.0\n");
	fprintf(fout_ply, "element vertex %d\n",n_camera);
	fprintf(fout_ply, "property float x\n");
	fprintf(fout_ply, "property float y\n");
	fprintf(fout_ply, "property float z\n");
	fprintf(fout_ply, "end_header\n");
    cout << file_name << endl;
    cout << n_camera << endl;
    for (int i = 0; i < n_camera; i++)
    {
        ifile >> image_name;
        ifile >> f;
        ifile >> qw >> qx >> qy >> qz;
        ifile >> cx >> cy >> cz;
        ifile >> dd >> zz;
        fprintf(fout_ply, " %lf %lf %lf\n", cx, cy, cz);
    }
    fclose(fout_ply);
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
