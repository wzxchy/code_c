#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
const int maxn=100003;
int Hash(char* word)
{
    unsigned long s=1,t=1,r=1,m=1;
    int i;
    int len=strlen(word);
    for(i=0;i<4&&i<len;i++)   s*=word[i];
    while(word[i]!='\0'&&i<8)
    {
        t*=word[i];
        i++;
    }
    while(word[i]!='\0'&&i<12)
    {
        r*=word[i];
        i++;
    }
    while(word[i]!='\0')
    {
        m*=word[i];
        i++;
    }
    return (s+t+r+m);
}
int main()
{
    char s[]="£¿";
    int i,j;
    int a[100];
    cout<<Hash(s)<<endl;
    //cout<<s<<endl;
    return 0;
}
