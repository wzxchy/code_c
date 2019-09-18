#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string DoubleToString(double d)
{
	string str;
	stringstream ss;
	ss<<d;
	ss>>str;
	return str;
}
string Cal(string str)
{
	str.insert(str.length(),"#");
	int i,j;
	string s;
	double d1,d2,d3;
	bool ismul;
	while(str.find('*')>0&&str.find('*')<str.length()||str.find('/')>0&&str.find('/')<str.length())
	{
		for(i=0;;i++)
		{
		 if(str[i]=='*')
		 {
			 ismul=true;
			 break;
		 }
		 if(str[i]=='/')
		 {
			 ismul=false;
			 break;
		 }
		}
		for(j=1;;j++)
		{
			if(str[i+j]=='+'||str[i+j]=='-'||str[i+j]=='*'||str[i+j]=='/'||str[i+j]=='#') 
			 break;
		}
		s=str.substr(i+1,j-1);
		str.erase(i,j);
		d1=atof(s.c_str());
		for(j=1;i-j>=0;j++)
		{
			if(str[i-j]=='+'||str[i-j]=='-') 
			 break;
		}
		s=str.substr(i-j+1,j-1);
		str.erase(i-j+1,j-1);
		d2=atof(s.c_str());
	    if(ismul) d3=d1*d2;
		else d3=d2/d1;
		s=DoubleToString(d3);
		str.insert(i-j+1,s);
	}
	double sum=0;
	if(str[0]!='+'&&str[0]!='-')
		str.insert(0,'+');
	while(1)
	{
		for(i=1;;i++)
		{
			if(str[i]=='+'||str[i]=='-'||str[i]=='#')
				break;
		}
		s=str.substr(1,i-1);
		d1=atof(s.c_str());
		if(str[0]=='+')sum=sum+d1;
		if(str[0]=='-')sum=sum-d1;
		if(str[i]=='#')
			break;
		str.erase(0,i);
	}
	return DoubleToString(sum);
}
string CalBra(string str)
{
	int i,j;
	string s;
	double ds;
	while(str.find('(')>=0&&str.find('(')<str.length())
	{	
		i=str.find(')');
		for(j=1;;j++)
		{
			if(str[i-j]=='(')
				break;
		}
		s=str.substr(i-j+1,j-1);
		s=Cal(s);
		ds=atof(Cal(s).c_str());
		str.erase(i-j,j+1);
		str.insert(i-j,s);
		if(i-j!=0)
		{
			if(ds<0&&str[i-j-1]!='(')
			{
			    if(str[i-j-1]=='+')
					str.erase(i-j-1,1);
				if(str[i-j-1]=='-')
				{
					str.erase(i-j-1,2);
					str.insert(i-j-1,"+");
				}
				if(str[i-j-1]=='*'||str[i-j-1]=='/')
				{
					str.erase(i-j,1);
					int k;
					for(k=1;i-j-1-k>=0;k++)
					{
						if(str[i-j-1-k]=='+')
						{
							str.erase(i-j-1-k,1);
							str.insert(i-j-1-k,"-");
							break;
						}
						if(str[i-j-1-k]=='-')
						{
							str.erase(i-j-1-k,1);
							str.insert(i-j-1-k,"+");
							break;
						}
						if(str[i-j-1-k]=='(')
						{
							str.insert(i-j-k,"-");
							break;
						}
						if(i-j-1-k==0)str.insert(i-j-1-k,"-");
					}
				}
			}
		}
	}
	return str;
}
int main()
{
	string str;
	cout<<"ÇëÊäÈëËãÊ½ :"<<endl;
	cin>>str;
	str=CalBra(str);
	cout<<str<<endl;
	str=Cal(str);
	cout<<str<<endl;
	return 0;
}
