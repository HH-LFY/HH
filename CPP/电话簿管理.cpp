#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<stdlib.h>
using namespace std;
#define M 20
#define N 12
class Fphone        //��Ķ��壬�����������͵绰����
{
    char name[M];     //������Ա
    char phone_num[N];      //�绰�����Ա
public:
    Fphone(char *namep=NULL,char *phone_nump=NULL)  //���캯��
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
    char *getname();        //��ȡ����
    char *getphone_num();                //��ȡ�绰����
void setname(char *na);               //��������
    void setphone_num(char *num);        //���õ绰����
    void disp();                         //����û���Ϣ
    ~Fphone(){};                        //��������
};

char *Fphone::getname()                 //���ⶨ�庯��
{
    return name;
}

char *Fphone::getphone_num()            //���ⶨ�庯��

{
    return phone_num;
}

void Fphone::setname(char *na)          //���ⶨ�庯��

{
    strcpy(name,na);
}

void Fphone::setphone_num(char*num)   //���ⶨ�庯��

{
    strcpy(phone_num,num);
}

void Fphone::disp()                     //���ⶨ�庯��

{
    cout<<"������"<<name<<'\t'<<"�绰���룺"<<phone_num<<endl;
}

class UserDatabase
{
    int nElem;            //�û���Ϣ���е�Ԫ�ظ���
    int Maxu;            //�û���Ϣ��������Ԫ�ظ���
    Fphone *user;        //ָ���û���Ϣ��ָ��
public:
    UserDatabase();       //���캯������ʼ���û���Ϣ����user.txt�ļ��е����ݶ���user[]��
    ~UserDatabase();        //������������user[]д��user->txt�ļ���
    Fphone *getuser()
    {
        return user;
    }        //��ȡָ���û���Ϣ���ָ��
    void clear();        //ɾ�������û���Ϣ
    void add_record(char *na,char *ph_num);      //����û���Ϣ�������û����԰���������
    void delete_record(Fphone *p,int k);        //ɾ���û���Ϣ
    void modify_record(Fphone *p,char *ph_num);        //�޸��û���Ϣ
    Fphone *query(char *na);        //����������
    void sorta_name();        //��������������
    void sorta_phonenum();        //���绰������������
    void sort_name();        //����������,���ų�����Ķ��������������
    void sort_phonenum();        //���绰���뽵������
    void disp();        //��������û���Ϣ
};

UserDatabase::UserDatabase()        //���ⶨ�幹�캯��
{
    nElem=0;     //�û���Ϣ����Ԫ�ظ�����ֵΪ��

    Maxu=100;    //�û��������100
    user=new Fphone[Maxu];   //��̬����ռ�
    fstream infile;  //����һ���ļ�������

    infile.open("user.txt",ios::in);      //��ȡuser.txt�ļ�
    if(!infile)
    {
        cout<<"�޷����ļ���user.txt"<<endl;
        exit(1);     //������������
    }
	for(int i=0;(!infile.eof());i++)
		{	infile>>user[i].getname();infile>>user[i].getphone_num();         //���ļ��л�ȡ�������绰����
         	nElem++;
	}
    infile.close();    //�ر��ļ�
}

UserDatabase::~UserDatabase()      //���ⶨ����������
{
    fstream outfile;                  //����һ���ļ�������
    outfile.open("user.txt",ios::out);       //����д��user.txt
    if(!outfile)
        cout<<"�޷����ļ���user.txt"<<endl;
    exit(2);                      //������������
    Fphone *p=NULL;
    p=user;
    for(int i=0;i<nElem;i++)
		{	outfile<<setw(20)<<((p+i)->getname())<<setw(15)
			<<((p+i)->getphone_num())<<endl;            //���ļ��в����������绰
		}delete []user;          //�ͷſռ�
		outfile.close();          //�ر��ļ�
}

