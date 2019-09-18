#include<iostream>
#include"stdio.h"
#include"string.h"
using namespace std;
const int maxn=25;
int vis[maxn][maxn];
char mat[maxn][maxn];
int a[4][2]={-1,0,0,-1,0,1,1,0};
int main()
{
    int m,n;
    while(~scanf("%d %d",&n,&m))
    {
        if(m==0)   break;
        memset(vis,0,sizeof(vis));
        char str[105];
        int i,j,x0,y0;
        for(i=0;i<m;i++)
        {
            scanf("%s",str);
            for(j=0;j<n;j++)
            {
                mat[i][j]=str[j];
                if(mat[i][j]=='@')
                {
                    x0=i;
                    y0=j;
                }
            }
        }
        int count=1;
        int s[5000];
        int top=0;
        s[top++]=x0;
        s[top++]=y0;
        while(top>0)
        {
            int x,y;
            y=s[--top];
            x=s[--top];
            int k;
            for(k=0;k<4;k++)
            {
                int tx=x+a[k][0];
                int ty=y+a[k][1];
                if(tx>=0&&tx<m&&ty>=0&&ty<n&&mat[tx][ty]=='.'&&vis[tx][ty]==0)
                {
                     vis[tx][ty]=1;
                     count++;
                     s[top++]=tx;
                     s[top++]=ty;
                }
            }
        }
		printf("%d\n",count);
    }
    return 0;
}

