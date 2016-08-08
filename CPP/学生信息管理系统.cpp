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
		cout<<"当学生姓名输入为0时退回菜单界面！！！"<<endl;
		cout<<"请输入学生的姓名：  ";
		cin>>setname;
		name=setname;
		if(setname=="0")break;
		if(setname!="0")
		{
			n++;
			num++;
			outfile<<num<<" ";
			outfile<<name<<" ";
			cout<<"请输入学生的性别：  ";
			cin>>setsex;
			sex=setsex;
			outfile<<setsex<<" ";
			cout<<"请输入学生的政治面貌：";
			cin>>setpolitic;
			politic=setpolitic;
			outfile<<setpolitic<<" ";
			cout<<"请输入学生的家庭住址：";
			cin>>setaddress;
			address=setaddress;
			outfile<<setaddress<<endl;
		}
	}
	outfile.close();
	cout<<"输入信息成功！"<<endl;
}
void student::add()
{
    string addname,addsex,addpolitic,addaddress;
	ofstream outfile("f1.txt",ios::app); //以输出的方式打开文件，写入的数据添加在文件末尾
	if(!outfile)
	{
		cout<<"open f1.txt error!"<<endl;
		exit(1);
	}
	n=n+1;
	cout<<"请输入添加信息："<<endl;
	num++;
	outfile<<num;
	cout<<"请输入学生的姓名：  ";
	cin>>addname;
	name=addname;
	outfile<<addname<<" ";
	cout<<"请输入学生的性别：  ";
	cin>>addsex;
	sex=addsex;
	outfile<<addsex<<" ";
	cout<<"请输入学生的政治面貌：";
	cin>>addpolitic;
	politic=addpolitic;
	outfile<<addpolitic<<" ";
	cout<<"请输入学生的家庭住址：";
	cin>>addaddress;
	address=addaddress;
	outfile<<address<<endl;
	outfile.close();
	cout<<"添加信息成功！！！"<<endl;
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
	cout<<"你想删除第几个？"<<endl;
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
		cout<<"删除成功！！！"<<endl;
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
	cout<<"你想改变第几个学生的数据？"<<endl;
	cin>>k;
	k=k-1;
	cout<<"请输入新的数据："<<endl;
	cout<<"请输入学生的姓名：  ";
	cin>>name[k];
	cout<<"请输入学生的性别：  "<<endl;
	cin>>sex[k];
	cout<<"请输入学生的政治面貌："<<endl;
	cin>>politic[k];
	cout<<"请输入学生的家庭住址："<<endl;
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
	cout<<"修改信息成功！！！"<<endl;
}
void student::search()
{
	char ch;
	int i,w=0,num[m],a[m],h;
	string searchname,name[m],sex[m],politic[m],address[m],b[m][4];
	cout<<"a.按姓名查找   b.按学号查找"<<endl;
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
	cout<<"请输入a或b:"<<endl;
	cin>>ch;
	if(ch=='a')
	{
		cout<<"请输入学生的姓名"<<endl;
		cin>>searchname;
		for(i=0;i<n;i++)
			if(name[i]==searchname)
			{
				w=1;
			    cout<<"          学号      姓名     性别     政治面貌     家庭住址"<<endl;
                cout<<"   ";
		      	cout<<setw(10)<<a[i];
		     	cout<<setw(10)<<b[i][0];
		    	cout<<setw(10)<<b[i][1];
		    	cout<<setw(10)<<b[i][2];
			    cout<<setw(10)<<b[i][3]<<endl;
			}
		   if(w==0)
			    cout<<"无此人信息！"<<endl;
	}
	else if(ch=='b')
	{
		cout<<"请输入学生的学号："<<endl;
		cin>>h;
		for(i=0;i<n;i++)
			if(a[i]==h)
			{
				w=1;
			    cout<<"          学号      姓名     性别     政治面貌     家庭住址"<<endl;
		        cout<<"    ";
		    	cout<<setw(10)<<a[i];
		     	cout<<setw(10)<<b[i][0];
		    	cout<<setw(10)<<b[i][1];
		    	cout<<setw(10)<<b[i][2];
		        cout<<setw(10)<<b[i][3]<<endl;
			}
		    if(w==0)
		     	cout<<"无此人信息！"<<endl;
	}
	else  cout<<"没有此选项！"<<endl;
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
	cout<<"           学号      姓名     性别     政治面貌     家庭住址"<<endl;
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
		case '0':cout<<"退出系统!";break;
		default:cout<<"没有此选项！"<<endl;break;
		}
		menu();
		cin>>ch;
	}
}

void menu()
{
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	cout<<"\t**                1.输入学生信息                     **"<<endl;
	cout<<"\t**                2.添加新的信息                     **"<<endl;
	cout<<"\t**                3.删除信息                         **"<<endl;
	cout<<"\t**                4.修改信息                         **"<<endl;
	cout<<"\t**                5.查询信息                         **"<<endl;
	cout<<"\t**                6.显示全部信息                     **"<<endl;
	cout<<"\t**                0.退出                             **"<<endl;
	cout<<"\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
}


	

	
