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
	printf("                             %4d年%3d月%3d日   %3d时%3d分\n",s.wYear,s.wMonth,s.wDay,s.wHour,s.wMinute);
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
    cout<<"请输入你的姓名和身份证号码"<<endl;
	cout<<"姓名  ";
	cin>>a;
	cout <<"身份证号码   ";
	cin>>id;
	cout<<endl<<"系统正在为你处理请稍后......";
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
	    cout<<"请输入新火车车次 ";
	    cin>>num1;
		strcpy(num,num1);
	    cout<<"请输入新起始站 ";
        cin>>origin1;
		origin=origin1;
	    cout<<"请输入新终点站 ";
	    cin>>destination1;
		destination=destination1;
	    cout<<"请输入新起始时间 ";
	    cin>>start1;
		start=start1;
	    cout<<"请输入新结束时间 ";
	    cin>>endtime1;
		endtime=endtime1;
	    cout<<"请输入新行车时间 ";
	    cin>>sumtime1;
		sumtime=sumtime1;
 	    cout<<"请输入新总票数 ";
	    cin>>counts1;
		counts=counts1;
        cout<<"请输入新剩余票数 ";
	    cin>>uncount1;
		uncount=uncount1;
		cout<<"请输入新途径城市1 ";
		cin>>amongcity11;
		amongcity1=amongcity11;
        cout<<"请输入新途径城市2";
		cin>>amongcity21;
        amongcity2=amongcity21;
        cout<<endl<<"系统正在为你处理请稍后......";
		  Sleep(2000);
		cout<<"修改成功"<<endl;
}
void ticket::set()
{
	    cout<<"请输入火车车次 ";
	    cin>>num;
	    cout<<"请输入起始站 ";
        cin>>origin;
        cout<<"请输入终点站 ";
	    cin>>destination;
       cout<<"请输入起始时间 ";
	    cin>>start;
	    cout<<"请输入结束时间 ";
	    cin>>endtime;
	    cout<<"请输入行车时间 ";
	    cin>>sumtime;
 	    cout<<"请输入总票数 ";
	    cin>>counts;
	    cout<<"请输入剩余票数 ";
	    cin>>uncount;
		cout<<"请输入途径城市1 ";
		cin>>amongcity1;
		cout<<"请输入途径城市2 ";
		cin>>amongcity2;
	    N++;
	    cout<<endl<<"系统正在为你处理请稍后......";
		  Sleep(2000);
        cout <<endl;
        cout<<"*读入成功*"<<endl<<endl;
}

