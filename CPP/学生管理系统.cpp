#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<windows.h>
using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

struct student
{ 
  int  num;
  char name[10];
  int  age;
  char sex[5];
  float  Chinese;
  float  Math;
  float  English;
  float  Java;
} stud[10];  

int main()
{int t;            //定义一个整型变量t，来进行主界面的选项选择 
void read();      //声明一个读取文件中现有的学生信息的函数 
void find();      //声明一个按照要求查找学生信息的函数 
void add();       //声明一个添加学生信息的函数 
void cancel();    //声明一个删除学生信息的函数 
void change();    //声明一个修改信息的函数 
//======================================================
student stud[10] = 
	{
       1001,"陈天成",18,"man",90,66,60,87,
       1002,"林朝晖",20,"man",97,79,68,80,
       1003,"钟泽南",20,"man",78,89,80,90,
       1004,"黄罐华",19,"man",84,77,69,91,
       1005,"胡海"  ,18,"man",91,90,70,67,
   };

fstream iofile("longbiao.dat",ios::in|ios::out|ios::binary|ios::trunc);
 
if(!iofile)
{
   cerr<<"文件打开失败!"<<endl;
   exit(1);     
}
for(int i=0;i<5;i++)     
{iofile.write((char *)&stud[i],sizeof(stud[i]));}
iofile.close();
//======================================================

do
{ SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
    cout<<"                      ☆欢迎使用学生管理系统☆                           "<<endl;                                                                       
	cout<<"         ╲                 ☆        ☆         ╱        ╱            "<<endl;
	cout<<"           ╲              ★          ★      ╱        ╱              "<<endl; 
	cout<<"             ╲           ★            ★   ╱        ╱                "<<endl; 
    cout<<"               ╲        ★              ★╱        ╱                  "<<endl;
	cout<<"                 ╲                      ╱        ╱                    "<<endl;
	cout<<"     ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
	cout<<"     ※1***********读╲取学生信息              ╱                      ※"<<endl;
	cout<<"     ※2***********查询╲学生信息            ╱                        ※"<<endl;
	cout<<"     ※3***********添加学╲生信息          ╱                          ※"<<endl;
	cout<<"     ※4***********删除学生╲信息        ╱                            ※"<<endl;
	cout<<"     ※5***********修改学生信╲息      ╱                              ※"<<endl;
	cout<<"     ※6***********退出管理系统╲    ╱                                ※"<<endl;
	cout<<"     ※                  ╱      ╲╱                                  ※"<<endl; 
	cout<<"     ※                ╱        ╱╲                                  ※"<<endl;
	cout<<"     ※              ╱        ╱    ╲                  →龙标制作    ※"<<endl;
	cout<<"     ※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※"<<endl;
	cout<<"                ╱        ╱             ╲                              "<<endl;
	cout<<"              ╱        ╱                 ╲                            "<<endl;
	cout<<"            ╱        ╱                     ╲                          "<<endl;
	cout<<"          ╱        ╱                         ╲                        "<<endl;
	cout<<"        ╱        ╱                             ╲                      "<<endl; 
cout<<"※※※※※※※        请选择(1-6):"; 
cin>>t;
switch(t)
{
   case 1:     read();break;
   case 2:     find();break;
   case 3:     add();break;
   case 4:     cancel();break;
   case 5:     change();break;
}
}while(t!=6);
return 0;
}


//==============================定义一个读取文件中现有的学生信息的函数
void read()            
{ system("cls");       
    int i; 
    fstream iofile("longbiao.dat",ios::in|ios::binary);
    if(! iofile)
{
    cerr<<"文件打开失败!"<<endl;
    exit(1);
}
for(i=0;i<10;i++)   
{
   iofile.read((char *)&stud[i],sizeof(stud[i]));
   if(stud[i].num!=0)   //其余没有赋值的都为零，所以碰到零就不在输出了 
   cout<<" 学号:"<<stud[i].num<<" 姓名:"<<stud[i].name<<" 年龄:"<<stud[i].age<<" 性别:"<<stud[i].sex<<" 语文 :"<<stud[i].Chinese<<" 高数:"<<stud[i].Math<<" 英语:"<<stud[i].English<<" JAVA:"<<stud[i].Java<<endl<<endl;
}
   iofile.close();
}


