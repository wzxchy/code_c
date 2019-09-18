#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
typedef int DataType;
const int MaxStackSize=100;
class SeqStack
{
private:
	DataType data[MaxStackSize];	//堆栈
	int top;					//栈顶位置指示器、表长
public:
	SeqStack(void) {top = 0;};		//构造函数
	~SeqStack(void) {}; 			//析构函数
	void Push(const DataType item); 	//入栈
	DataType Pop(void);       			//出栈
	DataType GetTop(void) const; 		//取栈顶数据元素
	int NotEmpty(void) const{return(top != 0);}; //堆栈非空否
};
DataType SeqStack::GetTop(void) const
{
	if(top == 0)
	{
		cout << "堆栈空!" << endl;
		exit(0);
	}
	return data[top-1];	//返回当前栈顶元素
}
void SeqStack::Push(const DataType item	)
{
	if(top == MaxStackSize) //栈满异常退出
	{
		cout << "堆栈已满!" << endl;
		exit(0);
	}
	data[top] = item;		//先存储item
	top++;				//然后top加1
}
DataType SeqStack::Pop( )
{
	if(top == 0)		//栈空异常退出
	{
		cout<<"堆栈已空!"<<endl;
		exit(0);
	}
	top--;				//top先减1
	return data[top];		//然后取元素返回
}
int main()
{

    return 0;
}
