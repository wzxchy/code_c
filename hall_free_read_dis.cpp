#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn=105;
const int nMesh=10;
const int size_face=1415902;
int main()
{
    cout<<M_PI<<endl;
    vector< vector<float> > distance_map;
    vector<float> conf_list(size_face, 0);
    vector<float> dist_list;
	for (int k = 1; k < nMesh; k++)
	{
		distance_map.push_back(std::vector<float>(size_face, 0));
	}
    ifstream ifile;
    ifile.open("F:\\Code\\HallucinationFree\\build\\HallucinationFree\\bin\\Release\\meshs3\\debug_dis_out1.txt");
    for(int k=1;k<nMesh;k++)
    {
        cout<<"read "<<k<<"th mesh:"<<endl;
        for(int i=0;i<size_face;i++)
        {
            ifile>>distance_map[k-1][i];
            dist_list.push_back(distance_map[k-1][i]);
        }
    }

    int max_pos = dist_list.size()*0.9545;
	sort(dist_list.begin(), dist_list.end());
    float sigma = dist_list[max_pos]/1.96;
    //sigma=0.01;
    cout<<"sigma:"<<sigma<<endl;
    float lower=2.0*sigma*sigma;
    float avg=0;
    for (int j = 0; j < size_face; j++)
	{
		conf_list[j] = 0;

		for (int k = 1; k < nMesh; k++)
		{
			float upper = -1.0*(distance_map[k - 1][j] - avg)*(distance_map[k - 1][j] - avg);

			//conf_list[j] += distance_map[k - 1][j]*std::exp(upper/lower)/(sqrt(2*M_PI));
			conf_list[j] += distance_map[k - 1][j];
		}

	}

	std::size_t pos = conf_list.size()*0.90;

	std::sort(conf_list.begin(), conf_list.end());

	//90%分位点的值是
	float s = conf_list[pos];
	cout<<"S:"<<s<<endl;
	cout<<"logs:"<<log10(s)<<endl;

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
    for (int j = 0; j < size_face; j++)
    {
        cnt0++;
        x=conf_list[j];
        double logx=log10(x);
        for(int i=0;i<n;i++)
        {
            if(logx<=r[i])
            {
                cnt[i]++;
                break;
            }
        }

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
    ifile.close();
    return 0;
}
/*
*/
