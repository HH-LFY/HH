#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<windows.h>
#include<conio.h>
#define ESC 27
using namespace std;
struct Friend //定义一个Friend结构体
{
    char name[20]; //姓名
    int age; //年龄
    char sex[5];
    char guanxi[10]; //关系类型:室友、同学、朋友
    char number[20]; //电话号码
    char qnumber[20]; //QQ号码
}  fri[20];

void add()
{
    system("cls");
    cout << "                ╲               ☆  通讯录  ☆               ╱\n";
	cout << "                  ╲            ★    管理    ★            ╱  \n";
	cout << "                    ╲         ★    System    ★         ╱    \n";
	cout << "                      ╲      ★    添加信息    ★      ╱      \n";
    int i;
    char yn;
    Friend stu[20];
    cout<<"请按顺序输入添加的信息:"<<endl;
    for(i = 3; i < 20; i++)   //先录入到结构数组
    {
        cout << "姓名:";
        cin >> stu[i].name;
        cout << "年龄:";
        cin >> stu[i].age;
        cout << "性别:";
        cin >> stu[i].sex;
        cout << "关系:(A.室友、B.同学、C.朋友)" << endl;
        char g;
        g = getch();
        if(g == 'a' || g == 'A')
        {
            strcpy(stu[i].guanxi,"室友");
            cout << "你和"<< stu[i].name << "的关系:室友" << endl;
        }
        if(g == 'b' || g == 'B')
        {
            strcpy(stu[i].guanxi,"同学");
            cout << "你和"<< stu[i].name << "的关系:同学" << endl;
        }
        if(g == 'c' || g == 'C')
        {
            strcpy(stu[i].guanxi,"朋友");
            cout << "你和"<< stu[i].name << "的关系:朋友" << endl;
        }
        cout << "电话号码:";
        cin >> stu[i].number;
        cout << "QQ号码:";
        cin >> stu[i].qnumber;
        fstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
        if(! iofile)
        {
            cerr<<"文件打开失败!"<<endl;
            exit(1);
        }
        iofile.seekp(0,ios::end);  //找到文件末尾
        iofile.write((char *)&stu[i],sizeof(stu[i]));  //把结构数组信息添加到文件末尾处
        iofile.close();
        cout << "按ESC键返回主菜单,按任意键继续添加信息" << endl;
        yn = getch();
        if(yn == ESC) break;
        else continue;
    }
}

int del()
{
    system("cls");
    cout << "                ╲               ☆  通讯录  ☆               ╱\n";
	cout << "                  ╲            ★    管理    ★            ╱  \n";
	cout << "                    ╲         ★    System    ★         ╱    \n";
	cout << "                      ╲      ★    删除信息    ★      ╱      \n";
    while(true)
    {
        cout<<"请输入姓名:";
        string name;
        int temp = -1;
        int j = 1, i, k = 1;
        cin >> name;
        ifstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
        if(! iofile)
        {
            cerr<<"文件打开失败!"<<endl;
            abort();
        }
        iofile.seekg(0,ios::beg); //找到文件头
        for(i = 0; i < 20; i++)//从文件中第一个
        {
            if(fri[i].age) k = 0;
            iofile.read((char *)&fri[i],sizeof(fri[i]));
            if(name == fri[i].name)
            {
                j = 0;   //找到后进行标记
                temp = i;  //找到的序号
            }
        }
        iofile.close();
        if(k)
        {
            cout << "抱歉,系统数据被盗走了,返回主菜单添加信息吧" << endl;
            Sleep(2000);
            cout << "正在返回主菜单……" << endl;
            return 1;
        }
        if(j)
        {
            cout << "抱歉,系统用尽九牛二虎之力都没有找到" << name << endl;
            cout << "按ESC键返回主菜单,按任意键继续删除信息" << endl;
            char yn;
            yn = getch();
            if(yn == ESC)
            {
                cout << "正在返回主菜单……" << endl;
                Sleep(2000);
                return 1;
            }
            else continue;
        }
        if(temp != -1)
        {
            ofstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
            if(! iofile)
            {
                cerr<<"文件打开失败!"<<endl;
                abort();
            }
            cout<<"确定删除[" << fri[temp].name << "]吗?[y/n]"<<endl;
            char c;
            c = getch();
            if(c =='y')    //把待删除的所有学生信息置0，再重写到文件，其实未真正删除
            {
                fri[temp].name[0]='0';
                fri[temp].age=0;
                iofile.seekp(temp*sizeof(fri[temp]),ios::beg);
                iofile.write((char *)&fri[temp],sizeof(fri[temp]));
                cout<<"已经成功删除!"<<endl;   //其实未真正删除
            }
            if(c == 'n')
            {
                cout << "取消删除,正在返回主菜单……" << endl;
                Sleep(2000);
                return 1;
            }
        }
        cout << "按ESC键返回主菜单,按任意键继续删除信息" << endl;
        char yn;
        yn = getch();
        if(yn == ESC)
        {
            cout << "正在返回主菜单……" << endl;
            Sleep(2000);
            return 1;
        }
        else continue;
    }
}

