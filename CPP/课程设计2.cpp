/*ѧ��ͨѶ¼ϵͳ*/
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
//����ѧ�����ݽṹ��


void mainscreen(student *p);
void title();
void Login(student *head);


void UserReg(student *head)
{
system("cls");
FILE *fp;                                  //�����ļ�ָ��
char Linedata[50]={0},User[20],Pass[20];  //�����ֱ��� һ������  �û���  ����
fp = fopen("data.dat","at");              //��data.txt ׷��д����
cout<<"******��ӭ�������˺�ע�����˺�ע��:******"<<endl;
cout<<"�������û���:";
fflush(stdin);                             //��ջ�����
gets(User);                                 //��������û���
cout<<"����������:";
fflush(stdin);                              //��ջ�����
gets(Pass);                                 //�����������
strcpy(Linedata,User);                      //����ȡ���� �û��� �����ʽת��Ϊ data.txt�еĸ�ʽ
strcat(Linedata,",");
strcat(Linedata,Pass);
strcat(Linedata,"\n");
fputs(Linedata,fp);                         //����һ�и�ʽ�����õ��û��� ������Ϣд��data.txt�ļ�
fclose(fp);                                 //�ر�data.txt�ļ�ָ��
cout<<"ע��ɹ�!"<<endl;
system("pause");
system("cls");
title();
cout<<"�ȴ�ת���½���桭����������"<<endl;
Login(head);
 }
