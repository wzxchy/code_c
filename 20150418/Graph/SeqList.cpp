#include "SeqList.h"
#include <iostream>
using namespace std;
SeqList::SeqList(int max)              //���캯��
{
	maxsize=max;
	size=0;                           //��ʼ��
	list=new DataType[maxsize];
}
SeqList::~SeqList(void)
{
	delete []list;     //���տռ�Ϊ����ʱ, delete��Ҫ��[ ]
}
int SeqList::Size() const
{
	return size;
}
DataType SeqList::GetData(int i)const
{
	if(i<0 || i>size)
	{
	    cout<<"����iԽ�������"<<endl;
	    exit(0);
    }        
	return list[i];
}
void SeqList::Insert(const DataType& item,int i)
{
	if(size==maxsize)
	{
	    cout<<"˳��������޷��壡"<<endl;
        exit(0);
    }
 	if(i<0 || i>size)
	{
	    cout<<"����iԽ�������"<<endl;
	    exit(0);
    }                                                 //�����������
	for(int j=size;j>i;j--)   list[j]=list[j-1];      //��size-1��i���Ԫ�غ���
	list[i]=item;                                   //��iλ�ò���item
	size++;                                         //��ǰԪ�ظ�����1
}
DataType SeqList::Delete(const int i)
{
	if(size==0)
   	{
   	    cout<<"˳����ѿ��޷�ɾ����"<<endl;
   	    exit(0);
    }
 	if (i<0 || i>size-1)
	{
	    cout<<"����iԽ�������"<<endl;
	    exit(0);
    }
	DataType x=list[i];      //ȡ��Ҫɾ����Ԫ��
	for(int j=i;j<size-1;j++)
        list[j]=list[j+1];                 //��i+1��size-1���Ԫ��ǰ��
	size--;                                //��ǰԪ�ظ�����1
	return x;                              //����ɾ����Ԫ��
}
void SeqList::Print()
{
    int i;
    for(i=0;i<size;i++)  cout<<list[i]<<"    ";      //�������������ÿ��Ԫ��
    cout<<endl;
}