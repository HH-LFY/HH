#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
using namespace std;
string zi[3]= {"数学","语文","英语"};
struct student
{
    string name, id;
    int score[3];//score[0]是语文，score[1]是数学，score[2]是英语
};
int number;
vector<student>m;//定义student类型的容器
vector<student>::size_type ix;//定义变量
void input();
void init()//一开始对界面
{
    system("cls");
    printf("\n\n\n\n\t\t****************************\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**          欢迎          **\t\t\n");
    printf("\t\t**  进入学生成绩管理系统  **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t****************************\t\t\n");
    input();
    printf("\n数据正在读取中，请稍候！");
    printf("\t请按任意键继续！！！\n");
    getchar();
}
void init1()//设置登入密码
{
    string yonghuming;
    int mima;
    system("cls");
    printf("\n\n\n\n\t\t****************************\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**           欢迎         **\t\t\n");
    printf("\t\t**   进入学生成绩管理系统 **\t\t\n");
    printf("\t\t**         之登入         **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t****************************\t\t\n");
    printf("\n\t\t用户名 (提示：学生的学号！！):");
    cin>>yonghuming;
    printf("\n");
    printf("\n\t\t密码  (提示：今年的年份！！):");
    cin>>mima;
    printf("\n");
    printf("你已成功登入，请按任意键继续！！");
    getchar();
    getchar();
}
void init2()//第二段的初始化
{
    system("cls");
    printf("\n\n\n\n\t\t***********************************\t\t\n");
    printf("\t\t*****                         *****\t\t\n");
    printf("\t\t*****                         *****\t\t\n");
    printf("\t\t*****           欢迎          *****\t\t\n");
    printf("\t\t*****   进入学生成绩管理系统  *****\t\t\n");
    printf("\t\t*****      之学生查找         *****\t\t\n");
    printf("\t\t*****                         *****\t\t\n");
    printf("\t\t***********************************\t\t\n");
}
void init3()
{
    system("cls");
    printf("\n\n\n\n\t\t****************************\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**          欢迎          **\t\t\n");
    printf("\t\t**  进入学生成绩管理系统  **\t\t\n");
    printf("\t\t**     之成绩排序         **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t******************************\t\t\n");
}
void input()//从磁盘中输入
{
    ifstream infile;
    infile.open("D://学生成绩管理系统.txt",ios::in);
    infile>>number;
    for(int j=1; j<=number; j++)
    {
        student p;
        infile>>p.name>>p.id;
        for(int i=0; i<3; i++)
            infile>>p.score[i];
        m.push_back(p);
    }
    infile.close();
}
void insert1()//增加学生信息
{
    int i;
    student p;
    cout<<"请输入你要增加学生的姓名:"<<endl;
    cin>>p.name;
    cout<<"请输入你要增加学生的学号:"<<endl;
    cin>>p.id;
    cout<<"请输入你要增加学生的分数:"<<endl;
    for(i=0; i<3; i++)
        cin>>p.score[i];
    m.push_back(p);
    cout<<"学生信息增加结束！谢谢使用！！"<<endl;
}
void zfhpjf()//计算该同学的总分和平均分
{
    string name1;
    int sum=0;
    cout<<"请输入需要计算总分的学生的姓名:"<<endl;
    cin>>name1;
    for(ix=0; ix!=m.size(); ix++)
    {
        if(m[ix].name==name1)
        {
            for(int i=0; i<3; i++)
                sum+=m[ix].score[i];
        }
    }
    cout<<"该同学的总分为:"<<endl;
    cout<<sum<<endl;
    cout<<"该同学的平均分为:"<<endl;
    printf("%.2lf\n",(sum*1.0)/3);
    cout<<"已结束该功能，请继续使用！！\n"<<endl;
    getchar();
    getchar();
}

