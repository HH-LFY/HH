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
	cout<<"������Ҫ��ѯ��������";
    cin>>chaxun_name;
	struct student *p;
	if(head==NULL)
		cout<<"��ϵ��Ϊ��";
	p=head;
	for(i=0;i<student_num;i++)
	{if(strcmp(chaxun_name,p->name)==0)
	{cout<<"ȱ��ʱ��:"<<p->time<<"     ѧ������:"<<p->name<<"      �γ�����:"<<p->lesson_name<<"      �ڴ�:"<<p->lesson_time<<endl
	        <<"�ٵ�����:"<<p->chidao_num<<"            ���˴���:"<<p->zaotui_num<<"           ��ٴ���:"<<p->qingjia_num<<"     ���δ���:"<<p->kuangke_num<<endl;
	}	
	p=p->next; }
	
}
struct student *xiugai(struct student *head)
{char xiugai_name[50];
	char xiugai_xueke_name[50];
	int k;
	cout<<"������Ҫ�޸ĵ�ѧ��������ѧ�����ơ���ʽ:ѧ������(�ո�)ѧ�����ơ���";
	cin>>xiugai_name>>xiugai_xueke_name;
	struct student *p1,*p2; 
	p2=(struct student *)malloc(LEN);
	p1=head;
	if(head==NULL)
	{cout<<"û��ѧ����Ϣ\n";
		return head; }
	while((strcmp(xiugai_name,p1->name)!=0||strcmp(xiugai_xueke_name,p1->lesson_name)!=0)&&(p1->next!=NULL))
		p1=p1->next;
    if(strcmp(xiugai_name,p1->name)==0&&strcmp(xiugai_xueke_name,p1->lesson_name)==0)
	{   cout<<"====================================  �޸���Ϣ =================================\n"; 
		cout<<"                                   1-�޸�ȱ��ʱ��             \n";
		cout<<"                                   2-�޸�ѧ������             \n";
		cout<<"                                   3-�޸Ŀγ�����             \n";
		cout<<"                                   4-�޸ĵڼ���ȱ��           \n";
		cout<<"                                   5-�޸ĳٵ�����             \n";
		cout<<"                                   6-�޸����˴���             \n";
		cout<<"                                   7-�޸���ٴ���             \n";
		cout<<"                                   8-�޸Ŀ��δ���             \n\n";
		cout<<"================================================================================\n";
		cin>>k;
		switch(k)
		{case 1:
			cout<<"�������µ�ȱ��ʱ��:";
			cin>>p1->time;
			break;
		case 2:
			cout<<"�������µ�ѧ������:";
			cin>>p1->name;
			break;
		case 3:
			cout<<"�������µĿγ�����:";
			cin>>p1->lesson_name;
			break;
		case 4:
			cout<<"�������µ�ȱ�νڴ�:";
			cin>>p1->lesson_time;
			break;
		case 5:
			cout<<"�������µĳٵ�����:";
			cin>>p1->chidao_num;
			break;
		case 6:
			cout<<"�������µ����˴���:";
			cin>>p1->zaotui_num;
			break;
		case 7:
			cout<<"�������µ���ٴ���:";
			cin>>p1->qingjia_num;
			break;
		case 8:
			cout<<"�������µĿ��δ���:";
			cin>>p1->kuangke_num;
			break; }
	}
	return head;
}
struct student *creat()
{
	int i,b;
		struct student *head,*p1,*p2;      
		cout<<"������Ҫ�������ϵ�ѧ��������";
		cin>>b;
		head=p2=NULL;
		p1=(struct student *)malloc(LEN);
		cout<<"�������ʽ��ȱ��ʱ��(�ո�)ѧ������(�ո�)�γ�����(�ո�)�ڼ���(�ո�)�ٵ�����(�ո�)���˴���(�ո�)��ٴ���(�ո�)���δ�����\n";
		cout<<"�������1��ѧ����Ϣ:";
	    cin>>p1->time>>p1->name>>p1->lesson_name>>p1->lesson_time>>p1->chidao_num>>p1->zaotui_num>>p1->qingjia_num>>p1->kuangke_num;
		head=p1;
		p2=p1;
		student_num+=1;
		for(i=1;i<b;i++)
		{
			p1=(struct student*)malloc(LEN);
			cout<<"�������"<<i+1<<"��ѧ����Ϣ:";
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
		cout<<"û��ѧ����Ϣ\n";
	while(p!=NULL)	
	{   cout<<"ȱ��ʱ��:"<<p->time<<"     ѧ������:"<<setw(10)<<p->name<<"      �γ�����:"<<p->lesson_name<<"      �ڴ�:"<<p->lesson_time<<endl
	        <<"�ٵ�����:"<<p->chidao_num<<"            ���˴���:"<<p->zaotui_num<<"           ��ٴ���:"<<p->qingjia_num<<"     ���δ���:"<<p->kuangke_num<<endl;
		p=p->next;}	
}
struct student *tongji_lesson(struct student *head)
{	struct student *p1,*p2,*p3;
	char lesson[50];
	long look_time1,look_time2;
	int xunhuan_num=0;
	p3=(struct student *)malloc(LEN);
	if(head==NULL)
	{cout<<"û��ѧ����Ϣ";
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
	cout<<"������Ҫ�鿴��ѧ�����ƣ�";
	cin>>lesson;
	cout<<"������Ҫ�鿴��ʱ�䷶Χ�������ʽ:ʱ��(�ո�)ʱ�䡿";
	cin>>look_time1>>look_time2;
	p1=head;   
	while(p1!=NULL)
	{if(strcmp(lesson,p1->lesson_name)==0&&look_time1<=p1->time&&p1->time<=look_time2)
			cout<<"ѧ������:"<<p1->name<<"     ���δ���:"<<p1->kuangke_num<<endl;
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
	{cout<<"û��ѧ����Ϣ\n";
	return head; 
	}
	cout<<"������һ����ѧ������";
	cin>>n;
	for(i=0;i<n;i++)
	{cout<<"�������"<<i+1<<"��ѧ�����ƣ�";
	cin>>a[i].xueke_name;
	a[i].people_num=0; 
	}
	cout<<"������Ҫ�鿴��ʱ�䷶Χ��С���������ʽ:ʱ��(�ո�)ʱ�䡿";
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
	{cout<<"ѧ������:"<<a[i].xueke_name<<" ���δ���:"<<a[i].people_num<<endl;
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
	cout<<"                    ����ɹ�\n";
}
int main()
{
struct student *head;
	int a,b,c;
zhuye:  cout<<"$$$$$$$$$$$$$$$$$$$$$$    ��ӭʹ��ѧ�����ڹ���ϵͳ    V1.0.0  $$$$$$$$$$$$$$$$$$\n";  
		cout<<"                              1_�������\n\n\n";
		cout<<"                              2_�鿴ϵͳ�����Ϣ\n\n\n";
	cout<<"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n\n\n\n\n";
		cin>>a;
		if(a==1)
		{
			do
			{ 	 cout<<"********************************************************************************\n";
		cout<<"                                1_����ѧ��ȱ�μ�¼\n";
		cout<<"                                2_�޸�ѧ��ȱ�μ�¼\n";
		cout<<"                                3_��ѯѧ��ȱ�μ�¼\n";
		cout<<"                                4_�鿴���ƿ��μ�¼\n";
		cout<<"                                5_�鿴ѧ�����μ�¼\n";
		cout<<"                                6_����ѧ�����μ�¼\n";
		cout<<"                                7_����ѧ�����μ�¼\n";
		cout<<"                                8_�˳����ڹ������\n";
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
		{cout<<"******************************��ϵͳ��Ȩ�����崺��������!***********************\n";
		 cout<<"******************************����ϵ�ң�tel:13177828979,QQ:545192632***********\n";
		 cout<<"******************************������ҳ�밴1*************************************\n";
		cin>>c;
		 if(c==1)
			 goto zhuye;
		}
	
}

