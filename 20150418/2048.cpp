#include<iostream>
#include<string>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int i,j,k,m,n,is,swa;
void print(int a[4][4])
{
	cout<<"_______________________"<<endl;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0)cout<<setw(4)<<' '<<' '<<'|';
			else cout<<setw(4)<<a[i][j]<<' '<<'|';

		}
		cout<<endl;
		cout<<"_____"<<'|'<<"_____"<<'|'<<"_____"<<'|'<<"_____"<<'|';
		cout<<endl;
	}
}
void inc(int a[4][4])
{
	do
	{
		i=0+rand()%4;j=0+rand()%4;
        m=1+rand()%10;n=1+rand()%10;
		is=0;
		if(a[i][j]==0)
		{
			if(m==1)a[i][j]=4;
			else a[i][j]=2;
			is++;
		}
	}while(is==0);
}
bool counta(int a[4][4])
{
	swa=0;
    for(i=0;i<=3;i++)
		for(j=0;j<=2;j++)
		{
			if(a[i][j]==0)continue;
			for(k=j+1;k<=3;k++)
			{
				if(a[i][k]==0)continue;
				if(a[i][k]==a[i][j])
				{
					a[i][j]+=a[i][k];
					a[i][k]=0;
					j=k;
					swa++;
				}
				break;
			}
		}
	    for(i=0;i<=3;i++)
		for(j=0;j<=2;j++)
		{
			for(k=j+1;k<=3;k++)if(a[i][k]!=0)break;
			if(k==4)break;
			if(a[i][j]==0)
			{
				for(k=j;k<=2;k++)a[i][k]=a[i][k+1];
			    a[i][3]=0;
				swa++;
			    if(a[i][j]==0)j--;
			}
		}
		if(swa>0)return 1;
		else return 0;
}
bool countw(int a[4][4])
{
	swa=0;
	for(j=0;j<=3;j++)
		for(i=0;i<=2;i++)
		{
			if(a[i][j]==0)continue;
			for(k=i+1;k<=3;k++)
			{
				if(a[k][j]==0)continue;
				if(a[k][j]==a[i][j])
				{
					a[i][j]+=a[k][j];
					a[k][j]=0;
					i=k;
					swa++;
				}
				break;
			}
		}
	    for(j=0;j<=3;j++)
		for(i=0;i<=2;i++)
		{
			for(k=i+1;k<=3;k++)if(a[k][j]!=0)break;
			if(k==4)break;
			if(a[i][j]==0)
			{
				for(k=i;k<=2;k++)a[k][j]=a[k+1][j];
			    a[3][j]=0;
				swa++;
			    if(a[i][j]==0)i--;
			}
		}
		if(swa>0)return 1;
		else return 0;
}
bool counts(int a[4][4])
{
	swa=0;
	for(j=0;j<=3;j++)
		for(i=3;i>=1;i--)
		{
			if(a[i][j]==0)continue;
			for(k=i-1;k>=0;k--)
			{
				if(a[k][j]==0)continue;
				if(a[k][j]==a[i][j])
				{
					a[i][j]+=a[k][j];
					a[k][j]=0;
					i=k;
					swa++;
				}
				break;
			}
		}
	    for(j=0;j<=3;j++)
		for(i=3;i>=1;i--)
		{
			for(k=i-1;k>=0;k--)if(a[k][j]!=0)break;
			if(k==-1)break;
			if(a[i][j]==0)
			{
				for(k=i;k>=1;k--)a[k][j]=a[k-1][j];
			    a[0][j]=0;
				swa++;
			    if(a[i][j]==0)i++;
			}
		}
		if(swa>0)return 1;
		else return 0;
}
bool countd(int a[4][4])
{
	swa=0;
    for(i=0;i<=3;i++)
		for(j=3;j>=1;j--)
		{
			if(a[i][j]==0)continue;
			for(k=j-1;k>=0;k--)
			{
				if(a[i][k]==0)continue;
				if(a[i][k]==a[i][j])
				{
					a[i][j]+=a[i][k];
					a[i][k]=0;
					j=k;
					swa++;
				}
				break;
			}
		}
	    for(i=0;i<=3;i++)
		for(j=3;j>=1;j--)
		{
			for(k=j-1;k>=0;k--)if(a[i][k]!=0)break;
			if(k==-1)break;
			if(a[i][j]==0)
			{
				for(k=j;k>=1;k--)a[i][k]=a[i][k-1];
			    a[i][0]=0;
				swa++;
			    if(a[i][j]==0)j++;
			}
		}
		if(swa>0)return 1;
		else return 0;
}
bool is2048(int a[4][4])
{
	is=0;
	for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)if(a[i][j]==2048)is++;
		if(is>0)return 1;
		else return 0;
}
bool isfull(int a[4][4])
{
	is=0;
	for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)if(a[i][j]!=0)is++;
		if(is==16)return 1;
		else return 0;
}
bool isable(int a[4][4])
{
	int issame=0;
	for(i=0;i<=3;i++)
	{
		for(j=1;j<=3;j++)
			if(a[i][j]==a[i][j-1])issame++;
	}
	for(j=0;j<=3;j++)
	{
		for(i=1;i<=3;i++)
			if(a[i][j]==a[i-1][j])issame++;
	}
	if(issame>0)return 1;
	else return 0;
}
int main()
{
	srand(time(NULL));
	int a[4][4];
	bool ismove;
	for(i=0;i<=3;i++)
		for(j=0;j<=3;j++)a[i][j]=0;
	inc(a);inc(a);
	print(a);
	char s;
	do
	{
		s=getch();
		s=getch();

		switch(s)
		{
		case 72:
			if(countw(a))ismove=true;
			else ismove=false;
			break;
		case 75:
			if(counta(a))ismove=true;
			else ismove=false;
			break;
		case 80:
			if(counts(a))ismove=true;
			else ismove=false;
			break;
		case 77:
			if(countd(a))ismove=true;
			else ismove=false;
			break;
		}
		if(ismove)
		{
			system("CLS");
			if(is2048(a))
			{
				print(a);
				cout<<"YOU WON !"<<endl;
				break;
			}
			inc(a);
			print(a);
		        if(isfull(a)&&!isable(a))
			{
				cout<<"GAME OVER !"<<endl;
				break;
			}
		}
	}while(1);
	return 0;
}
