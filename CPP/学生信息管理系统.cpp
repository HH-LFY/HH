#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#define m 200
int n=0;
class student
{
private:
	string name ,sex,politic,address;
	static int num;
public:
	student();
	void set();
	void add();
	void del();
	void change();
	void search();
	void show();
};
int student::num=1000;
student::student() {}
void student::set()
{ 
	string setname,setsex,setpolitic,setaddress;
	int i;
	ofstream outfile("f1.txt",ios::out);
	if(!outfile)
	{
		cout<<"open f1.txt error!"<<endl;
		exit(1);
	}
	for(i=0;i<m;i++)
	{
		cout<<"��ѧ����������Ϊ0ʱ�˻ز˵����棡����"<<endl;
		cout<<"������ѧ����������  ";
		cin>>setname;
		name=setname;
		if(setname=="0")break;
		if(setname!="0")
		{
			n++;
			num++;
			outfile<<num<<" ";
			outfile<<name<<" ";
			cout<<"������ѧ�����Ա�  ";
			cin>>setsex;
			sex=setsex;
			outfile<<setsex<<" ";
			cout<<"������ѧ����������ò��";
			cin>>setpolitic;
			politic=setpolitic;
			outfile<<setpolitic<<" ";
			cout<<"������ѧ���ļ�ͥסַ��";
			cin>>setaddress;
			address=setaddress;
			outfile<<setaddress<<endl;
		}
	}
	outfile.close();
	cout<<"������Ϣ�ɹ���"<<endl;
}
void student::add()
{
    string addname,addsex,addpolitic,addaddress;
	ofstream outfile("f1.txt",ios::app); //������ķ�ʽ���ļ���д�������������ļ�ĩβ
	if(!outfile)
	{
		cout<<"open f1.txt error!"<<endl;
		exit(1);
	}
	n=n+1;
	cout<<"�����������Ϣ��"<<endl;
	num++;
	outfile<<num;
	cout<<"������ѧ����������  ";
	cin>>addname;
	name=addname;
	outfile<<addname<<" ";
	cout<<"������ѧ�����Ա�  ";
	cin>>addsex;
	sex=addsex;
	outfile<<addsex<<" ";
	cout<<"������ѧ����������ò��";
	cin>>addpolitic;
	politic=addpolitic;
	outfile<<addpolitic<<" ";
	cout<<"������ѧ���ļ�ͥסַ��";
	cin>>addaddress;
	address=addaddress;
	outfile<<address<<endl;
	outfile.close();
	cout<<"�����Ϣ�ɹ�������"<<endl;
}
void student::del()
{
	int k,i;
	int num[m];
	string name[m],sex[m],politic[m],address[m];
	ifstream infile("f1.txt",ios::in);
	if(!infile)
	{
		cout<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		cout<<"     ";
		infile>>num[i];
		cout<<setw(10)<<num[i];
		infile>>name[i];
		cout<<setw(10)<<name[i];
		infile>>sex[i];
		cout<<setw(10)<<sex[i];
		infile>>politic[i];
		cout<<setw(10)<<politic[i];
		infile>>address[i];
		cout<<setw(10)<<address[i]<<endl;
	}
	infile.close();
	cout<<"����ɾ���ڼ�����"<<endl;
	cin>>k;
	k=k-1;
	ofstream outfile("f1.txt",ios::out);
		if(! outfile)
		{
			cout<<"open error!"<<endl;
			exit(1);
		}
		for(i=0;i<n;i++)
		{
			if(i!=k)
			{
				outfile<<num[i]<<" ";
				outfile<<name[i]<<" ";
				outfile<<sex[i]<<" ";
				outfile<<politic[i]<<" ";
				outfile<<address[i]<<" "<<endl;
			}
		}
		outfile.close();
		n=n-1;
		cout<<"ɾ���ɹ�������"<<endl;
}
void student::change()
{
	int k,i;
	int num[m];
	string name[m],sex[m],politic[m],address[m];
	ifstream infile("f1.txt",ios::in);
	if(!infile)
	{
		cout<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		cout<<"     ";
		infile>>num[i];
		cout<<setw(10)<<num[i];
		infile>>name[i];
		cout<<setw(10)<<name[i];
		infile>>sex[i];
		cout<<setw(10)<<sex[i];
		infile>>politic[i];
		cout<<setw(10)<<politic[i];
		infile>>address[i];
		cout<<setw(10)<<address[i]<<endl;
	}
	infile.close();
	cout<<"����ı�ڼ���ѧ�������ݣ�"<<endl;
	cin>>k;
	k=k-1;
	cout<<"�������µ����ݣ�"<<endl;
	cout<<"������ѧ����������  ";
	cin>>name[k];
	cout<<"������ѧ�����Ա�  "<<endl;
	cin>>sex[k];
	cout<<"������ѧ����������ò��"<<endl;
	cin>>politic[k];
	cout<<"������ѧ���ļ�ͥסַ��"<<endl;
	cin>>address[k];
	ofstream outfile("f1.txt",ios::out);
	if(! outfile)
	{
		cout<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<n;i++)
	{
     outfile<<num[i]<<" ";
	 outfile<<name[i]<<" ";
	 outfile<<sex[i]<<" ";
	 outfile<<politic[i]<<" ";
	 outfile<<address[i]<<" " <<endl;
	}
	outfile.close();
	cout<<"�޸���Ϣ�ɹ�������"<<endl;
}
void student::search()
{
	char ch;
	int i,w=0,num[m],a[m],h;
	string searchname,name[m],sex[m],politic[m],address[m],b[m][4];
	cout<<"a.����������   b.��ѧ�Ų���"<<endl;
	ifstream infile("f1.txt",ios::in);
	if(!infile)
	{
		cout<<"open error!"<<endl;
		exit(1);
	}
	for(i=0;i<n;i++)
	{
		infile>>num[i];a[i]=num[i];
		infile>>name[i];b[i][0]=name[i];
		infile>>sex[i];b[i][1]=sex[i];
		infile>>politic[i];b[i][2]=politic[i];
		infile>>address[i];b[i][3]=address[i];
	}
	cout<<"������a��b:"<<endl;
	cin>>ch;
	if(ch=='a')
	{
		cout<<"������ѧ��������"<<endl;
		cin>>searchname;
		for(i=0;i<n;i++)
			if(name[i]==searchname)
			{
				w=1;
			    cout<<"          ѧ��      ����     �Ա�     ������ò     ��ͥסַ"<<endl;
                cout<<"   ";
		      	cout<<setw(10)<<a[i];
		     	cout<<setw(10)<<b[i][0];
		    	cout<<setw(10)<<b[i][1];
		    	cout<<setw(10)<<b[i][2];
			    cout<<setw(10)<<b[i][3]<<endl;
			}
		   if(w==0)
			    cout<<"�޴�����Ϣ��"<<endl;
	}
	else if(ch=='b')
	{
		cout<<"������ѧ����ѧ�ţ�"<<endl;
		cin>>h;
		for(i=0;i<n;i++)
			if(a[i]==h)
			{
				w=1;
			    cout<<"          ѧ��      ����     �Ա�     ������ò     ��ͥסַ"<<endl;
		        cout<<"    ";
		    	cout<<setw(10)<<a[i];
		     	cout<<setw(10)<<b[i][0];
		    	cout<<setw(10)<<b[i][1];
		    	cout<<setw(10)<<b[i][2];
		        cout<<setw(10)<<b[i][3]<<endl;
			}
		    if(w==0)
		     	cout<<"�޴�����Ϣ��"<<endl;
	}
	else  cout<<"û�д�ѡ�"<<endl;
}
void student::show()
{
	int k,num;
	string name,sex,politic,address;
	ifstream infile("f1.txt",ios::in); 
	if(!infile)
	{
		cerr<<" open error!"<<endl;
		exit(1);
	}
	cout<<"           ѧ��      ����     �Ա�     ������ò     ��ͥסַ"<<endl;
	for(k=0;k<n;k++)
	{
		cout<<"     ";
		infile>>num;
		cout<<setw(9)<<num;
		infile>>name;
		cout<<setw(9)<<name;
		infile>>sex;
		cout<<setw(9)<<sex;
		infile>>politic;
		cout<<setw(9)<<politic;
		infile>>address;
		cout<<setw(9)<<address<<endl;
	}
	infile.close();
}


student stu;
void main()
{
	char ch;
	void menu();
	menu();
	cin>>ch;
	while(ch!='0')
	{
		system("cls");
		switch(ch)
		{
		case '1':stu.set();break;
		case '2':stu.add();break;
		case '3':stu.del();break;
		case '4':stu.change();break;
		case '5':stu.search();break;
		case '6':stu.show();break;
		case '0':cout<<"�˳�ϵͳ!";break;
		default:cout<<"û�д�ѡ�"<<endl;break;
		}
		menu();
		cin>>ch;
	}
}

void menu()
{
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	cout<<"\t**                1.����ѧ����Ϣ                     **"<<endl;
	cout<<"\t**                2.����µ���Ϣ                     **"<<endl;
	cout<<"\t**                3.ɾ����Ϣ                         **"<<endl;
	cout<<"\t**                4.�޸���Ϣ                         **"<<endl;
	cout<<"\t**                5.��ѯ��Ϣ                         **"<<endl;
	cout<<"\t**                6.��ʾȫ����Ϣ                     **"<<endl;
	cout<<"\t**                0.�˳�                             **"<<endl;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
}


	

	
