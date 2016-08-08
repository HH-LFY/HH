#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<windows.h>
using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

struct student
{ 
  int  num;
  char name[10];
  int  age;
  char sex[5];
  float  Chinese;
  float  Math;
  float  English;
  float  Java;
} stud[10];  

int main()
{int t;            //����һ�����ͱ���t���������������ѡ��ѡ�� 
void read();      //����һ����ȡ�ļ������е�ѧ����Ϣ�ĺ��� 
void find();      //����һ������Ҫ�����ѧ����Ϣ�ĺ��� 
void add();       //����һ�����ѧ����Ϣ�ĺ��� 
void cancel();    //����һ��ɾ��ѧ����Ϣ�ĺ��� 
void change();    //����һ���޸���Ϣ�ĺ��� 
//======================================================
student stud[10] = 
	{
       1001,"�����",18,"man",90,66,60,87,
       1002,"�ֳ���",20,"man",97,79,68,80,
       1003,"������",20,"man",78,89,80,90,
       1004,"�ƹ޻�",19,"man",84,77,69,91,
       1005,"����"  ,18,"man",91,90,70,67,
   };

fstream iofile("longbiao.dat",ios::in|ios::out|ios::binary|ios::trunc);
 
if(!iofile)
{
   cerr<<"�ļ���ʧ��!"<<endl;
   exit(1);     
}
for(int i=0;i<5;i++)     
{iofile.write((char *)&stud[i],sizeof(stud[i]));}
iofile.close();
//======================================================

do
{ SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
    cout<<"                      �ӭʹ��ѧ������ϵͳ��                           "<<endl;                                                                       
	cout<<"         �v                 ��        ��         �u        �u            "<<endl;
	cout<<"           �v              ��          ��      �u        �u              "<<endl; 
	cout<<"             �v           ��            ��   �u        �u                "<<endl; 
    cout<<"               �v        ��              ��u        �u                  "<<endl;
	cout<<"                 �v                      �u        �u                    "<<endl;
	cout<<"     ��������������������������������������������������������������������"<<endl;
	cout<<"     ��1***********���vȡѧ����Ϣ              �u                      ��"<<endl;
	cout<<"     ��2***********��ѯ�vѧ����Ϣ            �u                        ��"<<endl;
	cout<<"     ��3***********���ѧ�v����Ϣ          �u                          ��"<<endl;
	cout<<"     ��4***********ɾ��ѧ���v��Ϣ        �u                            ��"<<endl;
	cout<<"     ��5***********�޸�ѧ���ŨvϢ      �u                              ��"<<endl;
	cout<<"     ��6***********�˳�����ϵͳ�v    �u                                ��"<<endl;
	cout<<"     ��                  �u      �v�u                                  ��"<<endl; 
	cout<<"     ��                �u        �u�v                                  ��"<<endl;
	cout<<"     ��              �u        �u    �v                  ����������    ��"<<endl;
	cout<<"     ��������������������������������������������������������������������"<<endl;
	cout<<"                �u        �u             �v                              "<<endl;
	cout<<"              �u        �u                 �v                            "<<endl;
	cout<<"            �u        �u                     �v                          "<<endl;
	cout<<"          �u        �u                         �v                        "<<endl;
	cout<<"        �u        �u                             �v                      "<<endl; 
cout<<"��������������        ��ѡ��(1-6):"; 
cin>>t;
switch(t)
{
   case 1:     read();break;
   case 2:     find();break;
   case 3:     add();break;
   case 4:     cancel();break;
   case 5:     change();break;
}
}while(t!=6);
return 0;
}


//==============================����һ����ȡ�ļ������е�ѧ����Ϣ�ĺ���
void read()            
{ system("cls");       
    int i; 
    fstream iofile("longbiao.dat",ios::in|ios::binary);
    if(! iofile)
{
    cerr<<"�ļ���ʧ��!"<<endl;
    exit(1);
}
for(i=0;i<10;i++)   
{
   iofile.read((char *)&stud[i],sizeof(stud[i]));
   if(stud[i].num!=0)   //����û�и�ֵ�Ķ�Ϊ�㣬����������Ͳ�������� 
   cout<<" ѧ��:"<<stud[i].num<<" ����:"<<stud[i].name<<" ����:"<<stud[i].age<<" �Ա�:"<<stud[i].sex<<" ���� :"<<stud[i].Chinese<<" ����:"<<stud[i].Math<<" Ӣ��:"<<stud[i].English<<" JAVA:"<<stud[i].Java<<endl<<endl;
}
   iofile.close();
}


