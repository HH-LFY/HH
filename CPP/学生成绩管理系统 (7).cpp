# include <iostream>
# include <fstream>
# include <string.h>
#include <conio.h>//用getch();
using namespace std;

//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌Student类﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
class Student
{
public:
 char name[20];
 char Id[20];
 int Cnum;       //C课程得分
 int Mnum;       //数学课程得分
 int Enum;       //英语课程得分
 int sum;        //总分     
 Student * Next;
 void Input()
  {
  cout<<"\t\t请输入学生 姓名：";  cin>>name;
  cout<<"\t\t请输入学生 学号：";  cin>>Id;
  cout<<"\t\t请输入C课程 成绩：";  cin>>Cnum;
  cout<<"\t\t请输入数学课程 成绩：";  cin>>Mnum;
  cout<<"\t\t请输入英语课程 成绩：";  cin>>Enum;
  sum=Cnum+Mnum+Enum;
 }
 void ReadFile(istream & in)
 {
  in>>name>>Id>>Cnum>>Mnum>>Enum>>sum;
 }
 void Show()
 {
  cout<<"姓名:"<<name<<endl<<"学号:"<<Id<<endl<<"C++:"<<Cnum<<endl
   <<"数学:"<<Mnum<<endl<<"外语："<<Enum<<endl<<"总成绩:"<<sum<<endl<<endl<<endl;
 }
};
//﹌﹌﹌﹌﹌﹌﹌﹌﹌Studentmassage类﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
class Studentmassage
{
public:
 Studentmassage();
 ~Studentmassage();
 void ShowMenu();
 void Find();
 void Save();
 void ModifyItem();
 void RemoveItem();
 void Swap(Student *,Student *);
 void Sort();
 //void Unpass();
 int ListCount();
 //void Average();
 void Display()
 {
  for(Student * p=Head->Next;p!=End;p=p->Next)
   p->Show();
  cout<<"输入任意字符 继续……";
  getch();
 }
 void AddItem()
 {
  End->Input();
  End->Next=new Student;
  End=End->Next;
  cout<<"添加成功!"<<endl;
  cout<<"输入任意字符 继续……";
  getch();
 }
private:
 Student * Head,* End;
 ifstream in;
 ofstream out;
 Student *FindItem(char * name)
 {
  for(Student * p=Head;p->Next!=End;p=p->Next)//匹配成功则返回上  指针  成功 返回空
   if(!strcmp(p->Next->name,name))return p;
   return NULL;
 }
 Student *FindID(char * Id)
 {
  for(Student * p=Head;p->Next!=End;p=p->Next)//匹配成功则返回上  指针  成功 返回空
   if(!strcmp(p->Next->Id,Id))return p;
   return NULL;
 }
};

//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌构造函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
Studentmassage::Studentmassage()
{
 Head=new Student;
 Head->Next=new Student;
 End=Head->Next;
 in.open("sort.txt");
 if(!in)
  cout<<"    新系统 无学生信息 请先输入 "<<endl;
 else
 {
  while(!in.eof())
  {
   End->ReadFile(in);
   if(End->name[0]=='\0')break;
   End->Next=new Student;
   End=End->Next;
  }
  in.close();
  cout<<"\t\t读取学生信息成功!"<<endl;
 }
}

