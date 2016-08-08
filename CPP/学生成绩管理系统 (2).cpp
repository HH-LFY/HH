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
    printf("\n请输入学号:");
    scanf("%d",&st[i].id);
    fflush(stdin);
    printf("\n请输入姓名:");
    gets(st[i].name);
    printf("\n") ;
    printf("请输入年龄:");
    scanf("%d",&st[i].age);
    fflush(stdin);
    printf("\n请输入姓别:");
    gets(st[i].sex);
    fflush(stdin);
    printf("\n请输入班级:");
    scanf("%d",&st[i].clas);
    fflush(stdin);
    printf("\n请输入住宿:");
    scanf("%d",&st[i].department);
    fflush(stdin);
    printf("\n是否继续输入另外一个学生信息?(y/n)");
    fflush(stdin);
    a=getchar();
    i++;
}while(a=='y' && i<=50);
}

void xianshi()//显示
{
	 int j;
	 printf("学号\t姓名\t年龄\t性别\t班级\t住宿\n");
	 for(j=0;j<i;j++)
	 printf("%d\t%s\t%d\t%s\t%d\t%d\n",st[j].id,st[j].name,st[j].age,st[j].sex,st[j].clas,st[j].department);
}

void paixu() //排序
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

void chazhao()//查找
{
	int m;
	char name[50],b;
	do
	{
		printf("\n请输入想查找的学生学号:");
		fflush(stdin);
		gets(name);
		for(m=0;m<i;m++)
		{
			if(strcmp(name,st[m].name)==0)
			{
			printf("\n\t找到了\n",m+1);
			break;
			}
		}
		if(m>=50)
		printf("\n\t没有找到\n");
		else
		{
			printf("学号\t姓名\t年龄\t性别\t班级\t住宿\n");
			printf("%d\t%s\t%d\t%s\t%d\t%d\n",st[m].id,st[m].name,st[m].age,st[m].sex,st[m].clas,st[m].department);
		}
		printf("\n是否查找另一个学生的信息?(y/n)");
		fflush(stdin);
		b=getchar();
	}while(b=='y');
}

void shanchu()//删除
{
	char name[20],c;
	int a,b;
	do
	{
		printf("\n请输入要删除的学生姓名:\n");
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
			printf("\t没有找到\n");
			else
				{
				i--;
				xianshi();
				}
			printf("\n是否继续删除另一个学生信息?(y/n) ");
			fflush(stdin);
			c=getchar();
	}while(c=='y');
}

void zengjia()//增加
{
	shuru();
	paixu();
}

void main() //主函数
{
	int number;
	do{
		system("cls");
		printf("\n");
		printf("\n");
		printf("                          在校生信息查询系统\n\n");
		printf("                  1.输入信息\n");
		printf("                  2.显示信息\n");
		printf("                  3.查找信息\n");                                         
		printf("                  4.删除信息\n");             
		printf("                  5.增加信息\n");                                                     
		printf("                  6.排序信息\n");                                         
		printf("                  7.退出系统\n");                            
		printf("\n");                                                            
	
		printf("                          请输入功能选项：");
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