//==============================定义一个按照要求查找学生信息的函数
void find()   
{
void find_name();  //按名字查找指定学生信息
void find_num();  //按学号查找指定学生信息

cout<<"请选择查找方法:"<<endl;
   cout<<"※※※※※※※        1、按姓名查找。。。"<<endl;
   cout<<endl;
   cout<<"※※※※※※※        2、按学号查找。。。"<<endl;
   cout<<endl;
   cout<<"※※※※※※※        请选择 :";
int z;
cin>>z;
switch(z)
{
    case 1: find_name();break;
    case 2: find_num();break;
    }
}
void find_name()   //按名字查找学生信息 
{
    cout<<"※※※※※※※        请输入要查找的姓名：";
    string name;
    int i,j;     //j用来其标记作用， 
    cin>>name;
fstream iofile("longbiao.dat",ios::in|ios::binary);   
  if(! iofile)
  {
    cerr<<"文件打开失败!"<<endl;
    exit(1);
  }
for(i=0;i<10;i++)
{
iofile.read((char *)&stud[i],sizeof(stud[i]));
   if(name==stud[i].name)
   {j=1;
   cout<<"※※※※※※※        你要查找的学生信息是:"<<endl;
   cout<<"学号 :"<<stud[i].num<<endl;
   cout<<"姓名 :"<<stud[i].name<<endl;
   cout<<"年龄 :"<<stud[i].age<<endl;
   cout<<"性别 :"<<stud[i].sex<<endl;
   cout<<"语文 :"<<stud[i].Chinese<<endl;
   cout<<"高数 :"<<stud[i].Math<<endl;
   cout<<"英语 :"<<stud[i].English<<endl;
   cout<<"JAVA :"<<stud[i].Java<<endl;
   cout<<endl;
   i=9;}
}
if (j!=1) cout<<"※※※※※※※        对不起,没找到你要的信息!"<<endl<<endl ;
iofile.close();
}
void find_num()     //按学号查找学生信息 
{
cout<<"※※※※※※※        请输入要查找的学号：（例如：1001）";
int num;
int i,j;  //j用来起标记作用 
cin>>num;
fstream iofile("longbiao.dat",ios::in|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
exit(1);
}
for(i=0;i<10;i++)
{
    iofile.read((char *)&stud[i],sizeof(stud[i]));
    if(num==stud[i].num)
{  j=1;
   cout<<"※※※※※※※        你要查找的学生信息是:"<<endl;
   cout<<"学号 :"<<stud[i].num<<endl;
   cout<<"姓名 :"<<stud[i].name<<endl;
   cout<<"年龄 :"<<stud[i].age<<endl;
   cout<<"性别 :"<<stud[i].sex<<endl;
   cout<<"语文 :"<<stud[i].Chinese<<endl;
   cout<<"高数 :"<<stud[i].Math<<endl;
   cout<<"英语 :"<<stud[i].English<<endl;
   cout<<"JAVA :"<<stud[i].Java<<endl;
   cout<<endl;
   i=9;}
}
if (j!=1) cout<<"※※※※※※※        对不起,没找到你要的信息!"<<endl<<endl ;
}

//==============================定义一个添加学生信息的函数  
void add()
{system("cls");
int i;
char j; // 定义一个字符型变量j，用于选项选择 
cout<<"※※※※※※※       请按要球输入要添加的信息："<<endl;
for(i=0;i<10;i++)   
{
cout<<"学号:"<<"    ";  cin>>stud[i].num;
cout<<"姓名:"<<"    ";  cin>>stud[i].name;
cout<<"年龄:"<<"    ";  cin>>stud[i].age;
cout<<"性别:"<<"    ";  cin>>stud[i].sex;
cout<<"语文:"<<"    ";  cin>>stud[i].Chinese;
cout<<"高数:"<<"    ";  cin>>stud[i].Math;
cout<<"英语:"<<"    ";  cin>>stud[i].English;
cout<<"JAVA:"<<"    ";  cin>>stud[i].Java;

fstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
exit(1);
}
//=======================================
iofile.seekp(0,ios::end); 
//=======================================
iofile.write((char *)&stud[i],sizeof(stud[i]));  
iofile.close();
cout<<"※※※※※※※   是否继续添加学生信息（输入任意的数字或字母继续，否则请输入n）"<<endl;
cin>>j;
if(j=='n')
i=9;   
system("cls");
}
}

