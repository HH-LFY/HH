#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<windows.h>
using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
int m;

struct student
{
int num;
char name[20];
int age;
char sex[4];
float 	Chinese;
float Mathematics;
float English;
float Matlab;
}  stu[20];

///void del();
///void sadd();
///void read();
///void find();
///void change();

int main()
{
char c;
void change();  //修改信息
void del();     //删除信息
void sadd();    //添加信息
void read();   //读取信息
void find();   //查找信息

/*student stu[5] = {
100,"li",22,"nan",88,77,88,69,
101,"qs",34,"nan",78,78,69,79,
102,"ds",34,"nan",68,78,69,79,
103,"wa",34,"nan",58,78,69,79,
104,"jk",34,"nan",48,78,69,79};


fstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);  //ios::in方式打开文件时，文件必须存在。
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
exit(1);
}
for(int i=0;i<5;i++)     //把5个初值写入文件
{iofile.write((char *)&stu[i],sizeof(stu[i]));}
iofile.close();*/

do
{//system("color 3b");  
  SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE); //字体及背景颜色
cout<<"  \n\n          |学 生 信 息 绩 管 理 系 统|     \n";
cout<<"        *************************************************\n";
cout<<"        *    1……增加学生信息                          *\n";
cout<<"        *     2……删除学生信息                          *\n";
cout<<"        *      3……修改学生信息                          *\n";
SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED );
cout<<"        *       4……查询学生信息                          *\n";
cout<<"        *        5……读取学生信息                          *\n";
cout<<"        *         6……退出管理系统                          *\n";
cout<<"        *************************************************\n";
cout<<"请选择(1-8):";
cin>>c;
switch(c)
{
   case '1':     sadd();break;
   case '2':     del();break;
   case '3':     change();break;
   case '5':     read();break;
   case '4':     find();break;
}
}while(c!='6');
return 0;
}

void sadd()
{system("cls");
int i,m;
m=0;
char yn;
student stu[20];
cout<<"请输入要添加的："<<endl;
for(i=0;i<20;i++)   //先录入到结构数组
{
cout<<"学号:"<<endl;
cin>>stu[i].num;
cout<<"姓名:"<<endl;
cin>>stu[i].name;
cout<<"年龄 :"<<endl;
cin>>stu[i].age;
cout<<"性别:"<<endl;
cin>>stu[i].sex;
cout<<"语文 :"<<endl;
cin>>stu[i].Chinese;
cout<<"高数:"<<endl;
cin>>stu[i].Mathematics;
cout<<"英语:"<<endl;
cin>>stu[i].English;
cout<<"MATLAB"<<endl;
cin>>stu[i].Matlab;

fstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);

if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
exit(1);
}
iofile.seekp(0,ios::end);  //找到文件末尾，具体用法见课本270

iofile.write((char *)&stu[i],sizeof(stu[i]));  //把结构数组（学生）信息添加到文件末尾处

iofile.close();
cout<<"继续（y/n)\n";
cin>>yn;
if(yn=='n')
i=19;   //用break亦可
system("cls");
}
}

void read()   //读取文件中现有的所有学生信息
{system("cls");
int i;
fstream iofile("wwz314.dat",ios::in|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
abort();
}

iofile.seekg(0,ios::beg);

for(i=0;i<20;i++)   //把学号为非0的读出
{
   iofile.read((char *)&stu[i],sizeof(stu[i]));
   if(stu[i].num!=0) cout<<" 学号:"<<stu[i].num<<" 姓名:"<<stu[i].name<<" 年龄:"<<stu[i].age<<" 性别:"<<stu[i].sex<<" 语文 :"<<stu[i].Chinese<<" 高数:"<<stu[i].Mathematics<<" 英语:"<<stu[i].English<<" MATLAB:"<<stu[i].Matlab<<endl;
}
iofile.close();
}


void find()    //查找指定学生信息
{
void findname();  //按名字查找函数说明，另定义函数

void findnum();  //按学号

cout<<"请选择查找方法:"<<endl;
   cout<<"         1.....按姓名查找."<<endl;
   cout<<endl;
   cout<<"         2.....按学号查找."<<endl;
   cout<<endl;
cout<<"请选择:";
int k;
cin>>k;
switch(k)
{
case 1: findname();break;
    case 2: findnum();break;
    }
}

void findname()  //按名字查找代码
{

	cout<<"请输入要查找的姓名：";

	string name;

	int j,i;

	cin>>name;

	fstream iofile("wwz314.dat",ios::in|ios::binary);

	if(! iofile)

	{

		cerr<<"文件打开失败!"<<endl;

		abort();

	}

iofile.seekg(0,ios::beg);
for(i=0;i<20;i++)
{
iofile.read((char *)&stu[i],sizeof(stu[i]));
   if(name==stu[i].name)
   {j=1;
   cout<<"你要查找的资料是:"<<endl;
   cout<<"学号 :"<<stu[i].num<<endl;
   cout<<"姓名 :"<<stu[i].name<<endl;
   cout<<"年龄 :"<<stu[i].age<<endl;
   cout<<"性别 :"<<stu[i].sex<<endl;
   cout<<"语文 :"<<stu[i].Chinese<<endl;
   cout<<"高数 :"<<stu[i].Mathematics<<endl;
   cout<<"英语 :"<<stu[i].English<<endl;
   cout<<"MATLAB:"<<stu[i].Matlab<<endl;
   cout<<endl;
   i=19;}
}
if (j!=1) cout<<"对不起,没找到你要的信息!"<<endl<<endl ;
   iofile.close();
}

