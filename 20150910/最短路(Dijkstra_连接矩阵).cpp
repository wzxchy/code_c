#include<iostream>
#include<cstdio>
#include<cstring>
#include <fstream>
using namespace std;
#define INF 0x3f3f3f3;
int map[21][21],dis[21],visited[21];
void Dijkstra(int n,int x)//顶点从1到n编号，x为起点
{
    int i,p,j,min;
    for(i=1;i<=n;i++)
    {
        dis[i]=map[x][i];
        visited[i]=0;
    }
    visited[x]=1;
    for(i=1;i<=n;i++)
    {
        min=INF;
        for(j=1;j<=n;j++)
        {
            if(!visited[j] && dis[j]<min)
            {
                p=j;
                min=dis[j];
            }
        }
        visited[p]=1;
        for(j=1;j<=n;j++)
        {
            if(!visited[j] && dis[p]+map[p][j]<dis[j])
            {
                dis[j]=dis[p]+map[p][j];
            }
        }
    }
}

int main()
{

    /////////////////////////




    return 0;
}