void ticket:: book()
{
	SYSTEMTIME s;
	GetLocalTime(&s);
	int g;
	if((s.wHour*60+s.wMinute)<time1())
	{
      if(uncount>0)
	  {cout<<"请输入你需要几张     ";
		cin>>g;
		uncount=uncount-g;
		cout<<endl<<"系统正在为你处理请稍后......";
		  Sleep(2000);
	  cout<<"*订票成功*"<<endl;}
	else{cout<<endl<<"系统正在为你处理请稍后......";
		    Sleep(2000);
           cout<<"*对不起已经没有你所需要的票了*"<<endl;}
	}
	else {cout<<endl<<"系统正在为你处理请稍后......";
		  Sleep(2000);
            cout<<"*对不起该车已发 不能订票！！！*"<<endl;}
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
		    //cout<<endl<<"系统正在为你处理请稍后......";
		  //Sleep(2000);
			cout<<"*请你确认你是否买了这列火车的票*"<<endl;
		}
		else{//cout<<endl<<"系统正在为你处理请稍后......";
		      //Sleep(2000);
			  cout<<"你要退几张    ";
			  cin>>z;
			  if(uncount+z>counts)
				  { cout<<endl<<"系统正在为你处理请稍后......";
		            Sleep(2000);
		            cout<<"*请正确输入需要退得票数*"<<endl;}
			  else{ cout<<endl<<"系统正在为你处理请稍后......";
		            Sleep(2000);
		            uncount=uncount+z;
			        cout<<"*退票成功*"<<endl;}
		}
	}
	else{cout<<endl<<"系统正在为你处理请稍后......";
		  Sleep(2000);
		cout<<"*对不起本次车已发无法退票*"<<endl;
	}
}
void ticket::search()
{
   	SYSTEMTIME s;
	GetLocalTime(&s);
	int x=0;
	if((s.wHour*60+s.wMinute)>time1())
		x=1;
	cout<<"-------------------------------你所要查询的列车的信息如下----------------------"<<endl;
	cout<<"车次  起始站  终点站  起始时间  结束时间  行程时间  总票数  剩余票数  当前状态 "<<endl;
	     cout<<num;
		 cout<<setw(8)<<origin;
		 cout<<setw(7)<<destination;
		 cout<<setw(9)<<start;
		 cout<<setw(11)<<endtime;
		 printf("     %.2f小时",sumtime);
		 cout<<setw(5)<<counts<<"张";
		 cout<<setw(5)<<uncount<<"张";
		 if(x==0) cout<<"       未发车"<<endl;
		 else cout<<"      已发车"<<endl;
   cout<<"      途径的城市1          途径的城市2       "<<endl;
   cout<<setw(12)<<amongcity1;
   cout<<setw(20)<<amongcity2<<endl;;
}
void ticket::delect()
{
     strcpy(num,"0");
     cout<<endl<<"系统正在为你处理请稍后......";
		  Sleep(2000);
		  cout<<endl;
	 cout<<"删除成功"<<endl;
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
		 printf("     %.2f小时",sumtime);
		 cout<<setw(5)<<counts<<"张";
		 cout<<setw(5)<<uncount<<"张";
		 if(x==0) cout<<"       未发车"<<endl;
		 else cout<<"      已发车  "<<endl;

}
void show1()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
    cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"  **************************************************************************"<<endl;
    cout<<"  **************本系统只能对当天车次进行操作，敬请谅解!!!!!*****************"<<endl;
	cout<<"  *******************本系统所有操作以车次为依据*****************************"<<endl;
	cout<<"  **********************现在欢迎进入本系统**********************************"<<endl;
	cout<<"  **************************************************************************"<<endl;
}
void show()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_GREEN);
    cout<<endl<<endl<<endl<<endl<<endl;
         cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓";
		 cout<<"┃****************   ☆     火 车 票 管 理 系 统      ☆   ****************** ┃";
         cout<<"┃********** ★★★★★        ★★★★★★★         ★★★★★  *********** ┃";
         cout<<"┣━━━━━━━━━★★       1、查询火车详细信息        ★★━━━━━━━━┫";
         cout<<"┣━━━━━━━━━★★       2、火车票订购              ★★━━━━━━━━┫";
		 cout<<"┣━━━━━━━━━★★       3、火车票退票              ★★━━━━━━━━┫";
		 cout<<"┣━━━━━━━━━★★       4、显示列车信息            ★★━━━━━━━━┫";
		 cout<<"┣━━━━━━━━━★★       5、对列车信息操作          ★★━━━━━━━━┫";
		 cout<<"┣━━━━━━━━━★★       6、按ESC重复选项栏         ★★━━━━━━━━┫";
		 cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛";
         cout<<" ******************制作人——————————★付红贤***************************"<<endl;
		 time();
}
void show3()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE| FOREGROUND_GREEN);
    cout<<endl<<endl<<endl<<endl<<endl;
	      cout<< "------------------------------------------------------------------------------"<<endl;
          cout<<"------------------------------1.点击1键进入增加功能----------------------------"<<endl;
          cout<<"------------------------------2.点击2键进入删除功能----------------------------"<<endl;
		  cout<<"------------------------------3.点击3键进入修改功能----------------------------"<<endl;
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
	cout<<"------------------------------请管理员输入列车信息------------------------------ "<<endl;
    cout<<"当按N键时表示输入完成"<<endl;
	int i;
	char CC;
   for(i=0; i<m; i++)
	{
	   cout<<"是否要添加列车信息 Y/N "<<endl;
	   cout<<"请输入选项     "<<endl;
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
          cout<<"-----------------------------------欢迎进入查询功能-----------------------------"<<endl;
		  cout<<"                      欢迎进入查询系统，但愿我们的服务能让你满意                "<<endl;
		  cout<<endl<<endl;
		  cout<<"                               请输入你需要查询的车次号                         "<<endl;
		  cout<<endl<<endl;
		  cout<<"请输入：";
		  cin>>num1;
		  cout<<endl<<"系统正在为你处理请稍后......"<<endl;
		  Sleep(2000);
		  system("cls");
		  cout<<endl<<endl<<endl<<endl<<endl<<endl;
		  for(i=0;i<N;i++)
		  {
			  if(strcmp(tic[i].num,num1)==0&&strcmp(tic[i].num,"0")!=0)
			  tic[i].search();
			  //else
                //cout<<"*对不起列车不存在*"<<endl;
		  }break;
	case '2':
	    system("cls");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_BLUE);
		  cout<<"------------------------------------欢迎进入订票功能---------------------------"<<endl;
		  cout<<"                       欢迎进入订票系统，但愿我们的服务能让你满意              "<<endl;
		  jinglu();
		  cout <<endl;
		  cout<<"                           请输入你需要预定列车的车次号                        "<<endl;
		  cout<<endl<<endl;
	      cout<<"请输入：";
		  cin>>num2;
		  cout<<endl<<"系统正在为你处理请稍后......"<<endl;
		  Sleep(2000);
		  cout<<endl<<endl;
		  for(i=0;i<N;i++)
		  {
			  if(strcmp(tic[i].num,num2)==0&&strcmp(tic[i].num,"0")!=0)
			      tic[i].book();
			  else
               cout<<"*对不起列车不存在*"<<endl;
		  }
		  break;
    case '3':
        system("cls");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
		  cout<<"---------------------------------欢迎进入退票功能-----------------------------"<<endl;
		  cout<<"                         欢迎进入退票系统，但愿我们的服务能让你满意           "<<endl;
		  jinglu();
		  cout<<endl;
		  cout<<"                               请输入你需要退购的车次号                       "<<endl;
		  cout<<"请输入：";
		  cin>>num3;
		  cout<<endl<<"系统正在为你处理请稍后......"<<endl;
		  Sleep(2000);
		  for(i=0;i<N;i++)
		  {
			  if(strcmp(tic[i].num,num3)==0&&strcmp(tic[i].num,"0")!=0)
			  tic[i].unbook();
			  else
              cout<<"*对不起列车不存在*"<<endl;

		  }break;
	case '4':
	    system("cls");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN| FOREGROUND_BLUE);
		  cout<<"--------------------------欢迎进入查询当日所有车次状态功能-------------------"<<endl;
		  cout<<endl<<endl;
		  cout<<endl<<"系统正在为你处理请稍后......"<<endl;
		  Sleep(2000);
		  cout<<"车次  起始站  终点站  起始时间  结束时间  行程时间  总票数  剩余票数  当前状态 "<<endl;
		for(i=0;i<N;i++)
        {
            if(strcmp(tic[i].num,"0")!=0)
           {tic[i].display();}
               }break;

    case '5':
        system("cls");
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED| FOREGROUND_BLUE| FOREGROUND_GREEN);
		  cout<<"------------------------------欢迎进入车辆信息操作功能-------------------------"<<endl;
		  cout<<"                                 请选择你要操作的方式                       "<<endl;
		  show3();
		  cout<<"请输入你选择的操作     "<<endl<<endl;
		  while(1)
		  {
		      //system("cls");show3();
		      cout<<"ESC键返回主菜单---0键继续选择操作      ";
		      //cout<<endl<<"系统正在为你处理请稍后......"<<endl;
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
		      cout<<endl<<"系统正在为你处理请稍后......"<<endl;
		      Sleep(2000);
		      system("cls");
			  cout<<"请输入列车信息当按n键时表示输入完成"<<endl;
	          int c;
	          char s;
              for(c=N; c<m; c++)
			  {
			      cout<<"是否要添加列车信息 Y/N "<<endl;
	              cout<<"请输入选项     "<<endl;
		        cin>>s;
	        	if(s=='n')
	        	 {cout<<endl<<"系统正在为你处理请稍后......"<<endl;
                //system("cls");
                break;}
	        	else tic[c].set();
			  }break;
		  case '2':
		      cout<<endl<<"系统正在为你处理请稍后......"<<endl;
		      Sleep(2000);
		      system("cls");
			  cout<<"请输入你要删除的列车车次"<<endl;
			  cin>>num4;
			  cout<<endl<<"系统正在为你处理请稍后......"<<endl;
			  Sleep(2000);
                //system("cls");
			  for(i=0;i<N;i++)
			  {
				  if(strcmp(tic[i].num,num4)==0&&strcmp(tic[i].num,"0")!=0)
			      tic[i].delect();
				  else
                cout<<"*对不起列车不存在*"<<endl;
			  }break;
		  case '3':
		      cout<<endl<<"系统正在为你处理请稍后......"<<endl;
		      Sleep(2000);
		      system("cls");
			  cout<<"请输入你要修改的列车车次"<<endl;
			  cin>>num5;
			  cout<<endl<<"系统正在为你处理请稍后......"<<endl;
			  Sleep(2000);
                //system("cls");
			  for(i=0;i<N;i++)
			  {
				  if(strcmp(tic[i].num,num5)==0&&strcmp(tic[i].num,"0")!=0)
					  tic[i].change();
				 // else{cout<<"*对不起列车不存在*"<<endl;}
			  }break;
		  }
		  }
	}

}
return 0;
}
