#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;
#define m 200
#define l 1000
#define ESC 27
#define ENTER 10
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
int N=0;
void time()
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	printf("                             %4d��%3d��%3d��   %3dʱ%3d��\n",s.wYear,s.wMonth,s.wDay,s.wHour,s.wMinute);
}

class ticket
{
public:
	ticket();
	void change();
	void set();
	void book();
	void display();
	void search();
	void unbook();
	void add();
	int time1();
	void delect();
	char num[l];
	int uncount,counts;
	double sumtime;
	string endtime,start,origin,destination;
	string amongcity1,amongcity2;
};
ticket::ticket(){};
void jinglu()
{
	char a[m];
    long int id;
    cout<<"������������������֤����"<<endl;
	cout<<"����  ";
	cin>>a;
	cout <<"���֤����   ";
	cin>>id;
	cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
	Sleep(2000);
}
int ticket:: time1()
{
	char str1[10],str2[10];
	int k1=0,k2=0;
	int judge=0;
	int k = start.length();
   for(int i=0;i<=k-1;i++ )
   {
	   if(judge==0&&start[i]>='0'&&start[i]<='9')
	   {
		   str1[k1]=start[i];
		   k1++;
	   }
	   if(start[i]==':')
		   judge++;
	   if(judge==1&&start[i]>='0'&&start[i]<='9')
	   {
		   str2[k2]=start[i];
		   k2++;
	   }
   }
   int t1=atoi(str1);
   int t2=atoi(str2);
   int t=60*t1+t2;
   return t;
}
void ticket::change()
{
	char num1[l];
	int uncount1,counts1;
	double sumtime1;
	string endtime1,start1,origin1,destination1;
	string amongcity11,amongcity21;
	    cout<<"�������»𳵳��� ";
	    cin>>num1;
		strcpy(num,num1);
	    cout<<"����������ʼվ ";
        cin>>origin1;
		origin=origin1;
	    cout<<"���������յ�վ ";
	    cin>>destination1;
		destination=destination1;
	    cout<<"����������ʼʱ�� ";
	    cin>>start1;
		start=start1;
	    cout<<"�������½���ʱ�� ";
	    cin>>endtime1;
		endtime=endtime1;
	    cout<<"���������г�ʱ�� ";
	    cin>>sumtime1;
		sumtime=sumtime1;
 	    cout<<"����������Ʊ�� ";
	    cin>>counts1;
		counts=counts1;
        cout<<"��������ʣ��Ʊ�� ";
	    cin>>uncount1;
		uncount=uncount1;
		cout<<"��������;������1 ";
		cin>>amongcity11;
		amongcity1=amongcity11;
        cout<<"��������;������2";
		cin>>amongcity21;
        amongcity2=amongcity21;
        cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		  Sleep(2000);
		cout<<"�޸ĳɹ�"<<endl;
}
void ticket::set()
{
	    cout<<"������𳵳��� ";
	    cin>>num;
	    cout<<"��������ʼվ ";
        cin>>origin;
        cout<<"�������յ�վ ";
	    cin>>destination;
       cout<<"��������ʼʱ�� ";
	    cin>>start;
	    cout<<"���������ʱ�� ";
	    cin>>endtime;
	    cout<<"�������г�ʱ�� ";
	    cin>>sumtime;
 	    cout<<"��������Ʊ�� ";
	    cin>>counts;
	    cout<<"������ʣ��Ʊ�� ";
	    cin>>uncount;
		cout<<"������;������1 ";
		cin>>amongcity1;
		cout<<"������;������2 ";
		cin>>amongcity2;
	    N++;
	    cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		  Sleep(2000);
        cout <<endl;
        cout<<"*����ɹ�*"<<endl<<endl;
}

