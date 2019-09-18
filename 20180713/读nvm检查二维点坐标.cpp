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
    ifile.open("E:\\data\\camoutput\\result_pmvs.nvm");
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

    cout << file_name << endl;
    cout << n_camera << endl;
    for (int i = 0; i < n_camera; i++)
    {
        ifile >> image_name;
        ifile >> f;
        ifile >> qw >> qx >> qy >> qz;
        ifile >> cx >> cy >> cz;
        ifile >> dd >> zz;
    }

    int n_points;
    ifile >> n_points;

    double px, py, pz;
    int cr, cg, cb;

    int n_views;
    int index_image;
    int index_feature;
    double tx, ty;
    double minx=999999999,miny=99999999999;
    double maxx=-99999999,maxy=-999999999;
    for (int i = 0; i < n_points; i++)
    {
        ifile >> px >> py >> pz;
        ifile >> cr >> cg >> cb;
        ifile >> n_views;
        for (int j = 0; j < n_views; j++)
        {
            ifile >> index_image;
            ifile >> index_feature;
            ifile >> tx >> ty;
            minx=min(minx,tx);
            maxx=max(maxx,tx);
            miny=min(miny,ty);
            maxy=max(maxy,ty);
            cnt[index_image]++;
        }
    }
    for(int i=0;i<n_camera;i++)
    {
        cout<<i<<" "<<cnt[i]<<endl;
    }
    ifile.close();
    cout<<minx<<"  "<<maxx<<endl;
    cout<<miny<<"  "<<maxy<<endl;
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
