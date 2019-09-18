#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
struct studentinfo /*学生信息的结构体*/
{
    char sNo[14];/*学号*/
    char sName[20];/*学生的姓名*/
} st[100];
int n_student=0;
int n_ignore=0;//忽略学生个数
int a_ignore[100];//忽略学生序号
bool check_ignore(int x)
{
    int i;
    for(i=0; i<n_ignore; i++)
    {
        if(a_ignore[i]==x)  return true;
    }
    return false;
}
int main()
{
    int iclass;
    char filename[30];
    FILE *fp=NULL;
    printf("请选择班级(输入1,或2,3...)\n");
    scanf("%d",&iclass);
    sprintf(filename,"D:\\class%d.txt",iclass);
    printf("%s\n",filename);
    fp=fopen(filename,"r");
    while(fp==NULL)
    {
        printf("班级不存在，请重新选择班级(输入1,或2,3...)\n");
        scanf("%d",&iclass);
        sprintf(filename,"D:\\class%d.txt",iclass);
        fp=fopen(filename,"r");
    }
    while(~fscanf(fp,"%s %s",st[n_student].sNo,st[n_student].sName))
    {
        n_student++;
    }
    printf("名单如下：\n");
    int i;
    for(i=0; i<n_student; i++)
    {
        printf("%s %s\n",st[i].sNo,st[i].sName);
    }
    while(1)
    {
        printf("\n\n************************************\n");
        printf("1. 抽取一个学生\n");
        printf("2. 抽取指定数量学生\n");
        printf("3. 在指定区间抽取学生\n");
        printf("4. 增加忽略学生\n");
        printf("5. 退出\n");
        printf("请选择操作，输入操作序号并回车：\n");
        printf("************************************\n\n\n");

        /*设置随机数种子*/
        srand((unsigned)time(NULL));

        int f_exit=0;
        int i_ope;
        scanf("%d",&i_ope);
        switch(i_ope)
        {
        case 1:
        {
            int rn;
            do
            {
                rn=rand()%n_student; /*产生一个随机数*/
            }
            while(check_ignore(rn));
            printf("抽中的学生为：%s  %s\n",st[rn].sNo,st[rn].sName);
            break;
        }
        case 2:
        {
            printf("请输入学生数量");
            int n_st;
            scanf("%d",&n_st);
            int flag[100];
            memset(flag,0,sizeof(flag));//判断是否重复选取
            printf("抽中的学生为：\n");
            int i;
            for(i=0; i<n_st; i++)
            {
                int rn;
                do
                {
                    rn=rand()%n_student; /*产生一个随机数*/
                }
                while(check_ignore(rn) || flag[rn]==1);
                flag[rn]=1;
                printf("%s  %s\n",st[rn].sNo,st[rn].sName);
            }
            break;
        }
        case 3:
        {
            printf("请输入区间：\n");
            int l,r;
            scanf("%d %d",&l,&r);
            int rn;
            do
            {
                rn=rand()%n_student; /*产生一个随机数*/
            }
            while(check_ignore(rn) || rn<l || rn>r);
            printf("抽中的学生为：%s  %s\n",st[rn].sNo,st[rn].sName);
            break;
        }
        case 4:
        {
            printf("请输入忽略学生的学号：\n");
            char sNo[30];
            scanf("%s",sNo);
            int flag=0;
            int i;
            for(i=0;i<n_student;i++)
            {
                if(strcmp(sNo,st[i].sNo)==0)
                {
                    a_ignore[n_ignore++]=i;
                    printf("%s 已被忽略",st[i].sName);
                    flag=1;
                    break;
                }
            }
            if(flag==0)  printf("不存在该学生\n");
            break;
        }
        case 5:
        {
            f_exit=1;
            break;
        }
        default:
            printf("不存在该操作\n");
        }
        if(f_exit==1)  break;
    }
    return 0;

}