void findnum()
{
cout<<"请输入要查找的学号：";
int num;
int j,i;
cin>>num;
fstream iofile("wwz314.dat",ios::in|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
abort();
}

iofile.seekg(0,ios::beg);
for(i=0;i<20;i++)
{
   iofile.read((char *)&stu[i],sizeof(stu[i]));
    if(num==stu[i].num)
{j=1;
   cout<<"你要查找的资料是:"<<endl;
   cout<<"学号 :"<<stu[i].num<<endl;
   cout<<"姓名 :"<<stu[i].name<<endl;
   cout<<"年龄 :"<<stu[i].age<<endl;
   cout<<"性别 :"<<stu[i].sex<<endl;
   cout<<"语文 :"<<stu[i].Chinese<<endl;
   cout<<"高数 :"<<stu[i].Mathematics<<endl;
   cout<<"英语 :"<<stu[i].English<<endl;
   cout<<"MATLAB:"<<stu[i].Matlab<<endl;
   cout<<endl;
   i=19;}
}
if (j!=1) cout<<"对不起,没找到你要的信息!"<<endl<<endl ;
}

void del()
{//void read();
cout<<"请输入学号：";
int num;
int temp=-1;
int j=0,i;
cin>>num;
ifstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
abort();
}

iofile.seekg(0,ios::beg);

for(i=0;i<20;i++)
{
   iofile.read((char *)&stu[i],sizeof(stu[i]));
   if(num==stu[i].num)
   {j=1;   //找到后进行标记
   temp=i;  //找到的序号
   }
}
iofile.close();
if(j!=1)
{
cout<<"对不起,没找到你要的信息!"<<endl<<endl ;
}
if(temp!=-1)
{ofstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
abort();
}

    cout<<"确定删除吗?[y/n]"<<endl;
    char c;cin>>c;
    if(c=='y')    //把待删除的所有学生信息置0，再重写到文件，其实未真正删除
     {
      stu[temp].num=0;
      stu[temp].name[0]='0';
      stu[temp].age=0;
      stu[temp].sex[0]='0';
      stu[temp].Chinese=0;
      stu[temp].Mathematics=0;
      stu[temp].English=0;
      stu[temp].Matlab=0;

   iofile.seekp(temp*sizeof(stu[temp]),ios::beg);
   iofile.write((char *)&stu[temp],sizeof(stu[temp]));
   cout<<"已经成功删除!"<<endl;   //其实未真正删除
}}
}

void change()
{
//void read();
cout<<"请输入学号：";
char name[20],sex[20];
int temp,chi,mat,lab,eng,age,num;
int j,i;
cin>>num;
ifstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{cerr<<"文件打开失败!"<<endl;
abort();
}

iofile.seekg(0,ios::beg);

for(i=0;i<20;i++)
{
   iofile.read((char *)&stu[i],sizeof(stu[i]));
   if(num==stu[i].num)
   {j=1;
   temp=i;
   }
}
   if(j!=1)
   {
cout<<"对不起,没找到你要的信息!"<<endl<<endl ;
   }
iofile.close();
if(temp!=-1)
{ofstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
abort();
}
cout<<"确定修改吗?[y/n]"<<endl;
char c;cin>>c;
if(c='y')
{
   cout<<"请输入新的学生的学号:"<<"原学号："<<stu[temp].num<<endl;
   cin>>num;
   stu[temp].num=num;
   cout<<"请输入新的学生的姓名:"<<"原姓名："<<stu[temp].name<<endl;
   cin>>name;
   strcpy(stu[temp].name,name);
   cout<<"请输入新的学生的年龄:"<<"原年龄："<<stu[temp].age<<endl;
   cin>>age;
   stu[temp].age=age;
   cout<<"请输入新的学生的性别:"<<"原性别："<<stu[temp].sex<<endl;
   cin>>sex;
   strcpy(stu[temp].sex,sex);
   cout<<"请输入新的学生的语文分数"<<"原成绩："<<stu[temp].Chinese<<endl;
   cin>>chi;
   stu[temp].Chinese=chi;
   cout<<"请输入新的学生的高数分数"<<"原成绩："<<stu[temp].Mathematics<<endl;
   cin>>mat;
   stu[temp].Mathematics=mat;
   cout<<"请输入新的学生的英语分数"<<"原成绩："<<stu[temp].English<<endl;
   cin>>eng;
   stu[temp].English=eng;
   cout<<"请输入新的学生的MATLAB分数"<<"原成绩："<<stu[i].Matlab<<endl;
   cin>>lab;
   stu[i].Matlab=lab;
    iofile.seekp(temp*sizeof(stu[temp]),ios::beg);
   iofile.write((char *)&stu[temp],sizeof(stu[temp]));
   cout<<"已经成功修改！"<<endl;
   }}
}

