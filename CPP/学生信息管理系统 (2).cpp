#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class student
{
private:
    long int stu_num;      //学号，宿舍号
    char stu_name[40];     //姓名
    char class_name[40];   //班别
char house_name[20]; //宿舍
public:
    student()
{
   stu_num=0;
   stu_name[0] =0;
   class_name[0] =0;
   house_name[0] =0;
}
student::student(long a, char * b,char *c,char *d)
{
   Setdata(a , b, c, d);
}
char * Getstuname(void) //姓名查找
{
   return stu_name ;
}
long Getstunum(void) //学号查找
{
   return stu_num;
}
char * Gethousename(void) //宿舍号查找
{
   return house_name;
}
char * Getclassname(void) //按班级查找
{
   return class_name;
}
void Setdata(long a, char *b,char *c,char *d)
{
        stu_num = a;
        strcpy(stu_name, b);
        strcpy(class_name, c);
        strcpy(house_name, d);
}
void Show(void)
{
        cout<<"学号:"<<stu_num<<"\t"<<"姓名:"<<stu_name<<"\t";
        cout<<"班级:"<<class_name<<"\t\t"<<"宿舍:"<<house_name<<"\n";
}
};

void main(void)
{
student s1;
int flags=0;
    long stu_num; //学号
    char stu_name[40];        //姓名
    char class_name[40];        //班级
    char house_name[20];      //宿舍
time_t t;
    time(&t);
    ifstream file1;
    ofstream file3;
    char flag = 'y';
    cout<< "---------------------------------学生信息管理系统-------------------------------"<<endl;
    cout<< "\t\t\t 时间:" << ctime(&t);
    while( flag=='y' || flag=='Y')
{      //由flag控制循环
   cout<<"--------------------------------------------------------------------------------\n";
   cout<<"\t\t 1:注册学生!\n";
   cout<<"\t\t 2:按学号查看学生信息!\n";
   cout<<"\t\t 3:按宿舍号查看学生信息!\n";
   cout<<"\t\t 4:按姓名查看学生信息!\n";
   cout<<"\t\t 5:按班级查看学生信息!\n";
   cout<<"\t\t 6:显示全部学生信息\n";
   cout<<"\t\t 7:按学号修改学生信息\n";
//   cout<<"\t\t 8:按学号删除学生信息!\n";
   cout<<"--------------------------------------------------------------------------------\n";
   cout<<"请输入选择：";
   char choice;
   cin>>choice;
   switch(choice)
   {
        case '1':
    file3.open("c:\\stu.dat",ios::app|ios::binary);
input:      flags=0;
    cout<<"输入学号：";
    cin>>stu_num;
    while (stu_num<100000 || stu_num>999999)
    {
     cin.clear();
     rewind(stdin);
     cout << "你输入的学号不正确，请输入一个六位数的学号" << endl;
     cout << "学号:";
     cin >> stu_num;
    }
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//按读方式打开文件
    while(!file1.eof())
    {
     int n;
     file1.read((char *)&s1,sizeof(student));
     n=file1.gcount();
     if(n==sizeof(student))
     {
      if(s1.Getstunum()==stu_num)  
       flags=1;     
     }
    }
    file1.clear();
    file1.close();
    if (flags==1)
    {
     cin.clear();
     cout << "学号重复,请重输入!" << endl;
     goto input;
    }
    cout<<"输入姓名："; cin>>stu_name;
            cout<<"输入班级："; cin>>class_name;
            cout<<"输入宿舍："; cin>>house_name;
            s1.Setdata(stu_num,stu_name,class_name,house_name);
            file3.write((char*)&s1,sizeof(s1));
    file3.clear();
            file3.close();
            break;
        case '2': //按学号查找
            cout<<"请输入学生的学号：";
    cin>>stu_num;
    while (stu_num<100000 || stu_num>999999)
    {
     cin.clear();
     rewind(stdin);
     cout << "你输入的学号不正确，请输入一个六位数的学号" << endl;
     cout << "学号:";
     cin >> stu_num;
    }
            file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//按读方式打开文件
    while(!file1.eof())
    {
     int n;
     file1.read((char *)&s1,sizeof(student));
     n=file1.gcount();
     if(n==sizeof(student))
     {
      if(s1.Getstunum()==stu_num)    //显示学生信息
      {
       s1.Show();
       flags=1;
      }
     }
    }
    file1.clear();
            file1.close();
    if (flags==0)
     cout << "没有找学号为："<< stu_num <<"的学生记录!" << endl;
    flags=0;
            break;
   case '3':   //按宿舍号查找
    cout<<"请输入宿舍号:";
    cin>>house_name;
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//按读方式打开文件
            while(!file1.eof())
    {
                int n;
                file1.read((char *)&s1,sizeof(student));
                n=file1.gcount();
                if(n==sizeof(student))
     {
      if(strcmp(s1.Gethousename(),house_name)==0)
      {
       s1.Show();
       flags=1;
      }
                }
            }
    file1.clear();
            file1.close();
    if (flags==0)
     cout << "没有找到宿舍为:"<< house_name <<"的学生记录!" << endl;
    flags=0;
    break;
   case '4':   //按姓名查找
    cout<<"请输入学生姓名:";
    cin>>stu_name;
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//按读方式打开文件
            while(!file1.eof())
    {
                int n;
                file1.read((char *)&s1,sizeof(student));
                n=file1.gcount();
                if(n==sizeof(student))
     {
      if(strcmp(s1. Getstuname(),stu_name)==0)
      {
       s1.Show();
       flags=1;
      }
                }
            }
    file1.clear();
            file1.close();
    if (flags==0)
     cout << "没有找到姓名为:"<< stu_name <<"的学生记录!" << endl;
    flags=0;
    break;
   case '5':   //按班级查找
    cout<<"请输入班级名称:";
    cin>>class_name;
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//按读方式打开文件
            while(!file1.eof())
    {
                int n;
                file1.read((char *)&s1,sizeof(student));
                n=file1.gcount();
                if(n==sizeof(student))
     {
      if(strcmp(s1. Getclassname(),class_name)==0)
      {
       s1.Show();
       flags=1;
      }
                }
            }
    file1.clear();
            file1.close();
    if (flags==0)
     cout << "没有找到该班级为:"<< class_name <<"的学生记录!" << endl;
    flags=0;
    break;
   case '6': //显示全部学生信息
            file1.open("c:\\stu.dat",ios::in | ios::binary);//按读方式打开文件
            while(!file1.eof())
    {
                int n;
                file1.read((char *)&s1,sizeof(student));
                n=file1.gcount();
                if(n==sizeof(student))
     {
      s1.Show();
      flags=1;
                }
            }
    file1.clear();
            file1.close();
    if (flags==0)
     cout << "数据库没有记录!" << endl;
    flags=0;
    break;
   case '7':   //修改学生信息按学号
    flags=0;
    cout<<"请输入要修改学生的学号:";
    cin>>stu_num;
    while (stu_num<100000 || stu_num>999999)
    {
     cin.clear();
     rewind(stdin);
     cout << "你输入的学号不正确，请输入一个六位数的学号" << endl;
     cout << "学号:";
     cin >> stu_num;
    }
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//按读方式打开文件
    while(!file1.eof())
    {
     int n;
     file1.read((char *)&s1,sizeof(student));
     n=file1.gcount();
     if(n==sizeof(student))
     {
      if(s1.Getstunum()==stu_num)
      {
       file3.open("c:\\stu.dat",ios::out|ios::binary);
       cout<<"输入姓名："; cin>>stu_name;
       cout<<"输入班级："; cin>>class_name;
       cout<<"输入宿舍："; cin>>house_name;
       s1.Setdata(stu_num,stu_name,class_name,house_name);
       file3.write((char*)&s1,sizeof(s1));
      file3.close();
       flags=1;
      }
     }
    }
    file1.clear();
            file1.close();
    if (flags==0)
    {
     cout << "没有此学生记录，不能进行修改！" << endl;
     break;
    }
    break;
// case '8':   //删除学生信息按学号
   default: flag = 'n';
    break;
        }
    }
cout << "谢谢您的使用!" << endl;
}