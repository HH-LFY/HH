
#include<iostream.h>
#include<string.h>
#include<fstream.h>
#include<stdlib.h>
#include<iomanip.h> 
class student
{ 
private:
    
     char name[4]; //姓名
     double cpro,english,math,sport,law,hbpro,computer,allscore,average,averagecore,core;//课程
     int order, number; //名次，学号
  
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

    cout<<"                    欢迎使用学生管理系统"<<endl;
 
    cout<<"      ******************************************"<<endl; 
    cout<<"            ****   学生成绩管理系统   ****"<<endl;
    cout<<"      ******************************************"<<endl;
 
   cout<<"                    0、输入数据         "<<endl;
   cout<<"                    1、增加数据         "<<endl;
   cout<<"                    2、修改数据         "<<endl;
   cout<<"                    3、删除学生的信息   "<<endl;
   cout<<"                    4、按姓名查询       "<<endl;
   cout<<"                    5、按学号查询       "<<endl;
   cout<<"                    6、输出所有学生成绩 "<<endl;
   cout<<"                    7、按总分高低排序   "<<endl;
   cout<<"                    8、保存文件         "<<endl;
   cout<<"                    9、退出系统         "<<endl;

   cout<<"      =========================================="<<endl;
   cout<<"                 选择0-9数字进行操作"<<endl;
   cout<<"      =============制作人:邹力================"<<endl;
   char p;char w;
   student s[50];        //指针对象，最多存50个学生数据
   ofstream *file[50];   //负责对文件插入操作
   int i=0;
   int j=0;
   int flag=0;
do                     //flag判断输入是否有效
 {
   cin>>p;
if((p>='0'&&p<='9'))
   flag=1;
else
   cout<<"  指令错误！请重新输入："<<endl;
 }while(flag==0);
do{
    switch(p)                 //接收功能选项
    {
     case '0':  //输入数据
     {
      char c;
      char name[4];int number;double cpro,english,math,sport,law,hbpro,core,computer;
   
    do{
    
     cout<<endl<<"   姓名:";
     cin>>name;
     cout<<endl<<"   学号:";
     cin>>number;
     cout<<endl<<"   C++成绩:";
     cin>>cpro;
     cout<<endl<<"   英语成绩:";
     cin>>english;
     cout<<endl<<"   线代成绩:";
     cin>>math;
     cout<<endl<<"   体育成绩:";
     cin>>sport;
     cout<<endl<<"   法律成绩:";
     cin>>law;
     cout<<endl<<"   复变成绩:";
     cin>>hbpro;
     cout<<endl<<"   电工成绩:";
     cin>>computer;
     cout<<endl;
     {allscore=cpro+english+math+sport+law+hbpro+computer;}
  cout<<"  总成绩:"<<allscore<<endl;
  {average=(cpro+english+math+sport+law+hbpro+computer)/7;}
  cout<<"  平均成绩:"<<average<<endl;
  {core=(1+(cpro-60.00)/10)*3.5+(1+(english-60.00)/10)*5+(1+(math-60.00)/10)*4+(1+(sport-60.00)/10)*2+(1+(law-60.00)/10)*2+(1+(hbpro-60.00)/10)*1.5+(1+(computer-60.00)/10)*2;}
  cout<<"  积点:"<<core<<endl;
  {averagecore=core/20;}
  cout<<"  平均积点:"<<averagecore<<endl;
     file[j]=new ofstream("D:\student.dat",ios::ate);
     *file[j]<<"   姓名 "<<name<<" 学号 "<<number<<" C++成绩 "<<cpro
     <<" 英语成绩 "<<english<<" 线代成绩 "<<math<<" 体育成绩 "
     <<sport<<" 法律成绩 "<<law<<" 复变成绩 "<<hbpro<<"电工成绩 "<<computer<<"总成绩"<<allscore<<"平均成绩"<<average<<"积点"<<core<<"平均积点"<<averagecore<<endl;
     j++;
     s[i]= student(name, number,cpro,english,math,sport,law,hbpro,computer,allscore,average,core,averagecore);
     i++;
     cout<<"  数据输入成功，想继续输入吗(y/n):";
     cin>>c;
     cout<<endl;
do
  {
if(c!='y'&&c!='n')
  {
     cout<<"  指令错误！请重新输入！"<<endl<<"     ";
     cin>>c;
  }
else
     flag=1;
  }while(flag==0);
    }while(c=='y');
break;
   }
  
  case '1':         //增加数据
   {
    char name[20];
    int number;double cpro,english,math,sport,law,hbpro,computer,core,averagecore;
    char c;
 
    do
    {
     cout<<"  请输入您要增加的学生的姓名:";
     cin>>name;
     cout<<endl<<"   学号:";
     cin>>number;    
     cout<<endl<<"   C++成绩:";
     cin>>cpro;
     cout<<endl<<"   英语成绩:";
     cin>>english;
     cout<<endl<<"   线代成绩:";
     cin>>math;
     cout<<endl<<"   体育成绩:";
     cin>>sport;
     cout<<endl<<"   法律成绩:";
     cin>>law;
     cout<<endl<<"   复变成绩:";
     cin>>hbpro;
     cout<<endl<<"   电工成绩:";
     cin>>computer;
     cout<<endl;
     {allscore=cpro+english+math+sport+law+hbpro+computer;}
  cout<<"  总成绩:"<<allscore<<endl;
  {average=(cpro+english+math+sport+law+hbpro+computer)/7;}
  cout<<"  平均成绩:"<<average<<endl;
  {core=(1+(cpro-60.00)/10)*3.5+(1+(english-60.00)/10)*5+(1+(math-60.00)/10)*4+(1+(sport-60.00)/10)*2+(1+(law-60.00)/10)*2+(1+(hbpro-60.00)/10)*1.5+(1+(computer-60.00)/10)*2;}
  cout<<"  积点:"<<core<<endl;
  {averagecore=core/20;}
  cout<<"  平均积点:"<<averagecore<<endl;
     file[j]=new ofstream("d:\student.dat",ios::ate);
     *file[j]<<"  姓名 "<<name<<" 学号  "<<number<<" C++成绩 "<<cpro<<" 英语成绩 "<<english<<" 线代成绩 "<<math<<" 体育成绩 "<<sport<<" 法律成绩 "<<law<<" 复变成绩 "<<hbpro<<" 电工成绩 "<<computer<<" 总成绩 "<<allscore<<" 平均成绩 "<<average<<"  积点 "<<core<<" 平均积点 "<<averagecore<<endl;
     j++;
     s[i]= student(name, number,cpro,english,math,sport,law,hbpro,computer,allscore,average,core,averagecore);
     i++;
     cout<<"  数据输入成功，想继续数入吗(y/n):";
     cin>>c;
     cout<<endl;
     if(c!='y'&&c!='n')
     {
      cout<<"  指令错误！请重新输入！"<<endl<<"     ";
      cin>>c;
     }
    }while(c=='y');
    break;
   }
  
  case '2':                    //修改数据
   {
     char name[20];int nu;double cc,eng,ma,sp,l,hb,com,as,av,c1,ac;flag=0;
     char c;
     if(i==0)
    {
  cout<<"系统中找不到这个学生";
    }
    do
    {
     cout<<"  请输入您要修改的学生的姓名:";
     cin>>name;
     cout<<endl;
  for(int h=0;h<i;h++)         //h纪录要修改学生的位置
  {
      if(strcmp(name,s[h].name)==0)
 {
      flag=1;
      cout<<"   新的学号:";
      cin>>nu;
      cout<<endl<<"   C++成绩:";
      cin>>cc;
      cout<<endl<<"   英语成绩:";
      cin>>eng;
      cout<<endl<<"   线代成绩:";
      cin>>ma;
      cout<<endl<<"   体育成绩:";
      cin>>sp;
      cout<<endl<<"   法律成绩:";
      cin>>l;
      cout<<endl<<"   复变成绩:";
      cin>>hb;
      cout<<endl<<"   电工成绩:";
      cin>>com;
   {as=cc+eng+ma+sp+l+hb+com;}
   cout<<endl<<"  总成绩:"<<as;
   {av=as/7;}
      cout<<endl<<"  平均成绩:"<<av;
   {c1=(1+(cc-60.00)/10)*3.5+(1+(eng-60.00)/10)*5+(1+(ma-60.00)/10)*4+(1+(sp-60.00)/10)*2+(1+(l-60.00)/10)*2+(1+(hb-60.00)/10)*1.5+(1+(com-60.00)/10)*2;}
   cout<<"  积点:"<<c1<<endl;
   {ac=c/20;}
   cout<<"  平均积点:"<<ac<<endl;
      cout<<endl;
      s[h].cpro=cc;
      s[h].english=eng;
      s[h].math=ma;
      s[h].sport=sp;
      s[h].law=l;
      s[h].hbpro=hb;
      s[h].number=nu;
    
      cout<<"  数据修改成功！"<<endl;
   }
  }
     if(flag==0)
     {
      cout<<"  您要修改的学生本来就不存在！请检查重新输入！"<<endl;
     }
     cout<<"  想继续修改吗(y/n):";
     cin>>c;
     cout<<endl;
     if(c!='y'&&c!='n')
     {
      cout<<"  指令错误！请重新输入！"<<endl<<"     ";
      cin>>c;
     }
    }while(c=='y');
    break;
   }
   case '3':
    {
 
 cout<<" 请输入你要删除的姓名 ：";
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
  cout<<"  删除成功！"<<endl;
  
  }
  }
  break;}
  case '4':         //按姓名查询
   {
    char n[20];int j=0;char c;
    if(i==0)
    {
     cout<<"  管理系统中没有输入数据！"<<endl;break;
    }   
    do{
     int flag=0;
     cout<<"  请输入你要查询的学生姓名:";
     cin>>n;
  cout<<endl;
     for(int j=0;j<i;j++)
     {
      if(strcmp(n,(s[j]).name)==0)
      {
       flag=1;
       cout<<"  您要查询的学生是:"<<(s[j]).name<<endl;
       cout<<(s[j]).name<<"的成绩是: "<<" C++: "<<(s[j]).cpro<<" 英语: "<<(s[j]).english<<" 线代："<<(s[j]).math<<" 体育："<<(s[j]).sport<<" 法律："<<(s[j]).law<<" 复变："<<(s[j]).hbpro<<" 电工 "<<(s[j]).computer<<"  总成绩"<<(s[j]).allscore<<"  平均成绩"<<(s[j]).average<<" 积点"<<(s[j]).core<<" 平均积点"<<(s[j]).averagecore<<endl;
      }
     }
     if(flag==0)
      cout<<"  对不起!您要查询的学生不存在!"<<endl;
     cout<<"  您想继续查询吗?(y/n):";
     cin>>c;
     cout<<endl;
     if(c!='y'&&c!='n')
     {
      cout<<"  指令错误！请重新输入！"<<endl;
      cin>>c;
     }
    }
    while(c=='y');
    break;
   }
  case '5':           //按学号查询
   {
    int n,j=0;char c;
    if(i==0){
    
     cout<<"  管理系统中没有输入数据！"<<endl;break;
    }   
    do{
     int flag=0;
     cout<<"  请输入你要查询的学生的学号:";
     cin>>n;
  cout<<endl;
     for(int j=0;j<i;j++)
     {
      if(s[j].number==n)
      {
       flag=1;
       cout<<"  您要查询的学生是："<<(s[j]).name<<endl;
       cout<<(s[j]).name<<"的成绩是:  "<<" C++："<<(s[j]).cpro<<" 英语："<<(s[j]).english<<" 线代："<<(s[j]).math<<" 体育："<<(s[j]).sport<<" 法律："<<(s[j]).law<<"复变："<<(s[j]).hbpro<<" 电工: "<<(s[j]).computer<<"总成绩:"<<(s[j]).allscore<<"平均成绩:"<<(s[j]).average<<" 积点"<<(s[j]).core<<" 平均积点"<<(s[j]).averagecore<<endl;
      }
     }
     if(flag==0)
      cout<<"  对不起!您要查询的学生不存在!"<<endl;
     cout<<"  您想继续查询吗?(y/n):";
     cin>>c;
     cout<<endl;
     if(c!='y'&&c!='n')
     {
      cout<<"  指令错误！请重新输入！"<<endl;
      cin>>c;
     }
    }
    while(c=='y');
    break;
   }
  case '6':           //输出
   {
    cout<<"  本系统所有学生数据如下："<<endl;
    if(i==0)
     cout<<"  管理系统中没有输入数据！"<<endl;
     cout<<"姓名  学号 c++ 英语 线代 体育 法律 复变 电工 总成绩 平均成绩 总积点 平均积点  "<<endl;
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
  cout<<"已经排好序了，是否需要输出（y/n）:";
        char yn;
        cin>>yn;
        while(yn!='y'&&yn!='n')
 {
        cout<<"操作错误！！！请重新输入：";
        cin>>yn;
 }
 if(yn=='y')
 {
     cout<<"所有学生的成绩按总分从高到低的排名是："<<endl;
  cout<<"  本系统所有学生数据如下："<<endl;
     if(i==0)
     cout<<"  管理系统中没有输入数据！"<<endl;
     cout<<"姓名  学号 c++ 英语 线代 体育 法律 复变 电工 总成绩 平均成绩 总积点 平均积点  "<<endl;
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
 cout<<"  保存成功!"<<endl;break;
  }
   case'9'://退出
   {exit(0); cout<<"Bye bye!"<<endl;}
}
cout<<"  您想继续进行其他操作吗?(y/n):";
int flag=0;
do
{
    cin>>w;
    cout<<endl;
 if(w!='y'&&w!='n')
     cout<<"  指令错误！请重新输入！"<<endl;
    else
     flag=1;
}while(flag==0);
if(w=='y')
   cout<<"  请输入操作代码:0 输入数据"<<endl;
   cout<<"                 1 增加数据"<<endl;
   cout<<"                 2 修改数据"<<endl;
   cout<<"                 3 删除学生的信息"<<endl;
   cout<<"                 4 按姓名查询"<<endl;
   cout<<"                 5 按学号查找"<<endl;
   cout<<"                 6 输出所有学生成绩"<<endl;
   cout<<"                 7 按总分高低排序 "<<endl;
   cout<<"                 8 保存文件"<<endl;
   cout<<"                 9 退出系统"<<endl;
   cin>>p;
  }while(w=='y');

  
}

 
