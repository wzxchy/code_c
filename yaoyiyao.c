#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
struct studentinfo /*ѧ����Ϣ�Ľṹ��*/
{
    char sNo[14];/*ѧ��*/
    char sName[20];/*ѧ��������*/
} st[100];
int n_student=0;
int n_ignore=0;//����ѧ������
int a_ignore[100];//����ѧ�����
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
    printf("��ѡ��༶(����1,��2,3...)\n");
    scanf("%d",&iclass);
    sprintf(filename,"D:\\class%d.txt",iclass);
    printf("%s\n",filename);
    fp=fopen(filename,"r");
    while(fp==NULL)
    {
        printf("�༶�����ڣ�������ѡ��༶(����1,��2,3...)\n");
        scanf("%d",&iclass);
        sprintf(filename,"D:\\class%d.txt",iclass);
        fp=fopen(filename,"r");
    }
    while(~fscanf(fp,"%s %s",st[n_student].sNo,st[n_student].sName))
    {
        n_student++;
    }
    printf("�������£�\n");
    int i;
    for(i=0; i<n_student; i++)
    {
        printf("%s %s\n",st[i].sNo,st[i].sName);
    }
    while(1)
    {
        printf("\n\n************************************\n");
        printf("1. ��ȡһ��ѧ��\n");
        printf("2. ��ȡָ������ѧ��\n");
        printf("3. ��ָ�������ȡѧ��\n");
        printf("4. ���Ӻ���ѧ��\n");
        printf("5. �˳�\n");
        printf("��ѡ����������������Ų��س���\n");
        printf("************************************\n\n\n");

        /*�������������*/
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
                rn=rand()%n_student; /*����һ�������*/
            }
            while(check_ignore(rn));
            printf("���е�ѧ��Ϊ��%s  %s\n",st[rn].sNo,st[rn].sName);
            break;
        }
        case 2:
        {
            printf("������ѧ������");
            int n_st;
            scanf("%d",&n_st);
            int flag[100];
            memset(flag,0,sizeof(flag));//�ж��Ƿ��ظ�ѡȡ
            printf("���е�ѧ��Ϊ��\n");
            int i;
            for(i=0; i<n_st; i++)
            {
                int rn;
                do
                {
                    rn=rand()%n_student; /*����һ�������*/
                }
                while(check_ignore(rn) || flag[rn]==1);
                flag[rn]=1;
                printf("%s  %s\n",st[rn].sNo,st[rn].sName);
            }
            break;
        }
        case 3:
        {
            printf("���������䣺\n");
            int l,r;
            scanf("%d %d",&l,&r);
            int rn;
            do
            {
                rn=rand()%n_student; /*����һ�������*/
            }
            while(check_ignore(rn) || rn<l || rn>r);
            printf("���е�ѧ��Ϊ��%s  %s\n",st[rn].sNo,st[rn].sName);
            break;
        }
        case 4:
        {
            printf("���������ѧ����ѧ�ţ�\n");
            char sNo[30];
            scanf("%s",sNo);
            int flag=0;
            int i;
            for(i=0;i<n_student;i++)
            {
                if(strcmp(sNo,st[i].sNo)==0)
                {
                    a_ignore[n_ignore++]=i;
                    printf("%s �ѱ�����",st[i].sName);
                    flag=1;
                    break;
                }
            }
            if(flag==0)  printf("�����ڸ�ѧ��\n");
            break;
        }
        case 5:
        {
            f_exit=1;
            break;
        }
        default:
            printf("�����ڸò���\n");
        }
        if(f_exit==1)  break;
    }
    return 0;

}