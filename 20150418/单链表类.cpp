#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class LinList;

template <class T>
class ListNode
{
	friend class LinList <T>;
public:
	ListNode <T> *next;
	T data;
public:
	ListNode(ListNode<T> *ptrNext=NULL){next=ptrNext;}
	ListNode(const T & item, ListNode<T> *ptrNext=NULL){data=item;next=ptrNext;}
	~ListNode(void){}
};

template <class T>
class LinList
{
private:
	ListNode <T> *head;
	int size;
	ListNode <T> *Index(int i);
public:
	LinList(void);
	~LinList(void);
	int Size(void) const;
	void Insert(const T& item,int i);
	T Delete(int i);
	T GetData(int i);
	void print();
	void ListDeleteMore(T x);
	ListNode<T>* FindPrior(T x);
	void OrderInsert(T x);
	ListNode<T>* Reverse1();
	void Reverse2();
};

template <class T>
LinList <T>::LinList()
{
	head=new ListNode <T>();
	size=0;
}

template <class T>
LinList <T>::~LinList(void)
{
    ListNode <T> *p,*q;
	p=head;
	while(p!=NULL)
	{
        q=p;
        p=p->next;
        delete q;
	}
	size=0;
	head=NULL;
}

template <class	T>
ListNode<T> *LinList<T>::Index(int i)
{
    if(i<-1||i>size-1)
    {
        cout<<"参数i越界！"<<endl;
        exit(0);
    }
	if(i == -1) return head;
	ListNode<T> *p = head->next;
	int j = 0;
	while(p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

template <class T>
int LinList<T>::Size(void) const
{
	return size;
}

template <class T>
void LinList<T>::Insert(const T& e, int i)  //i:待插入元素在链表中位置（0为第一个元素）
{
    if(i<0||i>size)
    {
        cout<<"参数i越界！"<<endl;
        exit(0);
    }
	ListNode <T> *p=Index(i-1);
    ListNode <T> *s=new ListNode <T> (e,  p->next);
    p->next=s;
    size++;
}
template <class T>
T LinList<T>:: Delete(int i)
{
    if(size==0)
    {
        cout<<"链表已空"<<endl;
        exit(0);
    }
   if(i<0||i>size-1)
    {
        cout<<"参数i越界！"<<endl;
        exit(0);
    }
	ListNode <T> *s,*p=Index(i-1);
    s=p->next;
    p->next=p->next->next;
    T x=s->data;
    delete s;
    size--;
    return x;
}

template <class T>
T LinList<T>::GetData(int i)
{
    if(i<0||i>size-1)
    {
        cout<<"参数i越界！"<<endl;
        exit(0);
    }
    ListNode<T> *p=Index(i);
    return p->data;
}

template <class T>
void LinList<T>::print()
{
    ListNode<T> *p;
    p=head->next;
    while(p!=NULL)
    {
        cout<<p->data<<"   ";
        p=p->next;
    }
    cout<<endl;
}
template <class T>
void LinList<T>::ListDeleteMore(T x)
{
    ListNode<T> *p;
    p=head;
    while(p->next!=NULL)
    {
        if(p->next->data==x)
        {
            p->next=p->next->next;
        }
        p=p->next;
    }
}

template <class T>
ListNode<T>* LinList<T>::FindPrior(T x)
{
    ListNode<T> *p;
    p=head->next;
    if(p==NULL)   return NULL;
    while(p->next!=NULL)
    {
        if(p->next->data==x)   return p;
        p=p->next;
    }
    return NULL;
}

template <class T>
void LinList<T>::OrderInsert(T x)
{
    ListNode<T> *p;
    p=head;
    while(p->next&&p->next->data<=x)
    {
        p=p->next;
    }
    ListNode<T> *q=new ListNode<T>(x,p->next);
    p->next=q;
    size++;
}

template <class T>
ListNode<T>* LinList<T>::Reverse1()
{
    ListNode<T> *head2;
    head2->next=NULL;
    ListNode<T> *p,*q;
    p=head->next;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        q->next=head->next;
        head2->next=q;
    }
    return head2;
}

template <class T>
void LinList<T>::Reverse2()
{
    ListNode<T> *p,*q;
    p=head->next;
    head->next=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        q->next=head->next;
        head->next=q;
    }
}
int main()
{
	LinList<int> mylist;
    int i;
    for(i=0;i<10;i++)
        mylist.Insert(i,i);
    mylist.print();
    mylist.OrderInsert(-1);
    mylist.print();
    mylist.Reverse2();
    mylist.print();
    return 0;
}