void UserDatabase::clear()            //ɾ��ȫ�����ݺ���
{
    cout<<"***********************************"<<endl;
    cout<<"             ɾ��ȫ����¼"          <<endl;
    cout<<"***********************************"<<endl;
    cout<<"ȷ��ɾ��ȫ���û���Ϣ��"<<endl;
    cout<<"ȷ��(1)       ȡ��(2)"<<endl;
    int i;
    cin>>i;
    switch(i)
    {        case 1: delete []user;   //ִ���������
                   nElem=0;
                   break;
             case 2: break;       //��������
             default:cout<<"�������"<<endl;
    }
}

void UserDatabase::add_record(char *na,char *num)        //��Ӽ�¼
{
	int i;
    if (nElem==0)         //û�м�¼
    {
        nElem++;
        user->setname(na);
        user->setphone_num(num);
    }
    else if(nElem<Maxu)          //�м�¼���пռ�
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
    else             //�ռ䲻��
        cout <<"�ռ䲻�㣬�޷����!"<<endl;
}

void UserDatabase::delete_record(Fphone *a,int b)        //ɾ����¼
{
    cout<<"ȷ��ɾ�����û���Ϣ��"<<endl;
    cout<<"ȷ��(1)       ȡ��(2)"<<endl;
    int c;
    cin>>c;
    if (c==2) return;              //ȡ������
    else if (c==1)
    {
        for(int i=b;i<nElem;i++)
        {
            user[i]=user[i+1];
        }
        nElem--;
        cout<<"ɾ���ɹ�"<<endl;
    return;
    }
    else
    {
		cout<<"�������"<<endl;
        system("pause");
        return;
    }
}

void UserDatabase::modify_record(Fphone *a,char *num)         //�޸ļ�¼
{
    cout<<"ȷ���޸ĸ��û���Ϣ��"<<endl;
    cout<<"ȷ��(1)       ȡ��(2)"<<endl;
    int b;
    cin>>b;
    if(b==1)
    {
        a->setphone_num(num);         //���õ绰����
        cout<<"�޸ĳɹ�"<<endl;
        return;
    }
    else        if(b==2) return;
    else
    {        cout<<"�������"<<endl;
    system("pause");
    return;
    }
}

Fphone *UserDatabase::query(char *na)         //����������
{
    Fphone *p=user;
    int i=0;
    while(1)
    {
        if(strcmp(p->getname(),na)==0)        //��ͬ������
            return p;
        p++;
        if(i++==nElem)
            break;
    }
    return NULL;
}

void UserDatabase::sorta_name()       //���������򣬲��뷨����
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
    cout<<"�������"<<endl;
}

void UserDatabase::sorta_phonenum()      //���绰���򣬲��뷨����
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
    cout<<"�������"<<endl;

}

void UserDatabase::sort_name()       //���������򣬲��뷨����
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
    cout<<"�������"<<endl;
}

void UserDatabase::sort_phonenum()        //���绰���򣬲��뷨����
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
    cout<<"�������"<<endl;
}