void del()//删除学生信息
{
    int i;
    string name1;
    cout<<"请输入你要删除的学生的姓名:"<<endl;
    cin>>name1;
    for(ix=0; ix!=m.size(); ix++)
    {
        if(m[ix].name==name1)
        {
            m[ix].name="";
            m[ix].id="";
            for(i=0; i<3; i++)
                m[ix].score[i]=0;
        }
    }
    cout<<"学生信息已删除！谢谢使用！！"<<endl;
}
void xiugai()//修改学生信息
{
    int i;
    string name2;
    cout<<"\n请输入你要修改学生姓名:";
    cin>>name2;
    for(ix=0; ix!=m.size(); ++ix)
    {
        if(m[ix].name==name2)
        {
            cout<<"\n请输入新的资料!\n";
            cout<<"\n新的姓名:";
            cin>>m[ix].name;
            cout<<"\n新的学号:";
            cin>>m[ix].id;
            cout<<"\n新的成绩:";
            for(i=0; i<2; i++)
                cout<<m[ix].score[i]<<" ";
            cout<<m[ix].score[2];
        }
    }
    cout<<"已成功修改该学生的信息！！"<<endl;
}

void select1()//按照姓名查找学生信息
{
    int i;
    string name2;
    cout<<"请输入要查找学生的姓名:"<<endl;;
    cin>>name2;
    for(ix=0; ix!=m.size(); ++ix)
    {
        if(m[ix].name==name2)
        {
            cout<<"该学生的信息为:"<<endl;
            cout<<m[ix].name<<" "<<m[ix].id<<" ";
            for(i=0; i<2; i++)
            {
                cout<<m[ix].score[i]<<" ";
            }
            cout<<m[ix].score[2];
        }
    }
    getchar();
    getchar();
}

void select2()//按照学号查找学生信息
{
    int i;
    string id1;
    cout<<" 请输入要查找学生的学号:"<<endl;;
    cin>>id1;
    for(ix=0; ix!=m.size(); ++ix)
    {
        if(m[ix].id==id1)
        {
            cout<<" 该学生的信息为:"<<endl;
            cout<<m[ix].name<<" "<<m[ix].id<<" ";
            for(i=0; i<2; i++)
            {
                cout<<m[ix].score[i]<<" ";
            }
            cout<<m[ix].score[2];
        }
    }
    getchar();
    getchar();
}

bool s_math1(student x,student y)//按照数学成绩从小到大进行排序
{
    return x.score[0]<y.score[0];
}
bool s_math2(student x,student y)//按照数学成绩从大到小进行排序
{
    return x.score[0]>y.score[0];
}

