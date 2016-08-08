#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;
#define M 20
#define N 12
class Fphone        //类的定义，包括：姓名和电话号码
{
    char name[M];     //姓名成员
    char phone_num[N];      //电话号码成员
public:
    Fphone(char *namep=NULL,char *phone_nump=NULL)  //构造函数
    {
		if(namep)
			strcpy(name,namep);
		else
			strcpy(name," ");
		if(phone_nump)
			strcpy(phone_num,phone_nump);
		else
            strcpy(phone_num," ");

    }
    char *getname();        //获取姓名
    char *getphone_num();                //获取电话号码
void setname(char *na);               //设置姓名
    void setphone_num(char *num);        //设置电话号码
    void disp();                         //输出用户信息
    ~Fphone(){};                        //析构函数
};

char *Fphone::getname()                 //类外定义函数
{
    return name;
}

char *Fphone::getphone_num()            //类外定义函数

{
    return phone_num;
}

void Fphone::setname(char *na)          //类外定义函数

{
    strcpy(name,na);
}

void Fphone::setphone_num(char*num)   //类外定义函数

{
    strcpy(phone_num,num);
}

void Fphone::disp()                     //类外定义函数

{
    cout<<"姓名："<<name<<'\t'<<"电话号码："<<phone_num<<endl;
}

class UserDatabase
{
    int nElem;            //用户信息表中的元素个数
    int Maxu;            //用户信息表中最大的元素个数
    Fphone *user;        //指向用户信息的指针
public:
    UserDatabase();       //构造函数，初始化用户信息表，将user.txt文件中的数据读到user[]中
    ~UserDatabase();        //析构函数，将user[]写入user->txt文件中
    Fphone *getuser()
    {
        return user;
    }        //获取指向用户信息表的指针
    void clear();        //删除所有用户信息
    void add_record(char *na,char *ph_num);      //添加用户信息，插入用户后仍按升序排列
    void delete_record(Fphone *p,int k);        //删除用户信息
    void modify_record(Fphone *p,char *ph_num);        //修改用户信息
    Fphone *query(char *na);        //按姓名查找
    void sorta_name();        //按姓名升序排列
    void sorta_phonenum();        //按电话号码升序排列
    void sort_name();        //按姓名降序,将排成升序的对象数组逆向放置
    void sort_phonenum();        //按电话号码降序排序
    void disp();        //输出所有用户信息
};

UserDatabase::UserDatabase()        //类外定义构造函数
{
    nElem=0;     //用户信息表中元素个数初值为零

    Maxu=100;    //用户个数最多100
    user=new Fphone[Maxu];   //动态申请空间
    fstream infile;  //定义一个文件流对象

    infile.open("user.txt",ios::in);      //读取user.txt文件
    if(!infile)
    {
        cout<<"无法打开文件：user.txt"<<endl;
        exit(1);     //结束函数运行
    }
	for(int i=0;(!infile.eof());i++)
		{	infile>>user[i].getname();infile>>user[i].getphone_num();         //从文件中获取姓名，电话号码
         	nElem++;
	}
    infile.close();    //关闭文件
}

UserDatabase::~UserDatabase()      //类外定义析构函数
{
    fstream outfile;                  //定义一个文件流对象
    outfile.open("user.txt",ios::out);       //内容写入user.txt
    if(!outfile)
        cout<<"无法打开文件：user.txt"<<endl;
    exit(2);                      //结束程序运行
    Fphone *p=NULL;
    p=user;
    for(int i=0;i<nElem;i++)
		{	outfile<<setw(20)<<((p+i)->getname())<<setw(15)
			<<((p+i)->getphone_num())<<endl;            //向文件中插入姓名，电话
		}delete []user;          //释放空间
		outfile.close();          //关闭文件
}

void UserDatabase::clear()            //删除全部内容函数
{
    cout<<"***********************************"<<endl;
    cout<<"             删除全部记录"          <<endl;
    cout<<"***********************************"<<endl;
    cout<<"确认删除全部用户信息？"<<endl;
    cout<<"确认(1)       取消(2)"<<endl;
    int i;
    cin>>i;
    switch(i)
    {        case 1: delete []user;   //执行清楚操作
                   nElem=0;
                   break;
             case 2: break;       //跳出函数
             default:cout<<"输入错误"<<endl;
    }
}

void UserDatabase::add_record(char *na,char *num)        //添加记录
{
	int i;
    if (nElem==0)         //没有记录
    {
        nElem++;
        user->setname(na);
        user->setphone_num(num);
    }
    else if(nElem<Maxu)          //有记录且有空间
    {
        for(i=nElem-1;i>=0;i--)
        {
            if(strcmp((user+i)->getname(),na)>0)
            {
                (user+i+1)->setname(((user+i)->getname()));
                (user+i+1)->setphone_num(((user+i)->getphone_num()));
            }
            else break;
        }
        (user+i+1)->setname(na);
        (user+i+1)->setphone_num(num);
        nElem++;
    }
    else             //空间不足
        cout <<"空间不足，无法添加!"<<endl;
}

