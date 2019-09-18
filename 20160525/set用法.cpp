#include <iostream>
#include <math.h>
#include <stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include <set>
using namespace std;
set<int> s[55];
int main()
{
    int n,m;
    scanf("%d",&n);
    int i,j,tmp;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&m);
        for(j=0; j<m; j++)
        {
            scanf("%d",&tmp);
            s[i].insert(tmp);
        }
    }
    int k;
    scanf("%d",&k);
    int x,y;
    for(i=0; i<k; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==y)
        {
            printf("100.00%\n");
            continue;
        }
        set<int>  st1,st2;
        //set_union(s[x].begin(),s[x].end(),s[y].begin(),s[y].end(),inserter(st1,st1.begin()));
        set_intersection(s[x].begin(),s[x].end(),s[y].begin(),s[y].end(),inserter(st2,st2.begin()));
        int size=s[x].size()+s[y].size();

        int size2=st2.size();;
        int size1=size-size2;//bing
        printf("%.2lf%%\n",size2*100.0/size1);
    }
    return 0;
}
