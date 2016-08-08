/*学生通讯录系统*/
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
struct student{
char name[20];
char address[20];
char phonenum[20];
student *next;
};
//定义学生数据结构体


void mainscreen(student *p);
void title();
void Login(student *head);


void UserReg(student *head)
{
system("cls");
FILE *fp;                                  //创建文件指针
char Linedata[50]={0},User[20],Pass[20];  //三个分别是 一行数据  用户名  密码
fp = fopen("data.dat","at");              //打开data.txt 追加写数据
cout<<"******欢迎进入新账号注册新账号注册:******"<<endl;
cout<<"请输入用户名:";
fflush(stdin);                             //清空缓冲区
gets(User);                                 //获得输入用户名
cout<<"请输入密码:";
fflush(stdin);                              //清空缓冲区
gets(Pass);                                 //获得输入密码
strcpy(Linedata,User);                      //将读取到的 用户名 密码格式转变为 data.txt中的格式
strcat(Linedata,",");
strcat(Linedata,Pass);
strcat(Linedata,"\n");
fputs(Linedata,fp);                         //将这一行格式调整好的用户名 密码信息写入data.txt文件
fclose(fp);                                 //关闭data.txt文件指针
cout<<"注册成功!"<<endl;
system("pause");
system("cls");
title();
cout<<"等待转入登陆界面………………"<<endl;
Login(head);
 }
void Login(student *head)
{


FILE *fp;                                   //创建文件指针
int find=0;
char User[20],Pass[20],Userstrcat[50]={0}; //用户名 密码 装用户信息的数组 用来存储格式调整后的用户名密码
char c,Userdata[50]={0};                     //用来存储从data.txt中读取的用户信息
fp = fopen("data.dat","r");                //读data.txt文件
cout<<"用户登录:"<<endl;
cout<<"请输入用户名:";
fflush(stdin);                                 //清空缓冲区
gets(User);                                    //获得输入用户名
cout<<"请输入密码:";
fflush(stdin);                                  //清空缓冲区
gets(Pass);                                    //获得输入密码
strcpy(Userstrcat,User);                      //将读取到的 用户名 密码拷贝到Userstrcat 格式转变为 data.txt中的格式
strcat(Userstrcat,",");
strcat(Userstrcat,Pass);
strcat(Userstrcat,"\n");
 while (!feof(fp))                             //循环逐行读取data.txt  将读取到的信息保存在数组Userdata 中 直到文件结束
 {
fgets(Userdata,19,fp);
if (strcmp(Userdata,Userstrcat)==0 )   //对比 读取到的Userdata 和 接收处理过格式的Userstrcat  如果相同
  {
 cout<<"OK!登录成功!"<<endl;      //输出欢迎登陆信息
      find=1;                             //标记找到这个用户信息
      mainscreen(head);                            //跳出不再读文件
  }
 }
 fclose(fp);                                         //关闭文件指针
 if (!find)                                          //如果循环读完 仍未找到用户信息
 {
cout<<"用户名不存在或密码错误"<<endl;
cout<<"请选择重新登陆(按数字1）或者注册新账号（按数字2）：";
cin>>c;
if(c=='1')
{Login(head);}
else if(c=='2')
{UserReg(head);}
 }
}
void save(student *head)
{
FILE *fp;
student *point;
point=head;
    if((fp=fopen("F:\\lin.txt","wb+"))==NULL)
    {
        cout<<"can not open file"<<endl;
        exit(0);
    }
    while (point)
    {
        fwrite(point,1, sizeof(struct student),fp);
point=point->next;
    }
    fclose(fp);
}


