
#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<iomanip.h> 
class student
{ 
private:
    
     char name[4]; //����
     double cpro,english,math,sport,law,hbpro,computer,allscore,average,averagecore,core;//�γ�
     int order, number; //���Σ�ѧ��
  
public:
     
     student(){}
     student(char n[4],int nu,double cc,double eng,double ma,double sp,double l,double hb,double com,double as,double av,double c1,double ac)  
{
  strcpy(name,n);
     number=nu;
     cpro=cc; english=eng;math=ma;sport=sp;law=l;hbpro=hb;computer=com;allscore=as;average=av;core=c1;averagecore=ac;
}
 friend void main();
 
};

void main()
{

    double allscore;
    double average;
    double averagecore;

    cout<<"                    ��ӭʹ��ѧ������ϵͳ"<<endl;
 
    cout<<"      ******************************************"<<endl; 
    cout<<"            ****   ѧ���ɼ�����ϵͳ   ****"<<endl;
    cout<<"      ******************************************"<<endl;
 
   cout<<"                    0����������         "<<endl;
   cout<<"                    1����������         "<<endl;
   cout<<"                    2���޸�����         "<<endl;
   cout<<"                    3��ɾ��ѧ������Ϣ   "<<endl;
   cout<<"                    4����������ѯ       "<<endl;
   cout<<"                    5����ѧ�Ų�ѯ       "<<endl;
   cout<<"                    6���������ѧ���ɼ� "<<endl;
   cout<<"                    7�����ָܷߵ�����   "<<endl;
   cout<<"                    8�������ļ�         "<<endl;
   cout<<"                    9���˳�ϵͳ         "<<endl;

   cout<<"      =========================================="<<endl;
   cout<<"                 ѡ��0-9���ֽ��в���"<<endl;
   cout<<"      =============������:����================"<<endl;
   char p;char w;
   student s[50];        //ָ���������50��ѧ������
   ofstream *file[50];   //������ļ��������
   int i=0;
   int j=0;
   int flag=0;
do                     //flag�ж������Ƿ���Ч
 {
   cin>>p;
if((p>='0'&&p<='9'))
   flag=1;
else
   cout<<"  ָ��������������룺"<<endl;
 }while(flag==0);
do{
    switch(p)                 //���չ���ѡ��
    {
     case '0':  //��������
     {
      char c;
      char name[4];int number;double cpro,english,math,sport,law,hbpro,core,computer;
   
    do{
    
     cout<<endl<<"   ����:";
     cin>>name;
     cout<<endl<<"   ѧ��:";
     cin>>number;
     cout<<endl<<"   C++�ɼ�:";
     cin>>cpro;
     cout<<endl<<"   Ӣ��ɼ�:";
     cin>>english;
     cout<<endl<<"   �ߴ��ɼ�:";
     cin>>math;
     cout<<endl<<"   �����ɼ�:";
     cin>>sport;
     cout<<endl<<"   ���ɳɼ�:";
     cin>>law;
     cout<<endl<<"   ����ɼ�:";
     cin>>hbpro;
     cout<<endl<<"   �繤�ɼ�:";
     cin>>computer;
     cout<<endl;
     {allscore=cpro+english+math+sport+law+hbpro+computer;}
  cout<<"  �ܳɼ�:"<<allscore<<endl;
  {average=(cpro+english+math+sport+law+hbpro+computer)/7;}
  cout<<"  ƽ���ɼ�:"<<average<<endl;
  {core=(1+(cpro-60.00)/10)*3.5+(1+(english-60.00)/10)*5+(1+(math-60.00)/10)*4+(1+(sport-60.00)/10)*2+(1+(law-60.00)/10)*2+(1+(hbpro-60.00)/10)*1.5+(1+(computer-60.00)/10)*2;}
  cout<<"  ����:"<<core<<endl;
  {averagecore=core/20;}
  cout<<"  ƽ������:"<<averagecore<<endl;
     file[j]=new ofstream("D:\student.dat",ios::ate);
     *file[j]<<"   ���� "<<name<<" ѧ�� "<<number<<" C++�ɼ� "<<cpro
     <<" Ӣ��ɼ� "<<english<<" �ߴ��ɼ� "<<math<<" �����ɼ� "
     <<sport<<" ���ɳɼ� "<<law<<" ����ɼ� "<<hbpro<<"�繤�ɼ� "<<computer<<"�ܳɼ�"<<allscore<<"ƽ���ɼ�"<<average<<"����"<<core<<"ƽ������"<<averagecore<<endl;
     j++;
     s[i]= student(name, number,cpro,english,math,sport,law,hbpro,computer,allscore,average,core,averagecore);
     i++;
     cout<<"  ��������ɹ��������������(y/n):";
     cin>>c;
     cout<<endl;
do
  {
if(c!='y'&&c!='n')
  {
     cout<<"  ָ��������������룡"<<endl<<"     ";
     cin>>c;
  }
else
     flag=1;
  }while(flag==0);
    }while(c=='y');
break;
   }
  
  case '1':         //��������
   {
    char name[20];
    int number;double cpro,english,math,sport,law,hbpro,computer,core,averagecore;
    char c;
 
    do
    {
     cout<<"  ��������Ҫ���ӵ�ѧ��������:";
     cin>>name;
     cout<<endl<<"   ѧ��:";
     cin>>number;    
     cout<<endl<<"   C++�ɼ�:";
     cin>>cpro;
     cout<<endl<<"   Ӣ��ɼ�:";
     cin>>english;
     cout<<endl<<"   �ߴ��ɼ�:";
     cin>>math;
     cout<<endl<<"   �����ɼ�:";
     cin>>sport;
     cout<<endl<<"   ���ɳɼ�:";
     cin>>law;
     cout<<endl<<"   ����ɼ�:";
     cin>>hbpro;
     cout<<endl<<"   �繤�ɼ�:";
     cin>>computer;
     cout<<endl;
     {allscore=cpro+english+math+sport+law+hbpro+computer;}
  cout<<"  �ܳɼ�:"<<allscore<<endl;
  {average=(cpro+english+math+sport+law+hbpro+computer)/7;}
  cout<<"  ƽ���ɼ�:"<<average<<endl;
  {core=(1+(cpro-60.00)/10)*3.5+(1+(english-60.00)/10)*5+(1+(math-60.00)/10)*4+(1+(sport-60.00)/10)*2+(1+(law-60.00)/10)*2+(1+(hbpro-60.00)/10)*1.5+(1+(computer-60.00)/10)*2;}
  cout<<"  ����:"<<core<<endl;
  {averagecore=core/20;}
  cout<<"  ƽ������:"<<averagecore<<endl;
     file[j]=new ofstream("d:\student.dat",ios::ate);
     *file[j]<<"  ���� "<<name<<" ѧ��  "<<number<<" C++�ɼ� "<<cpro<<" Ӣ��ɼ� "<<english<<" �ߴ��ɼ� "<<math<<" �����ɼ� "<<sport<<" ���ɳɼ� "<<law<<" ����ɼ� "<<hbpro<<" �繤�ɼ� "<<computer<<" �ܳɼ� "<<allscore<<" ƽ���ɼ� "<<average<<"  ���� "<<core<<" ƽ������ "<<averagecore<<endl;
     j++;
     s[i]= student(name, number,cpro,english,math,sport,law,hbpro,computer,allscore,average,core,averagecore);
     i++;
     cout<<"  ��������ɹ��������������(y/n):";
     cin>>c;
     cout<<endl;
     if(c!='y'&&c!='n')
     {
      cout<<"  ָ��������������룡"<<endl<<"     ";
      cin>>c;
     }
    }while(c=='y');
    break;
   }
  
  case '2':                    //�޸�����
   {
     char name[20];int nu;double cc,eng,ma,sp,l,hb,com,as,av,c1,ac;flag=0;
     char c;
     if(i==0)
    {
  cout<<"ϵͳ���Ҳ������ѧ��";
    }
    do
    {
     cout<<"  ��������Ҫ�޸ĵ�ѧ��������:";
     cin>>name;
     cout<<endl;
  for(int h=0;h<i;h++)         //h��¼Ҫ�޸�ѧ����λ��
  {
      if(strcmp(name,s[h].name)==0)
 {
      flag=1;
      cout<<"   �µ�ѧ��:";
      cin>>nu;
      cout<<endl<<"   C++�ɼ�:";
      cin>>cc;
      cout<<endl<<"   Ӣ��ɼ�:";
      cin>>eng;
      cout<<endl<<"   �ߴ��ɼ�:";
      cin>>ma;
      cout<<endl<<"   �����ɼ�:";
      cin>>sp;
      cout<<endl<<"   ���ɳɼ�:";
      cin>>l;
      cout<<endl<<"   ����ɼ�:";
      cin>>hb;
      cout<<endl<<"   �繤�ɼ�:";
      cin>>com;
   {as=cc+eng+ma+sp+l+hb+com;}
   cout<<endl<<"  �ܳɼ�:"<<as;
   {av=as/7;}
      cout<<endl<<"  ƽ���ɼ�:"<<av;
   {c1=(1+(cc-60.00)/10)*3.5+(1+(eng-60.00)/10)*5+(1+(ma-60.00)/10)*4+(1+(sp-60.00)/10)*2+(1+(l-60.00)/10)*2+(1+(hb-60.00)/10)*1.5+(1+(com-60.00)/10)*2;}
   cout<<"  ����:"<<c1<<endl;
   {ac=c/20;}
   cout<<"  ƽ������:"<<ac<<endl;
      cout<<endl;
      s[h].cpro=cc;
      s[h].english=eng;
      s[h].math=ma;
      s[h].sport=sp;
      s[h].law=l;
      s[h].hbpro=hb;
      s[h].number=nu;
    
      cout<<"  �����޸ĳɹ���"<<endl;
   }
  }
     if(flag==0)
     {
      cout<<"  ��Ҫ�޸ĵ�ѧ�������Ͳ����ڣ������������룡"<<endl;
     }
     cout<<"  ������޸���(y/n):";
     cin>>c;
     cout<<endl;
     if(c!='y'&&c!='n')
     {
      cout<<"  ָ��������������룡"<<endl<<"     ";
      cin>>c;
     }
    }while(c=='y');
    break;
   }
   case '3':
    {
 
 cout<<" ��������Ҫɾ�������� ��";
 char m[20];
 cin>>m;
 for(int a=0;a<i;a++)
 {    
  if(strcmp(s[a].name,m)==0)
  {
  int w;
  w=a;
  for(w;w<i;w++)
  {
  
   s[w]=s[w+1];
    i=i-1;}
  cout<<"  ɾ���ɹ���"<<endl;
  
  }
  }
  break;}
  case '4':         //��������ѯ
   {
    char n[20];int j=0;char c;
    if(i==0)
    {
     cout<<"  ����ϵͳ��û���������ݣ�"<<endl;break;
    }   
    do{
     int flag=0;
     cout<<"  ��������Ҫ��ѯ��ѧ������:";
     cin>>n;
  cout<<endl;
     for(int j=0;j<i;j++)
     {
      if(strcmp(n,(s[j]).name)==0)
      {
       flag=1;
       cout<<"  ��Ҫ��ѯ��ѧ����:"<<(s[j]).name<<endl;
       cout<<(s[j]).name<<"�ĳɼ���: "<<" C++: "<<(s[j]).cpro<<" Ӣ��: "<<(s[j]).english<<" �ߴ���"<<(s[j]).math<<" ������"<<(s[j]).sport<<" ���ɣ�"<<(s[j]).law<<" ���䣺"<<(s[j]).hbpro<<" �繤 "<<(s[j]).computer<<"  �ܳɼ�"<<(s[j]).allscore<<"  ƽ���ɼ�"<<(s[j]).average<<" ����"<<(s[j]).core<<" ƽ������"<<(s[j]).averagecore<<endl;
      }
     }
     if(flag==0)
      cout<<"  �Բ���!��Ҫ��ѯ��ѧ��������!"<<endl;
     cout<<"  ���������ѯ��?(y/n):";
     cin>>c;
     cout<<endl;
     if(c!='y'&&c!='n')
     {
      cout<<"  ָ��������������룡"<<endl;
      cin>>c;
     }
    }
    while(c=='y');
    break;
   }
  case '5':           //��ѧ�Ų�ѯ
   {
    int n,j=0;char c;
    if(i==0){
    
     cout<<"  ����ϵͳ��û���������ݣ�"<<endl;break;
    }   
    do{
     int flag=0;
     cout<<"  ��������Ҫ��ѯ��ѧ����ѧ��:";
     cin>>n;
  cout<<endl;
     for(int j=0;j<i;j++)
     {
      if(s[j].number==n)
      {
       flag=1;
       cout<<"  ��Ҫ��ѯ��ѧ���ǣ�"<<(s[j]).name<<endl;
       cout<<(s[j]).name<<"�ĳɼ���:  "<<" C++��"<<(s[j]).cpro<<" Ӣ�"<<(s[j]).english<<" �ߴ���"<<(s[j]).math<<" ������"<<(s[j]).sport<<" ���ɣ�"<<(s[j]).law<<"���䣺"<<(s[j]).hbpro<<" �繤: "<<(s[j]).computer<<"�ܳɼ�:"<<(s[j]).allscore<<"ƽ���ɼ�:"<<(s[j]).average<<" ����"<<(s[j]).core<<" ƽ������"<<(s[j]).averagecore<<endl;
      }
     }
     if(flag==0)
      cout<<"  �Բ���!��Ҫ��ѯ��ѧ��������!"<<endl;
     cout<<"  ���������ѯ��?(y/n):";
     cin>>c;
     cout<<endl;
     if(c!='y'&&c!='n')
     {
      cout<<"  ָ��������������룡"<<endl;
      cin>>c;
     }
    }
    while(c=='y');
    break;
   }
  case '6':           //���
   {
    cout<<"  ��ϵͳ����ѧ���������£�"<<endl;
    if(i==0)
     cout<<"  ����ϵͳ��û���������ݣ�"<<endl;
     cout<<"����  ѧ�� c++ Ӣ�� �ߴ� ���� ���� ���� �繤 �ܳɼ� ƽ���ɼ� �ܻ��� ƽ������  "<<endl;
     for(int k=0;k<i;k++)
    { 
      cout<<s[k].name<<setw(7)<<s[k].number<<setw(4)
    <<(s[k]).cpro<<setw(5)<<(s[k]).english<<setw(5)
    <<(s[k]).math<<setw(4)<<(s[k]).sport<<setw(5)
   <<(s[k]).law <<setw(5)<<(s[k]).hbpro<<setw(6)<<(s[k]).computer<<setw(6)<<s[k].allscore<<setw(10)<<(s[k]).average<<setw(7)<<(s[k]).core <<setw(8)<<(s[k]).averagecore<<setw(4)<<endl;
   
    }
    break;
   }
  case'7':{
   student temp;
  
  
 for(int t=0;t<i;t++)
 for(int k=t+1;k<i;k++)
 while (s[t].allscore<s[k].allscore)
 {
  temp=s[t];
  s[t]=s[k];
  s[k]=temp;
 }
  cout<<"�Ѿ��ź����ˣ��Ƿ���Ҫ�����y/n��:";
        char yn;
        cin>>yn;
        while(yn!='y'&&yn!='n')
 {
        cout<<"�������󣡣������������룺";
        cin>>yn;
 }
 if(yn=='y')
 {
     cout<<"����ѧ���ĳɼ����ִܷӸߵ��͵������ǣ�"<<endl;
  cout<<"  ��ϵͳ����ѧ���������£�"<<endl;
     if(i==0)
     cout<<"  ����ϵͳ��û���������ݣ�"<<endl;
     cout<<"����  ѧ�� c++ Ӣ�� �ߴ� ���� ���� ���� �繤 �ܳɼ� ƽ���ɼ� �ܻ��� ƽ������  "<<endl;
     for(int k=0;k<i;k++)
    { 
      cout<<s[k].name<<setw(7)<<s[k].number<<setw(4)
    <<(s[k]).cpro<<setw(5)<<(s[k]).english<<setw(5)
    <<(s[k]).math<<setw(4)<<(s[k]).sport<<setw(5)
   <<(s[k]).law <<setw(5)<<(s[k]).hbpro<<setw(6)<<(s[k]).computer<<setw(6)<<s[k].allscore<<setw(10)<<(s[k]).average<<setw(7)<<(s[k]).core <<setw(8)<<(s[k]).averagecore<<setw(4)<<endl;
   
    }
    
     
 }
 break;
}

   case'8':{
 cout<<"  ����ɹ�!"<<endl;break;
  }
   case'9'://�˳�
   {exit(0); cout<<"Bye bye!"<<endl;}
}
cout<<"  ���������������������?(y/n):";
int flag=0;
do
{
    cin>>w;
    cout<<endl;
 if(w!='y'&&w!='n')
     cout<<"  ָ��������������룡"<<endl;
    else
     flag=1;
}while(flag==0);
if(w=='y')
   cout<<"  �������������:0 ��������"<<endl;
   cout<<"                 1 ��������"<<endl;
   cout<<"                 2 �޸�����"<<endl;
   cout<<"                 3 ɾ��ѧ������Ϣ"<<endl;
   cout<<"                 4 ��������ѯ"<<endl;
   cout<<"                 5 ��ѧ�Ų���"<<endl;
   cout<<"                 6 �������ѧ���ɼ�"<<endl;
   cout<<"                 7 ���ָܷߵ����� "<<endl;
   cout<<"                 8 �����ļ�"<<endl;
   cout<<"                 9 �˳�ϵͳ"<<endl;
   cin>>p;
  }while(w=='y');

  
}

 
