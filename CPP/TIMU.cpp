#include<iostream>
#include<iomanip>
#include<time.h> //�õ���time����������Ҫ�����ͷ�ļ�
#include<stdlib.h>//�õ���srand����������Ҫ�����ͷ�ļ�
using namespace std;
class Student  //����һ��STUDENT��
{  private:
	char Num[20];//ѧ��
	char Name[20];//����
	int  age;//����
	int  Score;//�ɼ�
public:
	void Input();//��Ϣ����
	void Output();//����ɼ�
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
    cout<<"*��������Сѧ��ѧ�����������������*      "<<endl;
	cout<<"                һ���꼶������                          "<<endl;
	cout<<"             ������ߣ���˫�飩                         "<<endl;
    cout<<"*��������Сѧ��ѧ�����������������*      "<<endl;
    cout<<"**************************************************         \n";
	Student stud; //����һ������
	while(1)
	{  stud.Input();//��Ϣ����
	   stud.AddSub();
	   stud.Output();//����ɼ�
	cout<<"do you want to continue?(Y/N)";
		char ch;
		cin>>ch;
		if(ch=='n'||ch=='N')
			break;
	}
	return 0;
}
void  Student::Input()
{   cout<<"���������ѧ�ţ�";
	cin>>Num;
	cout<<"���������������";
	cin>>Name;
	cout<<"������������䣺";
	cin>>age;
	cout<<"**************************************************"<<endl;
}

void Student::AddSub()
{
int a,b,c,score[10],trueanswer,sum=0,truth=0,flag,first,second,third,
first1=0,second1=0,third1=0;
  /*��a=rand()%51,b=rand()%51����a,b��ֵ������50 sum�ۼƷ�����flag=1��־����ȷ��zenΪ�ۼ���ȷ��ĸ���,first��һ����ȷ�ĸ�����second�ڶ�����ȷ�ĸ�����third��������ȷ�ĸ�����first1�ۼƽ�һ��������ĸ�����second1Ϊ���β��������ĸ�����third1Ϊ����������ĸ���*/
      //������10����
  {
	  for(a=rand()%51,b=rand()%51;a+b>50 || a+b<0  || a-b>50 || a-b<0; b=bb(),a=aa(b))
	  { }

//===================================================================== c=rand()%3;
	         //�����ǽ��мӷ����Ǽ�������
	  for(int i=1;i<=10;i++)
      {
          b=bb();
		  a=aa(b);
	   for(int j=1;j<=3;j++)  //J���Ƶ÷ֵ����
	  {   flag=0;
		  first=0;
		  second=0;
		  third=0;
		  if(c==1)
		  { cout<<"��"<<i<<"��:"<<a<<"+"<<b<<"=";
          trueanswer=a+b;
          cin>>score[i];
		  if(score[i]!=trueanswer)
		  {  if(j==1)
				  {  cout<<"�𰸴����㻹�����λ��ᣬ����������"<<endl;
                     score[i]+=10;    //����ϴδ����
				  }
				  else
					  if(j==2)
					  {
					cout<<"�𰸴����㻹�����һ�λ��ᣬ����������"<<endl;
                  score[i]+=0;    //����ϴδ����
					  }
					  else
					  { cout<<"�𰸴��󣬺��ź���û������Ļ�����"<<endl;
						 cout<<"��ȷ���ǣ�"<<" : "<<trueanswer<<endl;
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
						  flag=1;                             /*���Ե����*/
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
		  {cout<<"��"<<i<<"��:"<<a<<"-"<<b<<"=";
          trueanswer=a-b;
          cin>>score[i];
		  if(score[i]!=trueanswer)
		  {  if(j==1)
				  {  cout<<"�𰸴����㻹�����λ��ᣬ����������"<<endl;
                     score[i]=0;    //����ϴδ����
				  }
				  else
					  if(j==2)
					  {
					cout<<"�𰸴����㻹�����һ�λ��ᣬ����������"<<endl;
                  score[i]=0;    //����ϴδ����
					  }
					  else
					  { cout<<"�𰸴��󣬺��ź���û������Ļ�����"<<endl;
						 cout<<"��ȷ���ǣ�"<<" : "<<trueanswer<<endl;
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
					      score[i]=7;         /*���Ե����*/
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
	  truth=truth+flag;     //������ĸ���
	  first1=first1+first;
	  second1=second1+second;
	  third1=third1+third;
  }
      }
  Score=sum;      //�ܷ���
  cout<<"******************ͳ��******************"<<endl;
  cout<<"������"<<10-truth<<"����"<<endl;
  cout<<"������"<<truth<<"����"<<endl;
  cout<<"��һ������"<<first1<<"����"<<endl;
  cout<<"���β�����"<<second1<<"����"<<endl;
  cout<<"���β�����"<<third1<<"����"<<endl;
}
}
void  Student::Output()    //�������
{
cout<<"���ĳɼ�Ϊ:"<<Score<<endl;
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

