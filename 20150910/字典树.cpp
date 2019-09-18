#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxnode=6e5;
const int nsize=26;
int ch[maxnode][nsize];
int val[maxnode];
int sz;//结点个数
int nodeword[55];
char sword[55];
int idx(char c)
{
    return c-'a';
}
void insert(char s[])
{
    int u=0;
    int len=strlen(s);
    int i;
    for(i=0;i<len;i++)
    {
        int c=idx(s[i]);
        if(!ch[u][c])
        {
            val[sz]=0;
            memset(ch[sz],0,sizeof(ch[sz]));
            ch[u][c]=sz;
            sz++;
        }
        u=ch[u][c];
    }
    val[u]=1;
}

bool find(char s[])
{
    int u=0;
    int len=strlen(s);
    int i;
    for(i=0;i<len;i++)
    {
        int c=idx(s[i]);
        if(!ch[u][c])
        {
            return 0;
        }
        u=ch[u][c];
    }
    if(val[u])   return 1;
    return 0;
}
void dfs(int p,int depth,int nword)
{
    if(val[p])
    {
        sword[depth+1]='\0';
        int i;
        for(i=0;i<nword;i++)
        {
            if(find(sword+nodeword[i]+1))   break;
        }
        if(i<nword)   printf("%s\n",sword);
        nodeword[nword]=depth;
        nword++;
    }
    int i;
    for(i=0;i<nsize;i++)
    {
        if(ch[p][i])
        {
            sword[depth+1]=i+'a';
            dfs(ch[p][i],depth+1,nword);
        }
    }
}
int main()
{
    sz=1;
    memset(ch[0],0,sizeof(ch[0]));
    val[0]=0;
    char s[55];
    while(~scanf("%s",s))
    {
        insert(s);
    }
    int i;
    for(i=0;i<nsize;i++)
    {
        if(ch[0][i])
        {
            sword[0]='a'+i;
            dfs(ch[0][i],0,0);
        }
    }
    return 0;
}
