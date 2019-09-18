#include <iostream>
using namespace std;
template <typename T> int search(T x,T a[],int low,int high);
int main()
{
	int a[10],i,b;
	for(i=0;i<=9;i++)cin>>a[i];
	cin>>b;
	cout<<search(b,a,0,9);
	return 0;
}
template <typename T> int search(T x,T a[],int low,int high)
{
	int mid=-1;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]<x)mid=search(x,a,mid+1,high);
		else if(x<a[mid])mid=search(x,a,low,mid-1);
	}
	return mid;
}
