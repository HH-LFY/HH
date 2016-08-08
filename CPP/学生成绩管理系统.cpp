


#include <iostream> 
#include <string.h>
#include <ctime>     //时间头文件
#include <conio.h>   //库函数进行输入输出
using namespace std;
struct student //定义学生类
{
int num; //学号
char name[8]; //姓名
char classes[20]; //班别 
int math,english,computer,sum; //数学，英语，计算机，平均总成绩
};
int s=0; //全局变量
class student1
{
private:
student stu[40]; //结构体变量
char name, classes;
int num;
int math,english,computer,sum;
public:
void input(int, char *, char *, int, int, int);
void output(int);
int check(int stu_num)
{
   int m=0;
   while(m<=s+1)
    if(stu_num==stu[m++].num)
    {
     return 1;
     break;
    }
    if(m>s+1)
     return 0;
    else 
     return 1;
}
void search(int);
void search1(int);
void deleted(int);
void deleted1(int);
void desc(int);
void desc1(int);
void desc2(int);
};
void student1::input(int stu_num,char *stu_name, char *stu_classes, 
					 int stu_math, int stu_english, int stu_computer) //输入模块
{
stu[s].num=stu_num;
strcpy(stu[s].name, stu_name);
strcpy(stu[s].classes, stu_classes);
stu[s].math=stu_math;
stu[s].english=stu_english;
stu[s].computer=stu_computer;
}
void student1::output(int s) //输出模块
{
cout << s << "\t";
cout << stu[s].num << "\t";
cout << stu[s].name << "\t";
cout << stu[s].classes << "\t";
cout << stu[s].math << "\t\t";
cout << stu[s].english << "\t\t";
cout << stu[s].computer << "\t\n";
}
void student1::search(int s) //查找模块
{
int stu_num,p;
while (s==0)
{
   cout <<"没有记录,请先输入记录!" <<endl;
   break;
}
if (s!=0)
{
   cout << "请输入你要查找的学号:";
   cin >> stu_num;
   while (stu_num<100000 || stu_num>999999) //判断学号是否正确
   {
    cin.clear();
    rewind(stdin);            //将文件指针重新指向一个流的开头
    cout << "你输入的学号不正确，请输入一个六位数的学号" << endl;
    cin >> stu_num;
   }
   while (s!=0)            //查找是否有符合条件的记录
   {
    p=1;
    if (stu_num==stu[s].num)
    {
     cout << "学号\t姓名\t班级\t数学成绩\t英语成绩\t计算机成绩\t" << endl;
     cout << stu[s].num << "\t";
     cout << stu[s].name << "\t";
     cout << stu[s].classes << "\t";
     cout << stu[s].math << "\t\t";
     cout << stu[s].english << "\t\t";
     cout << stu[s].computer << "\t\n";
     getch(); 
     break;
    }
    else
     p=0;
    s--;
   }
   if (p==0)
    cout << "没有找到你要查找的记录!" << endl;
}
getch();
}
void student1::search1(int s) //按姓名查找模块
{
char stu_name[8],p;
while (s==0)
{
   cout <<"没有记录,请先输入记录!" <<endl;
   break;
}
if (s!=0)
{
   cout << "请输入你要查找的姓名:";
   cin >> stu_name;
   while (s!=0) //查找是否有符合条件的记录
   {
    p=1;
    if (strcmp(stu_name, stu[s].name)==0)
    {
     cout << "学号\t姓名\t班级\t数学成绩\t英语成绩\t计算机成绩\t" << endl;
     cout << stu[s].num << "\t";
     cout << stu[s].name << "\t";
     cout << stu[s].classes << "\t";
     cout << stu[s].math << "\t\t";
     cout << stu[s].english << "\t\t";
     cout << stu[s].computer << "\t\n";
     getch();
     break;
    }
    else
     p=0;
    s--;
   }
   if (p==0)
    cout << "没有找到你要查找的记录!" << endl;
}
getch();
}
void student1::deleted(int n)    //删除模块
{
int stu_num,p;
char yes;
while (s==0)
{
   cout << "没有记录，请先输入记录!" << endl;
   break;
}
if (s!=0)
{
   cout << "请输入要删除的学号:";
   cin >> stu_num;
   while (stu_num<100000 || stu_num>999999)
   {
    cin.clear();
    rewind(stdin);
    cout << "你输入的学号不正确，请输入一个六位数的学号" << endl;
    cout << "学号:";
    cin >> stu_num;
   }
   for (int i=1;i<=n;i++)
   {
    if (stu[i].num!=stu_num)
     p=0;
    if (stu[i].num==stu_num)   
    {
     cout << "学号\t姓名\t班级\t数学成绩\t英语成绩\t计算机成绩\t" <<endl;
     cout << stu[i].num << "\t";
     cout << stu[i].name << "\t";
     cout << stu[i].classes << "\t";
     cout << stu[i].math << "\t\t";
     cout << stu[i].english << "\t\t";
     cout << stu[i].computer << endl;
     cout << "你确定要删除此学生记录吗?(y/n)";
     cin >> yes;
     if (yes == 'y' || yes == 'Y')
     {
      for (int j=1; j<=n-1; j++) //删除记录
      {
       stu[j].num=stu[j+1].num;
       strcpy(stu[j].name, stu[j+1].name);
       strcpy(stu[j].classes, stu[j+1].classes);
       stu[j].math=stu[j+1].math;
       stu[j].english=stu[j+1].english;
       stu[j].computer=stu[j+1].computer;
      }
      cout << "学生记录删除成功" <<endl;
      s=s-1;
      p=1;
      break;
     }
     else
     {
      cout << "学生记录删除失败" << endl;
      p=1;
     }
    }
   }
   if (p==0) 
	   cout << "没有找到你要查找的记录!" <<endl;
}
getch();
   
}
void student1::deleted1(int n) //按姓名删除模块
{
char stu_name[8],p;
char yes;
while (s==0)
{
   cout << "没有记录，请先输入记录!" << endl;
   break;
}
if (s!=0)
{
   cout << "请输入要删除的姓名:";
   cin >> stu_name;
   for (int i=1;i<=n;i++)
   {
    if (strcmp(stu[i].name, stu_name)<0 || strcmp(stu[i].name, stu_name)>0)
     p=0;          //两个字符串自左向右逐个字符相比
    if (strcmp(stu[i].name, stu_name)==0)
    {
     cout << "学号\t姓名\t班级\t数学成绩\t英语成绩\t计算机成绩\t" <<endl;
     cout << stu[i].num << "\t";
     cout << stu[i].name << "\t";
     cout << stu[i].classes << "\t";
     cout << stu[i].math << "\t\t";
     cout << stu[i].english << "\t\t";
     cout << stu[i].computer << endl;
     cout << "你确定要删除此学生记录吗?(y/n)";
     cin >> yes;
     if (yes == 'y' || yes == 'Y')
     {
      for (int j=1; j<=n-1; j++) //删除记录
      {
       stu[j].num=stu[j+1].num;
       strcpy(stu[j].name, stu[j+1].name);
       strcpy(stu[j].classes, stu[j+1].classes);
       stu[j].math=stu[j+1].math;
       stu[j].english=stu[j+1].english;
       stu[j].computer=stu[j+1].computer;
      }
      cout << "学生记录删除成功" <<endl;
      s=s-1;
      p=1;
      break;
     }
     else
     {
      cout << "学生记录删除失败" << endl;
      p=1;
     }
    }
   }
   if (p==0)
    cout << "没有找到你要查找的记录!" <<endl;
}
getch();
}
void student1::desc1(int s) //按学号排序
{
int temp;
int sum[40];
while (s==0)
{
   cout << "没有记录,请先输入记录!" <<endl;
   break;
}
if (s!=0)
{
   cout << "学号\t姓名\t班级\t数学成绩\t英语成绩\t计算机成绩\t" <<endl;
   for (int k=1;k<=s;k++)
    sum[k]=stu[k].num;
   for (int i=1;i<=s;i++) //利用冒泡法对sum[]进行排序
    for (int j=1;j<=s-i;j++)
     if (sum[j]>sum[j+1])
     {
      temp=sum[j];
      sum[j]=sum[j+1];
      sum[j+1]=temp;
     }
     for (int x=1;x<=s;x++) //输出与sum[]中相同总分所对应的内容
      for (int y=1;y<=s;y++)
       if (sum[x]==stu[y].num)
       {
        cout << stu[y].num << "\t";
        cout << stu[y].name << "\t";
        cout << stu[y].classes << "\t";
        cout << stu[y].math << "\t\t";
        cout << stu[y].english << "\t\t";
        cout << stu[y].computer << "\t\t";
        cout << endl;
       }
}
getch();
}
void student1::desc2(int s) //按姓名排序
{
char sum[40][8];
char temp[8];
while (s==0)
{
   cout << "没有记录,请先输入记录!" <<endl;
   break;
}
if (s!=0)
{
   cout << "学号\t姓名\t班级\t数学成绩\t英语成绩\t计算机成绩\t" <<endl;
   for (int k=1;k<=s;k++)
    strcpy(sum[k], stu[k].name);
   for (int i=1;i<=s;i++)             //利用冒泡法对sum[]进行排序
    for (int j=1;j<=s-i;j++)
     if (strcmp(sum[j], sum[j+1])>0)
     {
      strcpy(temp, sum[j]);
      strcpy(sum[j], sum[j+1]);
      strcpy(sum[j+1], temp);
     }
     for (int x=1;x<=s;x++)          //输出与sum[]中相同总分所对应的内容
      for (int y=1;y<=s;y++)
       if (strcmp(sum[x], stu[y].name)==0)
       {
        cout << stu[y].num << "\t";
        cout << stu[y].name << "\t";
        cout << stu[y].classes << "\t";
        cout << stu[y].math << "\t\t";
        cout << stu[y].english << "\t\t";
        cout << stu[y].computer << "\t\t";
        cout << endl;
       }
}
getch();
}
void student1::desc(int s) //平均成绩排序模块
{
int temp;
int sum[40];
while (s==0)
{
   cout << "没有记录,请先输入记录!" <<endl;
   break;
}
if (s!=0)
{
   cout << "学号\t姓名\t班级\t数学成绩\t英语成绩\t计算机成绩\t平均成绩" <<endl;
   for (int k=1;k<=s;k++)
   {
    sum[k]=(stu[k].math+stu[k].english+stu[k].computer)/3; //平均成绩
    stu[k].sum=(stu[k].math+stu[k].english+stu[k].computer)/3;
   }
   for (int i=1;i<=s;i++) //利用冒泡法对sum[]进行排序
    for (int j=1;j<=s-i;j++)
     if (sum[j]<sum[j+1])
     {
      temp=sum[j];
      sum[j]=sum[j+1];
      sum[j+1]=temp;
     }
     for (int x=1;x<=s;x++) //输出与sum[]中相同总分所对应的内容
      for (int y=1;y<=s;y++)
       if (sum[x]==stu[y].sum)
       {
        cout << stu[y].num << "\t";
        cout << stu[y].name << "\t";
        cout << stu[y].classes << "\t";
        cout << stu[y].math << "\t\t";
        cout << stu[y].english << "\t\t";
        cout << stu[y].computer << "\t\t";
        cout << stu[y].sum << endl;
       }
}
getch();
}
int main(int argc, char *argv[])   //主函数
{
student1 st;
char yes,choice;
char *name,*classes;
int math, english, computer, num;
time_t t;
time(&t);
while (1)
{
   system("cls");
   cout<< "\t--------------------------学生成绩管理系统--------------------------"<<endl;
   cout<< "\t\t\t时间:" << ctime(&t);
   cout<<"--------------------------------------------------------------------------------\n" 
    <<"                           1.增加学生成绩记录\n" 
    <<"                           2.显示学生成绩记录\n" 
    <<"                           3.查询学生成绩记录--按学号\n" 
    <<"                           4.查询学生成绩记录--按姓名\n" 
    <<"                           5.删除学生成绩记录--按学号\n" 
    <<"                           6.删除学生成绩记录--按姓名\n" 
    <<"                           7.排序学生成绩记录--按学号\n" 
    <<"                           8.排序学生成绩记录--按姓名\n" 
    <<"                           9.排序学生成绩记录--按平均成绩\n" 
    <<"                           0.退出学生成绩管理系统\n"
    <<"--------------------------------------------------------------------------------\n"; 
    cout<<"提示：按0-6进行选择您要的服务";
   cin >> choice;
t:
   if (choice=='0')
    break;
   switch(choice)
   {
   case '1':
    {
last:
    cout << "请依次输入学生的学号,姓名,班级,数学成绩,英语成绩,计算机成绩--学号为6位数字"<<endl;
    name = new char[];
    classes =new char[];
    cin >> num >> name >> classes >> math >> english >> computer;
    while (num<10000 || num>999999)
    {
     cin.clear();
     rewind(stdin);
     cout << "学号必须为6位数字，请重新输入学生信息" << endl;
     cin >> num >> name >> classes >> math >> english >> computer;
    }
    while (st.check(num)) //调用CHECK模块判断学号是否重复
    {
     cin.clear();
     cout << "学号重复,请重输入!" << endl;
     cout << "学号:";
     cin >> num;
    }
    s=s+1;
    st.input(num,name,classes,math,english,computer);
    cout << "是否要继续输入?(y/n)";
    cin >> yes;
    while (yes == 'y' || yes == 'Y')
    {
     goto last;   //指定跳转到标签，找到标签后，程序将处理从下一行开始的命令
    }
    getch();
    };
	break;
   case '2':
    {
     if (s==0) //判断是否有记录输入
     {
      cout << "没有学生记录,请先输入记录!" << endl;
      getch();
      break;
     }
     if (s!=0)
     {
      cout << "序号" << "\t";
      cout << "学号" << "\t";
      cout << "姓名" << "\t";
      cout << "班级" << "\t";
      cout << "数学成绩" << "\t";
      cout << "英语成绩" << "\t";
      cout << "计算机成绩" << "\t";
      for (int i=1;i<=s;i++)
       st.output(i);
      getch();
     }
    };break;
   case '3':st.search(s);break;
   case '4':st.search1(s);break;
   case '5':st.deleted(s);break;
   case '6':st.deleted1(s);break;
   case '7':st.desc1(s);break;
     case '8':st.desc2(s);break;
   case '9':st.desc(s);break;
   default:
    {
     while (choice=='0'||choice>'6')
     {
      cout << "错误选项, 请重新选择!" << endl;
      cin >> choice;
     }
     goto t;
    }break;
   }
}
cout << "谢谢您的使用!" << endl;
cout<<"  华东交通大学"<<endl;
return 0;
}
