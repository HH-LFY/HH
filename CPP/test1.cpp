#include<iostream>
#include<vector>
#include <cstdio>
#include <cstring>
#include<fstream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

void pf() 
{
	printf("ϵͳ����Ϊ������");
	for(int i = 1;i <= 5;i++)
	{
		printf(".");
	
		Sleep(500);
	}
	cout<<endl;
	system("cls");
}

//�����������
class employee
{
public:
	char name[50];
	char id[50];
public:
	void GetName()
	{
		cout<<name;
	}
	void SetName(char n[])
	{
		strcpy(name,n);
	}
	void GetID()
	{
		cout<<id;
	}
	void SetID(char i[])
	{
		strcpy(id,i);
	}
	virtual void Display()
	{
		cout<<"\t";
		GetID();
		cout<<"\t";
		GetName();
		cout<<endl;
	}

}a[100];
class employees:public employee
{
	friend class employee;
protected:
	char sex[50];
	int age;
public:
	void GetSex()
	{
		cout<<sex;
	}
	void SetSex(char s[])
	{
		strcpy(sex,s);
	}
	void GetAge()
	{
		cout<<age;
	}
	void SetAge(int a)
	{
		age=a;
	}
	void WriteFile();
	void ReadFile();
	//virtual��ʵ��
	void Display()
	{

		GetID();
		cout<<"\t";
		GetName();
		cout<<"\t";
		GetSex();
		cout<<"\t";
		GetAge();
		cout<<endl;
	}

};

//��������
vector<employee>vemp;
vector<employees>vemps;
//
void Printer(employee& s)
{
	s.Display();
}

void AddNew()
{
	char ch[50];
	int age;
	employees emps;
	cout<<"ע�⣺�����Ϊ��ʱ������������,��Ų���Ϊa-e��"<<endl;
	for (int i=0;i<11;i++)
	{
		cout<<"\t���:";
		cin.getline(ch,'\n');
		if (ch[0]=='0')  break;
		emps.SetID(ch);
        cout<<"\t����:";
		cin.getline(ch,'\n');
		emps.SetName(ch);
		cout<<"\t�Ա�:";
		cin.getline(ch,'\n');
		emps.SetSex(ch);
		cout<<"\t����:";
		cin>>age;
		emps.SetAge(age);
		vemps.push_back(emps);
		getchar();
		emps.WriteFile();
	}
}


void employees::WriteFile()
{
	ofstream curFile("Workers.txt");
	for(int i=0;i<11;i++)
	{
		curFile<<id<<'\n'<<name<<'\n'<<sex<<'\n'<<age<<'\n';
	}
	curFile.close();
}

void employees::ReadFile(){
	char line[81];
	ifstream   inFile("Workers.txt");
	inFile.getline (line, 80);
	if(inFile.eof()){cout<<"û�м�¼�������ֶ����ļ�������Ϣ"<<endl;
	}
	while(!inFile.eof())
	{
		cout<<line<<endl;
		inFile.getline (line, 80);
	}
	inFile.close ();
}
void brevity()
{
    friend class employee;
	employees emps;
    int top=vemps.size();
	int size=vemp.size();
	if (top==0)
	{
		cout<<"\tû�н�����¼�����Ƚ�����¼��Ϣ��"<<endl;
		return;
	}
	for(int i=size;i<top;i++)
	{
		vemp.push_back(emps);
		strcpy(vemp[i].id,vemps[i].id);
		strcpy(vemp[i].name,vemps[i].name);
	}
	cout<<"��Ϣ��������ɣ������"<<endl;
}

void Dispvemps()
{
	void Printer(employee&);
	if(vemps.size()==0){
		cout<<"\tû��������Ϣ������������Ϣ��"<<endl;
		return;
	}
	else {
		cout<<"���\t����\t�Ա�\t����"<<endl;
		for(int i=0;i<vemps.size();i++)
			Printer(vemps[i]);
    }
}
void Dispvemp()
{

	if (vemp.size()==0){
		cout<<"\tû�������µļ�� ���������µļ��"<<endl;
		return ;
	}
	else {
		cout<<"\t���"<<"\t����"<<endl;
		for(int i=0;i<vemp.size();i++)
			Printer(vemp[i]);
    }
}
char Menu_sel()
{
	char s[4];
	int chio;
    cout<<"\t\t\t*************************\n";
	cout<<"\t\t\t*    1.����ְ����Ϣ     *\n";
	cout<<"\t\t\t               \n";
    cout<<"\t\t\t*    2.������Ϣ���     *\n";
	cout<<"\t\t\t               \n";
    cout<<"\t\t\t*    3.��ʾԭʼ��¼     *\n";
	cout<<"\t\t\t               \n";
    cout<<"\t\t\t*    4.��ʾ����¼     *\n";
    cout<<"\t\t\t               \n";
    cout<<"\t\t\t*    5.������������     *\n";
    cout<<"\t\t\t               \n";
    cout<<"\t\t\t*************************\n";
	cout<<"\tѡ��1-5:";
	gets(s);
	chio=atoi(s);
	return chio;
}
void main()
{
	cout<<"\t\t\t      ְ����Ϣ�����\n\n";
	for( ; ; )
	{
		pf();
		switch( Menu_sel())
		{
		case 1:system("cls");pf();AddNew();break;
		case 2:system("cls");brevity();break;
		case 3:system("cls");Dispvemps();break;
		case 4:system("cls");Dispvemp();break;
		case 5:cout<<"\t��ӭ�´μ���ʹ�ã��ټ��� \n";return;
		default :cout<<"����������������룺";
		}
	}
}

