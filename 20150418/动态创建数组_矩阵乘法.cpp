#include<iostream>
#include<cstdlib>
using namespace std;
void display(int **,int ,int );//打印数组函数
void multi(int **,int **,int **,int ,int ,int );//矩阵相乘函数
void de_allocate(int **,int );//删除数组函数
int main()
{
	int m,n,k;
	cout<<"请输入m,n,k:"<<endl;
	cin>>m>>n>>k;//两个矩阵m*n,n*k
	int **a,**b,**result,i,j;
	a=new int*[m];
	for(i=0;i<m;i++)a[i]=new int[n];//动态建立a数组
	b=new int*[n];
	for(i=0;i<n;i++)b[i]=new int[k];//动态建立b数组
	result=new int*[m];
	for(i=0;i<m;i++)result[i]=new int[k];//动态建立result数组
	cout<<"请输入第一个矩阵各元素:"<<endl;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)cin>>a[i][j];//给a数组赋值
	cout<<"请输入第二个矩阵各元素:"<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<k;j++)cin>>b[i][j];//给b数组赋值
	multi(a,b,result,m,n,k);
	cout<<"结果为:"<<endl;
	display(result,m,k);
	de_allocate(result,m);
	de_allocate(b,n);
	de_allocate(a,m);
	return 0;
}
void display(int **data,int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)cout<<data[i][j]<<'\t';
		cout<<endl;
	}
}
void multi(int **a,int **b,int **result,int m,int n,int k)
{
	int i,j,x;
	for(i=0;i<m;i++)
	{
		for(j=0;j<k;j++)
		{
			result[i][j]=0;
			for(x=0;x<n;x++)result[i][j]+=a[i][x]*b[x][j];
		}
	}
}
void de_allocate(int **data,int m)
{
	int i;
	for(i=0;i<m;i++)delete[]data[i];
	delete[]data;
}


        



