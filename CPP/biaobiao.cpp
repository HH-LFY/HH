#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include<windows.h>
using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
int m;

struct student
{
int num;
char name[20];
int age;
char sex[4];
float 	Chinese;
float Mathematics;
float English;
float Matlab;
}  stu[20];

///void del();
///void sadd();
///void read();
///void find();
///void change();

int main()
{
char c;
void change();  //�޸���Ϣ
void del();     //ɾ����Ϣ
void sadd();    //�����Ϣ
void read();   //��ȡ��Ϣ
void find();   //������Ϣ

/*student stu[5] = {
100,"li",22,"nan",88,77,88,69,
101,"qs",34,"nan",78,78,69,79,
102,"ds",34,"nan",68,78,69,79,
103,"wa",34,"nan",58,78,69,79,
104,"jk",34,"nan",48,78,69,79};


fstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);  //ios::in��ʽ���ļ�ʱ���ļ�������ڡ�
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
exit(1);
}
for(int i=0;i<5;i++)     //��5����ֵд���ļ�
{iofile.write((char *)&stu[i],sizeof(stu[i]));}
iofile.close();*/

do
{//system("color 3b");  
  SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE); //���弰������ɫ
cout<<"  \n\n          |ѧ �� �� Ϣ �� �� �� ϵ ͳ|     \n";
cout<<"        *************************************************\n";
cout<<"        *    1��������ѧ����Ϣ                          *\n";
cout<<"        *     2����ɾ��ѧ����Ϣ                          *\n";
cout<<"        *      3�����޸�ѧ����Ϣ                          *\n";
SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED );
cout<<"        *       4������ѯѧ����Ϣ                          *\n";
cout<<"        *        5������ȡѧ����Ϣ                          *\n";
cout<<"        *         6�����˳�����ϵͳ                          *\n";
cout<<"        *************************************************\n";
cout<<"��ѡ��(1-8):";
cin>>c;
switch(c)
{
   case '1':     sadd();break;
   case '2':     del();break;
   case '3':     change();break;
   case '5':     read();break;
   case '4':     find();break;
}
}while(c!='6');
return 0;
}

void sadd()
{system("cls");
int i,m;
m=0;
char yn;
student stu[20];
cout<<"������Ҫ��ӵģ�"<<endl;
for(i=0;i<20;i++)   //��¼�뵽�ṹ����
{
cout<<"ѧ��:"<<endl;
cin>>stu[i].num;
cout<<"����:"<<endl;
cin>>stu[i].name;
cout<<"���� :"<<endl;
cin>>stu[i].age;
cout<<"�Ա�:"<<endl;
cin>>stu[i].sex;
cout<<"���� :"<<endl;
cin>>stu[i].Chinese;
cout<<"����:"<<endl;
cin>>stu[i].Mathematics;
cout<<"Ӣ��:"<<endl;
cin>>stu[i].English;
cout<<"MATLAB"<<endl;
cin>>stu[i].Matlab;

fstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);

if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
exit(1);
}
iofile.seekp(0,ios::end);  //�ҵ��ļ�ĩβ�������÷����α�270

iofile.write((char *)&stu[i],sizeof(stu[i]));  //�ѽṹ���飨ѧ������Ϣ��ӵ��ļ�ĩβ��

iofile.close();
cout<<"������y/n)\n";
cin>>yn;
if(yn=='n')
i=19;   //��break���
system("cls");
}
}

void read()   //��ȡ�ļ������е�����ѧ����Ϣ
{system("cls");
int i;
fstream iofile("wwz314.dat",ios::in|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
abort();
}

iofile.seekg(0,ios::beg);

for(i=0;i<20;i++)   //��ѧ��Ϊ��0�Ķ���
{
   iofile.read((char *)&stu[i],sizeof(stu[i]));
   if(stu[i].num!=0) cout<<" ѧ��:"<<stu[i].num<<" ����:"<<stu[i].name<<" ����:"<<stu[i].age<<" �Ա�:"<<stu[i].sex<<" ���� :"<<stu[i].Chinese<<" ����:"<<stu[i].Mathematics<<" Ӣ��:"<<stu[i].English<<" MATLAB:"<<stu[i].Matlab<<endl;
}
iofile.close();
}


void find()    //����ָ��ѧ����Ϣ
{
void findname();  //�����ֲ��Һ���˵�������庯��

void findnum();  //��ѧ��

cout<<"��ѡ����ҷ���:"<<endl;
   cout<<"         1.....����������."<<endl;
   cout<<endl;
   cout<<"         2.....��ѧ�Ų���."<<endl;
   cout<<endl;
cout<<"��ѡ��:";
int k;
cin>>k;
switch(k)
{
case 1: findname();break;
    case 2: findnum();break;
    }
}

void findname()  //�����ֲ��Ҵ���
{

	cout<<"������Ҫ���ҵ�������";

	string name;

	int j,i;

	cin>>name;

	fstream iofile("wwz314.dat",ios::in|ios::binary);

	if(! iofile)

	{

		cerr<<"�ļ���ʧ��!"<<endl;

		abort();

	}

iofile.seekg(0,ios::beg);
for(i=0;i<20;i++)
{
iofile.read((char *)&stu[i],sizeof(stu[i]));
   if(name==stu[i].name)
   {j=1;
   cout<<"��Ҫ���ҵ�������:"<<endl;
   cout<<"ѧ�� :"<<stu[i].num<<endl;
   cout<<"���� :"<<stu[i].name<<endl;
   cout<<"���� :"<<stu[i].age<<endl;
   cout<<"�Ա� :"<<stu[i].sex<<endl;
   cout<<"���� :"<<stu[i].Chinese<<endl;
   cout<<"���� :"<<stu[i].Mathematics<<endl;
   cout<<"Ӣ�� :"<<stu[i].English<<endl;
   cout<<"MATLAB:"<<stu[i].Matlab<<endl;
   cout<<endl;
   i=19;}
}
if (j!=1) cout<<"�Բ���,û�ҵ���Ҫ����Ϣ!"<<endl<<endl ;
   iofile.close();
}

