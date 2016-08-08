#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
#define M 200   //可以存信息总量
int N=0;        //学生总量
class student
{
public:
	student();
	void set();       //初始化信息，第一次对信息的录入
	void add();       //添加学生信息
	void del();       //删除某学生信息
	void change();    //修改某学生信息
    void search();    //查询某学生信息
	void display();   //显示全部学生信息
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
	outfile.open("f1.txt",ios::out);   //----打开文件----
	if(!outfile)
	{
		cerr<<" open error"<<endl; 
		exit(1);
	}
//----依次录入相应个数的学生信息----
	for(i=0;i<M;i++)
	{
		cout<<"当姓名输入为'0'时，停止输入！！！"<<endl;
		cout<<"请输入姓名："<<endl;
		cin>>setname;
	    name=setname;
		if(setname=="0") break;
		if(setname!="0")
		{
			N++;
			num++;
            outfile<<num<<"  ";
		   	outfile<<setname<<"  ";
		    cout<<"请输入性别："<<endl;
    		cin>>setsex;
	    	sex=setsex;
    		outfile<<setsex<<"  ";
    	    cout<<"请输入政治面貌："<<endl;
            cin>>setpolitic;
    		politic=setpolitic;
	    	outfile<<setpolitic<<"  ";
	    	cout<<"请输入家庭住址："<<endl;
	    	cin>>setaddress;
	    	address=setaddress;
	    	outfile<<setaddress<<endl;
		}
	}
	outfile.close();    //----关闭文件----
}


void student::add()
{
	string addname,addsex,addpolitic,addaddress;
	
//----以追加的方式录入信息，直接将信息追加到以前文件的末尾----
	ofstream outfile("f1.txt",ios::app);
	if(!outfile) 
	{
		cerr<<" open error"<<endl; 
		exit(1); 
	}
	N=N+1;
//----依次输入相应的数据，并且追加到之前的文件中去----
	cout<<"请输入您要添加的数据"<<endl;
        num++;
        outfile<<num<<"  ";
		cout<<"请输入姓名："<<endl;
		cin>>addname;
		outfile<<addname<<"  ";
		cout<<"请输入性别："<<endl;
		cin>>addsex;
		outfile<<addsex<<"  ";
		cout<<"请输入政治面貌："<<endl;
		cin>>addpolitic;
		outfile<<addpolitic<<"  ";
		cout<<"请输入家庭住址："<<endl;
		cin>>addaddress;
		outfile<<addaddress<<endl;
		outfile.close();
		cout<<"已添加成功！"<<endl;
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
	cout<<"你想删除第几个？"<<endl;
	cin>>k;
	k=k-1;
	infile.close();
	ofstream outfile("f1.txt",ios::out);
	if(!outfile)
	{
		cerr<<" open error"<<endl; 
		exit(1); //退出程序
	}
//----将数组存取的信息输出到文件中去----
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
	cout<<"已删除成功！"<<endl;
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
	cout<<"你想修改第几个数据?"<<endl;
	cin>>k;
	k=k-1;
	cout<<"请输入新的数据："<<endl;
	cout<<"请输入姓名："<<endl;
	cin>>name[k];
	cout<<"请输入性别："<<endl;
	cin>>sex[k];
	cout<<"请输入政治面貌："<<endl;
	cin>>politic[k];
	cout<<"请输入家庭住址："<<endl;
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
	cout<<"已修改成功！"<<endl;
}


void student::search()
{
	int i,n,w=0,num[M],a[M];char ch;
	string searchname,name[M],sex[M],politic[M],address[M],b[M][4];
    cout<<"a.按学号查找    b.按姓名查找"<<endl;
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
	cout<<"请输入a或者b!"<<endl;
	cin>>ch;
    if(ch=='a')
	{
		cout<<"请输入学号！"<<endl;
		cin>>n;
		for(i=0;i<N;i++)
			if(a[i]==n)	
			{
				w=1;
				cout<<"           学号      姓名     性别     政治面貌     家庭住址"<<endl;
				cout<<"     ";
				cout<<setw(9)<<a[i];
	         	cout<<setw(9)<<b[i][0];
	        	cout<<setw(9)<<b[i][1];
     		    cout<<setw(9)<<b[i][2];
	        	cout<<setw(9)<<b[i][3]<<endl;
			}
		if(w==0)
		    cout<<"无此人信息！"<<endl;
	}
	else if(ch=='b')
	{
		cout<<"请输入姓名！"<<endl;
		cin>>searchname;
		for(i=0;i<N;i++)
			if(name[i]==searchname)
			{
				w=1;
				cout<<"           学号      姓名     性别     政治面貌     家庭住址"<<endl;
				cout<<"     ";
				cout<<setw(9)<<a[i];
	         	cout<<setw(9)<<b[i][0];
	        	cout<<setw(9)<<b[i][1];
     		    cout<<setw(9)<<b[i][2];
	        	cout<<setw(9)<<b[i][3]<<endl;
			}
	   if(w==0)
		   cout<<"无此人信息！"<<endl;
	}
		else cout<<"没有此选项！"<<endl;
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
	cout<<"           学号      姓名     性别     政治面貌     家庭住址"<<endl;
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
			case '0':cout<<"退出系统!";break;
			default:cout<<"没有此选项！"<<endl;break;
		}
		menu();
		cin>>ch;
	}
}

void menu()
{
	cout<<"******************"<<endl;
	cout<<"*     1.输入     *"<<endl;
	cout<<"*     2.添加     *"<<endl;
	cout<<"*     3.删除     *"<<endl;
	cout<<"*     4.修改     *"<<endl;
	cout<<"*     5.查询     *"<<endl;
	cout<<"*     6.显示全部 *"<<endl;
	cout<<"*     0.退出     *"<<endl;
	cout<<"******************"<<endl;
}

