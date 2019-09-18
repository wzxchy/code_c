#include<iostream>
#include"stdio.h"
#include"string.h"
using namespace std;
const int maxn=105;
char mat[maxn][maxn];
int dis[maxn][maxn];
int a[4][2]={-1,0,0,1,0,-1,1,0};
int p[4][2];
int flag[4];
int main()
{
    int n,m;
    char s[105];
    while(scanf("%d %d",&n,&m))
    {
        if(m==0&&n==0)   break;
        int i,j;
        int x1,y1,x2,y2;
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            for(j=0;j<m;j++)
            {
                mat[i][j]=s[j];
                if(mat[i][j]=='@')
                {
                    x1=i;
                    y1=j;
                }
            }
        }
        int K;
        scanf("%d",&K);
        for(i=0;i<K;i++)
        {
            scanf("%d",&p[i][0]);
            scanf("%d",&p[i][1]);
        }
        int q[20000];
        int count=0;
        int step=0;
        memset(flag,0,sizeof(flag));
        int isfind=1;
        while(count<K&&isfind)
        {
            for(i=0;i<n;i++)
                for(j=0;j<m;j++)   dis[i][j]=-1;
            int front=0,rear=0;
            isfind=0;
            dis[x1][y1]=0;
            q[rear++]=x1;
            q[rear++]=y1;
            while(front<rear)
            {
                int x=q[front];
                front=(front+1)%20000;
                int y=q[front];
                front=(front+1)%20000;
                int tx;
                int ty;
                for(i=0;i<4;i++)
                {
                    tx=a[i][0]+x;
                    ty=a[i][1]+y;
                    if(tx>=0&&tx<n&&ty>=0&&ty<m&&mat[tx][ty]!='#'&&dis[tx][ty]==-1)
                    {
                        dis[tx][ty]=dis[x][y]+1;
                        for(j=0;j<K;j++)
                        {
                            if(flag[j]==0&&tx==p[j][0]-1&&ty==p[j][1]-1)
                            {
                                isfind=1;
                                break;
                            }
                        }
                        if(isfind)
                        {
                            flag[j]=1;
                            count++;
                            step+=dis[tx][ty];
                            x1=tx;
                            y1=ty;
                            break;
                        }
                        q[rear]=tx;
                        rear=(rear+1)%20000;
                        q[rear]=ty;
                        rear=(rear+1)%20000;
                    }
                }
                if(isfind)  break;
            }
        }
        if(count==K)  printf("%d\n",step);
        else   printf("-1\n");
    }
    return 0;
}
/*
2 3
..@
#..
3
2 2
2 3
1 1



4 4
#...
....
#@##
....
4
2 1
1 2
1 3
1 4
*/
