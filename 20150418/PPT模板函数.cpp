#include<iostream>
using namespace std;
template <typename T> T get(T a){return a;}
int main(){
	int a=1;
	cout<<get(a)<<endl;
	float b=2;
	cout<<get(b)<<endl;
	return 0;
}