//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌析构函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
Studentmassage::~Studentmassage()
{
 Save();
 for(Student * temp;Head->Next!=End;)
 {
  temp=Head->Next;
  Head->Next=Head->Next->Next;
  delete temp;
 }
 delete Head,End;
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌菜单﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::ShowMenu()                  
{
  cout<<"〓〓〓〓〓〓〓〓〓〓  ☆   学 生 成 绩 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓★★★★★         ★★★★★★★         ★★★★★〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          2.显示学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          3.排序统计成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          4.查找学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          5.删除学生成绩        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          6.修改学生信息        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
  cout<<"〓〓〓〓〓〓〓〓〓★  ☆          0.安全退出系统        ☆  ★〓〓〓〓〓〓〓〓〓"<<endl;
 
 cout<<"\n\t\t\n\t\t请选择：";
}

//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌查找函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Find()
{
 char name[20] ,Id[10];
 int x;
 Student * p=NULL;
 cout<<"\n\t\t*********************************\n";
 cout<<"\t\t※ 1.按学生 姓名查找\n\t\t※ 2.按学生学号查找";
 cout<<"\n\t\t*********************************\n请选择：";
 cin>>x;
 switch(x)
 {
 case 1:{cout<<"\t\t请输入要查找 学生 姓名：";cin>>name;
  if(p=FindItem(name))
  {
   p->Next->Show();
   cout<<"输入任意字符 继续……";
   getch();
  }
  else
  {
   cout<<"\t\t没有找 该姓名 学生 "<<'\n'<<endl;
   cout<<"输入任意字符 继续……";
   getch();
  }
     }break;
 case 2:
  {
   cout<<"\t\t请输入要查找 学生 学号：";cin>>Id;
   if(p=FindID(Id))
   {
    p->Next->Show();
    cout<<"输入任意字符 继续……";
    getch();
   }
   else
   {
    cout<<"\t\t没有找 该学好 学生 "<<'\n'<<endl;
    cout<<"输入任意字符 继续……";
    getch();
   }
  }break;
 }
 
}

//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌修改信息﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::ModifyItem()     //修改信息
{
 char name[20];
 Student * p=NULL;
 cout<<"\t\t请输入要修改 人 姓名:";cin>>name;
 if(p=FindItem(name))
 {
  cout<<"\t\t已找 学生 信息 请输入新 信息!"<<endl;
  p->Next->Input();
  cout<<"修改成功 "<<endl;
  cout<<"输入任意字符 继续……";
  getch();
 }
 else
 {
  cout<<"\t\t没有找 !"<<endl;
  cout<<"输入任意字符 继续……";
  getch();
 }
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌删除信息﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::RemoveItem()         // 删除信息
{
 char name[20];
 Student * p=NULL,*temp=NULL;
 cout<<"\t\t请输入要删除 学生 姓名:"<<endl;cin>>name;
 if(p=FindItem(name))
 {
  temp=p->Next;
  p->Next=p->Next->Next; 
  delete temp;
  cout<<"\t\t删除成功!"<<endl;
  cout<<"输入任意字符 继续……";
  getch();
 }
 else
 {
  cout<<"\t\t没有找 !"<<endl;
     cout<<"输入任意字符 继续……";
  getch();
 }
}

//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Swap(Student *p1, Student *p2)//交换两 combox变量 数据域
{
 Student *temp=new Student; 
 strcpy(temp->name,p1->name);
 strcpy(temp->Id,p1->Id);
 temp->Cnum=p1->Cnum;
 temp->Mnum=p1->Mnum;
 temp->Enum=p1->Enum;
 temp->sum=p1->sum;
 
 strcpy(p1->name,p2->name);
 strcpy(p1->Id,p2->Id);
 p1->Cnum=p2->Cnum;
 p1->Mnum=p2->Mnum;
 p1->Enum=p2->Enum;
 p1->sum=p2->sum;
 
 strcpy(p2->name,temp->name);
 strcpy(p2->Id,temp->Id);
 p2->Cnum=temp->Cnum;
 p2->Mnum=temp->Mnum;
 p2->Enum=temp->Enum;
 p2->sum=temp->sum;
}

//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
int Studentmassage::ListCount()//统计当前链表 记录总数 返回  整数
{
 if(! Head)
  return 0;
 int n=0;
 for(Student * p=Head->Next;p!=End;p=p->Next)
 {
  n++;
 }
 return n;
}

//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Sort()//对当前链表进行排序
{ 
 cout <<"Sorting..."<<endl;
 Student *p=NULL,*p1=NULL,*k=NULL;
 int n=Studentmassage::ListCount();
 if(n<2) 
  return;
 for(p=Head->Next;p!=End;p=p->Next)
  for(k=p->Next;k!=End;k=k->Next)
  {
   if(p->sum>k->sum)
   {
    Studentmassage::Swap(p,k);
   }
  }
 cout <<"排序完成 "<<endl;
 getch();
 return;
}

//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌保存函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
void Studentmassage::Save()
{
 out.open("sort.txt");
 for(Student *p=Head->Next;p!=End;p=p->Next)
  out<<p->name<<"\t"<<p->Id<<"\t"<<p->Cnum<<"\t"
  <<p->Mnum<<"\t"<<p->Enum<<"\t"<<p->sum<<'\n';
 out.close();
}
//﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌主函数﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌﹌
int main()
{
 int x,i=0;
 bool quit=false;
 cout<<"\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§"<<endl;
 for(i=0;i<3;i++)
  cout<<"\t\t◎\t\t\t\t\t\t  ◎"<<endl;
 cout<<"\t\t◎★★★★【  欢迎进入学生成绩管理系统  】★★★★◎"<<endl;
 for(i=0;i<3;i++)
  cout<<"\t\t◎\t\t\t\t\t\t  ◎"<<endl;
 cout<<"\t\t§§§§§§§§§§§§§§§§§§§§§§§§§§\n"<<endl;;
 Studentmassage Grade;
 cout<<"按任意键开始……";
  getch();
 while(!quit)
 {
  system("cls");
  Grade.ShowMenu();
  cin>>x;
  switch(x)
  {
  case 0:quit=true;break;
  case 1:Grade.AddItem();break;
  case 2:Grade.Display();break;
  case 3:Grade.Sort();break;
  case 4:Grade.Find();break;
  case 5:Grade.RemoveItem();break;
  case 6:Grade.ModifyItem();break;
  }
 }
 return 0;
}