void UserDatabase::delete_record(Fphone *a,int b)        //删除记录
{
    cout<<"确认删除该用户信息？"<<endl;
    cout<<"确认(1)       取消(2)"<<endl;
    int c;
    cin>>c;
    if (c==2) return;              //取消操作
    else if (c==1)
    {
        for(int i=b;i<nElem;i++)
        {
            user[i]=user[i+1];
        }
        nElem--;
        cout<<"删除成功"<<endl;
    return;
    }
    else
    {
		cout<<"输入错误"<<endl;
        system("pause");
        return;
    }
}

void UserDatabase::modify_record(Fphone *a,char *num)         //修改记录
{
    cout<<"确认修改该用户信息？"<<endl;
    cout<<"确认(1)       取消(2)"<<endl;
    int b;
    cin>>b;
    if(b==1)
    {
        a->setphone_num(num);         //重置电话号码
        cout<<"修改成功"<<endl;
        return;
    }
    else        if(b==2) return;
    else
    {        cout<<"输入错误"<<endl;
    system("pause");
    return;
    }
}

Fphone *UserDatabase::query(char *na)         //按姓名查找
{
    Fphone *p=user;
    int i=0;
    while(1)
    {
        if(strcmp(p->getname(),na)==0)        //相同的姓名
            return p;
        p++;
        if(i++==nElem)
            break;
    }
    return NULL;
}

void UserDatabase::sorta_name()       //按姓名升序，插入法排序
{
    Fphone temp;
    int i,j;
    for(i=1;i<nElem;i++)
    {
        temp=user[i];
        for(j=i-1;j>=0&&(strcmp(temp.getname(),user[j].getname())<0);j--)
        {
            strcpy(user[j+1].getname(),user[j].getname());
            strcpy(user[j+1].getphone_num(),user[j].getphone_num());
        }
        strcpy(user[j+1].getname(),temp.getname());
        strcpy(user[j+1].getphone_num(),temp.getphone_num());
    }
    cout<<"排序完成"<<endl;
}

void UserDatabase::sorta_phonenum()      //按电话升序，插入法排序
{
    Fphone temp;
    int i,j;
    for(i=1;i<nElem;i++)
    {
        temp=user[i];
        for(j=i-1;j>=0&&(strcmp(temp.getphone_num(),user[j].getphone_num())<0);j--)
        {
            strcpy(user[j+1].getname(),user[j].getname());
            strcpy(user[j+1].getphone_num(),user[j].getphone_num());
        }
        strcpy(user[j+1].getname(),temp.getname());
        strcpy(user[j+1].getphone_num(),temp.getphone_num());
    }
    cout<<"排序完成"<<endl;

}

void UserDatabase::sort_name()       //按姓名降序，插入法排序
{
	Fphone temp;
    int i,j;
    for(i=1;i<nElem;i++)
    {
        temp=user[i];
        for(j=i-1;j>=0&&(strcmp(temp.getname(),user[j].getname())>0);j--)
        {
            strcpy(user[j+1].getname(),user[j].getname());
            strcpy(user[j+1].getphone_num(),user[j].getphone_num());
        }
        strcpy(user[j+1].getname(),temp.getname());
        strcpy(user[j+1].getphone_num(),temp.getphone_num());
    }
    cout<<"排序完成"<<endl;
}

void UserDatabase::sort_phonenum()        //按电话降序，插入法排序
{
   Fphone temp;
    int i,j;
    for(i=1;i<nElem;i++)
    {
        temp=user[i];
        for(j=i-1;j>=0&&(strcmp(temp.getphone_num(),user[j].getphone_num())>0);j--)
        {
            strcpy(user[j+1].getname(),user[j].getname());
            strcpy(user[j+1].getphone_num(),user[j].getphone_num());
        }
        strcpy(user[j+1].getname(),temp.getname());
        strcpy(user[j+1].getphone_num(),temp.getphone_num());
    }
    cout<<"排序完成"<<endl;
}

void UserDatabase::disp()        //输出所有用户信息
{
    int i,n=0;
    cout<<setw(22)<<"姓名"<<setw(14)<<"电话号码"<<endl;
    for(i=0;i<nElem;i++)
    {
        cout<<setw(22)<<(user+i)->getname()
            <<setw(14)<<(user+i)->getphone_num()<<endl;
        n++;
        if(n%10==0)
        {
            system("pause");
            system("cls");
        }
    }
    cout<<endl;
}

