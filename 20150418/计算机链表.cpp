#include<iostream>
using namespace std;
struct node
{
	char no[12];
	char name[40];
	float dj;
	int num;
	float jine;
	struct node *link;
};
int main()
{
	int n;
	cout<<"请输入记录个数n:"<<endl;
	cin>>n;
	node njsj;
	char no[12];
	char name[40];
	float dj;
	int num;
	cout<<"请依次输入各记录计算机设备编号、名称、单价、数量、金额(以空格相隔,每条记录输入完后按回车):"<<endl;
	int i;
	node *head,*tail,*p;
	head=new node;
	tail=head;
	for(i=0;i<n;i++)
	{
		cin>>no>>name>>dj>>num;
		p=new node;
		strcpy(p->no,no);
		strcpy(p->name,name);
		p->dj=dj;
		p->num=num;
		tail->link=p;
		tail=p;
	}
	tail->link=NULL;
	char nofind[12];
	cout<<"请输入要查找的设备编号:"<<endl;
	cin>>nofind;
	p=head->link;
	while(p!=NULL&&strcmp(p->no,nofind)!=0)
	{
		p=p->link;
	}
	if(p==NULL)
	{
		cout<<"未找到!"<<endl;
	}
	else
	{
		cout<<p->name<<'\t'<<p->dj<<'\t'<<p->num<<endl;
	}
	p=head->link;
	while(p!=NULL)
	{
		p->jine=p->dj*p->num;
		p=p->link;
	}
	node *head1,*tail1,*p1;
	head1=new node;
	tail1=head1;
	p=head->link;
	while(p!=NULL)
	{
		p1=p;
		tail1->link=p1;
		tail1=p1;
		p=p->link;
	}
	tail1->link=NULL;
	p1=head1->link;
	while(p1!=NULL)
	{
		cout<<p1->dj<<endl;
		p1=p1->link;
	}
	return 0;
}