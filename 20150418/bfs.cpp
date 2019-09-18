#include<iostream>
#include"stdio.h"
#include"string.h"
using namespace std;
const int maxn=205;
char mat[maxn][maxn];
int dis[maxn][maxn];
int a[4][2]={0,1,0,-1,1,0,-1,0};
int main()
{
    int n,m;
    char s[205];
    while(~scanf("%d %d",&n,&m))
    {
        int i,j;
        for(i=0;i<maxn;i++)
        {
            for(j=0;j<maxn;j++)
            {
                dis[i][j]=-1;
                mat[i][j]='#';
            }
        }
        int x1,y1,x2,y2;
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            for(j=1;j<=n;j++)
            {
                mat[i][j]=s[j-1];
                if(mat[i][j]=='r')
                {
                    x1=i;
                    y1=j;
                }
                if(mat[i][j]=='a')
                {
                    x2=i;
                    y2=j;
                }
            }
        }
        int q[20000];
        int front=0,rear=0;
        dis[x1][y1]=0;
        q[rear++]=x1;
        q[rear++]=y1;
        while(front<rear)
        {
            int x=q[front++];
            int y=q[front++];
            int tx;
            int ty;
            for(i=0;i<4;i++)
            {
                tx=a[i][0]+x;
                ty=a[i][1]+y;
                if(mat[tx][ty]!='#'&&dis[tx][ty]==-1)
                {
                    if(mat[tx][ty]=='x')
                    {
                        if(dis[x][y]+2<dis[tx][ty])   dis[tx][ty]=dis[x][y]+2;
                        mat[tx][ty]='.';
                    }
                    else
                    {
                        if(dis[x][y]+1<dis[tx][ty])   dis[tx][ty]=dis[x][y]+1;
                    }
                    q[rear++]=tx;
                    q[rear++]=ty;
                }
            }
        }
        if(dis[x2][y2]>0)  printf("%d\n",dis[x2][y2]);
        else   printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}

