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
int a[maxn];
struct point3
{
    double x,y,z;
};
struct point2
{
    double x,y;
};
struct face
{
    int index_v;
    int index_vt;
    int index_vn;
};
point3 v[maxn];
point3 vn[maxn];
point2 vt[maxn];
int main()
{
    std::string path="F:/Code/Texture/x64/Release/facemap.txt";
    FILE * fin;
    fin = fopen(path.c_str(), "rb");

    std::string path_out="F:/Code/Texture/x64/Release/facemap.txt";
    FILE * fout;
    fout = fopen(path_out.c_str(), "wb");

    char s1[100],s2[100];
    int n_v=0;
    int n_vt=0;
    int n_vn=0;
    int n_face=0;
    while(fscanf(fin, "%s", &s1)!=EOF)
    {
        if(strcmp(s1,"mtllib")==0 || strcmp(s1,"usemtl")==0)
        {
            fscanf(fin, "%s", &s2);
        }
        if(strcmp(s1,"v")==0)
        {
            fscanf(fin, "%lf %lf %lf", &v[n_v].x, &v[n_v].y, &v[n_v].z);
            n_v++;
        }
        if(strcmp(s1,"vn")==0)
        {
            fscanf(fin, "%lf %lf %lf", &vn[n_vn].x, &vn[n_vn].y, &vn[n_vn].z);
            n_vn++;
        }
        if(strcmp(s1,"vt")==0)
        {
            fscanf(fin, "%lf %lf", &vt[n_vt].x, &vt[n_vt].y);
            n_vt++;
        }
        if(strcmp(s1,"f")==0)
        {
            n_face++;
        }
    }


    fclose(fin);
    fclose(fout);
    return 0;
}
/*

int t0,t;
        int s0,s;

        fscanf(fin0, "%d %d", &t0,&s0);
        fscanf(fin, "%d %d", &t,&s);
        if(t!=t0) cout<<i<<std::endl;
        if(s!=s0) cout<<i<<std::endl;
ifstream ifile;
    ifile.open("C:/Users/wzx/Desktop/h.txt");

    string str;
    while(ifile>>str)
    {
        cout<<"src/main/cpp/"<<str<<endl;
    }
    ifile.close();

src/main/cpp/include/BoostArchiver.h
src/main/cpp/include/Converter.h
src/main/cpp/include/Frame.h
src/main/cpp/include/FrameDrawer.h
src/main/cpp/include/Initializer.h
src/main/cpp/include/KeyFrame.h
src/main/cpp/include/KeyFrameDatabase.h
src/main/cpp/include/LocalMapping.h
src/main/cpp/include/LoopClosing.h
src/main/cpp/include/Map.h
src/main/cpp/include/MapDrawer.h
src/main/cpp/include/MapPoint.h
src/main/cpp/include/MyStreamBuf.h
src/main/cpp/include/Optimizer.h
src/main/cpp/include/ORBextractor.h
src/main/cpp/include/ORBmatcher.h
src/main/cpp/include/ORBVocabulary.h
src/main/cpp/include/PnPsolver.h
src/main/cpp/include/Sim3Solver.h
src/main/cpp/include/System.h
src/main/cpp/include/Tracking.h
src/main/cpp/include/Viewer.h


src/main/cpp/src/Converter.cc
src/main/cpp/src/Frame.cc
src/main/cpp/src/FrameDrawer.cc
src/main/cpp/src/Initializer.cc
src/main/cpp/src/KeyFrame.cc
src/main/cpp/src/KeyFrameDatabase.cc
src/main/cpp/src/LocalMapping.cc
src/main/cpp/src/LoopClosing.cc
src/main/cpp/src/Map.cc
src/main/cpp/src/MapDrawer.cc
src/main/cpp/src/MapPoint.cc
src/main/cpp/src/Optimizer.cc
src/main/cpp/src/ORBextractor.cc
src/main/cpp/src/ORBmatcher.cc
src/main/cpp/src/PnPsolver.cc
src/main/cpp/src/Sim3Solver.cc
src/main/cpp/src/System.cc
src/main/cpp/src/Tracking.cc
src/main/cpp/src/Viewer.cc
*/
