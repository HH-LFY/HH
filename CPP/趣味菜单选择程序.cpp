#include <iostream>
#include <cstdio>
#include <cmath>
#include <windows.h>
#include <conio.h>
using namespace std;

#define qj printf("ϵͳ����Ϊ�����");for(int i = 1;i < 5; i++){printf("."),Sleep(500);}cout<<endl;
#define jz printf("������������");for(int i = 1;i < 5; i++){printf("."),Sleep(500);}cout<<endl;system("cls");
#define cz printf("ϵͳ����Ϊ�������Ȧ˳��");for( i = 1;i < 5; i++){printf("."),Sleep(500);}cout<<endl;system("cls");

int menu_select()
 {
      char s[2];
      int cn;
      system("color 01");
      cout<<endl<<endl<<endl<<endl;
      cout<<"  =========================================================================="<<endl;
      cout<<"  ==                     1.��һԪ���η���                                 =="<<endl;
      cout<<"  ==                     2.��Ȧ��Ϸ                                       =="<<endl;
      cout<<"  ==                     3.�˳�����                                       =="<<endl;
      cout<<"  =========================================================================="<<endl;
   for(; ;)
   {
       cout<<"������1-3��"<<endl;
        gets(s);
       cn=atoi(s); // ��Ϊ��ʹ������ַ���ת��Ϊ����
      if(cn<1||cn>3)
         printf("\n\t�������,��ѡ1-3:");
      else
           break;
   }
    return cn;
 }

void FindIt()
{
    system("cls");
    double a,b,c;
    system("color 02");
    cout<<"��������һ���� a*x^2 + b*x + c = 0 �Ľ�ĳ���"<<endl;
    cout<<"������ϵ��a��";
    cin>>a;
    cout<<"������ϵ��b��";
    cin>>b;
    cout<<"������ϵ��c��";
    cin>>c;
    system("cls");
    printf("������ķ���Ϊ %.0lf*x^2 + %.0lf*x + %.0lf = c\n",a,b,c);
    qj;
    double d=b*b-4*a*c;
    if(d < 0)
    {
        cout<<"�÷����޽⣡��ȷ���������ϵ���Ƿ���ȷ��"<<endl;
    }
    else if(0==d)
    {
        double x=-b/(2*a);
        cout<<"�÷���ֻ��һ���⣬���Ϊ��"<<endl<<" X = "<<x<<endl;
    }
    else if(d > 0)
    {
        d=sqrt(d);
        double x1=( -b + d )/(2 * a);
        double x2=( -b - d )/(2 * a);
        cout<<"�÷���ֻ�������⣬���Ϊ��"<<endl;
        cout<<"X1 = "<<x1<<endl;
        cout<<"X2 = "<<x2<<endl;
    }
    system("pause");
    system("cls");
    getchar();
}

void game()
{
    system("cls");
    system("color 03");
    cout<<"����������Ȧ��Ϸ������ (����-1�鿴����): ";
    int n,i,m,a[100];
    bool vis[100];
    cin>>n;
    if(n==-1)
    {
        cout<<"���� ��Ȧ��Ϸ�Ĺ����ǣ�����������Ϊn���˵�һ��С�飬��"<<endl;
        cout<<"�ǰ�˳ʱ�뷽����Χ��һȦ��һ��ʼ��ѡһ����������Ϊ����"<<endl;
        cout<<"����ֵm���ӵ�һ���˿�ʼ��˳ʱ�뷽����1��ʼ˳��������"<<endl;
        cout<<"��mʱֹͣ����������m���˳��У�Ȼ�����ԭ�����ڵ�,˳ʱ��"<<endl;
        cout<<"�뷽�����һ���˿�ʼ���´�1����������mʱֹͣ����������"<<endl;
        cout<<"�����ȥ��ֱ��������ȫ������Ϊֹ��Ҫ�����ǳ��е�˳��"<<endl;
        cout<<"������ǵ����֡�"<<endl;
        system("pause");
        system("cls");
        cout<<"����������Ȧ��Ϸ��������";
        cin>>n;
    }
    cout<<"�����뱨��������ֵm�� ";
    cin>>m;
    char str[100][20];
    for(i = 1;i <= n; i++)
    {
        vis[i] = 1;
        a[i] = i;
        printf("��%d���˵�����:",i);
        cin>>str[i];
        getchar( );
//       cout<<str[i]<<endl;
    }
    cz;
    int judge = 0;
    int km=0;
    i = 1;
    while(1)
    {
        if(judge==n) break;
        if(vis[i]==1&&km<m)
        {
            km++;
        }
        if(vis[i]==1&&km==m)
        {
            judge++;
            printf("��%d����Ȧ����Ϊ��%s\n",judge,str[i]);
            km=0;
            vis[i]=0;
        }
        if(i==n)i=1;
        else i++;
    }
    system("pause");
    system("cls");
}

int main( )
{
    jz;
  while(1)
  {
    switch(menu_select())//���ò˵�ѡ����
    {
    case 1:
       FindIt();//���һԪ���η���
        break;
    case 2:
       game();//��Ȧ��Ϸ
       break;
    case 3:
      cout<<"\t�ټ�!\n";
      return 0;
	}
  }
  return 0;
}
