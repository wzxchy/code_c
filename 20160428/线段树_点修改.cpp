#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF=(1<<30)-1;
const int maxn=1e6+5;
int a[maxn];//源数据，从a[1]到a[n]
int sum[maxn*4];//树，根节点为sum[1];
int ql,qr;//查询操作  左右区间
int p,v;//更新操作 将a[p]改为v
void init(int o,int L,int R)//结点序号 及 结点代表区间的左右端点
{
    if(L==R)   sum[o]=a[L];
    else
    {
        int M=(L+R)/2;
        init(o*2,L,M);
        init(o*2+1,M+1,R);
        sum[o]=min(sum[o*2],sum[o*2+1]);
    }
}
int query(int o,int L,int R)//结点序号 及 结点代表区间的左右端点
{
    if(ql<=L&&R<=qr)  return sum[o];
    int M=(L+R)/2,ans=INF;
    if(ql<=M)   ans=min(ans,query(o*2,L,M));
    if(qr>=M+1) ans=min(ans,query(o*2+1,M+1,R));
    return ans;
}
void update(int o,int L,int R)//结点序号 及 结点代表区间的左右端点
{
    if(L==R)  sum[o]=v;
    else
    {
        int M=(L+R)/2;
        if(p<=M)  update(o*2,L,M);
        else  update(o*2+1,M+1,R);
        sum[o]=min(sum[o*2],sum[o*2+1]);
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,j;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        init(1,1,n);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int op,x,y;
            scanf("%d %d %d",&op,&x,&y);
            if(op==0)
            {
                ql=x;
                qr=y;
                int ans=query(1,1,n);
                printf("%d\n",ans);
            }
            else
            {
                p=x;
                v=y;
                update(1,1,n);
            }
        }
    }
    return 0;
}
