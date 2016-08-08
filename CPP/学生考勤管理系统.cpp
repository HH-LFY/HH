#include<cstdio>
#include<iostream>
#include<malloc.h>
#include<cstring>
#include<iomanip>
#define NULL 0
#define guding 10
#define LEN sizeof(struct student)
using namespace std;
int student_num;
FILE *fp1;
struct xueke
{char xueke_name[50];
	int people_num;
};

struct student
{	char name[50];
	long time;
	int lesson_time;
	char lesson_name[50];
	int chidao_num;
	int zaotui_num;
	int qingjia_num;
	int kuangke_num;
	struct student *next;
};
void chaxun(struct student *head)
{	int i;
	char chaxun_name[50];
	cout<<"请输入要查询的人名：";
    cin>>chaxun_name;
	struct student *p;
	if(head==NULL)
		cout<<"联系人为空";
	p=head;
	for(i=0;i<student_num;i++)
	{if(strcmp(chaxun_name,p->name)==0)
	{cout<<"缺课时间:"<<p->time<<"     学生姓名:"<<p->name<<"      课程名称:"<<p->lesson_name<<"      节次:"<<p->lesson_time<<endl
	        <<"迟到次数:"<<p->chidao_num<<"            早退次数:"<<p->zaotui_num<<"           请假次数:"<<p->qingjia_num<<"     旷课次数:"<<p->kuangke_num<<endl;
	}	
	p=p->next; }
	
}
struct student *xiugai(struct student *head)
{char xiugai_name[50];
	char xiugai_xueke_name[50];
	int k;
	cout<<"请输入要修改的学生姓名与学科名称【格式:学生姓名(空格)学科名称】：";
	cin>>xiugai_name>>xiugai_xueke_name;
	struct student *p1,*p2; 
	p2=(struct student *)malloc(LEN);
	p1=head;
	if(head==NULL)
	{cout<<"没有学生信息\n";
		return head; }
	while((strcmp(xiugai_name,p1->name)!=0||strcmp(xiugai_xueke_name,p1->lesson_name)!=0)&&(p1->next!=NULL))
		p1=p1->next;
    if(strcmp(xiugai_name,p1->name)==0&&strcmp(xiugai_xueke_name,p1->lesson_name)==0)
	{   cout<<"====================================  修改信息 =================================\n"; 
		cout<<"                                   1-修改缺课时间             \n";
		cout<<"                                   2-修改学生姓名             \n";
		cout<<"                                   3-修改课程名称             \n";
		cout<<"                                   4-修改第几节缺课           \n";
		cout<<"                                   5-修改迟到次数             \n";
		cout<<"                                   6-修改早退次数             \n";
		cout<<"                                   7-修改请假次数             \n";
		cout<<"                                   8-修改旷课次数             \n\n";
		cout<<"================================================================================\n";
		cin>>k;
		switch(k)
		{case 1:
			cout<<"请输入新的缺课时间:";
			cin>>p1->time;
			break;
		case 2:
			cout<<"请输入新的学生姓名:";
			cin>>p1->name;
			break;
		case 3:
			cout<<"请输入新的课程名称:";
			cin>>p1->lesson_name;
			break;
		case 4:
			cout<<"请输入新的缺课节次:";
			cin>>p1->lesson_time;
			break;
		case 5:
			cout<<"请输入新的迟到次数:";
			cin>>p1->chidao_num;
			break;
		case 6:
			cout<<"请输入新的早退次数:";
			cin>>p1->zaotui_num;
			break;
		case 7:
			cout<<"请输入新的请假次数:";
			cin>>p1->qingjia_num;
			break;
		case 8:
			cout<<"请输入新的旷课次数:";
			cin>>p1->kuangke_num;
			break; }
	}
	return head;
}
struct student *creat()
{
	int i,b;
		struct student *head,*p1,*p2;      
		cout<<"请输入要建立资料的学生人数：";
		cin>>b;
		head=p2=NULL;
		p1=(struct student *)malloc(LEN);
		cout<<"【输入格式：缺课时间(空格)学生姓名(空格)课程名称(空格)第几节(空格)迟到次数(空格)早退次数(空格)请假次数(空格)旷课次数】\n";
		cout<<"请输入第1名学生信息:";
	    cin>>p1->time>>p1->name>>p1->lesson_name>>p1->lesson_time>>p1->chidao_num>>p1->zaotui_num>>p1->qingjia_num>>p1->kuangke_num;
		head=p1;
		p2=p1;
		student_num+=1;
		for(i=1;i<b;i++)
		{
			p1=(struct student*)malloc(LEN);
			cout<<"请输入第"<<i+1<<"名学生信息:";
            cin>>p1->time>>p1->name>>p1->lesson_name>>p1->lesson_time>>p1->chidao_num>>p1->zaotui_num>>p1->qingjia_num>>p1->kuangke_num;
			p2->next=p1;
			p2=p1;
			student_num+=1;
		}
      p2->next=NULL;      
      return head;
}
void print(struct student *head)
{struct student *p;
	p=head;
	if(p==NULL)
		cout<<"没有学生信息\n";
	while(p!=NULL)	
	{   cout<<"缺课时间:"<<p->time<<"     学生姓名:"<<setw(10)<<p->name<<"      课程名称:"<<p->lesson_name<<"      节次:"<<p->lesson_time<<endl
	        <<"迟到次数:"<<p->chidao_num<<"            早退次数:"<<p->zaotui_num<<"           请假次数:"<<p->qingjia_num<<"     旷课次数:"<<p->kuangke_num<<endl;
		p=p->next;}	
}
struct student *tongji_lesson(struct student *head)
{	struct student *p1,*p2,*p3;
	char lesson[50];
	long look_time1,look_time2;
	int xunhuan_num=0;
	p3=(struct student *)malloc(LEN);
	if(head==NULL)
	{cout<<"没有学生信息";
		return(head); }
	p1=head;
	p2=p1->next;
	while(xunhuan_num<student_num)
	{while(p2!=NULL)
		{
			if(p2->kuangke_num>p1->kuangke_num)
			{
				p3->chidao_num=p2->chidao_num;
				p3->kuangke_num=p2->kuangke_num;
				p3->qingjia_num=p2->qingjia_num;
				p3->zaotui_num=p2->zaotui_num;
				p3->lesson_time=p2->lesson_time;
				p3->time=p2->time;
				strcpy(p3->lesson_name,p2->lesson_name);
				strcpy(p3->name,p2->name);

				p2->chidao_num=p1->chidao_num;
				p2->kuangke_num=p1->kuangke_num;
				p2->qingjia_num=p1->qingjia_num;
				p2->zaotui_num=p1->zaotui_num;
				p2->lesson_time=p1->lesson_time;
				p2->time=p1->time;
				strcpy(p2->lesson_name,p1->lesson_name);
				strcpy(p2->name,p1->name);

				p1->chidao_num=p3->chidao_num;
				p1->kuangke_num=p3->kuangke_num;
				p1->qingjia_num=p3->qingjia_num;
				p1->zaotui_num=p3->zaotui_num;
			    p1->lesson_time=p3->lesson_time;
				p1->time=p3->time;
				strcpy(p1->lesson_name,p3->lesson_name);
				strcpy(p1->name,p3->name);
			}
			p1=p2;
			p2=p2->next;
		}
		p1=head;
		p2=p1->next;
		xunhuan_num++;
	}
	cout<<"请输入要查看的学科名称：";
	cin>>lesson;
	cout<<"请输入要查看的时间范围【输入格式:时间(空格)时间】";
	cin>>look_time1>>look_time2;
	p1=head;   
	while(p1!=NULL)
	{if(strcmp(lesson,p1->lesson_name)==0&&look_time1<=p1->time&&p1->time<=look_time2)
			cout<<"学生姓名:"<<p1->name<<"     旷课次数:"<<p1->kuangke_num<<endl;
		p1=p1->next; }
	return head;
}
struct student *tongji_student(struct student *head)
{    struct xueke a[10];
	int n,i,j,zhongjian;
	struct student *p1;
	char zhongjian_name[50];
	long look_time1,look_time2;
	if(head==NULL)
	{cout<<"没有学生信息\n";
	return head; 
	}
	cout<<"请输入一共的学科数：";
	cin>>n;
	for(i=0;i<n;i++)
	{cout<<"请输入第"<<i+1<<"个学科名称：";
	cin>>a[i].xueke_name;
	a[i].people_num=0; 
	}
	cout<<"请输入要查看的时间范围由小到大【输入格式:时间(空格)时间】";
	cin>>look_time1>>look_time2;
	p1=head;
	for(i=0;i<n;i++)
	{while(p1!=NULL&&look_time1<=p1->time&&p1->time<=look_time2)
		{if(a[i].xueke_name==p1->lesson_name)
			a[i].people_num+=p1->kuangke_num;
	        p1=p1->next;}
		p1=head; 
	}
 	for(j=0;j<n-1;j++)                                                 
	for(i=0;i<n-1-j;i++)
		{if(a[i].people_num<a[i+1].people_num)
			{	zhongjian=a[i+1].people_num;
				a[i+1].people_num=a[i].people_num;
				a[i].people_num=zhongjian;
				strcpy(zhongjian_name,a[i+1].xueke_name);
				strcpy(a[i+1].xueke_name,a[i].xueke_name);
				strcpy(a[i].xueke_name,zhongjian_name);}
		else if(a[i].people_num==a[i+1].people_num&&strcmp(a[i].xueke_name,a[i+1].xueke_name)>0)
		{       zhongjian=a[i+1].people_num;
				a[i+1].people_num=a[i].people_num;
				a[i].people_num=zhongjian;
				strcpy(zhongjian_name,a[i+1].xueke_name);
				strcpy(a[i+1].xueke_name,a[i].xueke_name);
				strcpy(a[i].xueke_name,zhongjian_name);}
		}
	for(i=0;i<n;i++)
	{cout<<"学科名称:"<<a[i].xueke_name<<" 旷课次数:"<<a[i].people_num<<endl;
	return head;}
	return head;
}
struct student *zairu()
{struct student *p1=NULL,*p2=NULL,*head=NULL;
	struct student student_ziliao[100];
	int i=0,n=0;
	if((fp1=fopen("xueshengziliao.txt","rb+"))==NULL)
	{ printf("cannot open file\n");
		return(head); }  
	while(!feof(fp1))
	{if(fread(&student_ziliao[i],LEN,1,fp1)!=1)
		{if(feof(fp1))
			{fclose(fp1); 
				break; }
  		  printf("file read error\n");}
		i++;
	}
	n=i;
	student_num=n;
	p1=p2=(struct student *)malloc(LEN);
	head=p1;	
	for(i=0;i<n;i++)
	{p1->chidao_num=student_ziliao[i].chidao_num;
		p1->kuangke_num=student_ziliao[i].kuangke_num;
		strcpy(p1->lesson_name,student_ziliao[i].lesson_name);
		p1->lesson_time=student_ziliao[i].lesson_time;
		strcpy(p1->name,student_ziliao[i].name);
		p1->qingjia_num=student_ziliao[i].qingjia_num;
		p1->time=student_ziliao[i].time;
		p1->zaotui_num=student_ziliao[i].zaotui_num;
		p2->next=p1;
		p2=p1;
		p1=(struct student*)malloc(LEN); }
	p2->next=NULL;
	return(head);
}
void chucun(struct student *head)
{	struct student *p1;
	p1=head;
	fp1=fopen("xueshengziliao.txt","wb+");
	while(p1!=NULL)
	{fwrite(p1,LEN,1,fp1);
		p1=p1->next; }
	fclose(fp1);
	cout<<"                    储存成功\n";
}
int main()
{
struct student *head;
	int a,b,c;
zhuye:  cout<<"$$$$$$$$$$$$$$$$$$$$$$    欢迎使用学生考勤管理系统    V1.0.0  $$$$$$$$$$$$$$$$$$\n";  
		cout<<"                              1_进入管理\n\n\n";
		cout<<"                              2_查看系统相关信息\n\n\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n\n";
		cin>>a;
		if(a==1)
		{
			do
			{ 	 cout<<"********************************************************************************\n";
		cout<<"                                1_建立学生缺课记录\n";
		cout<<"                                2_修改学生缺课记录\n";
		cout<<"                                3_查询学生缺课记录\n";
		cout<<"                                4_查看单科旷课记录\n";
		cout<<"                                5_查看学生旷课记录\n";
		cout<<"                                6_载入学生旷课记录\n";
		cout<<"                                7_储存学生旷课记录\n";
		cout<<"                                8_退出考勤管理程序\n";
cout<<"********************************************************************************\n";
		cin>>b;
		switch(b)
		{
		case 1:
			head=creat();
			print(head);
			break;
		case 2:
			head=xiugai(head);
			print(head);
			break;
		case 3:
			chaxun(head);
			break;
		case 4:
			head=tongji_lesson(head);
			break;
		case 5:
			head=tongji_student(head);
			break;
		case 6:
			head=zairu();print(head);
			break;
		case 7:
			chucun(head);
			break;}
			}while(b!=8);
		}
		else 
		{cout<<"******************************本系统版权归徐彦春个人所有!***********************\n";
		 cout<<"******************************请联系我：tel:13177828979,QQ:545192632***********\n";
		 cout<<"******************************返回主页请按1*************************************\n";
		cin>>c;
		 if(c==1)
			 goto zhuye;
		}
	
}

