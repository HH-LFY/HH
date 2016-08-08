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
	printf("系统正在为您加载");
	for(int i = 1;i <= 5;i++)
	{
		printf(".");
	
		Sleep(500);
	}
	cout<<endl;
	system("cls");
}

//构造的两个类
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
	//virtual的实现
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

//向量容器
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
	cout<<"注意：当编号为零时，进入主界面,编号不可为a-e："<<endl;
	for (int i=0;i<11;i++)
	{
		cout<<"\t编号:";
		cin.getline(ch,'\n');
		if (ch[0]=='0')  break;
		emps.SetID(ch);
        cout<<"\t姓名:";
		cin.getline(ch,'\n');
		emps.SetName(ch);
		cout<<"\t性别:";
		cin.getline(ch,'\n');
		emps.SetSex(ch);
		cout<<"\t年龄:";
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
	if(inFile.eof()){cout<<"没有记录，请先手动打开文件输入信息"<<endl;
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
		cout<<"\t没有建立记录，请先建立记录信息。"<<endl;
		return;
	}
	for(int i=size;i<top;i++)
	{
		vemp.push_back(emps);
		strcpy(vemp[i].id,vemps[i].id);
		strcpy(vemp[i].name,vemps[i].name);
	}
	cout<<"信息简表已生成，请继续"<<endl;
}

void Dispvemps()
{
	void Printer(employee&);
	if(vemps.size()==0){
		cout<<"\t没有输入信息，请先输入信息。"<<endl;
		return;
	}
	else {
		cout<<"编号\t姓名\t性别\t年龄"<<endl;
		for(int i=0;i<vemps.size();i++)
			Printer(vemps[i]);
    }
}
void Dispvemp()
{

	if (vemp.size()==0){
		cout<<"\t没有生成新的简表， 请先生成新的简表"<<endl;
		return ;
	}
	else {
		cout<<"\t编号"<<"\t姓名"<<endl;
		for(int i=0;i<vemp.size();i++)
			Printer(vemp[i]);
    }
}
char Menu_sel()
{
	char s[4];
	int chio;
    cout<<"\t\t\t*************************\n";
	cout<<"\t\t\t*    1.增加职工信息     *\n";
	cout<<"\t\t\t               \n";
    cout<<"\t\t\t*    2.生成信息简表     *\n";
	cout<<"\t\t\t               \n";
    cout<<"\t\t\t*    3.显示原始记录     *\n";
	cout<<"\t\t\t               \n";
    cout<<"\t\t\t*    4.显示简表记录     *\n";
    cout<<"\t\t\t               \n";
    cout<<"\t\t\t*    5.结束程序运行     *\n";
    cout<<"\t\t\t               \n";
    cout<<"\t\t\t*************************\n";
	cout<<"\t选择1-5:";
	gets(s);
	chio=atoi(s);
	return chio;
}
void main()
{
	cout<<"\t\t\t      职工信息表程序\n\n";
	for( ; ; )
	{
		pf();
		switch( Menu_sel())
		{
		case 1:system("cls");pf();AddNew();break;
		case 2:system("cls");brevity();break;
		case 3:system("cls");Dispvemps();break;
		case 4:system("cls");Dispvemp();break;
		case 5:cout<<"\t欢迎下次继续使用，再见！ \n";return;
		default :cout<<"输入错误，请重新输入：";
		}
	}
}

