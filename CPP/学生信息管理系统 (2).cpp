#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class student
{
private:
    long int stu_num;      //ѧ�ţ������
    char stu_name[40];     //����
    char class_name[40];   //���
char house_name[20]; //����
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
char * Getstuname(void) //��������
{
   return stu_name ;
}
long Getstunum(void) //ѧ�Ų���
{
   return stu_num;
}
char * Gethousename(void) //����Ų���
{
   return house_name;
}
char * Getclassname(void) //���༶����
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
        cout<<"ѧ��:"<<stu_num<<"\t"<<"����:"<<stu_name<<"\t";
        cout<<"�༶:"<<class_name<<"\t\t"<<"����:"<<house_name<<"\n";
}
};

void main(void)
{
student s1;
int flags=0;
    long stu_num; //ѧ��
    char stu_name[40];        //����
    char class_name[40];        //�༶
    char house_name[20];      //����
time_t t;
    time(&t);
    ifstream file1;
    ofstream file3;
    char flag = 'y';
    cout<< "---------------------------------ѧ����Ϣ����ϵͳ-------------------------------"<<endl;
    cout<< "\t\t\t ʱ��:" << ctime(&t);
    while( flag=='y' || flag=='Y')
{      //��flag����ѭ��
   cout<<"--------------------------------------------------------------------------------\n";
   cout<<"\t\t 1:ע��ѧ��!\n";
   cout<<"\t\t 2:��ѧ�Ų鿴ѧ����Ϣ!\n";
   cout<<"\t\t 3:������Ų鿴ѧ����Ϣ!\n";
   cout<<"\t\t 4:�������鿴ѧ����Ϣ!\n";
   cout<<"\t\t 5:���༶�鿴ѧ����Ϣ!\n";
   cout<<"\t\t 6:��ʾȫ��ѧ����Ϣ\n";
   cout<<"\t\t 7:��ѧ���޸�ѧ����Ϣ\n";
//   cout<<"\t\t 8:��ѧ��ɾ��ѧ����Ϣ!\n";
   cout<<"--------------------------------------------------------------------------------\n";
   cout<<"������ѡ��";
   char choice;
   cin>>choice;
   switch(choice)
   {
        case '1':
    file3.open("c:\\stu.dat",ios::app|ios::binary);
input:      flags=0;
    cout<<"����ѧ�ţ�";
    cin>>stu_num;
    while (stu_num<100000 || stu_num>999999)
    {
     cin.clear();
     rewind(stdin);
     cout << "�������ѧ�Ų���ȷ��������һ����λ����ѧ��" << endl;
     cout << "ѧ��:";
     cin >> stu_num;
    }
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//������ʽ���ļ�
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
     cout << "ѧ���ظ�,��������!" << endl;
     goto input;
    }
    cout<<"����������"; cin>>stu_name;
            cout<<"����༶��"; cin>>class_name;
            cout<<"�������᣺"; cin>>house_name;
            s1.Setdata(stu_num,stu_name,class_name,house_name);
            file3.write((char*)&s1,sizeof(s1));
    file3.clear();
            file3.close();
            break;
        case '2': //��ѧ�Ų���
            cout<<"������ѧ����ѧ�ţ�";
    cin>>stu_num;
    while (stu_num<100000 || stu_num>999999)
    {
     cin.clear();
     rewind(stdin);
     cout << "�������ѧ�Ų���ȷ��������һ����λ����ѧ��" << endl;
     cout << "ѧ��:";
     cin >> stu_num;
    }
            file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//������ʽ���ļ�
    while(!file1.eof())
    {
     int n;
     file1.read((char *)&s1,sizeof(student));
     n=file1.gcount();
     if(n==sizeof(student))
     {
      if(s1.Getstunum()==stu_num)    //��ʾѧ����Ϣ
      {
       s1.Show();
       flags=1;
      }
     }
    }
    file1.clear();
            file1.close();
    if (flags==0)
     cout << "û����ѧ��Ϊ��"<< stu_num <<"��ѧ����¼!" << endl;
    flags=0;
            break;
   case '3':   //������Ų���
    cout<<"�����������:";
    cin>>house_name;
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//������ʽ���ļ�
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
     cout << "û���ҵ�����Ϊ:"<< house_name <<"��ѧ����¼!" << endl;
    flags=0;
    break;
   case '4':   //����������
    cout<<"������ѧ������:";
    cin>>stu_name;
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//������ʽ���ļ�
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
     cout << "û���ҵ�����Ϊ:"<< stu_name <<"��ѧ����¼!" << endl;
    flags=0;
    break;
   case '5':   //���༶����
    cout<<"������༶����:";
    cin>>class_name;
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//������ʽ���ļ�
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
     cout << "û���ҵ��ð༶Ϊ:"<< class_name <<"��ѧ����¼!" << endl;
    flags=0;
    break;
   case '6': //��ʾȫ��ѧ����Ϣ
            file1.open("c:\\stu.dat",ios::in | ios::binary);//������ʽ���ļ�
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
     cout << "���ݿ�û�м�¼!" << endl;
    flags=0;
    break;
   case '7':   //�޸�ѧ����Ϣ��ѧ��
    flags=0;
    cout<<"������Ҫ�޸�ѧ����ѧ��:";
    cin>>stu_num;
    while (stu_num<100000 || stu_num>999999)
    {
     cin.clear();
     rewind(stdin);
     cout << "�������ѧ�Ų���ȷ��������һ����λ����ѧ��" << endl;
     cout << "ѧ��:";
     cin >> stu_num;
    }
    file1.open("c:\\stu.dat",ios::in | ios::binary | ios::beg);//������ʽ���ļ�
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
       cout<<"����������"; cin>>stu_name;
       cout<<"����༶��"; cin>>class_name;
       cout<<"�������᣺"; cin>>house_name;
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
     cout << "û�д�ѧ����¼�����ܽ����޸ģ�" << endl;
     break;
    }
    break;
// case '8':   //ɾ��ѧ����Ϣ��ѧ��
   default: flag = 'n';
    break;
        }
    }
cout << "лл����ʹ��!" << endl;
}