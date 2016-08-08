
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<conio.h>
#define N 30
#define M 3
typedef struct student
{	char number[10];
	char name[20];
	float score[M];
	float aver;
}STU;
STU stu[N];
int n;

void inputscore(void);
void savescore(void);
void avergescore(void);
void modifyscore(void);
void lookscore(void);
void searchscore(void);
void statistic(void);
void add(void);
void modify(void);
void delscore(void);
void menu(void);
void main()
{	short int flag=0;
	menu();
	do
	{	flag=1;
		switch(getch())
		{	case '1' : inputscore();break;    /*输入成绩*/
			case '2' : lookscore();break;	/*查看成绩*/
			case '3' : searchscore();break;	/*查找成绩*/
			case '4' : statistic();break;	/*成绩统计*/
			case '5' : modify();break;		/*修改成绩*/
			case '6' : add();break;			/*添加成绩*/
			case '7' : delscore();break;	/*删除成绩*/
			case '8' : savescore();break;	/*保存成绩*/
			case '9' :exit(0);				/*退出程序*/
			default : printf("输入有误\n");
		}
		printf("按任意键继续\n");
		getch();
		menu();
	}while (flag==1);
}

		


void menu(void)
{
	system("cls");
	printf("\n");
	printf("*********欢迎进入学生成绩管理系统**************\n");
	printf("                 菜单                          \n");
	printf("输入成绩-------------------------------------1\n");
	printf("查看成绩及成绩排序---------------------------2\n");
	printf("查询学生成绩---------------------------------3\n");
	printf("成绩统计-------------------------------------4\n");
	printf("修改成绩-------------------------------------5\n");
	printf("添加成绩-------------------------------------6\n");
printf("删除成绩-------------------------------------7\n");
	printf("保存成绩-------------------------------------8\n");
	printf("退出系统-------------------------------------9\n");
	printf("**********************************************\n");
	printf("请输入您的选择\n");
	
}






