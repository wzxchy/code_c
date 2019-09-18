#include "SeqList.h"
#include <iostream>
using namespace std;
SeqList::SeqList(int max)              //构造函数
{
	maxsize=max;
	size=0;                           //初始化
	list=new DataType[maxsize];
}
SeqList::~SeqList(void)
{
	delete []list;     //回收空间为数组时, delete后要加[ ]
}
int SeqList::Size() const
{
	return size;
}
DataType SeqList::GetData(int i)const
{
	if(i<0 || i>size)
	{
	    cout<<"参数i越界出错！"<<endl;
	    exit(0);
    }        
	return list[i];
}
void SeqList::Insert(const DataType& item,int i)
{
	if(size==maxsize)
	{
	    cout<<"顺序表已满无法插！"<<endl;
        exit(0);
    }
 	if(i<0 || i>size)
	{
	    cout<<"参数i越界出错！"<<endl;
	    exit(0);
    }                                                 //特殊情况处理
	for(int j=size;j>i;j--)   list[j]=list[j-1];      //从size-1至i逐个元素后移
	list[i]=item;                                   //在i位置插入item
	size++;                                         //当前元素个数加1
}
DataType SeqList::Delete(const int i)
{
	if(size==0)
   	{
   	    cout<<"顺序表已空无法删除！"<<endl;
   	    exit(0);
    }
 	if (i<0 || i>size-1)
	{
	    cout<<"参数i越界出错！"<<endl;
	    exit(0);
    }
	DataType x=list[i];      //取到要删除的元素
	for(int j=i;j<size-1;j++)
        list[j]=list[j+1];                 //从i+1至size-1逐个元素前移
	size--;                                //当前元素个数减1
	return x;                              //返回删除的元素
}
void SeqList::Print()
{
    int i;
    for(i=0;i<size;i++)  cout<<list[i]<<"    ";      //依次输出数组中每个元素
    cout<<endl;
}