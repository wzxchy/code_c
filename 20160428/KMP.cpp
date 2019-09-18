#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int maxn1=1e6+5;
const int maxn0=1e4+5;
char text[maxn1],s[maxn0];
int nxt[maxn0];
int n,m;
void getnext()
{
    int i=0;
    int j=-1;
    nxt[0]=-1;
    while(i<m)
    {
        if(j==-1||s[i]==s[j])nxt[++i]=++j;
        else j=nxt[j];
    }
}
int find()
{
    getnext();
    //for(int i=0;i<=m;i++)  printf("%d ",nxt[i]);
    //cout<<"ss"<<endl;
    int ans=0;
    int i=0,j=0;
    while(i<n)
    {
        if(text[i]==s[j])
        {
            if(j==m-1)
            {
                ans++;
                j=nxt[j];
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            j=nxt[j];
        }
        if(j==-1)
        {
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s %s",s,text);
        n=strlen(text);
        m=strlen(s);
        int ans=find();
        printf("%d\n",ans);
    }
    return 0;
}
