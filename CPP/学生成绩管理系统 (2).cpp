#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct student
{
    int id;
    char name[10];
    int age;
    char sex[10];
    int clas;
    int department;
}st[50];
int i=0;
void shuru() {
char a;
do{
    printf("\n������ѧ��:");
    scanf("%d",&st[i].id);
    fflush(stdin);
    printf("\n����������:");
    gets(st[i].name);
    printf("\n") ;
    printf("����������:");
    scanf("%d",&st[i].age);
    fflush(stdin);
    printf("\n�������ձ�:");
    gets(st[i].sex);
    fflush(stdin);
    printf("\n������༶:");
    scanf("%d",&st[i].clas);
    fflush(stdin);
    printf("\n������ס��:");
    scanf("%d",&st[i].department);
    fflush(stdin);
    printf("\n�Ƿ������������һ��ѧ����Ϣ?(y/n)");
    fflush(stdin);
    a=getchar();
    i++;
}while(a=='y' && i<=50);
}

void xianshi()//��ʾ
{
	 int j;
	 printf("ѧ��\t����\t����\t�Ա�\t�༶\tס��\n");
	 for(j=0;j<i;j++)
	 printf("%d\t%s\t%d\t%s\t%d\t%d\n",st[j].id,st[j].name,st[j].age,st[j].sex,st[j].clas,st[j].department);
}

void paixu() //����
{
	int j,k;
	int t;
	for(j=0;j<i;j++)
	{
		for(k=0;k<i-1-j;k++)
		{
			if(st[k].age<st[k+1].age)
			{
				t=st[k].age;
				st[k].age=st[k+1].age;
				st[k+1].age=t;
			}
		}
	}
xianshi();
}

void chazhao()//����
{
	int m;
	char name[50],b;
	do
	{
		printf("\n����������ҵ�ѧ��ѧ��:");
		fflush(stdin);
		gets(name);
		for(m=0;m<i;m++)
		{
			if(strcmp(name,st[m].name)==0)
			{
			printf("\n\t�ҵ���\n",m+1);
			break;
			}
		}
		if(m>=50)
		printf("\n\tû���ҵ�\n");
		else
		{
			printf("ѧ��\t����\t����\t�Ա�\t�༶\tס��\n");
			printf("%d\t%s\t%d\t%s\t%d\t%d\n",st[m].id,st[m].name,st[m].age,st[m].sex,st[m].clas,st[m].department);
		}
		printf("\n�Ƿ������һ��ѧ������Ϣ?(y/n)");
		fflush(stdin);
		b=getchar();
	}while(b=='y');
}

void shanchu()//ɾ��
{
	char name[20],c;
	int a,b;
	do
	{
		printf("\n������Ҫɾ����ѧ������:\n");
		fflush(stdin);
		gets(name);
		for(a=0;a<i;a++)
		{
			if(strcmp(name,st[a].name)==0)
			break;
		}
		for(b=a;b<i;b++) 
			st[b]=st[b+1];
			if(a>i)
			printf("\tû���ҵ�\n");
			else
				{
				i--;
				xianshi();
				}
			printf("\n�Ƿ����ɾ����һ��ѧ����Ϣ?(y/n) ");
			fflush(stdin);
			c=getchar();
	}while(c=='y');
}

void zengjia()//����
{
	shuru();
	paixu();
}

void main() //������
{
	int number;
	do{
		system("cls");
		printf("\n");
		printf("\n");
		printf("                          ��У����Ϣ��ѯϵͳ\n\n");
		printf("                  1.������Ϣ\n");
		printf("                  2.��ʾ��Ϣ\n");
		printf("                  3.������Ϣ\n");                                         
		printf("                  4.ɾ����Ϣ\n");             
		printf("                  5.������Ϣ\n");                                                     
		printf("                  6.������Ϣ\n");                                         
		printf("                  7.�˳�ϵͳ\n");                            
		printf("\n");                                                            
	
		printf("                          �����빦��ѡ�");
		scanf("%d",&number);
		switch(number)
			{
			case 1:
			shuru(); break;
			case 2:
			xianshi(); break;
			case 3:
			chazhao(); break;
			case 4:
			shanchu(); break;
			case 5:
			zengjia(); break;
			case 6:
			paixu(); break;
			case 7:
			break;
			}
		getch();
	}while(number!=7);
}