void ticket:: book()
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	int g;
	if((s.wHour*60+s.wMinute)<time1())
	{
      if(uncount>0)
	  {cout<<"����������Ҫ����     ";
		cin>>g;
		uncount=uncount-g;
		cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		  Sleep(2000);
	  cout<<"*��Ʊ�ɹ�*"<<endl;}
	else{cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		    Sleep(2000);
           cout<<"*�Բ����Ѿ�û��������Ҫ��Ʊ��*"<<endl;}
	}
	else {cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		  Sleep(2000);
            cout<<"*�Բ���ó��ѷ� ���ܶ�Ʊ������*"<<endl;}
}
void ticket:: unbook()
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	int z;
	if((s.wHour*60+s.wMinute)<time1())
	{
		if(uncount==counts)
		{
		    //cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		  //Sleep(2000);
			cout<<"*����ȷ�����Ƿ��������л𳵵�Ʊ*"<<endl;
		}
		else{//cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		      //Sleep(2000);
			  cout<<"��Ҫ�˼���    ";
			  cin>>z;
			  if(uncount+z>counts)
				  { cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		            Sleep(2000);
		            cout<<"*����ȷ������Ҫ�˵�Ʊ��*"<<endl;}
			  else{ cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		            Sleep(2000);
		            uncount=uncount+z;
			        cout<<"*��Ʊ�ɹ�*"<<endl;}
		}
	}
	else{cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		  Sleep(2000);
		cout<<"*�Բ��𱾴γ��ѷ��޷���Ʊ*"<<endl;
	}
}
void ticket::search()
{
   	SYSTEMTIME s;
	GetLocalTime(&s);
	int x=0;
	if((s.wHour*60+s.wMinute)>time1())
		x=1;
	cout<<"-------------------------------����Ҫ��ѯ���г�����Ϣ����----------------------"<<endl;
	cout<<"����  ��ʼվ  �յ�վ  ��ʼʱ��  ����ʱ��  �г�ʱ��  ��Ʊ��  ʣ��Ʊ��  ��ǰ״̬ "<<endl;
	     cout<<num;
		 cout<<setw(8)<<origin;
		 cout<<setw(7)<<destination;
		 cout<<setw(9)<<start;
		 cout<<setw(11)<<endtime;
		 printf("     %.2fСʱ",sumtime);
		 cout<<setw(5)<<counts<<"��";
		 cout<<setw(5)<<uncount<<"��";
		 if(x==0) cout<<"       δ����"<<endl;
		 else cout<<"      �ѷ���"<<endl;
   cout<<"      ;���ĳ���1          ;���ĳ���2       "<<endl;
   cout<<setw(12)<<amongcity1;
   cout<<setw(20)<<amongcity2<<endl;;
}
void ticket::delect()
{
     strcpy(num,"0");
     cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......";
		  Sleep(2000);
		  cout<<endl;
	 cout<<"ɾ���ɹ�"<<endl;
}


