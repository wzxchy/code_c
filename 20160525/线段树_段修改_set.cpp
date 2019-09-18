#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF=(1<<30)-1;
const int maxn=1e5+5;
int a[maxn];//源数据，从a[1]到a[n]
int sumv[maxn*4];//树，根节点为sumv[1];
int setv[maxn*4];//结点i代表区间内所有值置为set[i];
int y1,y2,v;//查询或更新的区间，更新操作为将区间内所有值置为v
int _sum;//查询结果
void init(int o,int L,int R)//结点序号 及 结点代表区间的左右端点
{
    if(L==R)   sumv[o]=a[L];
    else
    {
        int M=L+(R-L)/2;
        init(o*2,L,M);
        init(o*2+1,M+1,R);
        sumv[o]=sumv[o*2]+sumv[o*2+1];
    }
    setv[o]=-1;
}

void maintain(int o,int L,int R)
{
    int lc=o*2,rc=o*2+1;
    if(setv[o]>=0)
    {
        sumv[o]=(R-L+1)*setv[o];
    }
    else
    {
        if(R>L)
        {
            sumv[o]=sumv[lc]+sumv[rc];
        }
        else
        {
             sumv[o]=a[L];
        }
        //printf("bb %d %d %d %d\n",o,L,R,sumv[o]);
    }

}
void pushdown(int o)
{
    int lc=o*2,rc=o*2+1;
    if(setv[o]>=0)
    {
        setv[lc]=setv[rc]=setv[o];
        setv[o]=-1;
    }
}
void update(int o,int L,int R)//结点序号 及 结点代表区间的左右端点
{
    int lc=o*2,rc=o*2+1;
    if(y1<=L && R<=y2)
    {
        setv[o]=v;
    }
    else
    {
        pushdown(o);
        int M=L+(R-L)/2;
        if(y1<=M)  update(lc,L,M);
        else  maintain(lc,L,M);
        if(y2>M)   update(rc,M+1,R);
        else   maintain(rc,M+1,R);
    }
    maintain(o,L,R);
}
void query(int o,int L,int R)//结点序号 及 结点代表区间的左右端点
{
    if(setv[o]>=0)
    {
        _sum+=setv[o]*(min(R,y2)-max(L,y1)+1);
    }
    else if(y1<=L && y2>=R)
    {
        _sum+=sumv[o];
    }
    else
    {
        int M=L+(R-L)/2;
        if(y1<=M)  query(o*2,L,M);
        if(y2>M)   query(o*2+1,M+1,R);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        int i,n,m;
        scanf("%d %d",&n,&m);
        for(i=1; i<=n; i++)   a[i]=1;
        init(1,1,n);
        while(m--)
        {
            scanf("%d %d %d",&y1,&y2,&v);
            update(1,1,n);
        }
        _sum=0;
        y1=1;
        y2=n;
        query(1,1,n);
        printf("Case %d: The total value of the hook is %d.\n",cas++,_sum);
    }
    return 0;
}