//==============================定义一个删除学生信息的函数
void cancel()
{ cout<<"※※※※※※※        请输入要删除的学号（例如1001）：";
  int num;
  int temp=1; //定义一个用来存储学号的变量temp，同时也可以起标记作用 
  int i,j;   //j用来起标记作用 
  cin>>num;
ifstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
exit(1);
}
for(i=0;i<10;i++)
{
   iofile.read((char *)&stud[i],sizeof(stud[i]));
   if(num==stud[i].num)
   {j=1;     
   temp=i;   
   }
}
iofile.close();
if(j!=1)
{
cout<<"※※※※※※※        对不起,没找到你要的信息!"<<endl<<endl ;
}
if(temp!=1)
{ofstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
exit(1); 
}

    cout<<"※※※※※※※       确定删除吗?（确定请输入Y，输入任意的数字或字母将返回）"<<endl;
    char c;
	cin>>c;
    if(c=='y')    
     {
      stud[temp].num=0;
      stud[temp].name[0]='0';
      stud[temp].age=0;
      stud[temp].sex[0]='0';
      stud[temp].Chinese=0;
      stud[temp].Math=0;
      stud[temp].English=0;
      stud[temp].Java=0;
//================================================
   iofile.seekp(temp*sizeof(stud[temp]),ios::beg);
//================================================
   iofile.write((char *)&stud[temp],sizeof(stud[temp]));
   cout<<"已经成功删除!"<<endl;   
}}
}

//==============================定义一个修改信息的函数
void change()
{
cout<<"※※※※※※※       请输入学号（例如1001）：";
char name[10],sex[5];
int temp=1,chi,mat,Ja,eng,age,num;
int i,j;
cin>>num;
ifstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{cerr<<"文件打开失败!"<<endl;
exit(1);
}
for(i=0;i<10;i++)
{
   iofile.read((char *)&stud[i],sizeof(stud[i]));
   if(num==stud[i].num)
   {j=1;
   temp=i;
   }
}
if(j!=1)
   {
       cout<<"※※※※※※※       对不起,没找到你要的信息!"<<endl<<endl ;
   }
iofile.close();
if(temp!=1)
{ofstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"文件打开失败!"<<endl;
exit(1);
}
cout<<"※※※※※※※       确定修改吗?（确定请输入Y，输入任意的数字或字母将返回）"<<endl;
char c;
cin>>c;
if(c='y')
{
   cout<<"※※※※※※※       请输入新的学生的学号:"<<"原学号为："<<stud[temp].num<<endl;cin>>num;
   stud[temp].num=num;
   cout<<"※※※※※※※       请输入新的学生的姓名:"<<"原姓名为："<<stud[temp].name<<endl;cin>>name;
   strcpy(stud[temp].name,name);
   cout<<"※※※※※※※       请输入新的学生的年龄:"<<"原年龄为："<<stud[temp].age<<endl;cin>>age;
   stud[temp].age=age;
   cout<<"※※※※※※※       请输入新的学生的性别:"<<"原性别为："<<stud[temp].sex<<endl;cin>>sex;
   strcpy(stud[temp].sex,sex);
   cout<<"※※※※※※※       请输入新的学生的语文分数"<<"原成绩为："<<stud[temp].Chinese<<endl;cin>>chi;
   stud[temp].Chinese=chi;
   cout<<"※※※※※※※       请输入新的学生的高数分数"<<"原成绩为："<<stud[temp].Math<<endl;cin>>mat;
   stud[temp].Java=mat;
   cout<<"※※※※※※※       请输入新的学生的英语分数"<<"原成绩为："<<stud[temp].English<<endl;cin>>eng;
   stud[temp].English=eng;
   cout<<"※※※※※※※       请输入新的学生的JAVA分数"<<"原成绩为："<<stud[temp].Java<<endl;cin>>Ja;
   stud[temp].Java=Ja;
   iofile.write((char *)&stud[temp],sizeof(stud[temp]));
   cout<<"※※※※※※※       已经成功修改 "<<endl;
   }
}
}