void ticket::display()
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	int i,x=0;
	if((s.wHour*60+s.wMinute)>time1())
		x=1;
		 cout<<num;
		 cout<<setw(8)<<origin;
		 cout<<setw(7)<<destination;
		 cout<<setw(9)<<start;
		 cout<<setw(11)<<endtime;
		 printf("     %.2fСʱ",sumtime);
		 cout<<setw(5)<<counts<<"��";
		 cout<<setw(5)<<uncount<<"��";
		 if(x==0) cout<<"       δ����"<<endl;
		 else cout<<"      �ѷ���  "<<endl;

}
void show1()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"  **************************************************************************"<<endl;
    cout<<"  **************��ϵͳֻ�ܶԵ��쳵�ν��в����������½�!!!!!*****************"<<endl;
	cout<<"  *******************��ϵͳ���в����Գ���Ϊ����*****************************"<<endl;
	cout<<"  **********************���ڻ�ӭ���뱾ϵͳ**********************************"<<endl;
	cout<<"  **************************************************************************"<<endl;
}
void show()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN);
    cout<<endl<<endl<<endl<<endl<<endl;
         cout<<"��������������������������������������������������������������������������������";
		 cout<<"��****************   ��     �� �� Ʊ �� �� ϵ ͳ      ��   ****************** ��";
         cout<<"��********** ������        ��������         ������  *********** ��";
         cout<<"�ǩ��������������������       1����ѯ����ϸ��Ϣ        ��贈����������������";
         cout<<"�ǩ��������������������       2����Ʊ����              ��贈����������������";
		 cout<<"�ǩ��������������������       3����Ʊ��Ʊ              ��贈����������������";
		 cout<<"�ǩ��������������������       4����ʾ�г���Ϣ            ��贈����������������";
		 cout<<"�ǩ��������������������       5�����г���Ϣ����          ��贈����������������";
		 cout<<"�ǩ��������������������       6����ESC�ظ�ѡ����         ��贈����������������";
		 cout<<"��������������������������������������������������������������������������������";
         cout<<" ******************�����ˡ��������������������︶����***************************"<<endl;
		 time();
}
void show3()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE| FOREGROUND_GREEN);
    cout<<endl<<endl<<endl<<endl<<endl;
	      cout<< "------------------------------------------------------------------------------"<<endl;
          cout<<"------------------------------1.���1���������ӹ���----------------------------"<<endl;
          cout<<"------------------------------2.���2������ɾ������----------------------------"<<endl;
		  cout<<"------------------------------3.���3�������޸Ĺ���----------------------------"<<endl;
		  cout<<"-------------------------------------------------------------------------------"<<endl;
		  time();
}