int change()
{
    system("cls");
    cout << "                ╲               ☆  通讯录  ☆               ╱\n";
	cout << "                  ╲            ★    管理    ★            ╱  \n";
	cout << "                    ╲         ★    System    ★         ╱    \n";
	cout << "                      ╲      ★    修改信息    ★      ╱      \n";
    while(true)
    {
        cout<<"请输入姓名:";
        string name;
        int age, k = 1;
        char sex[5];
        char guanxi[10];
        char number[20];
        char qnumber[20];
        int j = 1, i, temp = -1;
        cin >> name;
        ifstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
        if(! iofile)
        {
            cerr<<"文件打开失败!"<<endl;
            abort();
        }
        iofile.seekg(0,ios::beg);
        for(i=0;i<20;i++)
        {
            if(fri[i].age) k = 0;
            iofile.read((char *)&fri[i],sizeof(fri[i]));
            if(name == fri[i].name)
            {
                j = 0;
                temp = i;
            }
        }
        if(k)
        {
            cout << "抱歉,系统数据被盗走了,返回主菜单添加信息吧" << endl;
            Sleep(2000);
            cout << "正在返回主菜单……" << endl;
            return 1;
        }
        if(j)
        {
            cout << "抱歉,系统用尽九牛二虎之力都没有找到" << name << endl;
            cout << "按ESC键返回主菜单,按任意键继续修改信息" << endl;
            char yn;
            yn = getch();
            if(yn == ESC)
            {
                cout << "正在返回主菜单……" << endl;
                Sleep(2000);
                return 1;
            }
            else continue;
        }
        iofile.close();
        if(temp != -1)
        {
            ofstream iofile("Frident.dat",ios::in|ios::out|ios::binary);
            if(! iofile)
            {
                cerr<<"文件打开失败!"<<endl;
                abort();
            }
            cout << "确定修改[" << fri[temp].name << "]吗?[y/n]"<< endl;
            char c;
            c = getch();
            if(c=='y')
            {
                char name[20];
                cout << "姓名:";
                cin >> name;
                strcpy(fri[temp].name,name);
                cout << "年龄:";
                cin >> age;
                fri[temp].age = age;
                cout<<"性别:";
                cin >> sex;
                strcpy(fri[temp].sex,sex);
                cout << "关系:(A.室友、B.同学、C.朋友)" << endl;
                char g;
                g = getch();
                if(g == 'a' || g == 'A')
                {
                    strcpy(fri[temp].guanxi,"室友");
                    cout << "你和"<< fri[temp].name << "的关系改为:室友" << endl;
                }
                if(g == 'b' || g == 'B')
                {
                    strcpy(fri[temp].guanxi,"同学");
                    cout << "你和"<< fri[temp].name << "的关系改为:同学" << endl;
                }
                if(g == 'c' || g == 'C')
                {
                    strcpy(fri[temp].guanxi,"朋友");
                    cout << "你和"<< fri[temp].name << "的关系改:朋友" << endl;
                }
                cout << "电话号码:";
                cin >> number;
                strcpy(fri[temp].number,number);
                cout << "QQ:";
                cin >> qnumber;
                strcpy(fri[temp].qnumber,qnumber);
                iofile.seekp(temp*sizeof(fri[temp]),ios::beg);
                iofile.write((char *)&fri[temp],sizeof(fri[temp]));
                cout<<"已经成功修改！"<<endl;
            }
            if(c == 'n')
            {
                cout << "取消修改,正在返回主菜单……" << endl;
                Sleep(2000);
                return 1;
            }
        }
        cout << "按ESC键返回主菜单,按任意键继续修改信息" << endl;
        char yn;
        yn = getch();
        if(yn == ESC)
        {
            cout << "正在返回主菜单……" << endl;
            Sleep(2000);
            return 1;
        }
        else continue;
    }
}

