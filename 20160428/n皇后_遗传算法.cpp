#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<time.h>
#include<stdlib.h>
using namespace std;
const int maxn=105;//最大皇后个数
const int m=18;//初始基因个数
int gene[m][maxn];//基因序列
int gene2[m][maxn];
int index[m][maxn];
int index2[maxn];
double adapt[m];
double accu_possi[m];
double sum_adapt;
double x2[maxn*maxn/2];
int n;//n皇后
int cnt;
int max_adapt;
void init_gene()
{
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            do
            {
                gene[i][j]=rand()%n;
                for(k=0;k<j;k++)
                {
                    if(gene[i][j]==gene[i][k])   break;
                }
            }while(k<j);
        }
    }
}
bool cal_possi()
{
    int i,j,k;
    sum_adapt=0;
    for(i=0;i<m;i++)
    {
        int count=0;
        for(j=0;j<n;j++)
        { 
            for(k=j+1;k<n;k++)
            {
                int t1=j-k;
                int t2=gene[i][j]-gene[i][k];
                if(t1==t2||t1==-t2)   count++;
            }
        }
        if(count==0)
        {
            for(j=0;j<n;j++)  printf("%d  ",gene[i][j]);
            printf("\n");
            return 1;
        }
        else adapt[i]=x2[count];

        sum_adapt+=adapt[i];
    }
    //////////////////////////////////////////
    accu_possi[0]=adapt[0]/sum_adapt;
    for(i=1;i<m;i++)
    {
        accu_possi[i]=accu_possi[i-1]+adapt[i]/sum_adapt;
    }
    return 0;
}
int select()
{
    int x=rand()%10000;
    double y=x/10000.0;
    int i;
    for(i=0;i<m;i++)
    {
        if(y<=accu_possi[i])   return i;
    }
}
void mating(int a[],int b[],int c[])
{
    int x=rand()%n;
    int y=rand()%n;
    //cout<<x<<"  "<<y<<"  "<<adapt[x]/sum_adapt<<"  "<<adapt[y]/sum_adapt<<endl;
    if(x>y)   swap(x,y);
    int i,j;
	for(i=x;i<=y;i++)
	{
		if(c[i]==b[i])  continue;
		int temp=index2[b[i]];
		c[temp]=c[i];
		index2[c[i]]=temp;
		c[i]=b[i];
		index2[c[i]]=i;
	}

}
void variation(int a[])
{
    int x=rand()%n;
    int y=rand()%n;
    swap(a[x],a[y]);	
}
void cal_next_generation()
{
    int i,j;
    for(i=0;i<m;i++)
    {
        int x=select();
        int y=select();
		memcpy(gene2[i],gene[x],sizeof(gene2[i]));
		memcpy(index2,index[x],sizeof(index2));
		mating(gene[x],gene[y],gene2[i]);
        variation(gene2[i]);
    }
    for(i=0;i<m;i++)
    {
        //for(j=0;j<n;j++)  gene[i][j]=gene2[i][j];
        memcpy(gene[i],gene2[i],sizeof(gene[i]));
    }

}
int main()
{
    
    srand(time(NULL));
    /////////////////////////
	int i,j;
	int temp=maxn*maxn/2;
	for(i=1;i<210;i++)   x2[i]=1.0/(i*i*i*i);
	for(i=250;i<temp;i++)  x2[i]=0;
	//for(i=200;i<400;i++)cout<<x2[i]<<endl;
	//////////////////////////////
    scanf("%d",&n);
	clock_t cBegin = clock();
	max_adapt=n*(n-1)/2;

    init_gene();
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			index[i][gene[i][j]]=j;
		}
	}
    while(cal_possi()==0)
    {
        cal_next_generation();
		for(i=0;i<m;i++)
		{
		    for(j=0;j<n;j++)
			{
			    index[i][gene[i][j]]=j;
			}
		}
    }

    //////////////////////
    clock_t cEnd = clock();
    printf("execution time: %d ms\n", (cEnd - cBegin)*1000 / CLOCKS_PER_SEC);
    return 0;
}

/*
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)   printf("%d  ",gene[i][j]);
        printf("\n");
    }
    cal_next_generation();
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)  printf("%d  ",gene[i][j]);
        printf("\n");
    }
*/

