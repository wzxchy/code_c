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
struct node
{
    double x,y,z;
}s[maxn];

int main()
{

    ifstream ifile;
    ifile.open("C:\\Users\\wzx\\Desktop\\mesh0186.ply");
    //ifile.open("C:\\Users\\wzx\\Desktop\\result.nvm");
    ofstream ofile;
    ofile.open("C:\\Users\\wzx\\Desktop\\mesh0001.ply");

    double x,y,z;
    double maxz=0;
    for (int i = 0; i < 25273; i++)
    {
       ifile>>x>>y>>z;
       s[i].x=x;
       s[i].y=y;
       s[i].z=z;
       maxz=max(z,maxz);
    }
    for (int i = 0; i < 25273; i++)
    {
        ofile<<s[i].x<<" "<<s[i].y<<" "<<2*maxz-s[i].z<<endl;
    }
    int zz,a,b,c;
    for (int i = 0; i < 50469; i++)
    {
       ifile>>zz>>a>>b>>c;
       ofile<<"3 "<<c<<" "<<b<<" "<<a<<endl;
    }
    ifile.close();
    ofile.close();
    return 0;
}
/*

ply
format ascii 1.0
comment VCGLIB generated
element vertex 25273
property float x
property float y
property float z
element face 50469
property list uchar int vertex_indices
end_header
*/

