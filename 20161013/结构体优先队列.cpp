#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include <vector>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
struct node
{
    int a,b;
}s[maxn];
bool cmp(node x,node y)
{
    if(x.a<y.a || x.a==y.a&&x.b<y.b)  return true;
    return false;
}
struct cmp1
{
     bool operator() (const node &x, const node &y)
     {
         if (x.b > y.b)    return true;//bÐ¡ÔÚÇ°
         else return false;
     }
};
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        priority_queue<node, vector<node>, cmp1> q;
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&s[i].a,&s[i].b);
        }

        sort(s,s+n,cmp);
        int cnt=1;
        q.push(s[0]);
        for(i=1;i<n;i++)
        {
            node tmp=q.top();
            if(s[i].a>=tmp.b)
            {
                q.pop();
                q.push(s[i]);
            }
            else
            {
                q.push(s[i]);
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
/*
*/
