#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
#define M 200   //���Դ���Ϣ����
int N=0;        //ѧ������
class student
{
public:
	student();
	void set();       //��ʼ����Ϣ����һ�ζ���Ϣ��¼��
	void add();       //���ѧ����Ϣ
	void del();       //ɾ��ĳѧ����Ϣ
	void change();    //�޸�ĳѧ����Ϣ
    void search();    //��ѯĳѧ����Ϣ
	void display();   //��ʾȫ��ѧ����Ϣ
private:
	static int num;
	string name,sex,politic,address;
};
int student::num=110;

student::student() {}

void student::set()
{
	int i;
	string setname,setsex,setpolitic,setaddress;
	ofstream outfile;
	outfile.open("f1.txt",ios::out);   //----���ļ�----
	if(!outfile)
	{
		cerr<<" open error"<<endl; 
		exit(1);
	}
//----����¼����Ӧ������ѧ����Ϣ----
	for(i=0;i<M;i++)
	{
		cout<<"����������Ϊ'0'ʱ��ֹͣ���룡����"<<endl;
		cout<<"������������"<<endl;
		cin>>setname;
	    name=setname;
		if(setname=="0") break;
		if(setname!="0")
		{
			N++;
			num++;
            outfile<<num<<"  ";
		   	outfile<<setname<<"  ";
		    cout<<"�������Ա�"<<endl;
    		cin>>setsex;
	    	sex=setsex;
    		outfile<<setsex<<"  ";
    	    cout<<"������������ò��"<<endl;
            cin>>setpolitic;
    		politic=setpolitic;
	    	outfile<<setpolitic<<"  ";
	    	cout<<"�������ͥסַ��"<<endl;
	    	cin>>setaddress;
	    	address=setaddress;
	    	outfile<<setaddress<<endl;
		}
	}
	outfile.close();    //----�ر��ļ�----
}


void student::add()
{
	string addname,addsex,addpolitic,addaddress;
	
//----��׷�ӵķ�ʽ¼����Ϣ��ֱ�ӽ���Ϣ׷�ӵ���ǰ�ļ���ĩβ----
	ofstream outfile("f1.txt",ios::app);
	if(!outfile) 
	{
		cerr<<" open error"<<endl; 
		exit(1); 
	}
	N=N+1;
//----����������Ӧ�����ݣ�����׷�ӵ�֮ǰ���ļ���ȥ----
	cout<<"��������Ҫ��ӵ�����"<<endl;
        num++;
        outfile<<num<<"  ";
		cout<<"������������"<<endl;
		cin>>addname;
		outfile<<addname<<"  ";
		cout<<"�������Ա�"<<endl;
		cin>>addsex;
		outfile<<addsex<<"  ";
		cout<<"������������ò��"<<endl;
		cin>>addpolitic;
		outfile<<addpolitic<<"  ";
		cout<<"�������ͥסַ��"<<endl;
		cin>>addaddress;
		outfile<<addaddress<<endl;
		outfile.close();
		cout<<"����ӳɹ���"<<endl;
}


void student::del()
{
	int k,i;
	int num[M];
	string name[M],sex[M],politic[M],address[M];
	ifstream infile("f1.txt",ios::in);
	if(!infile)
	{
		cerr<<" open error"<<endl;
		exit(1);
	}
	for(i=0;i<N;i++)
	{
		cout<<"      ";
		infile>>num[i];
		cout<<setw(9)<<num[i];
		infile>>name[i];
		cout<<setw(9)<<name[i];
		infile>>sex[i];
		cout<<setw(9)<<sex[i];
		infile>>politic[i];
		cout<<setw(9)<<politic[i];
		infile>>address[i];
		cout<<setw(9)<<address[i]<<endl;
	}
	cout<<"����ɾ���ڼ�����"<<endl;
	cin>>k;
	k=k-1;
	infile.close();
	ofstream outfile("f1.txt",ios::out);
	if(!outfile)
	{
		cerr<<" open error"<<endl; 
		exit(1); //�˳�����
	}
//----�������ȡ����Ϣ������ļ���ȥ----
	for(i=0;i<N;i++)
	{
		if(i!=k)
		{
			outfile<<num[i]<<"   ";
			outfile<<name[i]<<"   ";
			outfile<<sex[i]<<"   ";
			outfile<<politic[i]<<"   ";
			outfile<<address[i]<<"   "<<endl;
		}
	}
	outfile.close();
	N=N-1;
	cout<<"��ɾ���ɹ���"<<endl;
}


