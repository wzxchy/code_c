#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=105;
int a[maxn];
int main()
{
    ifstream ifile;
    ifile.open("d:\\myfile1.txt");
    ofstream ofile;
    ofile.open("d:\\myfile.txt");

    int T;
    //scanf("%d",&T);
    ifile>>T;
    while(T--)
    {
        int n,m;
        //scanf("%d %d",&n,&m);
        ifile>>n>>m;

        int i;
        for(i=0;i<n;i++)  ifile>>a[i];//scanf("%d",&a[i]);
        if(m>=n)
        {
            printf("100\n");
            ofile<<"100"<<endl;
            continue;
        }
        a[n++]=0;
        a[n++]=101;
        sort(a,a+n);
        int ans=0;
        for(i=1;i<n-m-1;i++)
        {
            int tmp=a[i+m]-a[i-1]-1;
            if(tmp>ans)  ans=tmp;
        }
        ofile<<ans<<endl;
        printf("%d\n",ans);
    }

    ofile.close();
    ifile.close();
    return 0;
}
/*


*/
