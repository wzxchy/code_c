#include<fstream>
#include<iostream>
using namespace std;
int main(){
    ifstream ifile;
	ifile.open("d:\\myfile.txt");
    char ch;
	char a[1000];
	int nline=0,nword=0,nch=0;
	int isword=0;
	do
	{
		ch=ifile.get();
		if(ch=='\n') nline++;
		if(ch!=' '&&ch!='\t'&&ch!='\n'&&ch!=EOF)
		{
			if(! isword) nword++;
			nch++;
			isword=1;
		}
		else isword=0;
	} while(ch!=EOF);
	cout<<"行数："<<nline<<endl;
	cout<<"单词数："<<nword<<endl;
	cout<<"字符数："<<nch<<endl;
	ifile.close();
	return 0;
}
