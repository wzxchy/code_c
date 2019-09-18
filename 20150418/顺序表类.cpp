#include <iostream>
#include <stdlib.h>
#include <cstdio>
#include<string>
#include<sstream>
using namespace std;
typedef int DataType;                 //定义具体问题元素数据类型

class SeqList
{
protected:
	DataType *list;                   //数组
	int maxsize;                      //最大元素个数
	int size;                         //当前元素个数
public:
	SeqList(int max=0);               //构造函数
	~SeqList(void);                   //析构函数
	void Insert(const DataType& item,int i);   //插入
	DataType Delete(const int i);              //删除
	void Print();                              //输出
};
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
int main()
{
    SeqList mylist(100);
    int i=0;
    while(1)
    {
        cout<<"1  插入"<<endl<<"2  删除"<<endl;
        cout<<"请输入操作序号:"<<endl;
        int c;
        cin>>c;
        switch(c)
        {
            case 1:
            {
                cout<<"输入要插入元素"<<endl;
                string str;
                while(cin>>str&&str!="@")
                {
                    int t=atoi(str.c_str());
                    mylist.Insert(t,i);
                    i++;
                }
                mylist.Print();
                break;
            }
            case 2:
            {
                cout<<"输入要删除元素的下标"<<endl;
                int t;
                cin>>t;
                mylist.Delete(t);
                i--;
                mylist.Print();
                break;
            }
            default: cout<<"输入错误！"<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}
