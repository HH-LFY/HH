#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
using namespace std;
int count=100;//最大学生数
void seek();//查询
void modify();//修改信息
void insert();//增加
void del();//删除
void display();//输出所有信息
void menu();//界面
class Student //建立学生类
{
public:
    char num[20];//学号
    char name[20];//姓名
    char sex[3];//性别
    char time[20];//出生年月
    char add[10];//籍贯
    char yuan[10];//所在学院
} stud[100];
int k=1,n=0;//定义全局变量
void menu() //界面
{
    int num;
    cout<<"\n\n\t\t\t\t简易学生信息管理系统\n\n"<<endl;
    cout<<"\t\t\t\t*****系统功能菜单"<<endl;
    cout<<"\t\t--------------------\n"<<endl;
    cout<<"\t\t1.增加学生信息\n"<<endl;
    cout<<"\t\t2.修改学生信息\n"<<endl;
    cout<<"\t\t3.查询学生信息\n"<<endl;
    cout<<"\t\t4.按学号删除信息\n"<<endl;
    cout<<"\t\t5.显示当前信息\n"<<endl;
    cout<<"\t\t6.退出系统\n"<<endl;
    cout<<"\t\t--------------------\n"<<endl;
    cout<<"\t\t请选择菜单编号:";
    cin>>num;
    switch(num)
    {
    case 1:
        insert();
        break;
    case 2:
        modify();
        break;
    case 3:
        seek();
        break;
    case 4:
        del();
        break;
    case 5:
        display();
        break;
    case 6:
        k=0;
        break;
    default:
        cout<<"请在1-6之间选择\n"<<endl;
    }
}
void seek()//查询
{
    int item;//子菜单编号
    int i;
    int flag;//判断学号是否存在
    char s1[10];
    cout<<"--------------------\n"<<endl;
    cout<<"1.按学号查询\n"<<endl;
    cout<<"2.按姓名查询\n"<<endl;
    cout<<"3.退出本菜单\n"<<endl;
    cout<<"--------------------\n";
    while(1)
    {
        cout<<"请选择子菜单编号:";
        cin>>item;
        flag=0;//先给变量赋初值0
        switch(item)
        {
        case 1:
            cout<<"请输入要查询的学生的学号:\n";
            cin>>s1;
            for(i=0; i<n; i++){
                if(strcmp(stud[i].num,s1)==0)
                {
                    flag=1;//flag=1表示存在该学号
                    cout<<"该学生学号，姓名，性别，出生年月，籍贯，所在学院 分别为:\n"<<endl;
                    cout<<stud[i].num<<"         ";
                    cout<<stud[i].name<<"         ";
                    cout<<stud[i].sex<<"          ";
                    cout<<stud[i].time<<"          ";
                    cout<<stud[i].add<<"          ";
                    cout<<stud[i].yuan<<"          "<<endl;
				}
			}
				if(flag==0) cout<<"该学号不存在!\n"<<endl;
            break;
        case 2:
            cout<<"请输入要查询学生的姓名\n"<<endl;
            cin>>s1;
            for(i=0; i<n; i++)
                if(strcmp(stud[i].name,s1)==0)
                {
                    flag=1;//存在该姓名
                    cout<<"该学生学号，姓名，性别，出生年月，籍贯，所在学院 分别为:\n"<<endl;
                    cout<<stud[i].num<<"         ";
                    cout<<stud[i].name<<"         ";
                    cout<<stud[i].sex<<"          ";
                    cout<<stud[i].time<<"          ";
                    cout<<stud[i].add<<"          ";
                    cout<<stud[i].yuan<<"          "<<endl;
                }
            if(flag==0) cout<<"该姓名不存在!\n"<<endl;
            break;//终止循环
        case 3:
            return;
        default:
            cout<<"请在1-3之间选择\n"<<endl;
        }
    }
}
void insert()
{
    int j,x,k;
    cout<<"请输入增加的学生数:\n";
    cin>>x;
    for(j=0; j<x; j++) //输入x个学生的信息
    {
        cout<<"请输入学生学号\n";
        cin>>stud[n].num;
        for(k=0; k<n; k++)
            if(strcmp(stud[n].num,stud[k].num)==0)
            {
                cout<<"已有该学号,请检查后重新输入!\n"<<endl;
				j=j-1;
                break;
            }
        if(k==n) //k==n表示该学号是新增加的
        {
            cout<<"请输入学生的姓名:\n";
            cin>>stud[n].name;
            cout<<"请输入学生的性别:\n";
            cin>>stud[n].sex;
            cout<<"请输入学生的出生年月:\n";
            cin>>stud[n].time;
            cout<<"请输入学生的籍贯:\n";
            cin>>stud[n].add;
            cout<<"请输入学生的所在学院:\n";
            cin>>stud[n].yuan;
            cout<<"录入成功!!\n\n"<<endl;
			n=n+1;//学生人数加1
        }
    }
}
void modify()
{
    int i,item,num,flag=0;
    char s1[10],s2[20];
    cout<<"请输入要修改学生的学号 :\n";
	while(!flag)
	{
        cin>>s1;
        for(i=0; i<n; i++)//判断该学号是否存在
		{
            if(strcmp(s1,stud[i].num)==0) num=i,flag=1;
		}
		if(flag==0) cout<<"该学号不存在，请重新输入!!!\n";
	}
        cout<<"--------------------\n"<<endl;
        cout<<"1.  修  改  姓  名  \n"<<endl;
        cout<<"2.  修  改  性  别  \n"<<endl;
        cout<<"3.  修  改  出  生  年  月  \n"<<endl;
        cout<<"4.  修  改  籍  贯  \n"<<endl;
        cout<<"5.  修  改  所  在  学  院  \n"<<endl;
        cout<<"6.  退  出  本  菜  单  \n"<<endl;
        cout<<"--------------------\n"<<endl;
		while(1)
	{
		cout<<"请选择子菜单编号\n";
        cin>>item;
        switch(item)
        {
        case 1:
            cout<<"请输入新的姓名:\n";
            cin>>s2;
            strcpy(stud[num].name,s2);
            break;
        case 2:
            cout<<"请输入新的性别:\n";
            cin>>s2;
            strcpy(stud[num].sex,s2);
            break;
        case 3:
            cout<<"请输入新的出生年月:\n";
            cin>>s2;
            strcpy(stud[num].time,s2);
            break;
        case 4:
            cout<<"请输入新的籍贯:\n";
            cin>>s2;
            strcpy(stud[num].add,s2);
            break;
        case 5:
            cout<<"请输入新的所在学院:\n";
            cin>>s2;
            strcpy(stud[num].yuan,s2);
            break;
        case 6:
            return;
        default:
            cout<<"请在1-6之间选择\n"<<endl;
		}
    }
}
void del()
{
    int i,x,j=0;
    char s1[10];
    cout<<"请输入要删除学生的学号:\n";
    cin>>s1;
    for(i=0; i<count; i++)
    {
        if(strcmp(stud[i].num,s1)==0)
        {
            for(x=i; x<count-1; x++)
            {
                stud[x]=stud[x+1];
                j++;
                count=count-1;
            }
            if(j==0) cout<<"该学号不存在!\n"<<endl;
            if(j!=0) cout<<"删除成功，显示结果请选择菜单5\n"<<endl;
        }
    }
}
void display()
{
    int i;
    cout<<"所有学生信息为:\n"<<endl;
    for(i=0; i<n; i++)
    {
       cout<<"学号，姓名，性别，出生年月，籍贯，所在学院分别为:\n"<<endl;
        cout<<stud[i].num<<"  ";
        cout<<stud[i].name<<"  ";
        cout<<stud[i].sex<<"  ";
        cout<<stud[i].add<<"  ";
        cout<<stud[i].yuan<<"  "<<endl;
    }
}
int main()
{
    while(k)menu();
    system("pause");//系统终止
    return 0;
}
