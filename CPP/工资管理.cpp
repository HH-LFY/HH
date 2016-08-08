#include<iostream>
#include<cstdio>
#include<windows.h>
#include<fstream>
#include<iomanip>
#include<string>
#define OK 1//宏定义 
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
void display(employee company[],int n)//展示所有员工信息
{
	if(n==0)
	cout<<"没有任何员工信息"<<endl;
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
int readfile(employee company[])//从文件中读入所有员工信息
{
	int n=0;
	ifstream in("incompany.txt");//读入文件，文件名为  incompany.txt
	for(int i=0;;i++,n++)
	{
		in>>company[i].name>>company[i].age>>company[i].salary;
		if(!in)break;
	}
	cout<<"你选择文件输入:\n";
	display(company,n);
	return n;
}
//===================================
void savefile(employee company[],int n)//将所有员工信息写入文件
{
	for(int i=0;i<n;i++)
	{
		cout<<company[i].name<<" "<<company[i].age<<" "<<company[i].salary<<endl;
	}
	cout<<"保存成功!\n";
}
//====================================
status update(employee company[],int n)//更新某个员工信息
{
	char _name[15];
	cout<<"请输入员工姓名:\n";
	cin>>_name;
	for(int i=0;i<n;i++)
	{
		if(strcmp(company[i].name,_name)==0)
		{
			cout<<setw(7)<<company[i].name<<" "<<setw(4)<<company[i].age<<" "<<setw(10)<<company[i].salary<<endl;
			cout<<"请输入修改后员工的姓名，年龄，工资.\n";
			cin>>company[i].name>>company[i].age>>company[i].salary;
			return OK;
		}
	} 
	cout<<"找不到这个员工的信息!\n";
	return ERROR;
}
//===================================================
int read(employee company[])//手动输入员工信息，并打印出来
{
	int n;
	cout<<"你选择手动输入\n";
	cout<<"请输入员工人数:\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"输入第"<<i+1<<"个员工姓名:\n";
		cin>>company[i].name;
		cout<<"输入第"<<i+1<<"个员工年龄:\n";
		cin>>company[i].age;
		cout<<"输入第"<<i+1<<"个员工工资:\n";
		cin>>company[i].salary;
	} 
	display(company,n);
	return n;
}
//====================================================
double total(employee company[],int n,int agestart=0,int ageend=100)
{
//计算某个年龄段的员工的总工资，返回值为总工资
   cout<<"请输入起始年龄:\n";
   cin>>agestart;
   cout<<"请输入结束年龄:\n";
   cin>>ageend;
   double sum=0;
   for(int i=0;i<n;i++)
   {
   	if(company[i].age>=agestart&&company[i].age<=ageend)
   	sum=sum+company[i].salary;
   }
   cout<<"年龄段:"<<agestart<<"~"<<ageend<<endl;
   cout<<"人数为"<<n<<",\n总工资:"<<sum<<endl;
   return sum;
}
//===============================================
double mean(employee company[],int n,int agestart=0,int ageend=100)
{//计算某个年龄段的员工平均工资，返回值为平均工资 
	cout<<"请输入起始年龄:\n";
   cin>>agestart;
   cout<<"请输入结束年龄:\n";
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
   cout<<"年龄段:"<<agestart<<"~"<<ageend<<endl;
   cout<<"人数为"<<n<<",\n平均工资:"<<sum/num<<endl;
   return sum/num;
}
int main()
{
	int slct;//选择读入方式
	int n=0;
	employee company[MAX_SIZE] ;//定义员工信息表
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	cout<<"请选择：\n";
	cout<<"◇1.文件读取员工信息:\n";
	cout<<"◇2.手动读取员工信息:\n";
	cin>>slct; 
	if(slct==1)n=readfile(company);
	else if(slct==2)n=read(company);
	
	for(int choice;;)//无限循环，输入0退出
	{
		system("cls");
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_GREEN );
		cout<<"                ★★★★★★★★★★★★★★★★★★★★★\n";
		cout<<"                  ★★★ 欢迎使用员工工资管理系统 ★★★\n";
		cout<<"                   ★★★★★★★★★★★★★★★★★★\n";
		cout<<"                    ※※※※※※※※※※※※※※※※※\n";
		cout<<"                    ※      请选择需要的操作:       ※\n";
		cout<<"                    ※      1.更新员工信息;         ※\n";
		cout<<"                    ※      2.计算员工总工资;       ※\n";
		cout<<"                    ※      3.计算员工平均工资;     ※\n";
		cout<<"                    ※      4.保存员工信息到文件;   ※\n";
		cout<<"                    ※※※※※※※※※※※※※※※※※\n"<<endl;
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
