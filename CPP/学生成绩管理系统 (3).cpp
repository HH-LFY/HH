#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
using namespace std;
string zi[3]= {"��ѧ","����","Ӣ��"};
struct student
{
    string name, id;
    int score[3];//score[0]�����ģ�score[1]����ѧ��score[2]��Ӣ��
};
int number;
vector<student>m;//����student���͵�����
vector<student>::size_type ix;//�������
void input();
void init()//һ��ʼ�Խ���
{
    system("cls");
    printf("\n\n\n\n\t\t****************************\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**          ��ӭ          **\t\t\n");
    printf("\t\t**  ����ѧ���ɼ�����ϵͳ  **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t****************************\t\t\n");
    input();
    printf("\n�������ڶ�ȡ�У����Ժ�");
    printf("\t�밴���������������\n");
    getchar();
}
void init1()//���õ�������
{
    string yonghuming;
    int mima;
    system("cls");
    printf("\n\n\n\n\t\t****************************\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**           ��ӭ         **\t\t\n");
    printf("\t\t**   ����ѧ���ɼ�����ϵͳ **\t\t\n");
    printf("\t\t**         ֮����         **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t****************************\t\t\n");
    printf("\n\t\t�û��� (��ʾ��ѧ����ѧ�ţ���):");
    cin>>yonghuming;
    printf("\n");
    printf("\n\t\t����  (��ʾ���������ݣ���):");
    cin>>mima;
    printf("\n");
    printf("���ѳɹ����룬�밴�������������");
    getchar();
    getchar();
}
void init2()//�ڶ��εĳ�ʼ��
{
    system("cls");
    printf("\n\n\n\n\t\t***********************************\t\t\n");
    printf("\t\t*****                         *****\t\t\n");
    printf("\t\t*****                         *****\t\t\n");
    printf("\t\t*****           ��ӭ          *****\t\t\n");
    printf("\t\t*****   ����ѧ���ɼ�����ϵͳ  *****\t\t\n");
    printf("\t\t*****      ֮ѧ������         *****\t\t\n");
    printf("\t\t*****                         *****\t\t\n");
    printf("\t\t***********************************\t\t\n");
}
void init3()
{
    system("cls");
    printf("\n\n\n\n\t\t****************************\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**          ��ӭ          **\t\t\n");
    printf("\t\t**  ����ѧ���ɼ�����ϵͳ  **\t\t\n");
    printf("\t\t**     ֮�ɼ�����         **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t**                        **\t\t\n");
    printf("\t\t******************************\t\t\n");
}
void input()//�Ӵ���������
{
    ifstream infile;
    infile.open("D://ѧ���ɼ�����ϵͳ.txt",ios::in);
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
void insert1()//����ѧ����Ϣ
{
    int i;
    student p;
    cout<<"��������Ҫ����ѧ��������:"<<endl;
    cin>>p.name;
    cout<<"��������Ҫ����ѧ����ѧ��:"<<endl;
    cin>>p.id;
    cout<<"��������Ҫ����ѧ���ķ���:"<<endl;
    for(i=0; i<3; i++)
        cin>>p.score[i];
    m.push_back(p);
    cout<<"ѧ����Ϣ���ӽ�����ллʹ�ã���"<<endl;
}
void zfhpjf()//�����ͬѧ���ֺܷ�ƽ����
{
    string name1;
    int sum=0;
    cout<<"��������Ҫ�����ֵܷ�ѧ��������:"<<endl;
    cin>>name1;
    for(ix=0; ix!=m.size(); ix++)
    {
        if(m[ix].name==name1)
        {
            for(int i=0; i<3; i++)
                sum+=m[ix].score[i];
        }
    }
    cout<<"��ͬѧ���ܷ�Ϊ:"<<endl;
    cout<<sum<<endl;
    cout<<"��ͬѧ��ƽ����Ϊ:"<<endl;
    printf("%.2lf\n",(sum*1.0)/3);
    cout<<"�ѽ����ù��ܣ������ʹ�ã���\n"<<endl;
    getchar();
    getchar();
}

void del()//ɾ��ѧ����Ϣ
{
    int i;
    string name1;
    cout<<"��������Ҫɾ����ѧ��������:"<<endl;
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
    cout<<"ѧ����Ϣ��ɾ����ллʹ�ã���"<<endl;
}
void xiugai()//�޸�ѧ����Ϣ
{
    int i;
    string name2;
    cout<<"\n��������Ҫ�޸�ѧ������:";
    cin>>name2;
    for(ix=0; ix!=m.size(); ++ix)
    {
        if(m[ix].name==name2)
        {
            cout<<"\n�������µ�����!\n";
            cout<<"\n�µ�����:";
            cin>>m[ix].name;
            cout<<"\n�µ�ѧ��:";
            cin>>m[ix].id;
            cout<<"\n�µĳɼ�:";
            for(i=0; i<2; i++)
                cout<<m[ix].score[i]<<" ";
            cout<<m[ix].score[2];
        }
    }
    cout<<"�ѳɹ��޸ĸ�ѧ������Ϣ����"<<endl;
}

void select1()//������������ѧ����Ϣ
{
    int i;
    string name2;
    cout<<"������Ҫ����ѧ��������:"<<endl;;
    cin>>name2;
    for(ix=0; ix!=m.size(); ++ix)
    {
        if(m[ix].name==name2)
        {
            cout<<"��ѧ������ϢΪ:"<<endl;
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

void select2()//����ѧ�Ų���ѧ����Ϣ
{
    int i;
    string id1;
    cout<<" ������Ҫ����ѧ����ѧ��:"<<endl;;
    cin>>id1;
    for(ix=0; ix!=m.size(); ++ix)
    {
        if(m[ix].id==id1)
        {
            cout<<" ��ѧ������ϢΪ:"<<endl;
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

bool s_math1(student x,student y)//������ѧ�ɼ���С�����������
{
    return x.score[0]<y.score[0];
}
bool s_math2(student x,student y)//������ѧ�ɼ��Ӵ�С��������
{
    return x.score[0]>y.score[0];
}

bool  s_yuwen1(student x,student y)//�������ĳɼ���С�����������
{
    return x.score[1]<y.score[1];
}
bool s_yuwen2(student x,student y)//�������ĳɼ��Ӵ�С��������
{
    return x.score[1]>y.score[1];
}
bool s_yingyu1(student x,student y)//����Ӣ��ɼ���С�����������
{
    return x.score[2]<y.score[2];
}
bool s_yingyu2(student x,student y)//����Ӣ��ɼ��Ӵ�С��������
{
    return x.score[2]>y.score[2];
}
void s_tongji()//ͳ�Ƴɼ������
{
    int i;
    string kemu;
    int a,b,sum=0;
    char c;
    cout<<"��������Ҫͳ�ƵĿ�Ŀ�ͷ�����:"<<endl;
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
    cout<<"��ͳ�ƣ��õ��Ľ��Ϊ:"<<endl;
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
        printf("\n\t\t\t1:ѧ����Ϣά��\n\t\t\t2:�ɼ�����\n\t\t\t3:����ѧ����Ϣ\n\t\t\t4:����ĳ��ͬѧ���ֺܷ�ƽ����\n\t\t\t5:�˳�\n");
        printf("��ѡ����ѡ��:\n");
        cin>>a;
        if(a==1)
        {
            printf("\n\t\t\t*****************\n\t\t\t");
            printf("\n\t\t\t1:����ѧ����Ϣ\n\t\t\t2:ɾ��ѧ����Ϣ\n\t\t\t3:�޸�ѧ����Ϣ\n\t\t\t4:�ɼ�ͳ��\n\t\t\t5:�˳�\n");
            cout<<"��ѡ����ѡ��:"<<endl;
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
            printf("\n\t\t\t1:������ѧ�ɼ�����\n\t\t\t2:�������ĳɼ�����\n\t\t\t3:����Ӣ��ɼ�����\n\t\t\t4:�˳�\n");
            cout<<"��ѡ����ѡ��:"<<endl;
            cin>>d;
            if(d==1)
            {
                int h;
                printf("\n\t\t\t1:������ѧ�ɼ���С��������\n\t\t\t2:������ѧ�ɼ��Ӵ�С����\n\t\t\t3:�˳�\n");
                cout<<"��ѡ����ѡ��:"<<endl;
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
                printf("\n\t\t\t1:�������ĳɼ���С��������\n\t\t\t2:�������ĳɼ��Ӵ�С����\n\t\t\t3:�˳�\n");
                cout<<"��ѡ����ѡ��:"<<endl;
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
                printf("\n\t\t\t1:����Ӣ��ɼ���С��������\n\t\t\t2:����Ӣ��ɼ��Ӵ�С����\n\t\t\t3:�˳�\n");
                cout<<"����������ѡ��:"<<endl;
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
            printf("\n\t\t\t1:����������\n\t\t\t2:��ѧ�Ų���\n\t\t\t");
            printf("\n��ѡ����ѡ��:\n");
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



