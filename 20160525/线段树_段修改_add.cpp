#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF=(1<<30)-1;
const int maxn=1e5+5;
int a[maxn];//源数据，从a[1]到a[n]
long long sumv[maxn*4];//树，根节点为sumv[1];
long long addv[maxn*4];//结点i代表区间内所有值增加add[i];
int y1,y2,v;//查询或更新的区间，更新操作为将区间内所有值增加v
long long _sum;//查询结果
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
    addv[o]=0;
}

void maintain(int o,int L,int R)
{
    int lc=o*2,rc=o*2+1;
    sumv[o]=0;
    if(L==R)
    {
        sumv[o]=a[L];
    }
    if(R>L)
    {
        sumv[o]=sumv[lc]+sumv[rc];
    }
    sumv[o]+=addv[o]*(R-L+1);
}

void update(int o,int L,int R)//结点序号 及 结点代表区间的左右端点
{
    int lc=o*2,rc=o*2+1;
    if(y1<=L && R<=y2)
    {
        addv[o]+=v;
    }
    else
    {
        int M=L+(R-L)/2;
        if(y1<=M)  update(lc,L,M);
        if(y2>M)   update(rc,M+1,R);
    }
    maintain(o,L,R);
}
void query(int o,int L,int R,long long add)//结点序号 及 结点代表区间的左右端点
{
    if(y1<=L && y2>=R)
    {
        _sum+=sumv[o]+add*(R-L+1);
    }
    else
    {
        int M=L+(R-L)/2;
        if(y1<=M)   query(o*2,L,M,add+addv[o]);
        if(y2>M)    query(o*2+1,M+1,R,add+addv[o]);
    }
}
int main()
{
    int n,q;
    while(~scanf("%d %d",&n,&q))
    {
        int i;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        init(1,1,n);
        while(q--)
        {
            char c;
            getchar();
            scanf("%c",&c);

            if(c=='Q')
            {
                scanf("%d %d",&y1,&y2);
                _sum=0;
                query(1,1,n,0);
                printf("%lld\n",_sum);
            }
            else
            {
                scanf("%d %d %d",&y1,&y2,&v);
                //cout<<y1<<" "<<y2<<" "<<v<<endl;
                update(1,1,n);
            }

        }
    }
    return 0;
}
