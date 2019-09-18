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
struct s_camera
{
    string image_name;
    double f;
    double qw, qx, qy, qz;
    double cx,cy,cz;
    double dd, zz;

};
struct s_point
{
    double px, py, pz;
    int idx;
};
s_point p[maxn];

bool cmp(s_point a,s_point b)
{
    if(a.px<b.px) return true;
    if(a.px>b.px) return false;

    if(a.py<b.py) return true;
    if(a.py>b.py) return false;
    if(a.pz<b.pz) return true;
    if(a.pz>b.pz) return false;
    return true;
}

int main()
{



    ifstream ifile;
    ifile.open("F:\\Code\\nvm2pc\\x64\\Release\\y.nvm");

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
        }
        p[i].px=px;
        p[i].py=py;
        p[i].pz=pz;
        p[i].idx=i;
    }
    ifile.close();
    sort(p,p+n_points,cmp);
    int cnt_same=0;
    memset(flag,0,sizeof(flag));
    for(int i=1;i<n_points;i++)
    {
        if(p[i].px==p[i-1].px && p[i].py==p[i-1].py && p[i].pz==p[i-1].pz)
        {
            int tmp=p[i].idx;
            flag[tmp]=1;
            cnt_same++;
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ifile.open("F:\\Code\\nvm2pc\\x64\\Release\\y.nvm");
    FILE *fout;
    fout=fopen("F:\\Code\\nvm2pc\\x64\\Release\\y1.nvm","wb");
    //ofstream ofile;
    //ofile.open("F:\\Code\\nvm2pc\\x64\\Release\\y1.nvm");

    ifile >> file_name;
    ifile >> n_camera;
    fprintf(fout,"%s\n",file_name.c_str());
    fprintf(fout,"%d\n",n_camera);

    for (int i = 0; i < n_camera; i++)
    {
        ifile >> image_name;
        ifile >> f;
        ifile >> qw >> qx >> qy >> qz;
        ifile >> cx >> cy >> cz;
        ifile >> dd >> zz;
        fprintf(fout,"%s %.9lf %.11lf %.11lf %.11lf %.11lf %.11lf %.11lf %.11lf %.11lf %d\n",image_name.c_str(),f,qw,qx,qy,qz,cx,cy,cz,dd,zz);
    }
    fprintf(fout,"\n");

    ifile >> n_points;

    fprintf(fout,"%d\n",n_points-cnt_same);

    for (int i = 0; i < n_points; i++)
    {
        ifile >> px >> py >> pz;
        ifile >> cr >> cg >> cb;
        ifile >> n_views;
        if(flag[i]==0)
        {
            //ofile<<px<<" "<<py<<" "<<pz<<" ";
            //ofile<<cr<<" "<<cg<<" "<<cb<<" ";
            //ofile<<n_views<<" ";
            fprintf(fout,"%.11lf %.11lf %.11lf %d %d %d %d ",px,py,pz,cr,cg,cb,n_views);
        }
        for (int j = 0; j < n_views; j++)
        {
            ifile >> index_image;
            ifile >> index_feature;
            ifile >> tx >> ty;
            if(flag[i]==0)
            {
               // ofile<<index_image<<" "<<index_feature<<" "<<tx<<" "<<ty<<" ";
               fprintf(fout,"%d %d %.11lf %.11lf ",index_image,index_feature,tx,ty);
            }
        }
        fprintf(fout,"\n");
    }
    ifile.close();
    fclose(fout);
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
