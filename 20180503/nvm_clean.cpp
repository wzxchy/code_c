#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 105;
int a[maxn];
struct s_camera;
{
    string image_name;
    double f;
	double qw, qx, qy, qz;
	double cx,cy,cz;
	double dd, zz;

};
struct s_point
{
    string image_name;
    double f;
	double qw, qx, qy, qz;
	double cx,cy,cz;
	double dd, zz;

};
bool cmp(node x,node y)
{
    return x.image_name<y.image_name;
}
node s[1000];
int main()
{
	ifstream ifile;
	ifile.open("F:\\Code\\nvm2pc\\x64\\Release\\x.nvm");


	string file_name;
	int n_camera;
	string image_name;
	double f;
	double qw, qx, qy, qz;
	double cx,cy,cz;
	double dd, zz;

	ifile >> file_name;
	ifile >> n_camera;

	cout << file_name << endl;
	cout << n_camera << endl;
	for (int i = 0;i < n_camera;i++)
	{
		ifile >> image_name;
		ifile >> f;
		ifile >> qw >> qx >> qy >> qz;
		ifile >> cx >> cy >> cz;
		ifile >> dd >> zz;
		s[i].image_name=image_name;
		s[i].f=f;
		s[i].qw=qw; s[i].qx=qx; s[i].qy=qy;s[i].qz=qz;
		s[i].cx=cx; s[i].cy=cy;s[i].cz=cz;
		s[i].dd=dd; s[i].zz=zz;
	}
	int n_points;
	ifile >> n_points;

	double px, py, pz;
	int cr, cg, cb;

	int n_views;
	int index_image;
	int index_feature;
	double tx, ty;
	for (int i = 0;i < n_points;i++)
	{
		ifile >> px >> py >> pz;
		ofile_points << px << " " << py << " " << pz << " " << endl;

		ifile >> cr >> cg >> cb;
		ifile >> n_views;
		ofile_pointview << n_views << "   ";
		for (int j = 0;j < n_views;j++)
		{
			ifile >> index_image;
			ifile >> index_feature;
			ifile >> tx >> ty;
			ofile_pointview << index_image << " ";
		}
	}
	ifile.close();
	return 0;
}
/*
	ofstream ofile_points;
	ofile_points.open("F:\\Code\\nvm2pc\\x64\\Release\\points.txt");
const int n=51;
int cnt[n];
float l[n];
float r[n];
float tmp=-10;
for(int i=0;i<n;i++)
{
l[i]=tmp-0.2;
r[i]=tmp;
tmp+=0.2;
}

for(int i=0;i<n;i++)  cnt[i]=0;
int cnt0=0;
double x;
while(ifile>>x)
{
cnt0++;
double xx=log10(x);
int flag=0;
for(int i=0;i<n-1;i++)
{
if(xx<=r[i])
{
cnt[i]++;
flag=1;
break;
}
}
if(flag==0)  cnt[n-1]++;

}
int cnt1=0;
for(int i=0;i<n;i++)
{
cnt1+=cnt[i];
printf("%.1lf  %.1lf:  %d\n",l[i],r[i],cnt[i]);
//cout<<cnt[i]<<endl;
}

cout<<"数据总个数:"<<cnt0<<endl;
cout<<"统计到的数据个数:"<<cnt1<<endl;
*/
