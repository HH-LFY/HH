#include<iostream>
#include<cstdio>
#include<windows.h>
#include<fstream>
#include<iomanip>
#include<string>
#define OK 1//�궨�� 
#define ERROR 0
#define MAX_SIZE 100
using namespace std;
//=========================
typedef int status;
struct employee
{
	int age;
	char name[15];
	double salary;
	
};
//=========================
void display(employee company[],int n)//չʾ����Ա����Ϣ
{
	if(n==0)
	cout<<"û���κ�Ա����Ϣ"<<endl;
	else
	{
	  cout<<"============"<<endl; 
	  for(int i=0;i<n;i++)
	  {
	  	cout<<setiosflags(ios::left)<<setw(7)<<company[i].name<<" "<<setw(4)<<company[i].age<<" "<<setw(10)<<company[i].salary<<endl;
	  }
	  cout<<"============\n";
	  system("pause");
  	}
}
//===================================
int readfile(employee company[])//���ļ��ж�������Ա����Ϣ
{
	int n=0;
	ifstream in("incompany.txt");//�����ļ����ļ���Ϊ  incompany.txt
	for(int i=0;;i++,n++)
	{
		in>>company[i].name>>company[i].age>>company[i].salary;
		if(!in)break;
	}
	cout<<"��ѡ���ļ�����:\n";
	display(company,n);
	return n;
}
//===================================
void savefile(employee company[],int n)//������Ա����Ϣд���ļ�
{
	for(int i=0;i<n;i++)
	{
		cout<<company[i].name<<" "<<company[i].age<<" "<<company[i].salary<<endl;
	}
	cout<<"����ɹ�!\n";
}
//====================================
status update(employee company[],int n)//����ĳ��Ա����Ϣ
{
	char _name[15];
	cout<<"������Ա������:\n";
	cin>>_name;
	for(int i=0;i<n;i++)
	{
		if(strcmp(company[i].name,_name)==0)
		{
			cout<<setw(7)<<company[i].name<<" "<<setw(4)<<company[i].age<<" "<<setw(10)<<company[i].salary<<endl;
			cout<<"�������޸ĺ�Ա�������������䣬����.\n";
			cin>>company[i].name>>company[i].age>>company[i].salary;
			return OK;
		}
	} 
	cout<<"�Ҳ������Ա������Ϣ!\n";
	return ERROR;
}
//===================================================
int read(employee company[])//�ֶ�����Ա����Ϣ������ӡ����
{
	int n;
	cout<<"��ѡ���ֶ�����\n";
	cout<<"������Ա������:\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"�����"<<i+1<<"��Ա������:\n";
		cin>>company[i].name;
		cout<<"�����"<<i+1<<"��Ա������:\n";
		cin>>company[i].age;
		cout<<"�����"<<i+1<<"��Ա������:\n";
		cin>>company[i].salary;
	} 
	display(company,n);
	return n;
}
//====================================================
double total(employee company[],int n,int agestart=0,int ageend=100)
{
//����ĳ������ε�Ա�����ܹ��ʣ�����ֵΪ�ܹ���
   cout<<"��������ʼ����:\n";
   cin>>agestart;
   cout<<"�������������:\n";
   cin>>ageend;
   double sum=0;
   for(int i=0;i<n;i++)
   {
   	if(company[i].age>=agestart&&company[i].age<=ageend)
   	sum=sum+company[i].salary;
   }
   cout<<"�����:"<<agestart<<"~"<<ageend<<endl;
   cout<<"����Ϊ"<<n<<",\n�ܹ���:"<<sum<<endl;
   return sum;
}
//===============================================
double mean(employee company[],int n,int agestart=0,int ageend=100)
{//����ĳ������ε�Ա��ƽ�����ʣ�����ֵΪƽ������ 
	cout<<"��������ʼ����:\n";
   cin>>agestart;
   cout<<"�������������:\n";
   cin>>ageend;
   double sum=0;
   int num=0;
   for(int i=0;i<n;i++)
   {
   	if(company[i].age>=agestart&&company[i].age<=ageend)
   	{
	   sum=sum+company[i].salary;
   	   num++;
   	}
   }
   cout<<"�����:"<<agestart<<"~"<<ageend<<endl;
   cout<<"����Ϊ"<<n<<",\nƽ������:"<<sum/num<<endl;
   return sum/num;
}
int main()
{
	int slct;//ѡ����뷽ʽ
	int n=0;
	employee company[MAX_SIZE] ;//����Ա����Ϣ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	cout<<"��ѡ��\n";
	cout<<"��1.�ļ���ȡԱ����Ϣ:\n";
	cout<<"��2.�ֶ���ȡԱ����Ϣ:\n";
	cin>>slct; 
	if(slct==1)n=readfile(company);
	else if(slct==2)n=read(company);
	
	for(int choice;;)//����ѭ��������0�˳�
	{
		system("cls");
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_GREEN );
		cout<<"                ����������������������\n";
		cout<<"                  ���� ��ӭʹ��Ա�����ʹ���ϵͳ ����\n";
		cout<<"                   �������������������\n";
		cout<<"                    ����������������������������������\n";
		cout<<"                    ��      ��ѡ����Ҫ�Ĳ���:       ��\n";
		cout<<"                    ��      1.����Ա����Ϣ;         ��\n";
		cout<<"                    ��      2.����Ա���ܹ���;       ��\n";
		cout<<"                    ��      3.����Ա��ƽ������;     ��\n";
		cout<<"                    ��      4.����Ա����Ϣ���ļ�;   ��\n";
		cout<<"                    ����������������������������������\n"<<endl;
		cin>>choice;
		if(!cin)continue;
		switch(choice)
		{
			case 1:update(company,n);break;
			case 2:total(company,n);break;
			case 3:mean(company,n);break;
			case 4:savefile(company,n);break;
			case 0:exit(0);
		} 
		system("pause");
	} 
	return 0;
}
