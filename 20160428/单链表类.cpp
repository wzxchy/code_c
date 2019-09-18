#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

template <class T>
class LinList;

template <class T>
class ListNode
{
	friend class LinList <T>;        //定义LinList类为友元
public:
	ListNode <T> *next;              //指针域
	T data;                          //数据域
public:
	ListNode(ListNode<T> *ptrNext=NULL){next=ptrNext;}    //构造函数，构造头结点
	ListNode(const T & item, ListNode<T> *ptrNext=NULL){data=item;next=ptrNext;} //构造函数，构造其他结点
	~ListNode(void){}  //析构函数
};

template <class T>
class LinList
{
private:
	ListNode <T> *head;   //头指针
	int size;     //当前元素个数
	ListNode <T> *Index(int i);   //定位函数
public:
	LinList(void);                         //构造
	~LinList(void);                        //析构
	void Insert(const T& item,int i);      //插入
	T Delete(int i);                       //删除
	void print();                          //输入
	bool IsExitsLoop();                    //判断是否有环
    ListNode <T> * FindLoopPort();         //寻找环入口点
    void BulidListLoop(int m,int n);       //建立环，将元素值为n的结点链域连接到元素值为m的结点
    void DeleteListLoop();                 //删除环
};

template <class T>
LinList <T>::LinList()
{
	head=new ListNode <T>();      //头指针指向头结点
	size=0;    //初始化
}

template <class T>
LinList <T>::~LinList(void)
{
    ListNode <T> *p,*q;
	p=head;                 //p指向头结点
	while(p!=NULL)
	{
        q=p;
        p=p->next;
        delete q;
	}                      //循环释放结点空间
	size=0;
	head=NULL;
}

template <class	T>
ListNode<T> *LinList<T>::Index(int i)     //定位
{
    if(i<-1||i>size-1)
    {
        cout<<"参数i越界！"<<endl;
        return 0;
    }
	if(i==-1) return head;              //i=-1时，返回头指针
	ListNode<T> *p=head->next;          //p指向除头结点外第一个结点
	int j=0;
	while(p!=NULL &&j<i)             //p不为空或结点个数小于i，循环继续
	{
		p=p->next;
		j++;
	}
	return p;
}

template <class T>
void LinList<T>::Insert(const T& e, int i)//i为该节点在链表中的位置
{
    if(i<0||i>size)
    {
        cout<<"参数i越界！"<<endl;
        return ;
    }
	ListNode <T> *p=Index(i-1);           //p指向要插入位置的前一个结点
    ListNode <T> *s=new ListNode <T> (e,p->next);     //构造新结点，数据域为e,指针域为p指向结点后一个结点的地址
    p->next=s;            //连接p指向结点与新构造结点
    size++;
}
template <class T>
T LinList<T>:: Delete(int i)
{
    if(size==0)
    {
        cout<<"链表已空"<<endl;
        return 0;
    }
   if(i<0||i>size-1)
    {
        cout<<"参数i越界！"<<endl;
        return 0;
    }
	ListNode <T> *s,*p=Index(i-1);   //p指向要删除结点的前一个结点
    s=p->next;                      //s指向要删除结点
    p->next=p->next->next;          //连接s前一个结点与后一个结点
    T x=s->data;                    //s数据域赋给x;
    delete s;                       //释放删除结点空间
    size--;
    return x;
}


template <class T>
void LinList<T>::print()
{
    ListNode<T> *p;
    p=head->next;              //p指向除头结点外第一个结点
    while(p!=NULL)
    {
        cout<<p->data<<"   ";
        p=p->next;
    }                          //依次输出每个结点的数据域
    cout<<endl<<endl<<endl;
}

template <class T>
bool LinList<T>::IsExitsLoop()     //Foyed判圈法
{
    ListNode<T>  *slow=head->next, *fast=head->next;    //定义两个结点，从第一个结点开始遍历
	while (fast&&fast->next)
    {
        slow=slow->next;                                 //慢结点每次走一个结点
        fast=fast->next->next;                           //快结点每次走两个结点
        if(slow==fast) break;
    }
    return !(fast==NULL || fast->next==NULL);
}