int main()
{
	ticket tic[m];
	char num1[l],num2[l],num3[l],num4[l],num5[l];
	show1();
    Sleep(3000);
	system("cls");
	time();
	cout<<"------------------------------�����Ա�����г���Ϣ------------------------------ "<<endl;
    cout<<"����N��ʱ��ʾ�������"<<endl;
	int i;
	char CC;
   for(i=0; i<m; i++)
	{
	   cout<<"�Ƿ�Ҫ����г���Ϣ Y/N "<<endl;
	   cout<<"������ѡ��     "<<endl;
	   cin>>CC;
	    if(CC=='n')break;
	    else tic[i].set();
	}
	system("cls");
	show();
	while(1)
	{
	  char h;
	h= getch();
	if(h==ESC)
	{
		system("cls");
		show();continue;}
switch(h)
	{
	case '1':
	    system("cls");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
          cout<<"-----------------------------------��ӭ�����ѯ����-----------------------------"<<endl;
		  cout<<"                      ��ӭ�����ѯϵͳ����Ը���ǵķ�������������                "<<endl;
		  cout<<endl<<endl;
		  cout<<"                               ����������Ҫ��ѯ�ĳ��κ�                         "<<endl;
		  cout<<endl<<endl;
		  cout<<"�����룺";
		  cin>>num1;
		  cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
		  Sleep(2000);
		  system("cls");
		  cout<<endl<<endl<<endl<<endl<<endl<<endl;
		  for(i=0;i<N;i++)
		  {
			  if(strcmp(tic[i].num,num1)==0&&strcmp(tic[i].num,"0")!=0)
			  tic[i].search();
			  //else
                //cout<<"*�Բ����г�������*"<<endl;
		  }break;
	case '2':
	    system("cls");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_BLUE);
		  cout<<"------------------------------------��ӭ���붩Ʊ����---------------------------"<<endl;
		  cout<<"                       ��ӭ���붩Ʊϵͳ����Ը���ǵķ�������������              "<<endl;
		  jinglu();
		  cout <<endl;
		  cout<<"                           ����������ҪԤ���г��ĳ��κ�                        "<<endl;
		  cout<<endl<<endl;
	      cout<<"�����룺";
		  cin>>num2;
		  cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
		  Sleep(2000);
		  cout<<endl<<endl;
		  for(i=0;i<N;i++)
		  {
			  if(strcmp(tic[i].num,num2)==0&&strcmp(tic[i].num,"0")!=0)
			      tic[i].book();
			  else
               cout<<"*�Բ����г�������*"<<endl;
		  }
		  break;
    case '3':
        system("cls");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
		  cout<<"---------------------------------��ӭ������Ʊ����-----------------------------"<<endl;
		  cout<<"                         ��ӭ������Ʊϵͳ����Ը���ǵķ�������������           "<<endl;
		  jinglu();
		  cout<<endl;
		  cout<<"                               ����������Ҫ�˹��ĳ��κ�                       "<<endl;
		  cout<<"�����룺";
		  cin>>num3;
		  cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
		  Sleep(2000);
		  for(i=0;i<N;i++)
		  {
			  if(strcmp(tic[i].num,num3)==0&&strcmp(tic[i].num,"0")!=0)
			  tic[i].unbook();
			  else
              cout<<"*�Բ����г�������*"<<endl;

		  }break;
	case '4':
	    system("cls");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN| FOREGROUND_BLUE);
		  cout<<"--------------------------��ӭ�����ѯ�������г���״̬����-------------------"<<endl;
		  cout<<endl<<endl;
		  cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
		  Sleep(2000);
		  cout<<"����  ��ʼվ  �յ�վ  ��ʼʱ��  ����ʱ��  �г�ʱ��  ��Ʊ��  ʣ��Ʊ��  ��ǰ״̬ "<<endl;
		for(i=0;i<N;i++)
        {
            if(strcmp(tic[i].num,"0")!=0)
           {tic[i].display();}
               }break;

    case '5':
        system("cls");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_BLUE| FOREGROUND_GREEN);
		  cout<<"------------------------------��ӭ���복����Ϣ��������-------------------------"<<endl;
		  cout<<"                                 ��ѡ����Ҫ�����ķ�ʽ                       "<<endl;
		  show3();
		  cout<<"��������ѡ��Ĳ���     "<<endl<<endl;
		  while(1)
		  {
		      //system("cls");show3();
		      cout<<"ESC���������˵�---0������ѡ�����      ";
		      //cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
		      //Sleep(2000);
		      //system("cls");
		      //show3();
		    char c;
	        c= getch();
	        if(c==ESC){system("cls");break ;}
            if(c=='0'){ system("cls");show3();continue;}
		  switch(c)
		  {
		  case '1':
		      cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
		      Sleep(2000);
		      system("cls");
			  cout<<"�������г���Ϣ����n��ʱ��ʾ�������"<<endl;
	          int c;
	          char s;
              for(c=N; c<m; c++)
			  {
			      cout<<"�Ƿ�Ҫ����г���Ϣ Y/N "<<endl;
	              cout<<"������ѡ��     "<<endl;
		        cin>>s;
	        	if(s=='n')
	        	 {cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
                //system("cls");
                break;}
	        	else tic[c].set();
			  }break;
		  case '2':
		      cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
		      Sleep(2000);
		      system("cls");
			  cout<<"��������Ҫɾ�����г�����"<<endl;
			  cin>>num4;
			  cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
			  Sleep(2000);
                //system("cls");
			  for(i=0;i<N;i++)
			  {
				  if(strcmp(tic[i].num,num4)==0&&strcmp(tic[i].num,"0")!=0)
			      tic[i].delect();
				  else
                cout<<"*�Բ����г�������*"<<endl;
			  }break;
		  case '3':
		      cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
		      Sleep(2000);
		      system("cls");
			  cout<<"��������Ҫ�޸ĵ��г�����"<<endl;
			  cin>>num5;
			  cout<<endl<<"ϵͳ����Ϊ�㴦�����Ժ�......"<<endl;
			  Sleep(2000);
                //system("cls");
			  for(i=0;i<N;i++)
			  {
				  if(strcmp(tic[i].num,num5)==0&&strcmp(tic[i].num,"0")!=0)
					  tic[i].change();
				 // else{cout<<"*�Բ����г�������*"<<endl;}
			  }break;
		  }
		  }
	}

}
return 0;
}
