#include<iostream>
using namespace std;
template <typename T,int i>class array 
{
       T a[i];
       int size;
public: 
      array();
	  int geti();
};
template <typename T,int i> array<T,i>::array(){size=i;}
template <typename T,int i> int  array<T,i>::geti(){return i;}
int main(){
	array<int,10> m;
	cout<<m.geti()<<endl;
	return 0;
}