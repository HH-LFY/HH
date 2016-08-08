#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct student
{ int id;
  char name[50];
  int clas ;
  int gaoshu;
  int yingyu;
  int C;
}
st[50];
int i=0; 
int shuru()
{ 
	char a;
do {
	cout<<"请输入学号："<<endl;
	cin>>st[i].id;
	//fflush(stdin);
	cout<<"请输入姓名："<<endl;
	cin>>st[i].name;
	cout<<endl;
	cout<<"请输入班级："<<endl;
	cin>>st[i].clas;
	//fflush(stdin);
	cout<<"请输入高数成绩:"<<endl;
	cin>>st[i].gaoshu;
	//fflush(stdin);
	cout<<"请输入英语成绩： "<<endl;
	cin>>st[i].yingyu;
	//fflush(stdin);
	cout<<" 请输入C++成绩："<<endl;
	cin>>st[i].C;
	//fflush(stdin);
	cout<<"是否继续输入其他一个学生的信息？(y/n) "<<endl;
	//fflush(stdin);
	a=getchar();
	i++;
}
while(a=='y'&&i<=50);
return 0;}
int xianshi()
{
	int j; 
	cout<<"学号"<<"     "<<"姓名"<<"     "<<" 班级"<<"     "<<" 高数成绩"<< "      "<<" 英语成绩"<<"      "<<"C++成绩"<<endl;
	for(j=0;j<i;j++)   
			cout<<"  "<<st[j].id<<"       "<<st[j].name<<"         "<<st[j].clas<<"        "<<st[j].gaoshu<<"              "<<st[j].yingyu<<"            "<<st[j].C<<endl;
return 0;}
 int paixu()
 {
	 int j,k;
 
	 int temp;

	 for(j=0;j<i;j++)
 
	 {
	
		 for(k=0;k<i-1-j;k++)
	 
		 {
	
			 if(st[k].C<st[k+1].C)
	
			 {
				 temp=st[k].C;
	
				 st[k].C=st[k+1].C;
	
				 st[k+1].C=temp;
	
			 }
	
		 }
 
	 }
 
	 xianshi();
return 0; }
 void chazhao()
 {
	 int m,j;
	 char name[20],b;
	 do
	 {
		 cout<<"请输入想查找的学生姓名：";
		//fflush(stdin);
		 gets(name);
		 for(m=0;m<i;m++)
		 {
			 if(strcmp(name,st[m].name)==0)
			 {
				 cout<<"找到了"<<endl;
				 break;
			 }
		 }
			 if(m>50)
				 cout<<"没有找到"<<endl;
			 else
			 {
	cout<<"学号"<<"     "<<"姓名"<<"     "<<" 班级"<<"     "<<" 高数成绩"<< "      "<<" 英语成绩"<<"      "<<"C++成绩"<<endl;
 
			cout<<"  "<<st[m].id<<"       "<<st[m].name<<"         "<<st[m].clas<<"        "<<st[m].gaoshu<<"              "<<st[m].yingyu<<"            "<<st[m].C<<endl;
}

			 
cout<<"是否查找另一个学生的信息(y/n)："; 
//fflush(stdin);
b=getchar();
		 }
		 while(b=='y');
	 }
void shanchu()
{
	char name[50],c;
	int a,b;
	do 
	{
		cout<<"请输入要删除的学生的姓名：";
	//	fflush(stdin);
		gets(name);
		for(a=0;a,i;a++)
		{
			if(strcmp(name,st[a].name)==0)
				break;
		}
		for(b=a;b<i;b++)
		{st[b]=st[b+1];
		if(a>i)
			cout<<"没有找到"<<endl;
		else
		{
			i--;
			xianshi();
		}
		cout<<"是否继续删除另一个学生的成绩?(y/n)";
	//	fflush(stdin);
		c=getchar();
		}
	}
		while(c=='y');
}
void zengjia()
{	
	shuru();
	paixu();
	
}
int  main ()
	{
		int change;
	do
	{
		system("cls");
		cout<<endl;
		cout<<endl;
		cout<<"                    学生成绩查询系统                       "<<endl;
		cout<<"                                          "<<endl;
		cout<<"           1.输入学生信息："<<endl;
		cout<<"           2.显示学生信息                              "<<endl;
		cout<<"           3.查找学生信息：                              "<<endl;
		cout<<"           4.删除学生信息：                              "<<endl; 
        cout<<"           5.增加学生信息：                             "<<endl;
		cout<<"           6.排序学生信息：                             "<<endl;
        cout<<"           7.退出系统：                    "<<endl;
        cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		fflush(stdin);
		cout<<"请输入功能选项：";
        cin>>change;
switch(change)
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
}
while(change!=7);
return 0;}