void read(student *head)         //文件数据读取函数
{
    FILE *p=fopen("F:\\lin.txt","rb");
    fread(head,sizeof(struct student),1,p);
    /*while(head)
{
cout<<"%s\n",head->name);
cout<<"%s\n",head->address);
cout<<"%s\n",head->phonenum);
head=head->next;
}
*/
}
void assert_student(student *head)
{
system("cls");
title();
static student *p,*q;
if(head==NULL)
{
head=q=(struct student *)malloc(sizeof(student));
p=(struct student *)malloc(sizeof(student));
head->next=p;
cout<<"当前通讯录未初始化，请输入首对象的姓名：";
cin>>p->name;
cout<<"请输入对象的家庭住址:";
cin>>p->address;
cout<<"请输入对象的手机号码：";
cin>>p->phonenum;
q->next=p;
q=p;
q->next=NULL;
system("cls");
title();
}
else if(head!=NULL)
{
p=(struct student *)malloc(sizeof(student));
cout<<"请输入对象的姓名：";
cin>>p->name;
cout<<"请输入对象的家庭住址:";
cin>>p->address;
cout<<"请输入对象的手机号码：";
cin>>p->phonenum;
q->next=p;
q=p;
q->next=NULL;
system("cls");
title();
}
mainscreen(head);
}
void delete_student(student *head)
{
int flag=1;
system("cls");
char de_stu[20];
cout<<"请输入要注销信息的学生姓名:";
cin>>de_stu;
student *q,*front;
front=(struct student *)malloc(sizeof(student));
q=head->next;
while(q!=NULL)
{
if(strcmp(q->name,de_stu)==0)
{
cout<<"已找到需要注销的学生信息，正在注销中…………"<<endl;
q=front->next;
front->next=q->next;
cout<<"该数据已注销成功，返回主页面…………"<<endl;
flag=0;
break;
}
q=q->next;
}
if(flag==1)
cout<<"查找的学生信息不存在"<<endl;
mainscreen(head);
}
void change_student(student *head)
{
system("cls");
title();
int flag=1;
student *q;
char name_stu[20];
cout<<"请输入你要修改信息的学生姓名：";
cin>>name_stu;
q=head->next;
while(q!=NULL)
{
if(strcmp(q->name,name_stu)==0)
{
cout<<"请开始个人信息的修改："<<endl;
cout<<"姓名：";
cin>>q->name;
cout<<"家庭住址：";
cin>>q->address;
cout<<"电话号码：";
cin>>q->phonenum;
cout<<"个人信息修改完成！"<<endl;
flag=0;
break;
}
q=q->next;
}
if(flag==1)
cout<<"查找的学生信息不存在"<<endl;
mainscreen(head);
}
void loca_student(student *head)
{
system("cls");
title();
int flag=1;
char location[20];
cout<<"请输入你要查找的地区名称：";
cin>>location;
student *q;
q=head->next;
while(q!=NULL)
{
if(strcmp(q->address,location)==0)
{
cout<<"姓名："<<q->name<<endl;
cout<<"家庭住址："<<q->address<<endl;
cout<<"电话号码："<<q->phonenum<<endl<<endl;
flag=0;
}
q=q->next;
}
if(flag==1)
cout<<"没有该地区的学生信息"<<endl;
mainscreen(head);
}
void search_student(student *head)
{
system("cls");
title();
int flag=1;
char name_stu[20];
cout<<"请输入你要查找的学生姓名：";
cin>>name_stu;
student *q;
q=head->next;
while(q!=NULL)
{
if(strcmp(q->name,name_stu)==0)
{
cout<<"姓名："<<"       ";
cout<<"家庭住址："<<"       ";
cout<<"电话号码："<<"       "<<endl;
cout<<q->name<<"         ";
cout<<q->address<<"            ";
cout<<q->phonenum<<"        "<<endl;
flag=0;
break;
}
q=q->next;
}
if(flag==1)
cout<<"查找的学生信息不存在"<<endl;
mainscreen(head);
}
void show_student(student *head)
{
system("cls");
title();
student *q;
q=head->next;
while(q!=NULL)
{
cout<<"姓名："<<"       ";
cout<<"家庭住址："<<"       ";
cout<<"电话号码："<<"       "<<endl;
cout<<q->name<<"          ";
cout<<q->address<<"           ";
cout<<q->phonenum<<"        "<<endl;
q=q->next;
}
mainscreen(head);
}


void mainscreen(student *head)
{
int choice;
char a=14;
cout<<a<<"请按照要求选择要进行的操作："<<endl;
cout<<a<<"按照信息后的数字提示选择相应的操作:"<<endl<<endl;
for(int i=0;i<68;i++)
cout<<a;
cout<<endl;
cout<<" "<<a<<"  插入新的人物通讯录****************************************  1  "<<a<<endl;
cout<<" "<<a<<"  根据姓名查找相应的人物信息********************************  2  "<<a<<endl;
cout<<" "<<a<<"  根据姓名删除相应的人物信息********************************  3  "<<a<<endl;
cout<<" "<<a<<"  根据姓名修改相应的人物信息********************************  4  "<<a<<endl;
cout<<" "<<a<<"  退出通讯录登录系统****************************************  5  "<<a<<endl;
cout<<" "<<a<<"  显示当前数据库中所有的通讯录信息**************************  6  "<<a<<endl;
cout<<" "<<a<<"  查找居住在同一个地区的所有学生的信息**********************  7  "<<a<<endl;
for(int i=0;i<68;i++)
cout<<a;
cout<<endl;
cout<<"请输入你的选择：";
cin>>choice;
switch(choice)
{
case 1:assert_student(head);break;
case 2:search_student(head);break;
case 3:delete_student(head);break;
case 4:change_student(head);break;
case 5:  system("cls");save(head);exit(0);
case 6:show_student(head);break;
case 7:loca_student(head);break;
}
}

void title()
{
char a=3;
for(int i=0;i<90;i++)
cout<<a;
cout<<endl;
cout<<" **   **   **          **   *                  *        *****           *                  "<<endl;
cout<<"  **  *** **         **     *                  **         **           **   ************ "<<endl;
cout<<" ***************    ****************         ******  ************    *******     *     *   "<<endl;
cout<<"**  ******   **   **        *                    *   *    **    *       *        *     *    "<<endl;
cout<<"       **                   *                  *     ************       *        *     *    "<<endl;
cout<<"       *                    *                 ****   *    **    *       *        *     *    "<<endl;
cout<<"***************      ***************           *     ************       *      *********    "<<endl;
cout<<"       *                    *                 *      *    **    *       *   *    *     *     "<<endl;
cout<<"    *  *                    *                *       *    **    *       *  *     *      *   "<<endl;
cout<<"      **                    *               *        *    **    *       * *      *       * *"<<endl;
cout<<"       *           *******************        *******************       *        *        *  "<<endl;
    cout<<endl;
a=5;
for(int i=0;i<90;i++)
cout<<a;
cout<<endl;
}
int main()
{
char a;
student *head;
head=NULL;
title();
a=2;
cout<<a<<"欢迎进入学生通讯录管理系统，请登录你的用户名与密码："<<endl;
int selectNum;
cout<<"\n请选择登录的方式"<<endl;    //输出一个选择菜单
cout<<"1 注册新账户"<<endl;
cout<<"2 已有的账户登录"<<endl;
cout<<"3 退出通讯录管理系统"<<endl;
cin>>selectNum;        //接收输入的选择数字
switch (selectNum)         //按照输入的选择数调用函数
 {
 case 1:UserReg(head);          //调用注册函数
break;
 case 2:Login(head);           //调用登录函数
break;
 case 3:system("cls");exit(0); //调用退出函数
break;
 }
return 0;
}
