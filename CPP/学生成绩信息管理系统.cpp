#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

struct student                               // 结构体类型 
 {
 	char name[20];
    int num;
 	int yingyu;
 	int gaodengshuxue;
 	int lisanshuxue;
 };
int i;

student s[30],m[3];                       //定义结构体数组 

//--------------------------------------------

void jiemian()                            //开始界面 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
   printf("\n\n\n\n\n");
   printf("\t\t  **                                                  **  \t\t\n"); 
   printf("\t\t  **                                                  **  \t\t\n"); 
   printf("\t\t  **          欢迎使用学生成绩信息管理系统            **  \t\t\n"); 
   printf("\t\t  **                                                  **  \t\t\n"); 
   printf("\t\t  **                                                  **  \t\t\n"); 
   printf("\t\t按回车键进入管理系统：");
   getchar();
}
 //-----------------------------------------
 void zhucaidan();                   // 主菜单函数的声明 
 
 
 void zengjia()                      // 增加函数 
{
    system("cls");
    int a;
    printf("\n请输入所要增加的学生信息：\n");
    printf("姓名：");
	cin>>s[i].name;
	printf("英语成绩：");
    cin>>s[i].yingyu;
   	printf("高等数学成绩：");
    cin>>s[i].gaodengshuxue;
   	printf("离散数学成绩：");
    cin>>s[i].lisanshuxue;
    s[i].num=i+1;
    ofstream outfile("文件.txt",ios::binary);      //文件流 
	for(a=0;a<=i;a++)
    outfile.write((char*)&s[a],sizeof(s[a]));
    i++;
    outfile.close();
    printf("增加成功！！");
    getchar();
	getchar(); 
    zhucaidan();
} 
//--------------------------------------------------
void shanchu()                                //删除函数 
{
	system("cls");
	int a; 
	ifstream infile("文件.txt",ios::binary);     //文件流 从磁盘中获取数据 
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
   printf("\n\n\t\t  **                                             **  \t\t\n"); 
   printf("\t\t  **                                                 **  \t\t\n"); 
   printf("\t\t  **                删除学生成绩信息                 **  \t\t\n"); 
   printf("\t\t  **                                                 **  \t\t\n"); 
   printf("\t\t  **                                                 **  \t\t\n");
   printf("\t\t请输入要删除的学生学号：");
   int b,c,d,e;
    cin>>b;                                       //按学号查询 
	for(c=0;c<=i;c++)
	if(b==s[c].num)
	{
		cout<<"姓名："<<s[c].name<<endl;
		cout<<"学号："<<s[c].num<<endl;
		cout<<"英语："<<s[c].yingyu<<endl;
		cout<<"高等数学："<<s[c].gaodengshuxue<<endl;
		cout<<"离散数学："<<s[c].lisanshuxue<<endl; 
	    getchar();
		getchar();
		break;
	}
	if(b>i)
	{
	printf("输入有误！请重新输入！\n");
	getchar();
	getchar();
	}
	if(b==s[c].num)
	{
		cout<<"确定删除该学生信息? (Y/N) "<<endl;
		d=getchar();
		if(d=='Y')
		{
			for(e=c;e<i;e++)                    //删除数据后面每个往前移一位 
			{
			 strcpy(s[e].name,s[e+1].name); 
			 s[e].yingyu=s[e+1].yingyu;
			 s[e].gaodengshuxue=s[e+1].gaodengshuxue;
			 s[e].lisanshuxue=s[e+1].lisanshuxue;
			}
			i--;
			ofstream outfile("文件.txt",ios::binary);     //写入磁盘 
	        for(a=0;a<=i;a++)
            outfile.write((char*)&s[a],sizeof(s[a]));
			printf("成功删除！请继续！\n");
			getchar();
		}
		else
		printf("未删除！请重新操作！\n");
		getchar();
		getchar();
	}
	 zhucaidan();
}
//----------------------------------------------------------------
void xiugai()                                         
{ 
	system("cls");
	int a; 
	ifstream infile("文件.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
    printf("\n\n\t\t#                                              #\t\t\n"); 
    printf("\t\t#                                              #\t\t\n"); 
    printf("\t\t#                修改学生信息                  #\t\t\n"); 
    printf("\t\t#                                              #\t\t\n"); 
    printf("\t\t#                                              #\t\t\n");
	printf("\t\t请输入要修改的学生学号：");
	int b,c;
    cin>>b;
	for(c=0;c<i;c++)
	if(b==s[c].num)
	{
		cout<<"姓名："<<s[c].name<<endl;
		cout<<"学号："<<s[c].num<<endl;
		cout<<"英语："<<s[c].yingyu<<endl;
		cout<<"高等数学："<<s[c].gaodengshuxue<<endl;
		cout<<"离散数学："<<s[c].yingyu<<endl; 
		getchar();
	    getchar();
	    printf("\n\n请输入修改信息：\n"); 
        printf("姓名：");
	    cin>>s[c].name;
	    printf("英语成绩：");
        cin>>s[c].yingyu;
      	printf("高等数学成绩：");
        cin>>s[c].gaodengshuxue;
      	printf("离散数学成绩：");
        cin>>s[c].lisanshuxue;
        ofstream outfile("shuju.dat",ios::binary);      //文件流 
	    for(a=0;a<=i;a++)
        outfile.write((char*)&s[a],sizeof(s[a]));
        printf("修改成功！"); 
	    getchar();
		getchar();
		break;
	}
	if(c>=i)
	{
	printf("输入有误！请重新输入！\n");
	getchar();
	getchar();
	xiugai();
	}
    zhucaidan();
}
//-------------------------------------------------------------------

void chazhao();              

void chazhao1()              
{
	system("cls");
	int c,d;
	printf("请输入学号："); 
	cin>>c;
	for(d=0;d<=i;d++)
	if(c==s[d].num)
	{
		cout<<"姓名："<<s[d].name<<endl;
		cout<<"学号："<<s[d].num<<endl;
		cout<<"英语："<<s[d].yingyu<<endl;
		cout<<"高等数学："<<s[d].gaodengshuxue<<endl;
		cout<<"离散数学："<<s[d].lisanshuxue<<endl; 
		break;		
	}
	if(d>i)
	{
	printf("输入有误！！\n");
    }
	getchar();
	getchar();
    chazhao();
}
void chazhao2()               
{
	system("cls");
	char c[20];
	int d;
	printf("请输入姓名："); 
	cin>>c;
	for(d=0;d<=i;d++)
	if(!strcmp(c,s[d].name))
	{
		cout<<"姓名："<<s[d].name<<endl;
		cout<<"学号："<<s[d].num<<endl;
		cout<<"英语："<<s[d].yingyu<<endl;
		cout<<"高等数学："<<s[d].gaodengshuxue<<endl;
		cout<<"离散数学："<<s[d].lisanshuxue<<endl; 
		getchar();
		getchar();
		break;
	}
	if(strcmp(c,s[d].name))
	{
	printf("输入有误！请重新操作！\n");
	getchar();
	getchar();
    }
    chazhao();
}
void chazhao()              
{
   system("cls");
    int a;
	ifstream infile("文件.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
   printf("\n\n\n\t\t#                                              #\t\t\n"); 
   printf("\t\t#                1.按学号查找                  #\t\t\n"); 
   printf("\t\t#                                              #\t\t\n"); 
   printf("\t\t#                2.按姓名查找                  #\t\t\n"); 
   printf("\t\t#                                              #\t\t\n"); 
   printf("\t\t#                3.退出查找                    #\t\t\n"); 
   printf("\t\t#                                              #\t\t\n"); 
   int b;
   printf("\t\t请输入选项：");
   scanf("%d",&b);
   switch(b)
   {
   	case 1:
   	 chazhao1();
   	case 2:
     chazhao2();break;
    case 3:
     break;break;
    default:
	 chazhao();break;
   }
   zhucaidan();   	
}
//------------------
void chakan()
{
    int a;
    system("cls");
    ifstream infile("文件.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
   printf("\n\n所有学生成绩：\n\n\n");
   for(a=0;a<i;a++)
  {
    cout<<"学号："<<s[a].num<<"       ";
	cout<<"姓名："<<s[a].name<<"    ";	
	cout<<"英语："<<s[a].yingyu<<"    ";
	cout<<"高等数学："<<s[a].gaodengshuxue<<"    ";		
	cout<<"离散数学："<<s[a].lisanshuxue<<endl<<endl;
  }
  getchar();
  getchar();
  zhucaidan();
}
//----------------------------
void paixu()                                        //排序函数 使用冒泡法排序 
{
	system("cls");
	int a;
	ifstream infile("文件.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
   printf("\n\n\t                                                \t\n");
   printf("\t                        成绩排序                    \t\n"); 
   printf("\t                                                    \t\n");  
   printf("\t                      1.按英语成绩                  \t\n"); 
   printf("\t                                                    \t\n"); 
   printf("\t                      2.按高等数学成绩              \t\n"); 
   printf("\t                                                    \t\n"); 
   printf("\t                      3.按离散数学成绩              \t\n"); 
   printf("\t                                                    \t\n");
   printf("\t                      4.退出排序                    \t\n");  
   printf("\t                                                    \t\n"); 
   printf("\t       请输入选项：");
   cin>>a;
   int b,c,d,e;
   switch(a)
   {
   	case 1:
   	{
	   for(b=0;b<i;b++)
       for(c=i-1;c>=b;c--)
   	 {
	   	if(s[c].yingyu<s[c+1].yingyu)
	   	{
	   		m[1]=s[c];
	   		s[c]=s[c+1];
	   		s[c+1]=m[1];
	   	}
      }
      printf("\n按英语排序：\n\n");
      for(d=0;d<i;d++)
      {
      	cout<<"姓名："<<s[d].name<<"     ";
		cout<<"学号："<<s[d].num<<"   ";
		cout<<"英语："<<s[d].yingyu<<"   ";
		cout<<"高等数学："<<s[d].gaodengshuxue<<"   ";
		cout<<"离散数学："<<s[d].lisanshuxue<<endl<<endl; 
      }
      ifstream infile("文件.txt",ios::binary);  //数组中数据已为降序 
	  for(e=0;e<=i;e++)                          //故再次读入数据到数组 
	  infile.read((char*)&s[e],sizeof(s[e]));    //下同
	  infile.close();
	  getchar();
	  getchar();
	  paixu();break;
   	}
   	case 2:
   	{
	   for(b=0;b<i;b++)
       for(c=i-1;c>=b;c--)
   	 {
	   	if(s[c].gaodengshuxue<s[c+1].gaodengshuxue)
	   	{
	   		m[1]=s[c];
	   		s[c]=s[c+1];
	   		s[c+1]=m[1];
	   	}
      }
      printf("\n按高等数学排序：\n\n");
      for(d=0;d<i;d++)
      {
      	cout<<"姓名："<<s[d].name<<"     ";
		cout<<"学号："<<s[d].num<<"   ";
		cout<<"英语："<<s[d].yingyu<<"   ";
		cout<<"高等数学："<<s[d].gaodengshuxue<<"   ";		
		cout<<"离散数学："<<s[d].lisanshuxue<<endl<<endl; 
      }
      ifstream infile("文件.txt",ios::binary);
	  for(e=0;e<=i;e++)
	  infile.read((char*)&s[e],sizeof(s[e]));
	  infile.close();
	  getchar();
	  getchar();
	  paixu();break;
	  }
   	case 3:
	{
	   for(b=0;b<i;b++)
       for(c=i-1;c>=b;c--)
   	 {
	   	if(s[c].lisanshuxue<s[c+1].lisanshuxue)
	   	{
	   		m[1]=s[c];
	   		s[c]=s[c+1];
	   		s[c+1]=m[1];
	   	}
      }
      printf("\n按离散数学排序：\n\n");
      for(d=0;d<i;d++)
      {
      	cout<<"姓名："<<s[d].name<<"     ";
		cout<<"学号："<<s[d].num<<"   ";
		cout<<"英语："<<s[d].yingyu<<"   ";
		cout<<"高等数学："<<s[d].gaodengshuxue<<"   ";
		cout<<"离散数学："<<s[d].lisanshuxue<<endl<<endl;		 
      }
      ifstream infile("文件.txt",ios::binary);
	  for(e=0;e<=i;e++)
	  infile.read((char*)&s[e],sizeof(s[e]));
	  infile.close();
	  getchar();
	  getchar();
	  paixu();break;
	  } 
    case 4:
     break;
	default:
	 paixu();break;
    }
	zhucaidan();
}
//------------------------------ 
void tongji()                          
{
	system("cls");
	int a;
	ifstream infile("文件.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
   printf("\n\n\t                                                  \t\n");
   printf("\t                         成绩统计                     \t\n"); 
   printf("\t                                                      \t\n");  
   printf("\t                        1.英语成绩                    \t\n"); 
   printf("\t                                                      \t\n"); 
   printf("\t                        2.高等数学成绩                \t\n"); 
   printf("\t                                                      \t\n"); 
   printf("\t                        3.离散数学成绩                \t\n"); 
   printf("\t                                                      \t\n");
   printf("\t                        4.退出统计                    \t\n");  
   printf("\t                                                      \t\n"); 
   printf("\t       请输入选项：");
   cin>>a;
   int b,c,d,e=0;
   switch(a)
   {
   	case 1:
   	 printf("\n\n\n请输入统计的分数段：（如：a,b）");
   	 scanf("%d,%d",&b,&c);
   	 printf("\n该分数段学生：\n");
   	 for(d=0;d<i;d++)
		{
			if(s[d].yingyu>=b&&s[d].yingyu<=c)
			{
				cout<<"学号："<<s[d].num<<"       ";
	            cout<<"姓名："<<s[d].name<<"    ";	
	            cout<<"英语："<<s[d].yingyu<<"    ";
				cout<<"高等数学："<<s[d].gaodengshuxue<<"    ";	            		
	            cout<<"离散数学："<<s[d].lisanshuxue<<endl<<endl;
	            e++;
			}
		}
	printf("\n共计人数：");
	cout<<e; 
 	  getchar();
	  getchar();
	  tongji();break;  
   	case 2:
   	 printf("\n\n\n请输入统计的分数段：（如：a,b）");
   	 scanf("%d,%d",&b,&c);
   	 printf("\n该分数段学生：\n");
   	 for(d=0;d<i;d++)
		{
			if(s[d].gaodengshuxue>=b&&s[d].gaodengshuxue<=c)
			{
				cout<<"学号："<<s[d].num<<"       ";
	            cout<<"姓名："<<s[d].name<<"    ";	
	            cout<<"英语："<<s[d].yingyu<<"    ";
	            cout<<"高等数学："<<s[d].gaodengshuxue<<"    ";		
	            cout<<"离散数学："<<s[d].lisanshuxue<<endl<<endl;
	            e++;
			}
		}
	printf("\n共计人数：");
	cout<<e; 
 	  getchar();
	  getchar();
	  tongji();break;
   	case 3:
   	 printf("\n\n\n请输入统计的分数段：（如：a,b）");
   	 scanf("%d,%d",&b,&c);
   	 printf("\n该分数段学生：\n");
   	 for(d=0;d<i;d++)
		{
			if(s[d].lisanshuxue>=b&&s[d].lisanshuxue<=c)
			{
				cout<<"学号："<<s[d].num<<"       ";
	            cout<<"姓名："<<s[d].name<<"    ";	
	            cout<<"英语："<<s[d].yingyu<<"    ";
	            cout<<"高等数学："<<s[d].gaodengshuxue<<"    ";		
	            cout<<"离散数学："<<s[d].lisanshuxue<<endl<<endl;
	            e++;
			}
		}
	printf("\n共计人数：");
	cout<<e; 
 	  getchar();
	  getchar();
	  tongji();break;
   	case 4:
   	break; 
   } 
   zhucaidan();
}
//------------------------------------
void zhucaidan()                                   
{
	char a;
	system("cls");
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY| FOREGROUND_BLUE);
	printf("\n\n\n\n\n");
    printf("\t                                                              \n"); 
	printf("\t                                                              \n"); 
	printf("\t           a.增加学生信息                                     \n");
	printf("\t           b.删除学生信息                                     \n ");
	 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);  
	printf("\t           c.修改学生信息                                     \n"); 
	printf("\t           d.查找学生信息                                     \n");
	 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("\t           e.学生分数排序                                      \n");
	printf("\t           f.查找学生信息                                      \n");
	printf("\t           g.学生成绩统计                                      \n"); 
	printf("\t                                                               \n");
	printf("\t  请输入选项：");
	a=getchar();
//-------------------------------------------
   switch(a)
   {
  	case 'a':
   	zengjia();break; 
   	case 'b':
   	shanchu();break;
   	case 'c':
   	xiugai();break;
   	case 'd':
   	chazhao();break;
   	case 'e':
   	paixu();break;
 	case 'f':
   	chakan();break;
   	case 'g':
   	tongji();break;
	default:
   	zhucaidan();break;
   	
   }
}
//------------------------------------------
int main()
{
	int a;
	jiemian();
	ifstream infile("文件.txt",ios::binary);
    for(a=0;a<=29;a++)
    infile.read((char*)&s[a],sizeof(s[a]));
    for(i=0;s[i].num!=0;i++);
	zhucaidan();		
	return 0;
}
