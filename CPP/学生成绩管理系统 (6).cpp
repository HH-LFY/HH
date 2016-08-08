#include<windows.h>//调用字体颜色系统函数的头文件 
#include<iostream>
#include<fstream>
using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//改变字体颜色的系统函数 
#define max 5
struct student
{
	char name[15];
	int number;
	int math;
	int english;
	int lisan;
	int sum;
	float avg;
	float failure;
	float pass;
	float good;
};

class sys
{
public:
	sys(){size=0;}
	~sys(){}
	void add();
	void show();
	void sort();
	void percent();
	void save();
	void output();
private:
    student stu[max];
	int size;
};

void sys::add() 
{   
	cout<<"学号：";
	cin>>stu[size].number;
	cout<<"姓名：";
	cin>>stu[size].name;
	cout<<"数学：";
	cin>>stu[size].math;
	cout<<"英语：";
	cin>>stu[size].english;
	cout<<"离散：";
	cin>>stu[size].lisan;
	size++;
}

void sys::show()
{   SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
   	cout<<"学号   姓名   数学   英语   离散"<<endl;
	for(int i=0;i<size;i++)
		{
             cout<<" "<<stu[i].number<<"      ";
			 cout<<" "<<stu[i].name<<"     ";
			 cout<<" "<<stu[i].math<<"     ";
			 cout<<" "<<stu[i].english<<"  ";
			 cout<<" "<<stu[i].lisan<<endl;
         }
}
void sys::percent()
{
     int a,b,c,m,i;
     a=b=c=m=0;
     stu[m].avg=(stu[m].math+stu[m].english+stu[m].lisan)/size;
	 printf("xxxxxxxx");
	 for(i=0;i<size;i++)
	 {	 if (stu[i].avg<60)
			a++;
		else
		{
			if(stu[i].avg>=60&&stu[i].avg<80)
				b++;
			else
				c++;
		}
	}
            stu[i].failure=100*a/size;
			stu[i].pass=100*b/size;
			stu[i].good=100*c/size;
	cout<<"the rate of failure is"<<stu[i].failure<<"%"<<endl;
	cout<<"the rate of pass is"<<stu[i].pass<<"%"<<endl;
    cout<<"the rate of good is"<<stu[i].good<<"%"<<endl;
}


void sys::sort()
{
	student temp;
	for(int m=0;m<size;m++)
	stu[m].sum=stu[m].math+stu[m].english+stu[m].lisan;
	for(int i=0;i<size;i++)
	    for(int j=0;j<size-i;j++)
			{
				if(stu[j].sum<stu[j+1].sum)
					{
					 temp=stu[j];
					 stu[j]=stu[j+1];
					 stu[j+1]=temp;
					 }
			}
	cout<<"学号   姓名   数学   英语   离散  总分"<<endl;
	for(int k=0;k<size;k++)
		{
             cout<<" "<<stu[k].number<<"      ";
			 cout<<" "<<stu[k].name<<"     ";
			 cout<<" "<<stu[k].math<<"     ";
			 cout<<" "<<stu[k].english<<"     ";
			 cout<<" "<<stu[k].lisan<<"    ";
			 cout<<" "<<stu[k].sum<<endl;
         }
}

void sys::save()
{
	ofstream ofile("D:\\sort.txt",ios_base::out);
	ofile<<"学号  姓名  数学  英语  离散   总分 "<<endl;
	for(int i=0;i<size;i++)
	{
		ofile<<stu[i].number<<"      "<<stu[i].name<<"     "<<stu[i].math<<"     "<<stu[i].english<<"     "<<stu[i].lisan<<"     "<<stu[i].sum<<"    "<<endl;
	}
	ofile.close();
	cout<<"学生信息已存入文件!"<<endl;
}

void sys::output() 
{

	char line[101];
	ifstream infile("D:\\sort.txt",ios_base::in);
	for(int i=0;i<size+1;i++)
	{
		infile.getline(line,100);
		cout<<line<<endl;
	}
	infile.close();
}

int main()
{
	sys people;
	int  enter;
	do
	{
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
		cout<<"***************************************************************************"<<endl;
		cout<<"****************************学生成绩管理系统*******************************"; 
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		cout<<endl<<endl;
		cout<<"1.添加   2.显示  3.排序  4.比例  5.保存  6.读文件 7.退出系统"<<endl;
		cout<<endl<<endl;
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		cout<<"***************************************************************************"<<endl;
		cout<<"*********关于软件---------专属涂小宝--------版权所有------翻版必究*********"<<endl;
		cout<<"***************************************************************************"<<endl;
		cout<<"请选择(1~7):";
		cin>>enter;
		switch(enter)
		{
			case 1: 
					cout<<"请依次输入该学生的学号，姓名以及数学，英语，离散三科成绩："<<endl;
					people.add();
					break;
			case 2: 
				people.show();   
				break;
			case 3:
					cout<<"按总分排名："<<endl;
					people.sort();
					break;
			case 4:
				cout<<" 各种比例："<<endl;
				people.percent();
				break;
			case 5:
					people.save();
					break;
			case 6:
					cout<<"读取文件信息如下："<<endl;
					people.output();
					break;
			}
	}while(enter<7);
	return 0;
}