void Login(student *head)
{


FILE *fp;                                   //�����ļ�ָ��
int find=0;
char User[20],Pass[20],Userstrcat[50]={0}; //�û��� ���� װ�û���Ϣ������ �����洢��ʽ��������û�������
char c,Userdata[50]={0};                     //�����洢��data.txt�ж�ȡ���û���Ϣ
fp = fopen("data.dat","r");                //��data.txt�ļ�
cout<<"�û���¼:"<<endl;
cout<<"�������û���:";
fflush(stdin);                                 //��ջ�����
gets(User);                                    //��������û���
cout<<"����������:";
fflush(stdin);                                  //��ջ�����
gets(Pass);                                    //�����������
strcpy(Userstrcat,User);                      //����ȡ���� �û��� ���뿽����Userstrcat ��ʽת��Ϊ data.txt�еĸ�ʽ
strcat(Userstrcat,",");
strcat(Userstrcat,Pass);
strcat(Userstrcat,"\n");
 while (!feof(fp))                             //ѭ�����ж�ȡdata.txt  ����ȡ������Ϣ����������Userdata �� ֱ���ļ�����
 {
fgets(Userdata,19,fp);
if (strcmp(Userdata,Userstrcat)==0 )   //�Ա� ��ȡ����Userdata �� ���մ������ʽ��Userstrcat  �����ͬ
  {
 cout<<"OK!��¼�ɹ�!"<<endl;      //�����ӭ��½��Ϣ
      find=1;                             //����ҵ�����û���Ϣ
      mainscreen(head);                            //�������ٶ��ļ�
  }
 }
 fclose(fp);                                         //�ر��ļ�ָ��
 if (!find)                                          //���ѭ������ ��δ�ҵ��û���Ϣ
 {
cout<<"�û��������ڻ��������"<<endl;
cout<<"��ѡ�����µ�½(������1������ע�����˺ţ�������2����";
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


void read(student *head)         //�ļ����ݶ�ȡ����
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
cout<<"��ǰͨѶ¼δ��ʼ�����������׶����������";
cin>>p->name;
cout<<"���������ļ�ͥסַ:";
cin>>p->address;
cout<<"�����������ֻ����룺";
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
cout<<"����������������";
cin>>p->name;
cout<<"���������ļ�ͥסַ:";
cin>>p->address;
cout<<"�����������ֻ����룺";
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
cout<<"������Ҫע����Ϣ��ѧ������:";
cin>>de_stu;
student *q,*front;
front=(struct student *)malloc(sizeof(student));
q=head->next;
while(q!=NULL)
{
if(strcmp(q->name,de_stu)==0)
{
cout<<"���ҵ���Ҫע����ѧ����Ϣ������ע���С�������"<<endl;
q=front->next;
front->next=q->next;
cout<<"��������ע���ɹ���������ҳ�桭������"<<endl;
flag=0;
break;
}
q=q->next;
}
if(flag==1)
cout<<"���ҵ�ѧ����Ϣ������"<<endl;
mainscreen(head);
}
void change_student(student *head)
{
system("cls");
title();
int flag=1;
student *q;
char name_stu[20];
cout<<"��������Ҫ�޸���Ϣ��ѧ��������";
cin>>name_stu;
q=head->next;
while(q!=NULL)
{
if(strcmp(q->name,name_stu)==0)
{
cout<<"�뿪ʼ������Ϣ���޸ģ�"<<endl;
cout<<"������";
cin>>q->name;
cout<<"��ͥסַ��";
cin>>q->address;
cout<<"�绰���룺";
cin>>q->phonenum;
cout<<"������Ϣ�޸���ɣ�"<<endl;
flag=0;
break;
}
q=q->next;
}
if(flag==1)
cout<<"���ҵ�ѧ����Ϣ������"<<endl;
mainscreen(head);
}
void loca_student(student *head)
{
system("cls");
title();
int flag=1;
char location[20];
cout<<"��������Ҫ���ҵĵ������ƣ�";
cin>>location;
student *q;
q=head->next;
while(q!=NULL)
{
if(strcmp(q->address,location)==0)
{
cout<<"������"<<q->name<<endl;
cout<<"��ͥסַ��"<<q->address<<endl;
cout<<"�绰���룺"<<q->phonenum<<endl<<endl;
flag=0;
}
q=q->next;
}
if(flag==1)
cout<<"û�иõ�����ѧ����Ϣ"<<endl;
mainscreen(head);
}
void search_student(student *head)
{
system("cls");
title();
int flag=1;
char name_stu[20];
cout<<"��������Ҫ���ҵ�ѧ��������";
cin>>name_stu;
student *q;
q=head->next;
while(q!=NULL)
{
if(strcmp(q->name,name_stu)==0)
{
cout<<"������"<<"       ";
cout<<"��ͥסַ��"<<"       ";
cout<<"�绰���룺"<<"       "<<endl;
cout<<q->name<<"         ";
cout<<q->address<<"            ";
cout<<q->phonenum<<"        "<<endl;
flag=0;
break;
}
q=q->next;
}
if(flag==1)
cout<<"���ҵ�ѧ����Ϣ������"<<endl;
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
cout<<"������"<<"       ";
cout<<"��ͥסַ��"<<"       ";
cout<<"�绰���룺"<<"       "<<endl;
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
cout<<a<<"�밴��Ҫ��ѡ��Ҫ���еĲ�����"<<endl;
cout<<a<<"������Ϣ���������ʾѡ����Ӧ�Ĳ���:"<<endl<<endl;
for(int i=0;i<68;i++)
cout<<a;
cout<<endl;
cout<<" "<<a<<"  �����µ�����ͨѶ¼****************************************  1  "<<a<<endl;
cout<<" "<<a<<"  ��������������Ӧ��������Ϣ********************************  2  "<<a<<endl;
cout<<" "<<a<<"  ��������ɾ����Ӧ��������Ϣ********************************  3  "<<a<<endl;
cout<<" "<<a<<"  ���������޸���Ӧ��������Ϣ********************************  4  "<<a<<endl;
cout<<" "<<a<<"  �˳�ͨѶ¼��¼ϵͳ****************************************  5  "<<a<<endl;
cout<<" "<<a<<"  ��ʾ��ǰ���ݿ������е�ͨѶ¼��Ϣ**************************  6  "<<a<<endl;
cout<<" "<<a<<"  ���Ҿ�ס��ͬһ������������ѧ������Ϣ**********************  7  "<<a<<endl;
for(int i=0;i<68;i++)
cout<<a;
cout<<endl;
cout<<"���������ѡ��";
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
cout<<a<<"��ӭ����ѧ��ͨѶ¼����ϵͳ�����¼����û��������룺"<<endl;
int selectNum;
cout<<"\n��ѡ���¼�ķ�ʽ"<<endl;    //���һ��ѡ��˵�
cout<<"1 ע�����˻�"<<endl;
cout<<"2 ���е��˻���¼"<<endl;
cout<<"3 �˳�ͨѶ¼����ϵͳ"<<endl;
cin>>selectNum;        //���������ѡ������
switch (selectNum)         //���������ѡ�������ú���
 {
 case 1:UserReg(head);          //����ע�ắ��
break;
 case 2:Login(head);           //���õ�¼����
break;
 case 3:system("cls");exit(0); //�����˳�����
break;
 }
return 0;
}
