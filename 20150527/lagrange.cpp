#include<iostream>
using namespace std;
double x[8],y[8];
int n;
void init()
{
    n=8;
	int i;
	for(i=0;i<8;i++)
		x[i]=60*i;

	y[0]=1.0,y[1]=1.40,y[2]=1.70,y[3]=1.85,y[4]=1.95,y[5]=2.00,y[6]=1.95,y[7]=1.80;
}
double lagrange(double xx)     //拉格朗日插值
{
	int i,j;
	double a[10],yy=0.0;


	for(i=0;i<=n-1;i++)
	{
		a[i]=y[i];
		for(j=0;j<=n-1;j++)
			if(j!=i)
				a[i]*=(xx-x[j])/(x[i]-x[j]);
			yy+=a[i];
	}

	return yy;
}
int main()
{

	double xx,yy;
    init();
	cout<<"请输入x"<<endl;
    while(scanf("%lf",&xx)!=EOF)
	{
	  yy=lagrange(xx);
      printf("x=%lf,y=%lf\n",xx,yy);
	  cout<<"请输入x"<<endl;
	}
	return 0;
 }