void UserDatabase::disp()        //��������û���Ϣ
{
    int i,n=0;
    cout<<setw(22)<<"����"<<setw(14)<<"�绰����"<<endl;
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

int main()       //������
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
                 cout<<"    ��ӭʹ�õ绰������ϵͳ    "<<endl;
                 cout<<"                              "<<endl;
                 cout<<"                              "<<endl;
                 cout<<"                              "<<endl;
                 cout<<"                              "<<endl;
        cout<<"-----------------------------------------------"<<endl;
        system("pause");
        system("cls");
        cout<<"��ѡ�����¹���"<<endl;
        cout<<"1-���Ӽ�¼"<<endl;
        cout<<"2-�޸ļ�¼"<<endl;
        cout<<"3-ɾ����¼"<<endl;
        cout<<"4-���ң���������"<<endl;
        cout<<"5-����"<<endl;
        cout<<"6-��ʾ��¼"<<endl;
        cout<<"7-ȫɾ"<<endl;
        cout<<"0-�˳�"<<endl;
        cout<<"����ѡ��"<<endl;
        cin>>i;
        cout<<endl;
        switch(i)          //�˵�ѡ����
        {
        case 1:
            {
                system("cls");                 //����
                char name[20],num[12];
                cout<<"***********************************"<<endl;
                cout<<"             ���Ӽ�¼"<<endl;
                cout<<"***********************************"<<endl;
                cout<<"�����������û���������";
                cin>>name;
                cout<<endl;
                cout<<"�����������û��ĺ��룺";
                cin>>num;
                userdatabase.add_record(name,num);   //���Ӽ�¼����
                userdatabase.sorta_name();           //Ĭ�ϰ���������
                system("pause");                    //��ͣ
                break;
            }
        case 2:
            {
                system("cls");
                cout<<"***********************************"<<endl;
                cout<<"             �޸ļ�¼"<<endl;
                cout<<"***********************************"<<endl;
                char na[20],ph_num[12];
                Fphone *t=new Fphone;
                cout<<"��������Ҫ�޸ĵ��û�������";
                cin>>na;
                t=userdatabase.query(na);      //����������
                if(!t)
                    cout<<"û�и��û�!"<<endl;
                else
                {
                    cout<<"���û�ԭ����Ϊ��"<<t->getphone_num()<<endl;
                    cout<<"�������µĵ绰����";
                    cin>>ph_num;
                    userdatabase.modify_record(t,ph_num);   //�޸ļ�¼
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
                cout<<"             ɾ����¼"<<endl;
                cout<<"***********************************"<<endl;
                cout<<"��������Ҫɾ�����û�������";
                cin>>name;
                Fphone *p=userdatabase.query(name);
                if(p==0)
                    cout<<"û�и��û�"<<endl;
                else
                {
                    cout<<"������"<<p->getname()<<endl;
                    cout<<"�绰���룺"<<p->getphone_num()<<endl;
                    int k=p-userdatabase.getuser();     //��ȡ�û�ָ��
                    userdatabase.delete_record(p,k);    //ɾ����¼
                }
                system("pause");
                break;
            }
        case 4:
            {
                system("cls");
                char name[20];
                cout<<"***********************************"<<endl;
                cout<<"             ���Ҽ�¼"<<endl;
                cout<<"***********************************"<<endl;
                cout<<"�������û�����"<<'\t';
                cin>>name;
                Fphone *i=NULL;
                i=userdatabase.query(name);       //����������
                if(i)
                {
                    cout<<"������"<<i->getname()<<endl;
                    cout<<"�绰���룺"<<i->getphone_num()<<endl;
                }
                else
                    cout<<"û�д��û�"<<endl;
                system("pause");
                break;
            }
        case 5:
            {
                system("cls");
                int j;
                cout<<"��ѡ������ʽ"<<endl;
                cout<<"1-������������"<<endl;
                cout<<"2-���绰���루����"<<endl;
                cout<<"3-������������"<<endl;
                cout<<"4-���绰���루����"<<endl;
                cout<<"������ѡ��"<<endl;
                cin>>j;
                cout<<endl;
                switch(j)
                {
                case 1:
                    {        system("cls");
                    userdatabase.sorta_name();   //����������
                    userdatabase.disp();
                    system("pause");
                    break;
                    }
                case 2:
                    {        system("cls");
                    userdatabase.sorta_phonenum();   //���绰����
                    userdatabase.disp();
                    system("pause");
                    break;
                    }
                case 3:
                    {        system("cls");
                    userdatabase.sort_name();     //����������
                    userdatabase.disp();
                    system("pause");
                    break;
                    }
                case 4:
                    {        system("cls");
                    userdatabase.sort_phonenum();      //���绰����
                    userdatabase.disp();
                    system("pause");
                    break;
                    }
                default :cout<<"�������"<<endl;
                };break;
                case 6:
                    {
                        system("cls");
                        userdatabase.disp();         //��������û���Ϣ
                        system("pause");
                        break;
                    }
                case 7:
                    {
                        system("cls");
                        userdatabase.clear();         //ɾ��ȫ����¼
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
                        cout<<"***********��ӭ�ٴ�ʹ��***********"<<endl;
                        cout<<endl;
                        exit(1);
                    };break;
                default :
                    {        cout<<"�������"<<endl;                }
            }
        }
}
return 0;
}
