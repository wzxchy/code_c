#include<iostream>
#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;

const int maxn=1000005;
bool prime[maxn];
int f[maxn];

void fun()
{

    memset(prime,true,sizeof(prime));
    memset(f,0,sizeof(f));

    prime[0]=false;
    prime[1]=false;
    int i;
    for(i=2;i<=1000000;i++)  ///只找素数时改为i*i<=maxn
    {
        if(prime[i])
        {
            f[i]++;
            int j=2*i;

            while(j<=1000000)
            {
                prime[j]=false;
                f[j]++;
                j+=i;
            }

        }
    }


}
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

int a[1000005][8];
int main()
{
    fun();
    int i,j;
    int cnt=0;
    for(i=0;i<100;i++)
        if(prime[i])
    {
        cnt++;
        cout<<i<<endl;
    }
    cout<<cnt;
    for(i=2;i<=7;i++)  a[1][i]=0;
    for(i=2;i<=7;i++)  a[2][i]=0;
    for(i=3;i<=1000000;i++)
    {
        for(j=2;j<=7;j++)  a[i][j]=a[i-1][j];
        switch(f[i])
        {
        case 1:
            break;
            case 2:a[i][2]++;
            break;
            case 3:a[i][3]++;
            break;
            case 4:a[i][2]++;a[i][4]++;
            break;
            case 5:a[i][5]++;
            break;
            case 6:a[i][2]++;a[i][3]++;a[i][6]++;
            break;
            case 7:a[i][7]++;
            break;

        }
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int i;
        int ans=1;
        for(i=7;i>=2;i--)
        {
            if(a[r][i]-a[l-1][i]>=2)
            {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
