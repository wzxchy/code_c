#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef int DataType;
const int MaxStackSize=100;
class SeqStack
{
private:
	DataType data[MaxStackSize];
	int top;
public:
	SeqStack(void) {top = 0;}
	~SeqStack(void) {};
	void Push(const DataType item);
	DataType Pop(void);
	DataType GetTop(void) const;
	int NotEmpty(void) const{return(top != 0);}
};
DataType SeqStack::GetTop(void) const
{
	if(top == 0)
	{
		cout << "堆栈空!" << endl;
		exit(0);
	}
	return data[top-1];
}
void SeqStack::Push(const DataType item	)
{
	if(top == MaxStackSize)
	{
		cout << "堆栈已满!" << endl;
		exit(0);
	}
	data[top] = item;
	top++;
}
DataType SeqStack::Pop()
{
	if(top == 0)
	{
		cout<<"堆栈已空!"<<endl;
		exit(0);
	}
	top--;
	return data[top];
}
int main()
{

    return 0;
}