/***************输入各个同学的学生信息******************************/
void inputscore(void)
{	int i,j;
	
	system("cls");
	printf("请输入学生总数：\n");
	scanf("%d",&n);
	printf("提示：*输入学号时请输入位数为8位的数字*\n");		/*因二维表上下需对正故有此要求*/
	for(i=0;i<n;i++)
	{	printf("请输入学生%d的学号 姓名:\n",i+1);
		scanf("%s%s",stu[i].number,stu[i].name);
		printf("请输入学生成绩:\n");
		printf("数学\t英语\t计算机\n");
		for(j=0;j<M;j++)
			scanf("%f",&stu[i].score[j]);
	}
	printf("成功输入\n");
}
/*****************计算各个同学的平均分*****************************/
void avergescore(void)
{	int i,j;
	
	for(i=0;i<n;i++)
	{	stu[i].aver=0;
		for(j=0;j<M;j++)
		{	
			stu[i].aver+=stu[i].score[j];
		}
		stu[i].aver=stu[i].aver/M;
	}
}
/************查看学生成绩及根据平均分对学生进行排序*********************/
void lookscore(void)
{	int i,j,k;
	
	STU t;
	avergescore();
	system("cls");
	
	for(i=0;i<n-1;i++)
	{	for(k=i,j=i+1;j<n;j++)
			if(stu[j].aver>stu[k].aver)
				k=j;
			if(k!=j)
			{	t=stu[k];
				stu[k]=stu[i];
				stu[i]=t;
			}
	}
	printf("名次\t学号\t\t姓名\t数学\t英语\t计算机\t平均分\n");
	for(i=0;i<n;i++)
	{	printf("%d\t%s\t%s\t",i+1,stu[i].number,stu[i].name);
		for(j=0;j<M;j++)
			printf("%4.2f\t",stu[i].score[j]);
		printf("%4.2f",stu[i].aver);
		printf("\n");
	}
}
/*****************通过输入学号查找学生成绩***************************/
void searchscore(void)
{	char a[10];
	int i,j;
	system("cls");
	printf("请输入需查询的学生学号\n");
	scanf("%s",a);
	for(i=0;i<n;i++)
	{	if(strcmp(a,stu[i].number)==0)
		{	printf("名次\t学号\t\t姓名\t数学\t英语\t计算机\t平均分\n");
			printf("%d\t%s\t%s\t",i+1,stu[i].number,stu[i].name);	
			for(j=0;j<M;j++)
			printf("%4.2f\t",stu[i].score[j]);
			printf("%4.2f",stu[i].aver);
			printf("\n");
			break;							/*找到该学生成绩信息后跳出for循环*/
}		
		else
			printf("未找到该学生信息\n");
	}

}
/*******统计学生成绩信息，平均分及格率，优秀率，成绩方差****************/
void statistic(void)
{	STU *p=stu;
	int i,j;
	float count=0.0,sum=0.0;
	system("cls");
	for(i=0;i<n;i++)
	{	sum+=(p+i)->aver;}
	printf("该班级平均分为%4.2f\n",sum/n);		/*平均分计算*/
	for(i=0;i<n;i++)
	{	if((p+i)->aver>=60)
			count++;
	}
	printf("该班级及格率为%4.2f%%\n",count/n*100);	/*及格率计算*/
	count=0.0;
	for(i=0;i<n;i++)
	{	if((p+i)->aver>=90)
		count++;
	}
	printf("该班级优秀率为%4.2f%%\n",count/n*100);	/*优秀率计算*/
	for(i=0;i<n;i++)
	{	for(j=0;j<M;j++)
		{	sum=((p+i)->score[j]-(p+i)->aver)*((p+i)->score[j]-(p+i)->aver);
		}
		sum=sum/n;
		printf("学生%s的成绩方差为%4.2f\n",(p+i)->name,sum);	/*方差计算*/
	}
	printf("平均分低于60的学生名单\n");
	for(i=0;i<n;i++)
	{	
			if(stu[i].aver<60)
			printf("%s\n",stu[i].name);
	}														/*统计不及格学生名单*/

}
/***************修改学生成绩*****************/
void modify(void)
{	char a[10];
	int i,j;
	system("cls");
	printf("请输入需要修改成绩的学生学号\n");
	scanf("%s",a);
	for(i=0;i<n;i++)
	{	if(strcmp(a,stu[i].number)==0)
		{	printf("名次\t学号\t\t姓名\t数学\t英语\t计算机\t平均分\n");
			printf("%d\t%s\t%s\t",i+1,stu[i].number,stu[i].name);	
			for(j=0;j<M;j++)
			printf("%4.2f\t",stu[i].score[j]);
			printf("%4.2f",stu[i].aver);
			printf("\n");
			printf("请重新输入该学生的学号 姓名:\n");
			scanf("%s%s",stu[i].number,stu[i].name);
			printf("请重新输入学生成绩:\n");
			printf("数学\t英语\t计算机\n");
			for(j=0;j<M;j++)
				scanf("%f",&stu[i].score[j]);/*找到该学生成绩后进行修改，跳出for循环*/
			printf("修改成功\n");
			break;
		}
	else
		printf("未找到该学生信息\n");
	}
	
}
/*****************添加学生成绩********************/
void add(void)
{	int a,i,j;
	system("cls");
	printf("请输入新增加的学生人数：\n");
	scanf("%d",&a);
	n=n+a;
	for(i=n-a;i<n;i++)
	{	printf("请输入学生%d的学号 姓名:\n",i+1);
		scanf("%s%s",stu[i].number,stu[i].name);
		printf("请输入学生成绩:\n");
		printf("数学\t英语\t计算机\n");
		for(j=0;j<M;j++)
			scanf("%f",&stu[i].score[j]);
		printf("添加成功\n");
	}
}
/*******************删除学生成绩*************************/
void delscore(void)
{	int i,j,c;
	char m,a[10];
	system("cls");
	printf("请输入学生学号\n");
	scanf("%s",a);
	for(i=0;i<n;i++)
	{	if(strcmp(a,stu[i].number)==0)
		{	printf("名次\t学号\t\t姓名\t数学\t英语\t计算机\t平均分\n");
			printf("%d\t%s\t%s\t",i+1,stu[i].number,stu[i].name);	
			for(j=0;j<M;j++)
			printf("%4.2f\t",stu[i].score[j]);
			printf("%4.2f",stu[i].aver);
			printf("\n");
			c=i;
			break;
		}
		else
			printf("未找到该学生信息\n");
	}
		printf("是否删除该学生成绩(y/n)\n");
		scanf("%s",&m);
		if(m=='y')
		{	
			for(i=c;i<n-1;i++)
				stu[i]=stu[i+1];			/*结构体整体赋值将后一位学生成绩信息拷贝进入前一位学生信息的存储位置*/
				n=n-1;						/*删除该学生信息后学生总数减一*/
				printf("删除成绩成功\n");
		}
		else
			printf("删除成绩失败\n");
}
/******************保存学生成绩************************/
void savescore(void)
{	FILE *fp;
	int i,flag=1;
	char m;
	system("cls");
	puts("是否保存学生成绩(y/n)");
	scanf("%s",&m);
	if(m=='y')
	{	if((fp=fopen("score.dat","wb"))==NULL)
		{	printf("文件打开失败\n");
			return;
		}
		for(i=0;i<n;i++)
			if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)
			{	printf("保存失败\n");
				flag=0;
			}
		if(flag==1)
			printf("保存成功!\n");
		fclose(fp);
	}
	else
		return;
}

