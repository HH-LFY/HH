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
	cout<<"������ѧ�ţ�"<<endl;
	cin>>st[i].id;
	//fflush(stdin);
	cout<<"������������"<<endl;
	cin>>st[i].name;
	cout<<endl;
	cout<<"������༶��"<<endl;
	cin>>st[i].clas;
	//fflush(stdin);
	cout<<"����������ɼ�:"<<endl;
	cin>>st[i].gaoshu;
	//fflush(stdin);
	cout<<"������Ӣ��ɼ��� "<<endl;
	cin>>st[i].yingyu;
	//fflush(stdin);
	cout<<" ������C++�ɼ���"<<endl;
	cin>>st[i].C;
	//fflush(stdin);
	cout<<"�Ƿ������������һ��ѧ������Ϣ��(y/n) "<<endl;
	//fflush(stdin);
	a=getchar();
	i++;
}
while(a=='y'&&i<=50);
return 0;}
int xianshi()
{
	int j; 
	cout<<"ѧ��"<<"     "<<"����"<<"     "<<" �༶"<<"     "<<" �����ɼ�"<< "      "<<" Ӣ��ɼ�"<<"      "<<"C++�ɼ�"<<endl;
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
		 cout<<"����������ҵ�ѧ��������";
		//fflush(stdin);
		 gets(name);
		 for(m=0;m<i;m++)
		 {
			 if(strcmp(name,st[m].name)==0)
			 {
				 cout<<"�ҵ���"<<endl;
				 break;
			 }
		 }
			 if(m>50)
				 cout<<"û���ҵ�"<<endl;
			 else
			 {
	cout<<"ѧ��"<<"     "<<"����"<<"     "<<" �༶"<<"     "<<" �����ɼ�"<< "      "<<" Ӣ��ɼ�"<<"      "<<"C++�ɼ�"<<endl;
 
			cout<<"  "<<st[m].id<<"       "<<st[m].name<<"         "<<st[m].clas<<"        "<<st[m].gaoshu<<"              "<<st[m].yingyu<<"            "<<st[m].C<<endl;
}

			 
cout<<"�Ƿ������һ��ѧ������Ϣ(y/n)��"; 
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
		cout<<"������Ҫɾ����ѧ����������";
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
			cout<<"û���ҵ�"<<endl;
		else
		{
			i--;
			xianshi();
		}
		cout<<"�Ƿ����ɾ����һ��ѧ���ĳɼ�?(y/n)";
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
		cout<<"                    ѧ���ɼ���ѯϵͳ                       "<<endl;
		cout<<"                                          "<<endl;
		cout<<"           1.����ѧ����Ϣ��"<<endl;
		cout<<"           2.��ʾѧ����Ϣ                              "<<endl;
		cout<<"           3.����ѧ����Ϣ��                              "<<endl;
		cout<<"           4.ɾ��ѧ����Ϣ��                              "<<endl; 
        cout<<"           5.����ѧ����Ϣ��                             "<<endl;
		cout<<"           6.����ѧ����Ϣ��                             "<<endl;
        cout<<"           7.�˳�ϵͳ��                    "<<endl;
        cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;
		fflush(stdin);
		cout<<"�����빦��ѡ�";
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