bool  s_yuwen1(student x,student y)//按照语文成绩从小到大进行排序
{
    return x.score[1]<y.score[1];
}
bool s_yuwen2(student x,student y)//按照语文成绩从大到小进行排序
{
    return x.score[1]>y.score[1];
}
bool s_yingyu1(student x,student y)//按照英语成绩从小到大进行排序
{
    return x.score[2]<y.score[2];
}
bool s_yingyu2(student x,student y)//按照英语成绩从大到小进行排序
{
    return x.score[2]>y.score[2];
}
void s_tongji()//统计成绩的情况
{
    int i;
    string kemu;
    int a,b,sum=0;
    char c;
    cout<<"请输入你要统计的科目和分数段:"<<endl;
    cin>>kemu;
    cin>>a>>c>>b;
    for(i=0; i<3; i++)
    {
        if(zi[i]==kemu)
        {
            for(ix=0; ix!=m.size(); ix++)
            {
                if(m[ix].score[i]<=b&&m[ix].score[i]>=a)
                    sum++;
            }
            break;
        }
    }
    cout<<"经统计，得到的结果为:"<<endl;
    cout<<sum<<endl;
    getchar();
    getchar();
}
int main()
{
    int a,b,c,d;
    init();
    init1();
    int n ;
    do
    {
        system("cls");
        printf("\n\t\t\t1:学生信息维护\n\t\t\t2:成绩排序\n\t\t\t3:查找学生信息\n\t\t\t4:查找某个同学的总分和平均分\n\t\t\t5:退出\n");
        printf("请选择功能选项:\n");
        cin>>a;
        if(a==1)
        {
            printf("\n\t\t\t*****************\n\t\t\t");
            printf("\n\t\t\t1:增加学生信息\n\t\t\t2:删除学生信息\n\t\t\t3:修改学生信息\n\t\t\t4:成绩统计\n\t\t\t5:退出\n");
            cout<<"请选择功能选项:"<<endl;
            cin>>c;
            if(c==1)insert1();
            else if(c==2)del();
            else if(c==3)xiugai();
            else if(c==4)s_tongji();
            else if(c==5) break;
        }
        else if(a==2)
        {
            init3();
            printf("\n\t\t\t1:按照数学成绩排序\n\t\t\t2:按照语文成绩排序\n\t\t\t3:按照英语成绩排序\n\t\t\t4:退出\n");
            cout<<"请选择功能选项:"<<endl;
            cin>>d;
            if(d==1)
            {
                int h;
                printf("\n\t\t\t1:按照数学成绩从小到大排序\n\t\t\t2:按照数学成绩从大到小排序\n\t\t\t3:退出\n");
                cout<<"请选择功能选项:"<<endl;
                cin>>h;
                if(h==1)
                {
                    sort(m.begin(),m.end(),s_math1);
                    for(ix=0; ix!=m.size(); ix++)
                    {
                        cout<<m[ix].name<<" "<<m[ix].id<<" ";
                        for(int i=0; i<3; i++)
                            cout<<m[ix].score[i]<<" ";
                        cout<<endl;
                    }
                    getchar();
                    getchar();
                }
                else if(h==2)
                {
                    sort(m.begin(),m.end(),s_math2);
                    for(ix=0; ix!=m.size(); ix++)
                    {
                        cout<<m[ix].name<<" "<<m[ix].id<<" ";
                        for(int i=0; i<3; i++)
                            cout<<m[ix].score[i]<<" ";
                        cout<<endl;
                    }
                    getchar();
                    getchar();
                }
            }
            else if(d==2)
            {
                int l;
                printf("\n\t\t\t1:按照语文成绩从小到大排序\n\t\t\t2:按照语文成绩从大到小排序\n\t\t\t3:退出\n");
                cout<<"请选择功能选项:"<<endl;
                cin>>l;
                if(l==1)
                {
                    sort(m.begin(),m.end(),s_yuwen1);
                    for(ix=0; ix!=m.size(); ix++)
                    {
                        cout<<m[ix].name<<" "<<m[ix].id<<" ";
                        for(int i=0; i<3; i++)
                            cout<<m[ix].score[i]<<" ";
                        cout<<endl;
                    }
                    getchar();
                    getchar();
                }
                else if(l==2)
                {
                    sort(m.begin(),m.end(),s_yuwen2);
                    for(ix=0; ix!=m.size(); ix++)
                    {
                        cout<<m[ix].name<<" "<<m[ix].id<<" ";
                        for(int i=0; i<3; i++)
                            cout<<m[ix].score[i]<<" ";
                        cout<<endl;
                    }
                    getchar();
                    getchar();
                }
                else if(l==3)
                    break;
            }
            else if(d==3)
            {
                int y;
                printf("\n\t\t\t1:按照英语成绩从小到大排序\n\t\t\t2:按照英语成绩从大到小排序\n\t\t\t3:退出\n");
                cout<<"请做出功能选项:"<<endl;
                cin>>y;
                if(y==1)
                {
                    sort(m.begin(),m.end(),s_yingyu1);
                    for(ix=0; ix!=m.size(); ix++)
                    {
                        cout<<m[ix].name<<" "<<m[ix].id<<" ";
                        for(int i=0; i<3; i++)
                            cout<<m[ix].score[i]<<" ";
                        cout<<endl;
                    }
                    getchar();
                    getchar();
                }
                else if(y==2)
                {
                    sort(m.begin(),m.end(),s_yingyu2);
                    for(ix=0; ix!=m.size(); ix++)
                    {
//                        cout<<m[ix].name<<" "<<m[ix].id<<" ";
                        for(int i=0; i<3; i++)
                            cout<<m[ix].score[i]<<" ";
                        cout<<endl;
                    }
                    getchar();
                    getchar();
                }
                else if(y==3)
                    break;
            }
            else if(d==4)break;

        }
        else if(a==3)
        {
            init2();
            printf("\n\t\t\t1:按姓名查找\n\t\t\t2:按学号查找\n\t\t\t");
            printf("\n请选择功能选项:\n");
            cin>>b;
            if(b==1)select1();
            else if(b==2)select2();
        }
        else if(a==4)zfhpjf();
        else if(a==5)break;
    }
    while(1);
    return 0;
}



