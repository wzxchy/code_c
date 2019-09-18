#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn=1e6+5;
struct point3
{
    double x,y,z;
    double nx,ny,nz;
    double u,v;
};
struct face
{
    int x,y,z;
};
face f[maxn];
point3  p[maxn];
point3  p_new[maxn];
int main()
{
    std::string path="F:/textured_as.ply";
    FILE * fin;
    fin = fopen(path.c_str(), "rb");
    std::string path1="F:/textured_as1.ply";
    FILE * fout;
    fout = fopen(path1.c_str(), "wb");


    int n_p=34452;
    int n_newp=0;
    int n_f=68869;
    char str[100024];

    for(int i=0;i<12;i++)
    {
        fgets(str,100024,fin);
    }
    for(int i=0;i<34452;i++)
    {
        double x,y,z;
        fscanf(fin,"%lf %lf %lf",&p[i].x,&p[i].y,&p[i].z);
        //fscanf(fin,"%lf %lf %lf",&p[i].nx,&p[i].ny,&p[i].nz);
    }


    for(int i=0;i<68869;i++)
    {
        int n1,n2;
        int index[3];
        double u[3],v[3];

        fscanf(fin,"%d",&n1);
        for(int j=0;j<3;j++)
        {
            fscanf(fin,"%d",&index[j]);
        }

        fscanf(fin,"%d",&n2);
        for(int j=0;j<3;j++)
        {
            fscanf(fin,"%lf %lf",&u[j],&v[j]);
        }

        for(int j=0;j<3;j++)
        {
            int inx=index[j];
            p_new[n_newp].x=p[inx].x;
            p_new[n_newp].y=p[inx].y;
            p_new[n_newp].z=p[inx].z;
            /*
            p_new[n_newp].nx=p[inx].nx;
            p_new[n_newp].ny=p[inx].ny;
            p_new[n_newp].nz=p[inx].nz;
            */
            p_new[n_newp].u=u[j];
            p_new[n_newp].v=v[j];

            if(j==0) f[i].x=n_newp;
            if(j==1) f[i].y=n_newp;
            if(j==2) f[i].z=n_newp;
            n_newp++;
        }
    }
    cout<<n_newp<<endl;
    for(int i=0;i<n_newp;i++)
    {
        fprintf(fout,"%lf %lf %lf \n",p_new[i].x,p_new[i].y,p_new[i].z);
        //fprintf(fout,"%lf %lf %lf\n",p_new[i].nx,p_new[i].ny,p_new[i].nz);
    }
    for(int i=0;i<n_f;i++)
    {
        int x=f[i].x;
        int y=f[i].y;
        int z=f[i].z;
        fprintf(fout,"3 %d %d %d 6 ",f[i].x,f[i].y,f[i].z);

        fprintf(fout,"%lf %lf ",p_new[x].u, p_new[x].v);
        fprintf(fout,"%lf %lf ",p_new[y].u, p_new[y].v);
        fprintf(fout,"%lf %lf\n",p_new[z].u, p_new[z].v);
    }
    fclose(fin);
    fclose(fout);
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
