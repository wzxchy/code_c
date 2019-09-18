#include <iostream>
#include "stdio.h"
#include "string.h"
#include <cmath>
using namespace std;
const int maxn=15;
void dividedifferences(double divdif[][maxn],double x[],double y[],int n)//divdif:dividedifferences table(0-n);  x:x of  datas;  二维数组先ror后column
{
    int i,j;
    for(i=0;i<=n;i++)//row(0-n)  以i结尾的差商
    {
        divdif[i][0]=y[i];
        for(j=1;j<=i;j++)//column(1-i)   区间两个端点差值为j
        {
            divdif[i][j]=(divdif[i][j-1]-divdif[i-1][j-1])/(x[i]-x[i-j]);
        }
    }
}
void increase_data(double divdif[][maxn],double x[],double y[],double tx,double ty,int n)//increase a data(the dividedifferenes table increase a row)
{
    int i;
    x[n]=tx;
    y[n]=ty;
    divdif[n][0]=y[n];
    for(i=1;i<=n;i++)
    {
        divdif[n][i]=(divdif[n][i-1]-divdif[n-1][i-1])/(x[n]-x[n-i]);
    }
}
double nest(double c[],double a[],double x,int n)//c:coefficient   a:x of datas  n:degree of polynomial
{
    double s=c[n];
    int i,j;
    for(i=n-1;i>=0;i--)
    {
        s=s*(x-a[i])+c[i];
    }
    return s;
}
int main()
{
    double x[maxn],y[maxn];//x:x of datas  y:y of datas
    double divdif[maxn][maxn];//divided differences
    double c[maxn];//coefficient
    int i,j,n;//n: degree of polynomial
    scanf("%d",&n);
    for(i=0;i<=n;i++)  scanf("%lf",&x[i]);
    for(i=0;i<=n;i++)  scanf("%lf",&y[i]);
    //for(i=0;i<=n;i++)   printf("%.5f  ",c[i]);
    //printf("\n");
    //for(i=0;i<=n;i++)   printf("%.5f  ",dd[i]);
    dividedifferences(divdif,x,y,n);
    for(i=0;i<=n;i++)   c[i]=divdif[i][i];
    //for(i=0;i<=n;i++)   printf("%lf   ",c[i]);

    printf("%.5f\n",nest(c,x,0.1,n));
    printf("\n");

    for(i=0;i<6;i++)
    {
        double tx,ty;
        scanf("%lf %lf",&tx,&ty);
        n++;
        increase_data(divdif,x,y,tx,ty,n);
        c[n]=divdif[n][n];
        printf("%.5f\n",nest(c,x,0.1,n));
        printf("\n");
    }
    return 0;
}
/*
4
0       3       6       9       12
9.8100  9.7487  9.6879  9.6278  9.5682
5
0.40     0.55      0.65      0.80      0.90     1.05
0.41075  0.57815   0.69675   0.88811   1.02652  1.25382

1
8       9
227.23  249.46
7  205.05
6  180.67
5  152.27
4  132.12
3  123.08
2  104.46


1
2       3       4       5        6       7         10
104.46  123.08  132.12  152.27   180.67  205.05    281.42


-0.25    0.25    0.5     -0.5      1       -1
-20.5    20.5    96.5    -96.5     637      -637

1
0.25  -0.25
20.5  -20.5
0.5   96.5
-0.5  -96.5
1   637
-1  -637


1
0.25 -0.25
20.5 -20.5

1
7   14
98  101

2
7     14    21
98    101   50

2
0      7     14
100    98    101

*/