//==============================����һ������Ҫ�����ѧ����Ϣ�ĺ���
void find()   
{
void find_name();  //�����ֲ���ָ��ѧ����Ϣ
void find_num();  //��ѧ�Ų���ָ��ѧ����Ϣ

cout<<"��ѡ����ҷ���:"<<endl;
   cout<<"��������������        1�����������ҡ�����"<<endl;
   cout<<endl;
   cout<<"��������������        2����ѧ�Ų��ҡ�����"<<endl;
   cout<<endl;
   cout<<"��������������        ��ѡ�� :";
int z;
cin>>z;
switch(z)
{
    case 1: find_name();break;
    case 2: find_num();break;
    }
}
void find_name()   //�����ֲ���ѧ����Ϣ 
{
    cout<<"��������������        ������Ҫ���ҵ�������";
    string name;
    int i,j;     //j�����������ã� 
    cin>>name;
fstream iofile("longbiao.dat",ios::in|ios::binary);   
  if(! iofile)
  {
    cerr<<"�ļ���ʧ��!"<<endl;
    exit(1);
  }
for(i=0;i<10;i++)
{
iofile.read((char *)&stud[i],sizeof(stud[i]));
   if(name==stud[i].name)
   {j=1;
   cout<<"��������������        ��Ҫ���ҵ�ѧ����Ϣ��:"<<endl;
   cout<<"ѧ�� :"<<stud[i].num<<endl;
   cout<<"���� :"<<stud[i].name<<endl;
   cout<<"���� :"<<stud[i].age<<endl;
   cout<<"�Ա� :"<<stud[i].sex<<endl;
   cout<<"���� :"<<stud[i].Chinese<<endl;
   cout<<"���� :"<<stud[i].Math<<endl;
   cout<<"Ӣ�� :"<<stud[i].English<<endl;
   cout<<"JAVA :"<<stud[i].Java<<endl;
   cout<<endl;
   i=9;}
}
if (j!=1) cout<<"��������������        �Բ���,û�ҵ���Ҫ����Ϣ!"<<endl<<endl ;
iofile.close();
}
void find_num()     //��ѧ�Ų���ѧ����Ϣ 
{
cout<<"��������������        ������Ҫ���ҵ�ѧ�ţ������磺1001��";
int num;
int i,j;  //j������������ 
cin>>num;
fstream iofile("longbiao.dat",ios::in|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
exit(1);
}
for(i=0;i<10;i++)
{
    iofile.read((char *)&stud[i],sizeof(stud[i]));
    if(num==stud[i].num)
{  j=1;
   cout<<"��������������        ��Ҫ���ҵ�ѧ����Ϣ��:"<<endl;
   cout<<"ѧ�� :"<<stud[i].num<<endl;
   cout<<"���� :"<<stud[i].name<<endl;
   cout<<"���� :"<<stud[i].age<<endl;
   cout<<"�Ա� :"<<stud[i].sex<<endl;
   cout<<"���� :"<<stud[i].Chinese<<endl;
   cout<<"���� :"<<stud[i].Math<<endl;
   cout<<"Ӣ�� :"<<stud[i].English<<endl;
   cout<<"JAVA :"<<stud[i].Java<<endl;
   cout<<endl;
   i=9;}
}
if (j!=1) cout<<"��������������        �Բ���,û�ҵ���Ҫ����Ϣ!"<<endl<<endl ;
}

//==============================����һ�����ѧ����Ϣ�ĺ���  
void add()
{system("cls");
int i;
char j; // ����һ���ַ��ͱ���j������ѡ��ѡ�� 
cout<<"��������������       �밴Ҫ������Ҫ��ӵ���Ϣ��"<<endl;
for(i=0;i<10;i++)   
{
cout<<"ѧ��:"<<"    ";  cin>>stud[i].num;
cout<<"����:"<<"    ";  cin>>stud[i].name;
cout<<"����:"<<"    ";  cin>>stud[i].age;
cout<<"�Ա�:"<<"    ";  cin>>stud[i].sex;
cout<<"����:"<<"    ";  cin>>stud[i].Chinese;
cout<<"����:"<<"    ";  cin>>stud[i].Math;
cout<<"Ӣ��:"<<"    ";  cin>>stud[i].English;
cout<<"JAVA:"<<"    ";  cin>>stud[i].Java;

fstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
exit(1);
}
//=======================================
iofile.seekp(0,ios::end); 
//=======================================
iofile.write((char *)&stud[i],sizeof(stud[i]));  
iofile.close();
cout<<"��������������   �Ƿ�������ѧ����Ϣ��������������ֻ���ĸ����������������n��"<<endl;
cin>>j;
if(j=='n')
i=9;   
system("cls");
}
}