int find()  //按名字查找代码
{
    system("cls");
    cout << "                ╲               ☆  通讯录  ☆               ╱\n";
	cout << "                  ╲            ★    管理    ★            ╱  \n";
	cout << "                    ╲         ★    System    ★         ╱    \n";
	cout << "                      ╲      ★    查找信息    ★      ╱      \n";
    while(true)
    {
        cout<<"请输入要查找的姓名:";
        string name;
        int j = 1, i, k = 1;
        cin>>name;
        fstream iofile("Frident.dat",ios::in|ios::binary);
        if(! iofile)
        {
            cerr<<"文件打开失败!"<<endl;
            abort();
        }
        iofile.seekg(0,ios::beg);
        for(i = 0; i < 20; i++)
        {
            if(fri[i].age) k = 0;
            iofile.read((char *)&fri[i],sizeof(fri[i]));
            if(name == fri[i].name)
            {
                j = 0;
                cout << "姓名:" << fri[i].name << "  ";
                cout << "年龄:" << fri[i].age << "  ";
                cout << "性别:" << fri[i].sex << "  ";
                cout << "关系:" << fri[i].guanxi << "  ";
                cout << "电话:" << fri[i].number << "  ";
                cout << "QQ:" << fri[i].qnumber << endl;
            }
        }
        iofile.close();
        if(k)
        {
            cout << "抱歉,系统数据被盗走了,返回主菜单添加信息吧" << endl;
            Sleep(2000);
            cout << "正在返回主菜单……" << endl;
            return 1;
        }
        if(j)
        {
            cout << "抱歉,系统用尽九牛二虎之力都没有找到" << name << endl;
            cout << "按ESC键返回主菜单,按任意键继续查找信息" << endl;
            char yn;
            yn = getch();
            if(yn == ESC)
            {
                cout << "正在返回主菜单……" << endl;
                Sleep(2000);
                return 1;
            }
            else continue;
        }
        cout << "按ESC键返回主菜单,按任意键继续查找信息" << endl;
        char yn;
        yn = getch();
        if(yn == ESC)
        {
            cout << "正在返回主菜单……" << endl;
            Sleep(2000);
            return 1;
        }
        else continue;
    }
}

int rea()   //读取文件中现有的所有学生信息
{
    system("cls");
    cout << "                ╲               ☆  通讯录  ☆               ╱\n";
	cout << "                  ╲            ★    管理    ★            ╱  \n";
	cout << "                    ╲         ★    System    ★         ╱    \n";
	cout << "                      ╲      ★  显示所有信息  ★      ╱      \n";
    cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t读取中……" << endl;
    Sleep(2000);
    system("cls");
    int i , j = 1;
    fstream iofile("Frident.dat",ios::in|ios::binary);
    if(! iofile)
    {
        cerr<<"文件打开失败!"<<endl;
        abort();
    }
    iofile.seekg(0,ios::beg);
    for(i = 0; i < 20; i++)   //把学号为非0的读出
    {
        iofile.read((char *)&fri[i],sizeof(fri[i]));
        if(fri[i].age!=0)
        {
            j = 0;
            cout << "姓名:" << fri[i].name << "  ";
            cout << "年龄:" << fri[i].age << "  ";
            cout << "性别:" << fri[i].sex << "  ";
            cout << "关系:" << fri[i].guanxi << "  ";
            cout << "电话:" << fri[i].number << "  ";
            cout << "QQ:" << fri[i].qnumber << endl;
        }
    }
    iofile.close();
    if(j)
    {
        cout << "抱歉,系统数据被盗走了,返回主菜单添加信息吧" << endl;
        Sleep(2000);
        cout << "正在返回主菜单……" << endl;
        return 1;
    }
    cout << "\n\n\n按ESC返回主菜单" << endl;
    char r;
    r = getch();
    if(r == ESC) return 1;
}

void message()
{
    cout << "\n\n\n\n\n\t\t**************************************************" << endl;
	cout << "\t\t\t *  欢迎进入通讯录信息管理系统  *" << endl;
	cout << "\t\t**************************************************" << endl << endl;
	cout << "                ╲               ☆  通讯录  ☆               ╱\n";
	cout << "                  ╲            ★    管理    ★            ╱  \n";
	cout << "                    ╲         ★    System    ★         ╱    \n";
	cout << "                      ╲      ★                ★      ╱      \n";
	cout << "                      ╱           关于软件             ╲      \n";
	cout << "                    ╱        通讯录信息管理系统          ╲    \n";
	cout << "                  ╱                                        ╲  \n";
	cout << "                ╱                                            ╲\n";
	cout << "\n\n正在加载主菜单,请稍候……";
	Sleep(2000);
}

void menu()
{
    system("cls");
	cout << "\n\n\n\n\t\t====================主菜单========================\n\n\n" << endl;
	cout << "\t\t\t  ※   1.按1键增加通讯录信息   ※" << endl;
	cout << "\t\t\t  ※   2.按2键删除通讯录信息   ※" << endl;
	cout << "\t\t\t  ※   3.按3键修改通讯录信息   ※" << endl;
	cout << "\t\t\t  ※   4.按4键查找通讯录信息   ※" << endl;
    cout << "\t\t\t  ※   5.按5键读取所有信息  　 ※" << endl;
	cout << "\t\t\t  ※   6.按ESC键退出程序   　  ※\n\n\n" << endl;
	cout << "\t\t====================@@@@@@========================" << endl << endl;
}

int main()
{
    message();
    menu();
    while(true) //通过while循环达到循环操作的目的
    {
        char control;
        control = getch();
        if(control == '1') {add();menu();} //增加通讯录信息
        if(control == '2') if(del()){menu();} //删除通讯录信息
        if(control == '3') if(change()){menu();} //修改通讯录信息
        if(control == '4') if(find()){menu();} //查找通讯录信息
        if(control == '5') if(rea()){menu();} //读取所有信息
        if(control == ESC) break; //退出程序
    }
    return 0;
}