int main()       //主函数
{
    Fphone p;
    int i;
    UserDatabase userdatabase;
    while(1)
    {
        cout<<"-----------------------------------------------"<<endl;
                 cout<<"                              "<<endl;
                 cout<<"                              "<<endl;
                 cout<<"                              "<<endl;
                 cout<<"                              "<<endl;
                 cout<<"    欢迎使用电话簿管理系统    "<<endl;
                 cout<<"                              "<<endl;
                 cout<<"                              "<<endl;
                 cout<<"                              "<<endl;
                 cout<<"                              "<<endl;
        cout<<"-----------------------------------------------"<<endl;
        system("pause");
        system("cls");
        cout<<"请选择以下功能"<<endl;
        cout<<"1-增加记录"<<endl;
        cout<<"2-修改记录"<<endl;
        cout<<"3-删除记录"<<endl;
        cout<<"4-查找（按姓名）"<<endl;
        cout<<"5-排序"<<endl;
        cout<<"6-显示记录"<<endl;
        cout<<"7-全删"<<endl;
        cout<<"0-退出"<<endl;
        cout<<"输入选择："<<endl;
        cin>>i;
        cout<<endl;
        switch(i)          //菜单选择函数
        {
        case 1:
            {
                system("cls");                 //清屏
                char name[20],num[12];
                cout<<"***********************************"<<endl;
                cout<<"             增加记录"<<endl;
                cout<<"***********************************"<<endl;
                cout<<"请输入增加用户的姓名：";
                cin>>name;
                cout<<endl;
                cout<<"请输入增加用户的号码：";
                cin>>num;
                userdatabase.add_record(name,num);   //增加记录函数
                userdatabase.sorta_name();           //默认按姓名升序
                system("pause");                    //暂停
                break;
            }
        case 2:
            {
                system("cls");
                cout<<"***********************************"<<endl;
                cout<<"             修改记录"<<endl;
                cout<<"***********************************"<<endl;
                char na[20],ph_num[12];
                Fphone *t=new Fphone;
                cout<<"请输入您要修改的用户的姓名";
                cin>>na;
                t=userdatabase.query(na);      //按姓名查找
                if(!t)
                    cout<<"没有该用户!"<<endl;
                else
                {
                    cout<<"该用户原号码为："<<t->getphone_num()<<endl;
                    cout<<"请输入新的电话号码";
                    cin>>ph_num;
                    userdatabase.modify_record(t,ph_num);   //修改记录
                    cout<<endl;
                }
                system("pause");
                break;
            }
        case 3:
            {
                system("cls");
                char name[20];
                cout<<"***********************************"<<endl;
                cout<<"             删除记录"<<endl;
                cout<<"***********************************"<<endl;
                cout<<"请输入您要删除的用户的姓名";
                cin>>name;
                Fphone *p=userdatabase.query(name);
                if(p==0)
                    cout<<"没有该用户"<<endl;
                else
                {
                    cout<<"姓名："<<p->getname()<<endl;
                    cout<<"电话号码："<<p->getphone_num()<<endl;
                    int k=p-userdatabase.getuser();     //获取用户指针
                    userdatabase.delete_record(p,k);    //删除记录
                }
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                char name[20];
                cout<<"***********************************"<<endl;
                cout<<"             查找记录"<<endl;
                cout<<"***********************************"<<endl;
                cout<<"请输入用户姓名"<<'\t';
                cin>>name;
                Fphone *i=NULL;
                i=userdatabase.query(name);       //按姓名查找
                if(i)
                {
                    cout<<"姓名："<<i->getname()<<endl;
                    cout<<"电话号码："<<i->getphone_num()<<endl;
                }
                else
                    cout<<"没有此用户"<<endl;
                system("pause");
                break;
            }
        case 5:
            {
                system("cls");
                int j;
                cout<<"请选择排序方式"<<endl;
                cout<<"1-按姓名（升序）"<<endl;
                cout<<"2-按电话号码（升序）"<<endl;
                cout<<"3-按姓名（降序）"<<endl;
                cout<<"4-按电话号码（降序）"<<endl;
                cout<<"请输入选择："<<endl;
                cin>>j;
                cout<<endl;
                switch(j)
                {
                case 1:
                    {        system("cls");
                    userdatabase.sorta_name();   //按姓名升序
                    userdatabase.disp();
                    system("pause");
                    break;
                    }
                case 2:
                    {        system("cls");
                    userdatabase.sorta_phonenum();   //按电话升序
                    userdatabase.disp();
                    system("pause");
                    break;
                    }
                case 3:
                    {        system("cls");
                    userdatabase.sort_name();     //按姓名降序
                    userdatabase.disp();
                    system("pause");
                    break;
                    }
                case 4:
                    {        system("cls");
                    userdatabase.sort_phonenum();      //按电话降序
                    userdatabase.disp();
                    system("pause");
                    break;
                    }
                default :cout<<"输入错误"<<endl;
                };break;
                case 6:
                    {
                        system("cls");
                        userdatabase.disp();         //输出所有用户信息
                        system("pause");
                        break;
                    }
                case 7:
                    {
                        system("cls");
                        userdatabase.clear();         //删除全部记录
                        system("pause");
                        break;
                    }
                case 0:
                    {
                        system("cls");
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"***********欢迎再次使用***********"<<endl;
                        cout<<endl;
                        exit(1);
                    };break;
                default :
                    {        cout<<"输入错误"<<endl;                }
            }
        }
}
return 0;
}