template <class T>
ListNode <T> *  LinList<T>::FindLoopPort()
{
    ListNode<T>  *slow=head->next,*fast=head->next;
    while (fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(fast==NULL || fast->next==NULL)   return NULL;
    slow=head->next;                                 //此时slow结点与fast结点与环入口距离相等
    while(slow!=fast)
    {
         slow=slow->next;
         fast=fast->next;
    }
    return slow;
}
template <class T>
void LinList<T>::BulidListLoop(int m,int n)
{
    ListNode<T>  *p=head->next;
    ListNode<T>  *q=head->next;
    int flag=0;
    while(p)       //寻找数据域为m的结点
    {
        if(p->data==m)   break;
        if(p->data==n)   flag=1;    //未找到m先找到n,flag标记为1；
        p=p->next;
    }
    if(p==NULL)
    {
        cout<<"元素值为m的结点不存在,建环失败！"<<endl;
        return ;
    }
    if(flag==1)
    {
        cout<<"元素值为n的结点在元素值为m的结点之前,建环失败！"<<endl;
        return ;
    }
    while(q)      //寻找数据域为n的结点
    {
        if(q->data==n)   break;
        q=q->next;
    }
    if(q==NULL)
    {
        cout<<"元素值为n的结点不存在,建环失败！"<<endl;
        return ;
    }
    ListNode<T>  *tempq=q->next;
    q->next=p;        //将n结点链域连接到m结点,建立环
    while(tempq)     //删除原来在n结点后面的结点
    {
        ListNode<T>  *tempp=tempq;
        tempq=tempq->next;
        delete tempp;
    }
}

template <class T>
void LinList<T>::DeleteListLoop()
{
    ListNode<T>  *p=FindLoopPort();   //寻找环入口结点
    ListNode<T>  *q=p->next;
    while(q->next!=p)  q=q->next;     //寻找环上入口结点之前的结点
    q->next=NULL;
}

int main()
{
	LinList<int> mylist;
    int i=0;
    cout<<"请输入要插入元素,以@结束:"<<endl;
    string str;
    while(cin>>str&&str!="@")
    {
        int t=atoi(str.c_str());
        mylist.Insert(t,i);
        i++;
    }
    cout<<"链表中各元素值为: ";
    mylist.print();

    int m,n;
    cout<<"请输入要建立环的元素值m,n,将元素值为n的结点链域连接到元素值为m的结点:"<<endl;
    cin>>m>>n;
    mylist.BulidListLoop(m,n);
    ListNode<int>  * node=mylist.FindLoopPort();
    if(node==NULL)   cout<<"链表中无环！"<<endl;
    else
    {
        cout<<"链表中环入口点元素值为:"<<node->data<<endl<<endl<<endl;
        mylist.DeleteListLoop();
        cout<<"删除环后,链表中个元素值为: ";
        mylist.print();
    }
    return 0;
}
/*
5 6 98 3 21 45 68 6 8 7 8 9 @
98 68

请输入要插入元素,以@结束:
1 2 3 4 1 3 5 7 @

*/
/*
bool IsExitsLoop(LinList<T>   *head)
{
	ListNode<T>  *slow = head->next, *fast = head->next;
	while ( fast && fast->next )
{
slow = slow->next;
fast = fast->next->next;
if ( slow == fast ) break;
}
return !(fast == NULL || fast->next == NULL);
}


slist* FindLoopPort(LinList<T>   *head)
{
    ListNode<T>  *slow = head->next, *fast = head->next;
    while ( fast && fast->next ) {
        slow = slow->next;
        fast = fast->next->next;
        if ( slow == fast ) break;
    }
    if (fast == NULL || fast->next == NULL)   return NULL;
    slow = head;
    while (slow != fast) {
         slow = slow->next;
         fast = fast->next;
    }
    return slow;
}


Status BulidListLoop(LinkList *L, int num){
	int i = 0;
	LinkList cur = *L;
	LinkList tail = NULL;
	if(num <= 0 || L == NULL)  return ERROR;
	for(i = 1; i < num; ++i) {
		if(cur == NULL)  return ERROR;
		cur = cur->next;
	}
	tail = cur;
	while(tail->next){
        		tail = tail->next;
	}
	tail->next = cur;
 	return OK;
}



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
                mylist.print();
                break;
            }
            case 2:
            {
                cout<<"输入要删除元素的下标"<<endl;
                int t;
                cin>>t;
                mylist.Delete(t);
                i--;
                mylist.print();
                break;
            }
            default: cout<<"输入错误！"<<endl;
        }
        cout<<endl<<endl;
    }

*/
