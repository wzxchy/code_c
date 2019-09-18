#include<iostream>
using namespace std;
template<typename T> class List;
template<typename T> class Node
{
	T info;
	Node<T>*link;
	public:
		Node();
		Node(const T & date);
		void InsertAfter(Node<T>*P);
		Node<T>*RemoveAfter();
		friend class List<T>;
};
template <typename T>Node<T>::Node(){link=NULL;}
template <typename T>Node<T>::Node(const T & date)
{
	info=date;
	link=NULL;
}
template <typename T>void Node<T>::InsertAfter(Node<T>*p)
{
	p->link=link;
	link=p;
}
template <typename T>Node<T>*Node<T>::RemoveAfter()
{
	Node<T>*tempP=link;
	if(link=NULL)tempP=NULL;
	else link=tempP->link;
	return tempP;
}
template <typename T>class List
{
	Node<T>*head,*tail;
	public:
		List();
		~List();
		void MakeEmpty();
		Node<T>*Find(T date);
		int Length();
		void PrintList();
		void InserFront(Node<T>*p);
		void InsertRear(Node<T>*p);
		void InsertOrder(Node<T>*p);
		Node<T>*CreatNode(T date);
		Node<T>*DeleteNode(Node<T>*p);
};
template<typename T>List<T>::List(){head=tail=new Node<T>();}
template<typename T>List<T>::~List()
{
	MakeEmpty();
	delete head;
}
template<typename T>void List<T>::MakeEmpty()
{
	Node<T>*tempP;
	while(head->link!=NULL)
	{
		tempP=head->link;
		head->link=tempP->link;
		delete tempP;
	}
	tail=head;
}
template<typename T>Node<T>*List<T>::Find(T date)
{
	Node<T>*temp=head->link;
	while(tempP!=NULL&&tempP->info!=date)tempP=tempP->link;
	return tempP;
}
template<typename T>int List<T>::Length()
{
	Node<T>*tempP=head->link;
	int count=0;
	while(tempP!=NULL)
	{
		tempP=tempP->link;
		count++;
	}
	return count;
}
template<typename T>void List<T>::PrintList()
{
	Node <T>*tempP=head->link;
	while(tempP!=NULL)
	{
		tempP->info.show();
		tempP=tempP->link;
	}
	cout<<endl;
}
template<typename T>void List<T>::InserFront(Node<T>*p)
{
	p->link=head->link;
	head->link=p;
	if(tail==head)tail=p;
}
template<typename T>void List<T>::InsertRear(Node<T>*p)
{
	p->link=tail->link;
	tail->link=p;
	tail=p;
}
template<typename T>void List<T>::InsertOrder(Node<T>*P)
{
	Node<T>*tempP=head->link,*tempQ=head;
	while(tempP!=NULL)
	{
		if(p->info<tempP->info)break;
		tempQ=tempP;
		tempP=tempP->link;
	}
	tempQ->InsertAfter(p);
	if(tail==tempQ)tail=tempQ->link;
}
template<typename T>Node<T>*List<T>::CreatNode(T date)
{
	Node<T>*tempP=new Node<T>(date);
	return tempP;
}
template<typename T>Node<T>*List<T>::DeleteNode(Node<T>*P)
{
	Node<T>*tempP=head;
	while(tempP->link!=NULL&&tempP->link!=p)tempP=tempP->link;
	if(tempP->link==tail)tail=tempP;
	return tempP->RemoveAfter();
}
class comp
{
private:
	char no[12];
	char name[40];
	float dj;
	int num;
	float jine;
public:
	void com(char NO[],char NAME[],float DJ,int NUM);
	void show();
};
void comp::com(char NO[],char NAME[],float DJ,int NUM)
{
	strcpy(no,NO);
	strcpy(name,NAME);
	dj=DJ;
	num=NUM;	
}
void comp::show()
{
	cout<<"soo"<<endl;
	cout<<name<<'\t'<<dj<<'\t'<<num<<endl;
}
int main()
{
	int n;
	cout<<"请输入记录个数n:"<<endl;
	cin>>n;	
	Node<comp> *P1;
	List<comp> list;
	char no[12];
	char name[40];
	float dj;
	int num;
	cout<<"请依次输入各记录计算机设备编号、名称、单价、数量(以空格相隔,每条记录输入完后按回车):"<<endl;
	int i;
	for(i=0;i<n;i++)
	{
		cin>>no>>name>>dj>>num;
		comp co;
		co.com(no,name,dj,num);
		P1=list.CreatNode(co);	
		list.InsertRear(P1);
	}

	list.PrintList();
	return 0;
}




