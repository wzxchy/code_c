#include<iostream>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
using namespace std;
template <class T> class LinStack;	//前视定义,否则友元无法定义
template <class T>			//模板类型为T
class StackNode
{
	friend class LinStack<T>;		//定义类LinStack<T>为友元
private:
	T data;				//数据元素
	StackNode<T> *next;		//指针
public:
	StackNode(StackNode<T> *ptrNext = NULL)	{next = ptrNext;}
	StackNode(const T& item, StackNode<T> *ptrNext= NULL)
    {
        data = item;
        next = ptrNext;
    }
	~StackNode( ){};
};

template <class T>
class LinStack
{
private:
	StackNode<T> *head;
	int size;
public:
	LinStack(void);
	~LinStack(void);
	void Push(const T& item);
	T Pop(void);
	T GetTop(void) const;
	int NotEmpty(void) const;
};
template <class T>
LinStack<T>::LinStack()
{
    head=new StackNode<T>;
    size=0;
}
template <class T>
LinStack<T>::~LinStack()
{
    StackNode<T> *p,*q;
    p=head;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        delete q;
    }
}
template <class T>
int LinStack<T>::NotEmpty() const
{
    return size!=0;
}
template <class T>
void LinStack<T>::Push(const T& item)
{
	StackNode<T>*newNode=new StackNode<T>(item,head->next);
	head->next = newNode;
	size++;
}
template <class T>
T LinStack<T>::Pop(void)
{
	if(size == 0)
	{
	    cout << "堆栈已空无元素可删！" << endl;
        exit(0);
    }
	StackNode<T> *p = head->next;
	T data = p->data;
	head->next = head->next->next;
	delete p;
	size--;
	return data;
}

int main()
{

    return 0;
}
