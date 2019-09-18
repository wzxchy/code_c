#include <iostream>
#include <string.h>
#include "BiTreeNode.h"
using namespace std;
template <class T>
BiTreeNode<T> *GetTreeNode(const T item, BiTreeNode<T> *left = NULL, BiTreeNode<T> *right = NULL)
{
	BiTreeNode<T> *p;
	p = new BiTreeNode<T> (item, left, right);
	return p;
}      
void MakeCharTree1(BiTreeNode<char> *&root)
{
	BiTreeNode<char> *b,*c,*d,*e,*f,*g,*h,*i,*j,*k,*null=NULL;
	j=GetTreeNode('J');
	k=GetTreeNode('K');
	i=GetTreeNode('I',null,j);
	h=GetTreeNode('H');
	g=GetTreeNode('G',h,i);
	d=GetTreeNode('D',null,g);
	b=GetTreeNode('B',d);
	e=GetTreeNode('E',k);
	f=GetTreeNode('F');
	c=GetTreeNode('C',e,f);
	root=GetTreeNode('A',b,c);
}
void MakeCharTree2(BiTreeNode<char> *&root)
{
	BiTreeNode<char> *b,*c,*d,*e,*f,*g,*null=NULL;
	g=GetTreeNode('G');
	f=GetTreeNode('F');
	d=GetTreeNode('D');
	e=GetTreeNode('E');
	b=GetTreeNode('B',d,e);	
	c=GetTreeNode('C',g,f);
	root=GetTreeNode('A',b,c);
}
template <class T>
int Hight(BiTreeNode<T> *root)
{
	if(root==NULL)   return 0;
	else
	{
		int h1=Hight(root->Left());
		int h2=Hight(root->Right());
		if(h1<h2)  h1=h2;
		return h1+1;
	}
}
template <class T>
void PreOrder2(BiTreeNode<T> *root, void Visit(T item))
{
	BiTreeNode<T> *t,*s[100];
	s[0]=root;
	int top=1;
	while(top>0)
	{
		t=s[--top];
		Visit(t->data);
		if(t->Right())   s[top++]=t->Right();
		if(t->Left())   s[top++]=t->Left();
	}
}
template <class T>
int NumOfLeaveNode(BiTreeNode<T> *root)
{
	BiTreeNode<T> *t,*s[100];
	s[0]=root;
	int top=1;
	int n=0;
	while(top>0)
	{
		t=s[--top];
		if(t->Right()==NULL&&t->Left()==NULL)   n++;
		if(t->Right())   s[top++]=t->Right();
		if(t->Left())   s[top++]=t->Left();
	}
	return n;
}
template <class T>
bool IsCompBiTree(BiTreeNode<T> *root,void Visit(T item))
{
	BiTreeNode<T> *t,*s[100];
	s[0]=root;
	int front=0,rear=1;
	bool b=0;
	while(front<rear)
	{
		t=s[front++];
		if(b&&((t->Left()!=NULL)||(t->Right()!=NULL))) return 0;
		if(t->Right()==NULL)  b=1;
		if(t->Left())   s[rear++]=t->Left();
		if(t->Right())   s[rear++]=t->Right();	
	}
	return 1;
}
template <class T>
void InOrder2(BiTreeNode<T> *root, void Visit(T item))
{
	BiTreeNode<T> *p,*s[100];//s栈
	p=root;
	int top=0;
    while((p!=NULL)||(top>0))
	{       
	    while(p!=NULL)
        {
			s[++top]=p;        //进栈
		    p=p->Left();  //进入左子树
        }
    	p=s[top--];    	//退栈
	    Visit(p->data);
	    p=p->Right(); 	//进入右子树
	}
}
template <class T>//使用Visit(item)函数后序遍历二叉树t
void PostOrder2(BiTreeNode<T> *root, void Visit(T item))
{
	BiTreeNode<T> *p,*s[100];//栈  
	int top=1;//栈顶指针
	int b,t[100];//数组标记栈中元素的子树是否入过栈
	memset(t,0,sizeof(t));//数组t元素初始化为0
	s[0]=root;//根节点入栈
	while(top>0)//栈非空，继续循环
	{	
		p=s[top-1];//取栈顶元素
		b=t[top-1];//取标记
		if(b)//若子树已遍历
		{
			Visit(p->data);		//遍历p指向结点的数据
			top--;//出栈
			t[top-1]=0;//标记还原为0
		}
		else//若子树未遍历
		{
	    	if(p->Right())  s[top++]=p->Right();//若右子树非空，右子树入栈
	    	if(p->Left())  s[top++]=p->Left();//若左子树非空，左子树入栈
			t[top-1]=1;//子树入栈，标记为1
		}
	}
}

void Printchar(char item)
{
	cout<<item<<" ";
}

int main()
{
	BiTreeNode<char> *root1,*p;
	MakeCharTree2(root1);
	cout<<Hight(root1)<<endl;
	return 0;
}