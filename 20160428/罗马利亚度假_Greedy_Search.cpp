#include<iostream>
#include<cstdio>
#include<cstring>
#include <fstream>
#include <queue>
using namespace std;
const int INF=99999999;
const int n=20;
int map[21][21],dis[21],vis[21];
int h[21];
string s_city[21];
int n_node;
int ans;
bool greedy(int u,int des,string path)
{
    if(u==des)
    {
        cout<<"路径: "<<path<<endl;
        return 1;
    }
    int i,p,min=INF;
    for(i=0;i<n;i++)
    {
        if(map[u][i]!=INF)
        {
            n_node++;
            if(h[i]<min)
            {
                min=h[i];
                p=i;
            }
        }
    }
    ans+=map[u][p];
    if(min==INF)   return 0;
    return greedy(p,des,path+"->"+s_city[p]);
}
int main()
{
    ifstream ifile;
    ifile.open("map_data.txt");
    int i,j;
    for(i=0;i<n;i++)
    {
        ifile>>s_city[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            ifile>>map[i][j];
            if(map[i][j]==1000)  map[i][j]=INF;
            //if(i==j)   map[i][j]=0;
        }
    }
    ifile.close();
    ifile.open("heuristic_data.txt");
    for(i=0;i<n;i++)
    {
        ifile>>s_city[i]>>h[i];
    }
    ifile.close();

    /////////////////////////
    n_node=1;
    //memset(vis,0,sizeof(vis));
    ans=0;
    if(greedy(0,2,s_city[0]))   cout<<"路径长度: "<<ans<<endl;
    cout<<"结点数目: "<<n_node<<endl;
    return 0;
}
