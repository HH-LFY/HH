#include<iostream>
#include<vector>
#include <cstdio>
#include <cstring>
#include<fstream>
using namespace std;

//�����������
class employee
{
public:
	char name[10];
	char id[9];
public:
	char GetName()
	{
		return *name;
	}
	void SetName(char n[])
	{
		strcpy(name,n);
	}
	char GetID()
	{
		return *id;
	}
	void SetID(char i[])
	{
		strcpy(id,i);
	}
	virtual void Display()
	{
		cout<<"\t"<<GetID()<<"\t"<<GetName()<<endl;
	}

};
class employees:public employee
{
	friend class employee;
protected:
	char sex[4];
	int age;
public:
	char GetSex()
	{
		return *sex;
	}
	void SetSex(char s[])
	{
		strcpy(sex,s);
	}
	int GetAge()
	{
		return age;
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

		cout<<GetID()<<"\t"<<GetName()<<"\t"<<GetSex()<<"\t"<<GetAge()<<endl;
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
	char ch[5];
	int age;
	employees emps;
	cout<<"ע�⣺�����Ϊ��ʱ������������,��Ų���Ϊa-e��"<<endl;
	for (int i=0;i<3;i++)
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
	for(int i=0;i<3;i++)
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
		switch( Menu_sel())
		{
		case 1:AddNew();break;
		case 2:brevity();break;
		case 3:Dispvemps();break;
		case 4:Dispvemp();break;
		case 5:cout<<"\t��ӭ�´μ���ʹ�ã��ټ��� \n";return;
		default :cout<<"����������������룺";
		}
	}
}

