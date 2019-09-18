#include<iostream>
#include<cstdio>
#include<cstring>
#include <fstream>
#include <queue>
using namespace std;
const int INF=99999999;
const int n=20;
const int l=3;//最大深度限制
int map[21][21],dis[21],vis[21];
string s_city[21];
int n_node;

bool dfs(int u,int des,int d,string path)
{
    n_node++;
    if(u==des)
    {
        cout<<"路径: "<<path<<endl;
        return 1;
    }
    if(d>l)  return 0;
    int i;
    for(i=0;i<n;i++)
    {
        if(map[u][i]!=INF&&dis[i]==INF)
        {
            dis[i]=dis[u]+map[u][i];
            if(dfs(i,des,d+1,path+"->"+s_city[i]))  return 1;
        }
    }
    return 0;
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

    /////////////////////////
    n_node=1;
    for(i=0;i<n;i++)   dis[i]=INF;
    dis[0]=0;
    if(dfs(0,2,0,s_city[0]))   cout<<"路径长度: "<<dis[2]<<endl;
    //UC_search(n,2,11);
    //for(i=0;i<n;i++)   cout<<i<<"  "<<dis[i]<<endl;
    cout<<"结点数目: "<<n_node<<endl;
    return 0;
}
