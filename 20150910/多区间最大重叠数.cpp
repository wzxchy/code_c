#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node
{
    double x;
    int p;
    int d;
}s1[105];
bool cmp(node a,node b)
{
    if(a.x<b.x)  return 1;
    if(a.x==b.x&&a.p<b.p)  return 1;
    return 0;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,j,cnt=0;
        double x;
        char c[5],str[15];
        for(i=0;i<n;i++)
        {
            getchar();
            scanf("%s %s %lf",c,str,&x);

            if(strcmp(str,"=")==0)
            {
                s1[cnt].x=x;
                s1[cnt].p=2;
                s1[cnt].d=1;
                cnt++;
                s1[cnt].x=x;
                s1[cnt].p=3;
                s1[cnt].d=-1;
                cnt++;
            }
            else if(strcmp(str,">=")==0)
            {
                s1[cnt].x=x;
                s1[cnt].p=2;
                s1[cnt].d=1;
                cnt++;
                s1[cnt].x=1005;
                s1[cnt].p=3;
                s1[cnt].d=-1;
                cnt++;
            }
            else if(strcmp(str,"<=")==0)
            {
                s1[cnt].x=x;
                s1[cnt].p=3;
                s1[cnt].d=-1;
                cnt++;
                s1[cnt].x=-5;
                s1[cnt].p=2;
                s1[cnt].d=1;
                cnt++;
            }
            else if(strcmp(str,">")==0)
            {
                s1[cnt].x=x;
                s1[cnt].p=4;
                s1[cnt].d=1;
                cnt++;
                s1[cnt].x=1005;
                s1[cnt].p=3;
                s1[cnt].d=-1;
                cnt++;
            }
            else
            {
                s1[cnt].x=x;
                s1[cnt].p=1;
                s1[cnt].d=-1;
                cnt++;
                s1[cnt].x=-5;
                s1[cnt].p=2;
                s1[cnt].d=1;
                cnt++;
            }
        }
        sort(s1,s1+cnt,cmp);
        int ans=0,t=0;
        for(i=0;i<cnt;i++)
        {
            t+=s1[i].d;
            if(t>ans)  ans=t;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*

9
X = 55
X >= 55
X <= 55
X > 505
X < 505
X >= 155
X <= 255
X > 2
X < 525

*/
