


#include <iostream> 
#include <string.h>
#include <ctime>     //ʱ��ͷ�ļ�
#include <conio.h>   //�⺯�������������
using namespace std;
struct student //����ѧ����
{
int num; //ѧ��
char name[8]; //����
char classes[20]; //��� 
int math,english,computer,sum; //��ѧ��Ӣ��������ƽ���ܳɼ�
};
int s=0; //ȫ�ֱ���
class student1
{
private:
student stu[40]; //�ṹ�����
char name, classes;
int num;
int math,english,computer,sum;
public:
void input(int, char *, char *, int, int, int);
void output(int);
int check(int stu_num)
{
   int m=0;
   while(m<=s+1)
    if(stu_num==stu[m++].num)
    {
     return 1;
     break;
    }
    if(m>s+1)
     return 0;
    else 
     return 1;
}
void search(int);
void search1(int);
void deleted(int);
void deleted1(int);
void desc(int);
void desc1(int);
void desc2(int);
};
void student1::input(int stu_num,char *stu_name, char *stu_classes, 
					 int stu_math, int stu_english, int stu_computer) //����ģ��
{
stu[s].num=stu_num;
strcpy(stu[s].name, stu_name);
strcpy(stu[s].classes, stu_classes);
stu[s].math=stu_math;
stu[s].english=stu_english;
stu[s].computer=stu_computer;
}
void student1::output(int s) //���ģ��
{
cout << s << "\t";
cout << stu[s].num << "\t";
cout << stu[s].name << "\t";
cout << stu[s].classes << "\t";
cout << stu[s].math << "\t\t";
cout << stu[s].english << "\t\t";
cout << stu[s].computer << "\t\n";
}
void student1::search(int s) //����ģ��
{
int stu_num,p;
while (s==0)
{
   cout <<"û�м�¼,���������¼!" <<endl;
   break;
}
if (s!=0)
{
   cout << "��������Ҫ���ҵ�ѧ��:";
   cin >> stu_num;
   while (stu_num<100000 || stu_num>999999) //�ж�ѧ���Ƿ���ȷ
   {
    cin.clear();
    rewind(stdin);            //���ļ�ָ������ָ��һ�����Ŀ�ͷ
    cout << "�������ѧ�Ų���ȷ��������һ����λ����ѧ��" << endl;
    cin >> stu_num;
   }
   while (s!=0)            //�����Ƿ��з��������ļ�¼
   {
    p=1;
    if (stu_num==stu[s].num)
    {
     cout << "ѧ��\t����\t�༶\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t" << endl;
     cout << stu[s].num << "\t";
     cout << stu[s].name << "\t";
     cout << stu[s].classes << "\t";
     cout << stu[s].math << "\t\t";
     cout << stu[s].english << "\t\t";
     cout << stu[s].computer << "\t\n";
     getch(); 
     break;
    }
    else
     p=0;
    s--;
   }
   if (p==0)
    cout << "û���ҵ���Ҫ���ҵļ�¼!" << endl;
}
getch();
}
void student1::search1(int s) //����������ģ��
{
char stu_name[8],p;
while (s==0)
{
   cout <<"û�м�¼,���������¼!" <<endl;
   break;
}
if (s!=0)
{
   cout << "��������Ҫ���ҵ�����:";
   cin >> stu_name;
   while (s!=0) //�����Ƿ��з��������ļ�¼
   {
    p=1;
    if (strcmp(stu_name, stu[s].name)==0)
    {
     cout << "ѧ��\t����\t�༶\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t" << endl;
     cout << stu[s].num << "\t";
     cout << stu[s].name << "\t";
     cout << stu[s].classes << "\t";
     cout << stu[s].math << "\t\t";
     cout << stu[s].english << "\t\t";
     cout << stu[s].computer << "\t\n";
     getch();
     break;
    }
    else
     p=0;
    s--;
   }
   if (p==0)
    cout << "û���ҵ���Ҫ���ҵļ�¼!" << endl;
}
getch();
}
void student1::deleted(int n)    //ɾ��ģ��
{
int stu_num,p;
char yes;
while (s==0)
{
   cout << "û�м�¼�����������¼!" << endl;
   break;
}
if (s!=0)
{
   cout << "������Ҫɾ����ѧ��:";
   cin >> stu_num;
   while (stu_num<100000 || stu_num>999999)
   {
    cin.clear();
    rewind(stdin);
    cout << "�������ѧ�Ų���ȷ��������һ����λ����ѧ��" << endl;
    cout << "ѧ��:";
    cin >> stu_num;
   }
   for (int i=1;i<=n;i++)
   {
    if (stu[i].num!=stu_num)
     p=0;
    if (stu[i].num==stu_num)   
    {
     cout << "ѧ��\t����\t�༶\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t" <<endl;
     cout << stu[i].num << "\t";
     cout << stu[i].name << "\t";
     cout << stu[i].classes << "\t";
     cout << stu[i].math << "\t\t";
     cout << stu[i].english << "\t\t";
     cout << stu[i].computer << endl;
     cout << "��ȷ��Ҫɾ����ѧ����¼��?(y/n)";
     cin >> yes;
     if (yes == 'y' || yes == 'Y')
     {
      for (int j=1; j<=n-1; j++) //ɾ����¼
      {
       stu[j].num=stu[j+1].num;
       strcpy(stu[j].name, stu[j+1].name);
       strcpy(stu[j].classes, stu[j+1].classes);
       stu[j].math=stu[j+1].math;
       stu[j].english=stu[j+1].english;
       stu[j].computer=stu[j+1].computer;
      }
      cout << "ѧ����¼ɾ���ɹ�" <<endl;
      s=s-1;
      p=1;
      break;
     }
     else
     {
      cout << "ѧ����¼ɾ��ʧ��" << endl;
      p=1;
     }
    }
   }
   if (p==0) 
	   cout << "û���ҵ���Ҫ���ҵļ�¼!" <<endl;
}
getch();
   
}
void student1::deleted1(int n) //������ɾ��ģ��
{
char stu_name[8],p;
char yes;
while (s==0)
{
   cout << "û�м�¼�����������¼!" << endl;
   break;
}
if (s!=0)
{
   cout << "������Ҫɾ��������:";
   cin >> stu_name;
   for (int i=1;i<=n;i++)
   {
    if (strcmp(stu[i].name, stu_name)<0 || strcmp(stu[i].name, stu_name)>0)
     p=0;          //�����ַ���������������ַ����
    if (strcmp(stu[i].name, stu_name)==0)
    {
     cout << "ѧ��\t����\t�༶\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t" <<endl;
     cout << stu[i].num << "\t";
     cout << stu[i].name << "\t";
     cout << stu[i].classes << "\t";
     cout << stu[i].math << "\t\t";
     cout << stu[i].english << "\t\t";
     cout << stu[i].computer << endl;
     cout << "��ȷ��Ҫɾ����ѧ����¼��?(y/n)";
     cin >> yes;
     if (yes == 'y' || yes == 'Y')
     {
      for (int j=1; j<=n-1; j++) //ɾ����¼
      {
       stu[j].num=stu[j+1].num;
       strcpy(stu[j].name, stu[j+1].name);
       strcpy(stu[j].classes, stu[j+1].classes);
       stu[j].math=stu[j+1].math;
       stu[j].english=stu[j+1].english;
       stu[j].computer=stu[j+1].computer;
      }
      cout << "ѧ����¼ɾ���ɹ�" <<endl;
      s=s-1;
      p=1;
      break;
     }
     else
     {
      cout << "ѧ����¼ɾ��ʧ��" << endl;
      p=1;
     }
    }
   }
   if (p==0)
    cout << "û���ҵ���Ҫ���ҵļ�¼!" <<endl;
}
getch();
}
void student1::desc1(int s) //��ѧ������
{
int temp;
int sum[40];
while (s==0)
{
   cout << "û�м�¼,���������¼!" <<endl;
   break;
}
if (s!=0)
{
   cout << "ѧ��\t����\t�༶\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t" <<endl;
   for (int k=1;k<=s;k++)
    sum[k]=stu[k].num;
   for (int i=1;i<=s;i++) //����ð�ݷ���sum[]��������
    for (int j=1;j<=s-i;j++)
     if (sum[j]>sum[j+1])
     {
      temp=sum[j];
      sum[j]=sum[j+1];
      sum[j+1]=temp;
     }
     for (int x=1;x<=s;x++) //�����sum[]����ͬ�ܷ�����Ӧ������
      for (int y=1;y<=s;y++)
       if (sum[x]==stu[y].num)
       {
        cout << stu[y].num << "\t";
        cout << stu[y].name << "\t";
        cout << stu[y].classes << "\t";
        cout << stu[y].math << "\t\t";
        cout << stu[y].english << "\t\t";
        cout << stu[y].computer << "\t\t";
        cout << endl;
       }
}
getch();
}
void student1::desc2(int s) //����������
{
char sum[40][8];
char temp[8];
while (s==0)
{
   cout << "û�м�¼,���������¼!" <<endl;
   break;
}
if (s!=0)
{
   cout << "ѧ��\t����\t�༶\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t" <<endl;
   for (int k=1;k<=s;k++)
    strcpy(sum[k], stu[k].name);
   for (int i=1;i<=s;i++)             //����ð�ݷ���sum[]��������
    for (int j=1;j<=s-i;j++)
     if (strcmp(sum[j], sum[j+1])>0)
     {
      strcpy(temp, sum[j]);
      strcpy(sum[j], sum[j+1]);
      strcpy(sum[j+1], temp);
     }
     for (int x=1;x<=s;x++)          //�����sum[]����ͬ�ܷ�����Ӧ������
      for (int y=1;y<=s;y++)
       if (strcmp(sum[x], stu[y].name)==0)
       {
        cout << stu[y].num << "\t";
        cout << stu[y].name << "\t";
        cout << stu[y].classes << "\t";
        cout << stu[y].math << "\t\t";
        cout << stu[y].english << "\t\t";
        cout << stu[y].computer << "\t\t";
        cout << endl;
       }
}
getch();
}
void student1::desc(int s) //ƽ���ɼ�����ģ��
{
int temp;
int sum[40];
while (s==0)
{
   cout << "û�м�¼,���������¼!" <<endl;
   break;
}
if (s!=0)
{
   cout << "ѧ��\t����\t�༶\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\tƽ���ɼ�" <<endl;
   for (int k=1;k<=s;k++)
   {
    sum[k]=(stu[k].math+stu[k].english+stu[k].computer)/3; //ƽ���ɼ�
    stu[k].sum=(stu[k].math+stu[k].english+stu[k].computer)/3;
   }
   for (int i=1;i<=s;i++) //����ð�ݷ���sum[]��������
    for (int j=1;j<=s-i;j++)
     if (sum[j]<sum[j+1])
     {
      temp=sum[j];
      sum[j]=sum[j+1];
      sum[j+1]=temp;
     }
     for (int x=1;x<=s;x++) //�����sum[]����ͬ�ܷ�����Ӧ������
      for (int y=1;y<=s;y++)
       if (sum[x]==stu[y].sum)
       {
        cout << stu[y].num << "\t";
        cout << stu[y].name << "\t";
        cout << stu[y].classes << "\t";
        cout << stu[y].math << "\t\t";
        cout << stu[y].english << "\t\t";
        cout << stu[y].computer << "\t\t";
        cout << stu[y].sum << endl;
       }
}
getch();
}
int main(int argc, char *argv[])   //������
{
student1 st;
char yes,choice;
char *name,*classes;
int math, english, computer, num;
time_t t;
time(&t);
while (1)
{
   system("cls");
   cout<< "\t--------------------------ѧ���ɼ�����ϵͳ--------------------------"<<endl;
   cout<< "\t\t\tʱ��:" << ctime(&t);
   cout<<"--------------------------------------------------------------------------------\n" 
    <<"                           1.����ѧ���ɼ���¼\n" 
    <<"                           2.��ʾѧ���ɼ���¼\n" 
    <<"                           3.��ѯѧ���ɼ���¼--��ѧ��\n" 
    <<"                           4.��ѯѧ���ɼ���¼--������\n" 
    <<"                           5.ɾ��ѧ���ɼ���¼--��ѧ��\n" 
    <<"                           6.ɾ��ѧ���ɼ���¼--������\n" 
    <<"                           7.����ѧ���ɼ���¼--��ѧ��\n" 
    <<"                           8.����ѧ���ɼ���¼--������\n" 
    <<"                           9.����ѧ���ɼ���¼--��ƽ���ɼ�\n" 
    <<"                           0.�˳�ѧ���ɼ�����ϵͳ\n"
    <<"--------------------------------------------------------------------------------\n"; 
    cout<<"��ʾ����0-6����ѡ����Ҫ�ķ���";
   cin >> choice;
t:
   if (choice=='0')
    break;
   switch(choice)
   {
   case '1':
    {
last:
    cout << "����������ѧ����ѧ��,����,�༶,��ѧ�ɼ�,Ӣ��ɼ�,������ɼ�--ѧ��Ϊ6λ����"<<endl;
    name = new char[];
    classes =new char[];
    cin >> num >> name >> classes >> math >> english >> computer;
    while (num<10000 || num>999999)
    {
     cin.clear();
     rewind(stdin);
     cout << "ѧ�ű���Ϊ6λ���֣�����������ѧ����Ϣ" << endl;
     cin >> num >> name >> classes >> math >> english >> computer;
    }
    while (st.check(num)) //����CHECKģ���ж�ѧ���Ƿ��ظ�
    {
     cin.clear();
     cout << "ѧ���ظ�,��������!" << endl;
     cout << "ѧ��:";
     cin >> num;
    }
    s=s+1;
    st.input(num,name,classes,math,english,computer);
    cout << "�Ƿ�Ҫ��������?(y/n)";
    cin >> yes;
    while (yes == 'y' || yes == 'Y')
    {
     goto last;   //ָ����ת����ǩ���ҵ���ǩ�󣬳��򽫴������һ�п�ʼ������
    }
    getch();
    };
	break;
   case '2':
    {
     if (s==0) //�ж��Ƿ��м�¼����
     {
      cout << "û��ѧ����¼,���������¼!" << endl;
      getch();
      break;
     }
     if (s!=0)
     {
      cout << "���" << "\t";
      cout << "ѧ��" << "\t";
      cout << "����" << "\t";
      cout << "�༶" << "\t";
      cout << "��ѧ�ɼ�" << "\t";
      cout << "Ӣ��ɼ�" << "\t";
      cout << "������ɼ�" << "\t";
      for (int i=1;i<=s;i++)
       st.output(i);
      getch();
     }
    };break;
   case '3':st.search(s);break;
   case '4':st.search1(s);break;
   case '5':st.deleted(s);break;
   case '6':st.deleted1(s);break;
   case '7':st.desc1(s);break;
     case '8':st.desc2(s);break;
   case '9':st.desc(s);break;
   default:
    {
     while (choice=='0'||choice>'6')
     {
      cout << "����ѡ��, ������ѡ��!" << endl;
      cin >> choice;
     }
     goto t;
    }break;
   }
}
cout << "лл����ʹ��!" << endl;
cout<<"  ������ͨ��ѧ"<<endl;
return 0;
}