//==============================����һ��ɾ��ѧ����Ϣ�ĺ���
void cancel()
{ cout<<"��������������        ������Ҫɾ����ѧ�ţ�����1001����";
  int num;
  int temp=1; //����һ�������洢ѧ�ŵı���temp��ͬʱҲ������������ 
  int i,j;   //j������������ 
  cin>>num;
ifstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
exit(1);
}
for(i=0;i<10;i++)
{
   iofile.read((char *)&stud[i],sizeof(stud[i]));
   if(num==stud[i].num)
   {j=1;     
   temp=i;   
   }
}
iofile.close();
if(j!=1)
{
cout<<"��������������        �Բ���,û�ҵ���Ҫ����Ϣ!"<<endl<<endl ;
}
if(temp!=1)
{ofstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
exit(1); 
}

    cout<<"��������������       ȷ��ɾ����?��ȷ��������Y��������������ֻ���ĸ�����أ�"<<endl;
    char c;
	cin>>c;
    if(c=='y')    
     {
      stud[temp].num=0;
      stud[temp].name[0]='0';
      stud[temp].age=0;
      stud[temp].sex[0]='0';
      stud[temp].Chinese=0;
      stud[temp].Math=0;
      stud[temp].English=0;
      stud[temp].Java=0;
//================================================
   iofile.seekp(temp*sizeof(stud[temp]),ios::beg);
//================================================
   iofile.write((char *)&stud[temp],sizeof(stud[temp]));
   cout<<"�Ѿ��ɹ�ɾ��!"<<endl;   
}}
}

//==============================����һ���޸���Ϣ�ĺ���
void change()
{
cout<<"��������������       ������ѧ�ţ�����1001����";
char name[10],sex[5];
int temp=1,chi,mat,Ja,eng,age,num;
int i,j;
cin>>num;
ifstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{cerr<<"�ļ���ʧ��!"<<endl;
exit(1);
}
for(i=0;i<10;i++)
{
   iofile.read((char *)&stud[i],sizeof(stud[i]));
   if(num==stud[i].num)
   {j=1;
   temp=i;
   }
}
if(j!=1)
   {
       cout<<"��������������       �Բ���,û�ҵ���Ҫ����Ϣ!"<<endl<<endl ;
   }
iofile.close();
if(temp!=1)
{ofstream iofile("longbiao.dat",ios::in|ios::out|ios::binary);
if(! iofile)
{
cerr<<"�ļ���ʧ��!"<<endl;
exit(1);
}
cout<<"��������������       ȷ���޸���?��ȷ��������Y��������������ֻ���ĸ�����أ�"<<endl;
char c;
cin>>c;
if(c='y')
{
   cout<<"��������������       �������µ�ѧ����ѧ��:"<<"ԭѧ��Ϊ��"<<stud[temp].num<<endl;cin>>num;
   stud[temp].num=num;
   cout<<"��������������       �������µ�ѧ��������:"<<"ԭ����Ϊ��"<<stud[temp].name<<endl;cin>>name;
   strcpy(stud[temp].name,name);
   cout<<"��������������       �������µ�ѧ��������:"<<"ԭ����Ϊ��"<<stud[temp].age<<endl;cin>>age;
   stud[temp].age=age;
   cout<<"��������������       �������µ�ѧ�����Ա�:"<<"ԭ�Ա�Ϊ��"<<stud[temp].sex<<endl;cin>>sex;
   strcpy(stud[temp].sex,sex);
   cout<<"��������������       �������µ�ѧ�������ķ���"<<"ԭ�ɼ�Ϊ��"<<stud[temp].Chinese<<endl;cin>>chi;
   stud[temp].Chinese=chi;
   cout<<"��������������       �������µ�ѧ���ĸ�������"<<"ԭ�ɼ�Ϊ��"<<stud[temp].Math<<endl;cin>>mat;
   stud[temp].Java=mat;
   cout<<"��������������       �������µ�ѧ����Ӣ�����"<<"ԭ�ɼ�Ϊ��"<<stud[temp].English<<endl;cin>>eng;
   stud[temp].English=eng;
   cout<<"��������������       �������µ�ѧ����JAVA����"<<"ԭ�ɼ�Ϊ��"<<stud[temp].Java<<endl;cin>>Ja;
   stud[temp].Java=Ja;
   iofile.write((char *)&stud[temp],sizeof(stud[temp]));
   cout<<"��������������       �Ѿ��ɹ��޸� "<<endl;
   }
}
}