void student::change()
{
	int i,k;
	int num[M];
	string name[M],sex[M],politic[M],address[M];
	ifstream infile("f1.txt",ios::in); 
	if(!infile)
	{
		cerr<<" open error"<<endl;
		exit(1);
	}
	for(i=0;i<N;i++)
	{
		cout<<"      ";
		infile>>num[i];
		cout<<setw(9)<<num[i];
		infile>>name[i];
		cout<<setw(9)<<name[i];
		infile>>sex[i];
		cout<<setw(9)<<sex[i];
		infile>>politic[i];
		cout<<setw(9)<<politic[i];
		infile>>address[i];
		cout<<setw(9)<<address[i]<<endl;
	}
	infile.close();
	ofstream outfile("f1.txt",ios::out);
	if(!outfile) 
		{
			cerr<<" open error"<<endl; 
			exit(1); 
		}
	cout<<"�����޸ĵڼ�������?"<<endl;
	cin>>k;
	k=k-1;
	cout<<"�������µ����ݣ�"<<endl;
	cout<<"������������"<<endl;
	cin>>name[k];
	cout<<"�������Ա�"<<endl;
	cin>>sex[k];
	cout<<"������������ò��"<<endl;
	cin>>politic[k];
	cout<<"�������ͥסַ��"<<endl;
	cin>>address[k];
	for(i=0;i<N;i++)
	{
            outfile<<num[i]<<"   ";
			outfile<<name[i]<<"   ";
			outfile<<sex[i]<<"   ";
			outfile<<politic[i]<<"   ";
			outfile<<address[i]<<"   "<<endl;
	}
	outfile.close();
	cout<<"���޸ĳɹ���"<<endl;
}


void student::search()
{
	int i,n,w=0,num[M],a[M];char ch;
	string searchname,name[M],sex[M],politic[M],address[M],b[M][4];
    cout<<"a.��ѧ�Ų���    b.����������"<<endl;
	ifstream infile("f1.txt",ios::in); 
	if(!infile)
	{
		cerr<<" open error"<<endl;
		exit(1);
	}
	for(i=0;i<N;i++)
	{
		infile>>num[i];a[i]=num[i];
		infile>>name[i];b[i][0]=name[i];
		infile>>sex[i];b[i][1]=sex[i];
		infile>>politic[i];b[i][2]=politic[i];
		infile>>address[i];b[i][3]=address[i];
	}
	cout<<"������a����b!"<<endl;
	cin>>ch;
    if(ch=='a')
	{
		cout<<"������ѧ�ţ�"<<endl;
		cin>>n;
		for(i=0;i<N;i++)
			if(a[i]==n)	
			{
				w=1;
				cout<<"           ѧ��      ����     �Ա�     ������ò     ��ͥסַ"<<endl;
				cout<<"     ";
				cout<<setw(9)<<a[i];
	         	cout<<setw(9)<<b[i][0];
	        	cout<<setw(9)<<b[i][1];
     		    cout<<setw(9)<<b[i][2];
	        	cout<<setw(9)<<b[i][3]<<endl;
			}
		if(w==0)
		    cout<<"�޴�����Ϣ��"<<endl;
	}
	else if(ch=='b')
	{
		cout<<"������������"<<endl;
		cin>>searchname;
		for(i=0;i<N;i++)
			if(name[i]==searchname)
			{
				w=1;
				cout<<"           ѧ��      ����     �Ա�     ������ò     ��ͥסַ"<<endl;
				cout<<"     ";
				cout<<setw(9)<<a[i];
	         	cout<<setw(9)<<b[i][0];
	        	cout<<setw(9)<<b[i][1];
     		    cout<<setw(9)<<b[i][2];
	        	cout<<setw(9)<<b[i][3]<<endl;
			}
	   if(w==0)
		   cout<<"�޴�����Ϣ��"<<endl;
	}
		else cout<<"û�д�ѡ�"<<endl;
}


void student::display()
{
	int k,num;
	string name,sex,politic,address;
	ifstream infile("f1.txt",ios::in); 
	if(!infile)
	{
		cerr<<" open error"<<endl;
		exit(1);
	}
	cout<<"           ѧ��      ����     �Ա�     ������ò     ��ͥסַ"<<endl;
	for(k=0;k<N;k++)
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
			case '6':stu.display();break;
			case '0':cout<<"�˳�ϵͳ!";break;
			default:cout<<"û�д�ѡ�"<<endl;break;
		}
		menu();
		cin>>ch;
	}
}

void menu()
{
	cout<<"******************"<<endl;
	cout<<"*     1.����     *"<<endl;
	cout<<"*     2.���     *"<<endl;
	cout<<"*     3.ɾ��     *"<<endl;
	cout<<"*     4.�޸�     *"<<endl;
	cout<<"*     5.��ѯ     *"<<endl;
	cout<<"*     6.��ʾȫ�� *"<<endl;
	cout<<"*     0.�˳�     *"<<endl;
	cout<<"******************"<<endl;
}

