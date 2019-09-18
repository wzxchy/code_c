#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn=105;
int a[maxn];
int main()
{

    int w_images, h_images;
	cout << "please input the width and height of images:" << endl;
	cin >> w_images >> h_images;
	ifstream ifile;
	ifile.open("F:\\Code\\nvm2pc\\x64\\Release\\result2.nvm");
	ofstream ofile_points;
	ofile_points.open("F:\\Code\\nvm2pc\\x64\\Release\\points.txt");
	ofstream ofile_images;
	ofile_images.open("F:\\Code\\nvm2pc\\x64\\Release\\images.txt");
	ofstream ofile_pointview;
	ofile_pointview.open("F:\\Code\\nvm2pc\\x64\\Release\\pointview.txt");
	string file_name;
	int n_camera;
	string image_name;
	double f;
	double qw, qx, qy, qz;
	double cx,cy,cz;
	double dd, zz;
	ifile >> file_name;
	ifile >> n_camera;
	ofile_images << n_camera << endl;;
	cout << file_name << endl;
	cout << n_camera << endl;
	for (int i = 0;i < n_camera;i++)
	{
		ifile >> image_name;
		ifile >> f;
		ifile >> qw >> qx >> qy >> qz;
		ifile >> cx >> cy >> cz;
		ifile >> dd >> zz;
		ofile_images << w_images <<" "<< h_images << endl;
		//cout << i<<" "<<qw << " " << qx << " " << qy << " " << qz << endl;

		Quaterniond t_Q(qw,qx,qy,qz);
		Matrix3d R;
		R = t_Q.matrix();
		Matrix3d K;
		K << f, 0, w_images/2.0,
			0, f, h_images/2.0,
			0, 0, 1;
		Matrix3d KR = K * R;

		Vector3d C(cx, cy, cz);
		Vector3d NC(-cx,-cy,-cz);
		Vector3d KR_NC = KR * NC;
		Vector3d KC = K * C;
		ofile_images << cx << " " << cy << " "<<cz << endl;
		ofile_images << KR(0, 0) << " " << KR(0, 1) << " " << KR(0, 2) << " " << KR_NC[0] << endl;
		ofile_images << KR(1, 0) << " " << KR(1, 1) << " " << KR(1, 2) << " " << KR_NC[1] << endl;
		ofile_images << KR(2, 0) << " " << KR(2, 1) << " " << KR(2, 2) << " " << KR_NC[2] << endl;
		/*ofile_images << KR(0, 0) << " " << KR(0, 1) << " " << KR(0, 2) << " " << KC[0] << endl;
		ofile_images << KR(1, 0) << " " << KR(1, 1) << " " << KR(1, 2) << " " << KC[1] << endl;
		ofile_images << KR(2, 0) << " " << KR(2, 1) << " " << KR(2, 2) << " " << KC[2] << endl;*/
	}

	int n_points;
	ifile >> n_points;

	ofile_points << n_points << endl;
	ofile_pointview << n_points << endl;



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
		ofile_pointview << n_views << endl;
		for (int j = 0;j < n_views;j++)
		{
			ifile >> index_image;
			a[j] = index_image;
			ifile >> index_feature;
			ifile >> tx >> ty;
			ofile_pointview << index_image << " ";
			for (int k = 0;k < j;k++)
			{
				if (a[j] == a[k])  cout << "error!" << endl;
			}
		}
		ofile_pointview << endl;
	}

	ifile.close();
    return 0;
}
/*
*/
