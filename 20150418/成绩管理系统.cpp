#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;
template <typename T> class student{
private:
	T list[100];
	int last;//数组下标
public:
	student(){last=-1;}
	int find1(string);//查找某学号的位置
	int find2(string);//查找某姓名的位置
	void insert();//存入
	void insert1();//自动存入
	void remove();//删除
	void change();//修改
	void findgrade();//查找成绩
	void findlist();//查看某分数段内成绩
	void tongji();//统计分析
	void print();//显示成绩单
	void order();//排序
    void f();//存入文件
	void m(string);//模糊查询
	int getlast(){return last;}
};
template <typename T>int student<T>::find1(string xuehao){
	int i;
	for(i=0;i<=last;i++) if(xuehao==list[i].getid()) break;
	if(i<=last) return i;
	else{
		cout<<"不在表中!"<<endl; 
		return -1;
	}
}
template <typename T>int student<T>::find2(string name){
    int i;
	for(i=0;i<=last;i++) if(name==list[i].getname()) break;
	if(i<=last) return i;
	else{
		cout<<"不在表中!"<<endl; 
		return -1;
	}
}
template <typename T>void student<T>::insert(){
    last++;
	grade g1;
	g1.in();
	int i;
	for(i=0;i<=last-1;i++)if(g1.getid()==list[i].getid())break;
	while(i<=last-1){
		cout<<"学号已存在,请重新输入:"<<endl;
		g1.in();
		for(i=0;i<=last-1;i++)if(g1.getid()==list[i].getid())break;
	}
	list[last]=g1;
}
template <typename T>void student<T>::insert1(){
	ifstream ifile;
	ifile.open("D:\\成绩单1.txt");
	string id1;
	string name1;
	int m,e,p;
	while(1){
		ifile>>id1>>name1>>m>>e>>p;	
		if(ifile.eof()!=0)break;
	    grade g1;
		g1.in1(id1,name1,m,e,p);
		last++;
	    list[last]=g1;
 	}
	ifile.close();
}
template <typename T>void student<T>::remove(){
	cout<<"按学号删除请输入a并回车，按姓名删除请输入b并回车:"<<endl;
	char x;
	cin>>x;
	while(x!='a'&&x!='A'&&x!='b'&&x!='B'){
		cout<<"输入有误!请重新输入:"<<endl;
		cin>>x;
	}//防止输入错误
	if(x=='a'||x=='A'){
	    string xuehao;
     	cout<<"输入要删除的学号(输入完请按回车):"<<endl;
    	cin>>xuehao;
	    int i=find1(xuehao),j;
	    if(i>=0){
		  cout<<"确认删除?"<<endl<<"确认请输入Y，取消请输入N(不区分大小写,输入完请按回车):"<<endl;
		  char m;
		  cin>>m;
		  while(m!='y'&&m!='Y'&&m!='n'&&m!='N'){
	    	cout<<"输入有误!请重新输入:"<<endl;
	    	cin>>m;
		  }
		  if(m=='Y'||m=='y'){
			for(j=i;j<=last-1;j++)list[j]=list[j+1];
	        last--;
		  }	
		}
	}
	if(x=='b'||x=='B'){
		string name;
     	cout<<"输入要删除的姓名(输入完请按回车):"<<endl;
    	cin>>name;
	    int i=find2(name),j;
	    if(i>=0){
		  cout<<"确认删除?"<<endl<<"确认请输入Y，取消请输入N(不区分大小写,输入完请按回车):"<<endl;
		  char m;
		  cin>>m;
		  while(m!='y'&&m!='Y'&&m!='n'&&m!='N'){
	    	cout<<"输入有误!请重新输入:"<<endl;
	    	cin>>m;
		  }
		  if(m=='Y'||m=='y'){
			for(j=i;j<=last-1;j++)list[j]=list[j+1];//删除一条记录，其余顺序不变
	        last--;
		  }
		}
	}
}
template <typename T>void student<T>::change(){
	cout<<"按学号修改请输入a并回车，按姓名修改请输入b并回车:"<<endl;
	char x;
	cin>>x;
	while(x!='a'&&x!='A'&&x!='b'&&x!='B'){
		cout<<"输入有误!请重新输入:"<<endl;
		cin>>x;
	}
	if(x=='a'||x=='A'){	
	   string xuehao;
	   cout<<"输入要修改的学号(输入完请按回车):"<<endl;
	   cin>>xuehao;
	   int i=find1(xuehao);
       if(i>=0)list[i].change();
	}
	if(x=='b'||x=='B'){
	   string name;
	   cout<<"输入要修改的姓名(输入完请按回车):"<<endl;
	   cin>>name;
	   int i=find2(name);
       if(i>=0)list[i].change();
	}
}
template <typename T>void student<T>::findgrade(){
	cout<<"按学号查找请输入a并回车，按姓名查找请输入b并回车(不区分大小写):"<<endl;
	char x;
	cin>>x;
	if(x=='a'||x=='A'){	
	   string xuehao;
	   cout<<"输入要查找学生的学号(输入完请按回车):"<<endl;
	   cin>>xuehao;
	   int i=find1(xuehao);
	   if(i>=0){
		  cout<<setw(10)<<"学号  "<<setw(10)<<"姓名"<<setw(12)<<"数学"<<setw(10)<<"英语"<<setw(10)<<"物理"<<setw(10)<<"总分"<<endl;
		  list[i].show();
	   }
	}
	if(x=='b'||x=='B'){
		 string name;
	     cout<<"输入要查找学生的姓名(输入完请按回车):"<<endl;
	     cin>>name;
	     int i=find2(name);
	     if(i>=0){
	 	     cout<<setw(10)<<"学号  "<<setw(10)<<"姓名"<<setw(12)<<"数学"<<setw(10)<<"英语"<<setw(10)<<"物理"<<setw(10)<<"总分"<<endl;
		     list[i].show();
		   }
	   }
}
template <typename T>void student<T>::findlist(){
	cout<<"请选择科目:数学请输入m，英语请输入e，物理请输入p(不区分大小写,输入完请按回车):"<<endl;
	char n;
	cin>>n;
	cout<<"请依次输入分数区间最小值、最大值(以空格相隔,输入完请按回车):"<<endl;
	int a,b;
	cin>>a>>b;
	int i;
    if(n=='m'||n=='M'){
     	cout<<"学生名单如下:"<<endl;
		for(i=0;i<=last;i++)if(list[i].getmath()>=a&&list[i].getmath()<=b)cout<<list[i].getname()<<setw(6)<<list[i].getmath()<<endl;
	}
	else if(n=='e'||n=='E'){
    	    cout<<"学生名单如下:"<<endl;
		    for(i=0;i<=last;i++)if(list[i].geteng()>=a&&list[i].geteng()<=b)cout<<list[i].getname()<<setw(6)<<list[i].geteng()<<endl;
	}
         else if(n=='p'||n=='P'){
		      cout<<"学生名单如下:"<<endl;
		      for(i=0;i<=last;i++)if(list[i].getphy()>=a&&list[i].getphy()<=b)cout<<list[i].getname()<<setw(6)<<list[i].getphy()<<endl;
		 }
		      else cout<<"科目输入错误!"<<endl;
}
template <typename T>void student<T>::tongji(){
	int i,smath=0,seng=0,sphy=0;
	float amath,aeng,aphy,asum,rmath,reng,rphy;
	for(i=0;i<=last;i++)smath=smath+list[i].getmath();
	amath=smath/(last+1);
	for(i=0;i<=last;i++)seng=seng+list[i].geteng();
	aeng=seng/(last+1);
	for(i=0;i<=last;i++)sphy=sphy+list[i].getphy();
	aphy=sphy/(last+1);
	asum=(smath+seng+sphy)/(last+1);
	cout<<"数学平均分:"<<amath<<'\t'<<"英语平均分:"<<aeng<<'\t'<<"物理平均分:"<<aphy<<'\t'<<"总平均分:"<<asum<<endl;
	int j;
	float nmath=0,neng=0,nphy=0;
	for(j=0;j<=last;j++)if(list[j].getmath()>=60)nmath++;
	rmath=nmath/(last+1);
	for(j=0;j<=last;j++)if(list[j].geteng()>=60)neng++;
	reng=neng/(last+1);
	for(j=0;j<=last;j++)if(list[j].getphy()>=60)nphy++;
	rphy=nphy/(last+1);
	cout<<"数学合格率:"<<rmath*100<<'%'<<'\t'<<"英语合格率:"<<reng*100<<'%'<<'\t'<<"物理合格率:"<<rphy*100<<'%'<<endl;
	float cmath=0,ceng=0,cphy=0,bmath,beng,bphy;
	int k;
	for(k=0;k<=last;k++) cmath=cmath+(list[k].getmath()-amath)*(list[k].getmath()-amath);
	bmath=sqrt(cmath/(last+1));
	for(k=0;k<=last;k++) ceng=ceng+(list[k].geteng()-aeng)*(list[k].geteng()-aeng);
	beng=sqrt(ceng/(last+1));
	for(k=0;k<=last;k++) cphy=cphy+(list[k].getphy()-aphy)*(list[k].getphy()-aphy);
	bphy=sqrt(cphy/(last+1));
	cout<<"数学标准差:"<<bmath<<'\t'<<"英语标准差:"<<beng<<'\t'<<"物理标准差:"<<bphy<<endl;
	int nm1=0,nm2=0,nm3=0,nm4=0,ne1=0,ne2=0,ne3=0,ne4=0,np1=0,np2=0,np3=0,np4=0;
	for(k=0;k<=last;k++)if(list[k].getmath()>=90)nm1++;
	for(k=0;k<=last;k++)if(list[k].getmath()>=80&&list[k].getmath()<90)nm2++;
	for(k=0;k<=last;k++)if(list[k].getmath()>=60&&list[k].getmath()<80)nm3++;
	for(k=0;k<=last;k++)if(list[k].getmath()<60)nm4++;
	for(k=0;k<=last;k++)if(list[k].geteng()>=90)ne1++;
	for(k=0;k<=last;k++)if(list[k].geteng()>=80&&list[k].geteng()<90)ne2++;
	for(k=0;k<=last;k++)if(list[k].geteng()>=60&&list[k].geteng()<80)ne3++;
	for(k=0;k<=last;k++)if(list[k].geteng()<60)ne4++;
	for(k=0;k<=last;k++)if(list[k].getphy()>=90)np1++;
	for(k=0;k<=last;k++)if(list[k].getphy()>=80&&list[k].getphy()<90)np2++;
	for(k=0;k<=last;k++)if(list[k].getphy()>=60&&list[k].getphy()<80)np3++;
	for(k=0;k<=last;k++)if(list[k].getphy()<60)np4++;
	cout<<"成绩分段:"<<endl;
	cout<<"数学:"<<endl;
	cout<<"优:"<<nm1<<setw(10)<<"良:"<<nm2<<setw(10)<<"中:"<<nm3<<setw(10)<<"差:"<<nm4<<endl;
	cout<<"物理:"<<endl;
	cout<<"优:"<<np1<<setw(10)<<"良:"<<np2<<setw(10)<<"中:"<<np3<<setw(10)<<"差:"<<np4<<endl;
	cout<<"英语:"<<endl;
	cout<<"优:"<<ne1<<setw(10)<<"良:"<<ne2<<setw(10)<<"中:"<<ne3<<setw(10)<<"差:"<<ne4<<endl;
	ofstream ofile;
	ofile.open("D:\\成绩单.txt");
	ofile<<setw(10)<<"学号  "<<setw(10)<<"姓名"<<setw(12)<<"数学"<<setw(10)<<"英语"<<setw(10)<<"物理"<<setw(10)<<"总分 "<<endl;
	for(i=0;i<=last;i++)ofile<<setw(10)<<list[i].getid()<<setw(10)<<list[i].getname()<<setw(10)<<list[i].getmath()<<setw(10)<<list[i].geteng()<<setw(10)<<list[i].getphy()<<setw(10)<<list[i].getz()<<endl;
	ofile<<"数学平均分:"<<amath<<'\t'<<"英语平均分:"<<aeng<<'\t'<<"物理平均分:"<<aphy<<'\t'<<"总平均分:"<<asum<<endl;
	ofile<<"数学合格率:"<<rmath*100<<'%'<<'\t'<<"英语合格率:"<<reng*100<<'%'<<'\t'<<"物理合格率:"<<rphy*100<<'%'<<endl;
	ofile<<"数学标准差:"<<bmath<<'\t'<<"英语标准差:"<<beng<<'\t'<<"物理标准差:"<<bphy<<endl;
	ofile<<"成绩分段:"<<endl;
	ofile<<"数学:"<<endl;
	ofile<<"优:"<<nm1<<setw(10)<<"良:"<<nm2<<setw(10)<<"中:"<<nm3<<setw(10)<<"差:"<<nm4<<endl;
	ofile<<"物理:"<<endl;
	ofile<<"优:"<<np1<<setw(10)<<"良:"<<np2<<setw(10)<<"中:"<<np3<<setw(10)<<"差:"<<np4<<endl;
	ofile<<"英语:"<<endl;
	ofile<<"优:"<<ne1<<setw(10)<<"良:"<<ne2<<setw(10)<<"中:"<<ne3<<setw(10)<<"差:"<<ne4<<endl;
	ofile.close();
}
template <typename T>void student<T>::print(){
	int i;
	cout<<setw(10)<<"学号  "<<setw(10)<<"姓名"<<setw(12)<<" 数学"<<setw(10)<<"英语"<<setw(10)<<"物理"<<setw(10)<<"总分 "<<endl;
	for(i=0;i<=last;i++) list[i].show();
}
template <typename T>void student<T>::order(){
	int s[100],i,j,k;
	for(i=0;i<=last;i++)s[i]=list[i].getmath()+list[i].geteng()+list[i].getphy();
	for(i=1;i<=last;i++)
		for(j=0;j<=i-1;j++){
			if(s[i]>s[j]||s[i]==s[j]&&list[i].getmath()>list[j].getmath()||s[i]==s[j]&&list[i].getmath()==list[j].getmath()&&list[i].getphy()>list[j].getphy()||s[i]==s[j]&&list[i].getmath()==list[j].getmath()&&list[i].getphy()==list[j].getphy()&&list[i].geteng()>list[j].geteng()||s[i]==s[j]&&list[i].getmath()==list[j].getmath()&&list[i].getphy()==list[j].getphy()&&list[i].geteng()==list[j].geteng()&&list[i].getid()<list[j].getid()){
		        T temp;
				temp=list[i];
				for(k=i;k>=j+1;k--)list[k]=list[k-1];
				list[j]=temp;
				int m;
				m=s[i];
				for(k=i;k>=j+1;k--)s[k]=s[k-1];
				s[j]=m;
				break;
			}
		}
}//直接插入排序
template <typename T>void student<T>::f(){
	ofstream ofile;
	ofile.open("D:\\成绩单.txt");
	ofile<<setw(10)<<"学号  "<<setw(10)<<"姓名"<<setw(12)<<"数学"<<setw(10)<<"英语"<<setw(10)<<"物理"<<setw(10)<<"总分 "<<endl;
	int i;
	for(i=0;i<=last;i++)ofile<<setw(10)<<list[i].getid()<<setw(10)<<list[i].getname()<<setw(10)<<list[i].getmath()<<setw(10)<<list[i].geteng()<<setw(10)<<list[i].getphy()<<list[i].getz()<<endl;
   	ofile.close();
}
template <typename T>void student<T>::m(string s){
	int n,i;
	n=s.length();
	cout<<setw(10)<<"学号  "<<setw(10)<<"姓名"<<setw(12)<<" 数学"<<setw(10)<<"英语"<<setw(10)<<"物理"<<setw(10)<<"总分 "<<endl;
	for(i=0;i<=last;i++){
		int a,j,b=0;
		for(j=0;j<=n-2;j=j+2){
			string s1=s.substr(j,2);
			a=list[i].getname().find(s1);
			if(a<0&&a>(list[i].getname().length()-2))b++;
		}
		if(b<n/2)list[i].show();
	}
}
//lei2
class grade{
private:
	string id;
	string name;
	int math,eng,phy,z;
public:
	void in();
	void in1(string,string,int,int,int);	
	void change();
	void show();
	string getid(){return id;}
	string getname(){return name;}
	int getmath(){return math;}
	int geteng(){return eng;}
	int getphy(){return phy;}
	int getz(){return z;}

};
void grade::in(){
	cout<<"请依次输入学号、姓名、数学成绩、英语成绩、物理成绩(以空格相隔,输入完请按回车):"<<endl;
	cin>>id>>name>>math>>eng>>phy;
	while(id.length()!=11){
		cout<<"学号长度有误，请重新输入:"<<endl;
		cin>>id;
	}
	z=math+eng+phy;
}
void grade::in1(string i,string n,int m,int e,int p){
	id=i;name=n;math=m;eng=e;phy=p;z=m+e+p;
}
void grade::change(){
	cout<<"请依次输入修改后的数学成绩、英语成绩、物理成绩(以空格相隔,输入完请按回车):"<<endl;
	int m,e,p;
	cin>>m>>e>>p;
	math=m;eng=e;phy=p;
	z=m+e+p;
}
void grade::show(){
	cout<<setw(10)<<id<<setw(10)<<name<<setw(10)<<math<<setw(10)<<eng<<setw(10)<<phy<<setw(10)<<z<<endl;
}
//zhuhanshu
int main(){
	student<grade> stu;
	while(1){
		   cout<<"a  增加记录（输入）"<<endl<<"b  增加记录（由文件自动增加） "<<endl<<"c  删除记录"<<endl<<"d  成绩修改"<<endl<<"e  查找某学生成绩"<<endl<<"f  查找某课程某分数段内学生名单"<<endl<<"g  统计分析 平均分 合格率 标准差 成绩分段"<<endl<<"h  排序"<<endl<<"i  将信息写入文件"<<endl<<"j  查看成绩单"<<endl<<"k  模糊查询"<<endl;
           cout<<"请输入操作前的序号(不区分大小写),并回车:"<<endl;
		   char cho;
		   cin>>cho;
		   while(cho!='a'&&cho!='b'&&cho!='c'&&cho!='d'&&cho!='e'&&cho!='f'&&cho!='g'&&cho!='h'&&cho!='i'&&cho!='j'&&cho!='k'&&cho!='A'&&cho!='B'&&cho!='C'&&cho!='D'&&cho!='E'&&cho!='F'&&cho!='G'&&cho!='H'&&cho!='I'&&cho!='J'&&cho!='K'){
			   cout<<"输入错误，请重新输入:"<<endl;
			   cin>>cho;	
		   }
		   switch(cho){
		   case 'a':case 'A':{
			   char a;
			   do{
			   stu.insert();
			   cout<<"是否继续增加记录?  继续请输入Y，取消请输入N(不区分大小写):"<<endl;
			   cin>>a;
			   while(a!='Y'&&a!='y'&&a!='N'&&a!='n'){
				   cout<<"输入错误，请重新输入:"<<endl;
				   cin>>a;
			   }
		   }while(a=='Y'||a=='y');
		   }break;
		   case 'b':case 'B':stu.insert1();break;
		   case 'c':case 'C':stu.remove();break;
		   case 'd':case 'D':stu.change();break;
		   case 'e':case 'E':stu.findgrade();break;
		   case 'f':case 'F':stu.findlist();break;
		   case 'g':case 'G':stu.tongji();break;
		   case 'h':case 'H':stu.order();break;
		   case 'i':case 'I':stu.f();break;
		   case 'j':case 'J':stu.print();break;
		   case 'k':case 'K':{
			   	cout<<"请输入模糊姓名并回车:"<<endl;
                string s;
               	cin>>s;
				stu.m(s);
				cout<<"请选择操作,删除请输入a,修改请输入b(不区分大小写,输入完请回车):"<<endl;
				char x;
				cin>>x;
				while(x!='a'&&x!='A'&&x!='b'&&x!='B'){
		            cout<<"输入有误!请重新输入:"<<endl;
	            	cin>>x;
				}
				if(x=='a'||x=='A')stu.remove();
				if(x=='b'||x=='B')stu.change();
		   }break;
		   }
		cout<<endl<<endl;
	}
	return 0;
}
