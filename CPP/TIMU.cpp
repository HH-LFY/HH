#include<iostream>
#include<iomanip>
#include<time.h> //用到了time函数，所以要有这个头文件
#include<stdlib.h>//用到了srand函数，所以要有这个头文件
using namespace std;
class Student  //定义一个STUDENT类
{  private:
	char Num[20];//学号
	char Name[20];//姓名
	int  age;//年龄
	int  Score;//成绩
public:
	void Input();//信息输入
	void Output();//输出成绩
	void AddSub();
	};
int aa(int b)
{
    int a=0;
    while(1)
    {
        a=rand()%100;
        if(a>=b)
            break;
    }
    return a;
}

int bb()
{
    int b;
    b=rand()%51;
    return b;
}
int main()
{	cout<<"**************************************************         \n";
    cout<<"*☆☆☆☆☆☆☆小学数学测试软件☆☆☆☆☆☆☆☆☆*      "<<endl;
	cout<<"                一二年级测试题                          "<<endl;
	cout<<"             （设计者：余双情）                         "<<endl;
    cout<<"*☆☆☆☆☆☆☆小学数学测试软件☆☆☆☆☆☆☆☆☆*      "<<endl;
    cout<<"**************************************************         \n";
	Student stud; //定义一个对象
	while(1)
	{  stud.Input();//信息输入
	   stud.AddSub();
	   stud.Output();//输出成绩
	cout<<"do you want to continue?(Y/N)";
		char ch;
		cin>>ch;
		if(ch=='n'||ch=='N')
			break;
	}
	return 0;
}
void  Student::Input()
{   cout<<"请输入你的学号：";
	cin>>Num;
	cout<<"请输入你的姓名：";
	cin>>Name;
	cout<<"请输入你的年龄：";
	cin>>age;
	cout<<"**************************************************"<<endl;
}

void Student::AddSub()
{
int a,b,c,score[10],trueanswer,sum=0,truth=0,flag,first,second,third,
first1=0,second1=0,third1=0;
  /*数a=rand()%51,b=rand()%51控制a,b的值不超过50 sum累计分数，flag=1标志答案正确，zen为累计正确题的个数,first第一次正确的个数，second第二次正确的个数，third第三次正确的个数，first1累计仅一次做对题的个数，second1为俩次才能完成题的个数，third1为三次做对题的个数*/
      //控制题10道题
  {
	  for(a=rand()%51,b=rand()%51;a+b>50 || a+b<0  || a-b>50 || a-b<0; b=bb(),a=aa(b))
	  { }

//===================================================================== c=rand()%3;
	         //控制是进行加法还是减法操作
	  for(int i=1;i<=10;i++)
      {
          b=bb();
		  a=aa(b);
	   for(int j=1;j<=3;j++)  //J控制得分的情况
	  {   flag=0;
		  first=0;
		  second=0;
		  third=0;
		  if(c==1)
		  { cout<<"第"<<i<<"个:"<<a<<"+"<<b<<"=";
          trueanswer=a+b;
          cin>>score[i];
		  if(score[i]!=trueanswer)
		  {  if(j==1)
				  {  cout<<"答案错误，你还有俩次机会，请重新输入"<<endl;
                     score[i]+=10;    //清空上次错误答案
				  }
				  else
					  if(j==2)
					  {
					cout<<"答案错误，你还有最后一次机会，请重新输入"<<endl;
                  score[i]+=0;    //清空上次错误答案
					  }
					  else
					  { cout<<"答案错误，很遗憾你没有做题的机会了"<<endl;
						 cout<<"正确答案是："<<" : "<<trueanswer<<endl;
						 score[i]+=10;
					  }
		  }
		  else
		  { if(j==1)
				  {  score[i]=10;
					  flag=1;
					  first=1;
				  }
				  else
					  if(j==2)
					  {  score[i]=7;
						  flag=1;                             /*做对的情况*/
						  second=1;
					  }
					  else
					  {  score[i]=5;
						  flag=1;	  third=1;
					  }
					  break;
		  }
	  }
		  else
		  {cout<<"第"<<i<<"个:"<<a<<"-"<<b<<"=";
          trueanswer=a-b;
          cin>>score[i];
		  if(score[i]!=trueanswer)
		  {  if(j==1)
				  {  cout<<"答案错误，你还有俩次机会，请重新输入"<<endl;
                     score[i]=0;    //清空上次错误答案
				  }
				  else
					  if(j==2)
					  {
					cout<<"答案错误，你还有最后一次机会，请重新输入"<<endl;
                  score[i]=0;    //清空上次错误答案
					  }
					  else
					  { cout<<"答案错误，很遗憾你没有做题的机会了"<<endl;
						 cout<<"正确答案是："<<" : "<<trueanswer<<endl;
						 score[i]=0;
					  }
		  }
		  else
		  {
		      if(j==1)
				  {
				      score[i]=10;
					  flag=1;
					  first=1;
				  }
				  else if(j==2)
					  {
					      score[i]=7;         /*做对的情况*/
						  flag=1;
						  second=1;
					  }
                  else
					  {
					      score[i]=5;
					      flag=1;
						  third=1;
					  }
                break;
            }
	  }
	  sum=sum+score[i];
	  truth=truth+flag;     //做对题的个数
	  first1=first1+first;
	  second1=second1+second;
	  third1=third1+third;
  }
      }
  Score=sum;      //总分数
  cout<<"******************统计******************"<<endl;
  cout<<"共做对"<<10-truth<<"个题"<<endl;
  cout<<"共做错"<<truth<<"个题"<<endl;
  cout<<"仅一次做对"<<first1<<"个题"<<endl;
  cout<<"俩次才做对"<<second1<<"个题"<<endl;
  cout<<"三次才做对"<<third1<<"个题"<<endl;
}
}
void  Student::Output()    //输出函数
{
cout<<"您的成绩为:"<<Score<<endl;
 if(Score>=90)
  cout<<"******************SMART*****************"<<endl;
 else if(Score>=80&&Score<90)
  cout<<"******************GOOD******************"<<endl;
 else if(Score>=70&&Score<80)
  cout<<"*******************OK*******************"<<endl;
 else if(Score>=60&&Score<70)
  cout<<"******************PASS******************"<<endl;
 else if(Score>=60&&Score<70)
  cout<<"****************TRYA GAIN****************"<<endl;
  }