void findnum()
{
cout<<"������Ҫ���ҵ�ѧ�ţ�";
int num;
int j,i;
cin>>num;
fstream iofile("wwz314.dat",ios::in|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
abort();
}

iofile.seekg(0,ios::beg);
for(i=0;i<20;i++)
{
   iofile.read((char *)&stu[i],sizeof(stu[i]));
    if(num==stu[i].num)
{j=1;
   cout<<"��Ҫ���ҵ�������:"<<endl;
   cout<<"ѧ�� :"<<stu[i].num<<endl;
   cout<<"���� :"<<stu[i].name<<endl;
   cout<<"���� :"<<stu[i].age<<endl;
   cout<<"�Ա� :"<<stu[i].sex<<endl;
   cout<<"���� :"<<stu[i].Chinese<<endl;
   cout<<"���� :"<<stu[i].Mathematics<<endl;
   cout<<"Ӣ�� :"<<stu[i].English<<endl;
   cout<<"MATLAB:"<<stu[i].Matlab<<endl;
   cout<<endl;
   i=19;}
}
if (j!=1) cout<<"�Բ���,û�ҵ���Ҫ����Ϣ!"<<endl<<endl ;
}

void del()
{//void read();
cout<<"������ѧ�ţ�";
int num;
int temp=-1;
int j=0,i;
cin>>num;
ifstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
abort();
}

iofile.seekg(0,ios::beg);

for(i=0;i<20;i++)
{
   iofile.read((char *)&stu[i],sizeof(stu[i]));
   if(num==stu[i].num)
   {j=1;   //�ҵ�����б��
   temp=i;  //�ҵ������
   }
}
iofile.close();
if(j!=1)
{
cout<<"�Բ���,û�ҵ���Ҫ����Ϣ!"<<endl<<endl ;
}
if(temp!=-1)
{ofstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
abort();
}

    cout<<"ȷ��ɾ����?[y/n]"<<endl;
    char c;cin>>c;
    if(c=='y')    //�Ѵ�ɾ��������ѧ����Ϣ��0������д���ļ�����ʵδ����ɾ��
     {
      stu[temp].num=0;
      stu[temp].name[0]='0';
      stu[temp].age=0;
      stu[temp].sex[0]='0';
      stu[temp].Chinese=0;
      stu[temp].Mathematics=0;
      stu[temp].English=0;
      stu[temp].Matlab=0;

   iofile.seekp(temp*sizeof(stu[temp]),ios::beg);
   iofile.write((char *)&stu[temp],sizeof(stu[temp]));
   cout<<"�Ѿ��ɹ�ɾ��!"<<endl;   //��ʵδ����ɾ��
}}
}

void change()
{
//void read();
cout<<"������ѧ�ţ�";
char name[20],sex[20];
int temp,chi,mat,lab,eng,age,num;
int j,i;
cin>>num;
ifstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{cerr<<"�ļ���ʧ��!"<<endl;
abort();
}

iofile.seekg(0,ios::beg);

for(i=0;i<20;i++)
{
   iofile.read((char *)&stu[i],sizeof(stu[i]));
   if(num==stu[i].num)
   {j=1;
   temp=i;
   }
}
   if(j!=1)
   {
cout<<"�Բ���,û�ҵ���Ҫ����Ϣ!"<<endl<<endl ;
   }
iofile.close();
if(temp!=-1)
{ofstream iofile("wwz314.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
abort();
}
cout<<"ȷ���޸���?[y/n]"<<endl;
char c;cin>>c;
if(c='y')
{
   cout<<"�������µ�ѧ����ѧ��:"<<"ԭѧ�ţ�"<<stu[temp].num<<endl;
   cin>>num;
   stu[temp].num=num;
   cout<<"�������µ�ѧ��������:"<<"ԭ������"<<stu[temp].name<<endl;
   cin>>name;
   strcpy(stu[temp].name,name);
   cout<<"�������µ�ѧ��������:"<<"ԭ���䣺"<<stu[temp].age<<endl;
   cin>>age;
   stu[temp].age=age;
   cout<<"�������µ�ѧ�����Ա�:"<<"ԭ�Ա�"<<stu[temp].sex<<endl;
   cin>>sex;
   strcpy(stu[temp].sex,sex);
   cout<<"�������µ�ѧ�������ķ���"<<"ԭ�ɼ���"<<stu[temp].Chinese<<endl;
   cin>>chi;
   stu[temp].Chinese=chi;
   cout<<"�������µ�ѧ���ĸ�������"<<"ԭ�ɼ���"<<stu[temp].Mathematics<<endl;
   cin>>mat;
   stu[temp].Mathematics=mat;
   cout<<"�������µ�ѧ����Ӣ�����"<<"ԭ�ɼ���"<<stu[temp].English<<endl;
   cin>>eng;
   stu[temp].English=eng;
   cout<<"�������µ�ѧ����MATLAB����"<<"ԭ�ɼ���"<<stu[i].Matlab<<endl;
   cin>>lab;
   stu[i].Matlab=lab;
    iofile.seekp(temp*sizeof(stu[temp]),ios::beg);
   iofile.write((char *)&stu[temp],sizeof(stu[temp]));
   cout<<"�Ѿ��ɹ��޸ģ�"<<endl;
   }}
}

