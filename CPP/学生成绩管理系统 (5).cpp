#include "stdio.h"    /*I/O函数*/
#include "bios.h"  /*ROM基本输入输出函数*/
#include "stdlib.h"   /*其它说明*/
#include "dos.h"    /*dos接口函数*/
#include "string.h"   /*字符串函数*/
#include "conio.h"   /*屏幕操作函数*/
#include "mem.h"   /*内存操作函数*/
#include "ctype.h"   /*字符操作函数*/
#include "alloc.h"   /*动态地址分配函数*/
#define N 3       /*定义常数*/
typedef struct z1   /*定义数据结构*/
{
   char no[11];
   char name[15];
   int score[N];
   float sum;
   float average;
   int order;
   struct z1 *next;
 }STUDENT;
/*以下是函数原型*/
STUDENT  *init();      /*初始化函数*/
STUDENT *create();   /*创建链表*/
STUDENT *delete(STUDENT *h);   /*删除记录*/
void print(STUDENT *h);   /* 显示所有记录*/
void search(STUDENT *h);    /*查找*/
void save(STUDENT *h);     /*保存*/
STUDENT *load();        /*读入记录*/
void computer(STUDENT *h);  /*计算总分和平均分*/
STUDENT *insert(STUDENT *h);   /*插入记录*/
void append();            /*追加记录*/
void copy();            /*复制文件*/
STUDENT *sort(STUDENT *h);    /*排序*/
STUDENT *index(STUDENT *h);  /*索引*/
void auther();        /*版本信息*/ 
void total(STUDENT *h);       /*分类合计*/
int menu_select();            /*菜单函数*/
/******主函数开始*******/
main()
{
   int i;
   STUDENT *head;     /*链表定义头指针*/
   head=init();          /*初始化链表*/

   printf("\n\n\n\n\n\n\n\n\n");
   printf("\t\t \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
   printf("\t\t \6     Welcome to the students-score System!    \6 \n");
   printf("\t\t \6             ---Chen Tian Lin---              \6 \n");
   printf("\t\t \4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
   for(;;)             /*无限循环*/
   {
      switch(menu_select())     /*调用主菜单函数，返回值整数作开关语句的条件*/
      {                     /*值不同，执行的函数不同，break 不能省略*/
     case 0:head=init();break;   /*执行初始化*/
     case 1:head=create();break; /*创建链表*/
     case 2:head=delete(head);break; /*删除记录*/
     case 3:print(head);break;   /*显示全部记录*/
     case 4:search(head);break;  /*查找记录*/
     case 5:save(head);break;  /*保存文件*/
     case 6:head=load(); break;  /*读文件*/
     case 7:computer(head);break;  /*计算总分和均分*/
     case 8:head=insert(head);  break; /*插入记录*/
     case 9:copy();break;    /*复制文件*/
     case 10:head=sort(head);break;  /*排序*/
     case 11:append();break;     /*追加记录*/
     case 12:head=index(head);break;  /*索引*/
     case 13:total(head);break;   /*分类合计*/
     case 14:exit(0);       /*如菜单返回值为14程序结束*/
     case 15:auther();     /*版本信息*/
      }
   }
}
/*菜单函数，返回值为整数*/
menu_select()
{
   char *f[]={"\2\2\1\1\1\1\1\1\1\1\1 SCORES MENU \1\1\1\1\1\1\1\1\1\2\2",  /*定义菜单字符串数组*/
   " 0. init list    ",    /*初始化*/
   " 1. Enter list    ",   /*输入记录*/
   " 2. Delete a record from list    ",  /*从表中删除记录*/
   " 3. print list ",       /*显示单链表中所有记录*/
   " 4. Search record on name        ",   /*按照姓名查找记录*/
   " 5. Save the file                 ",          /*将单链表中记录保存到文件中*/
   " 6. Load the file                  ",         /*从文件中读入记录*/
   " 7. computer the score",    /*计算所有学生的总分和均分*/
   " 8. insert record to list ",   /*插入记录到表中*/
   " 9. copy the file to new file",   /*复制文件*/
   "10. sort to make new file",   /*排序*/
   "11. append  record to file",   /*追加记录到文件中*/
   "12. index on nomber",       /*索引*/
   "13. total on nomber",      /*分类合计*/
   "14. Quit " ,                   /*退出*/
   "15. auther ", /*版本信息*/
   "\5\3\5 Enter the * to return when need ! \5\3\5",
   };
   char s[80];    /*以字符形式保存选择号*/
   int  i;
   int key=0; /*记录所压键值*/
   int c=0;
   gotoxy(25,25); /*移动光标*/
   printf("press any key enter menu......\n");/*压任意键进入主菜单*/
   getch();
   clrscr();  /*清屏*/
   textcolor(YELLOW ); /*设置文本颜色为黄色*/
   textbackground(BLUE );  /*设置背景颜色为蓝色*/
   gotoxy(10,2);
   putch(0xda); /*输出左上角边框┏*/
   for(i=1;i<53;i++)
   putch(0xc4); /*输出上边框水平线*/
   putch(0xbf); /*输出右上角边框  ┓*/
   for(i=3;i<22;i++)/*输出左右两边的垂直线*/
   {
      gotoxy(10,i);putch(0xb3);
      gotoxy(63,i);putch(0xb3);
   }
   gotoxy(10,22);putch(0xc0); /*输出左下角边框┗*/
   for(i=1;i<53;i++)
      putch(0xc4);  /*输出下边框水平线*/
   putch(0xd9);  /*输出右下角边框┛*/
   window(11,3,62,21); /* 制作显示菜单的窗口，大小根据菜单条数设计*/
   clrscr();   /*清屏*/
   for(i=0;i<18;i++)
   {
      gotoxy(10,i+1);
      cprintf("%s",f[i]); /*输出菜单项数组*/
   }
   i=1;
   gotoxy(10,2);  /*设置默认选项在第一项*/
   textbackground(BLINK );/*设置背景颜色为浅绿*/
   cprintf("%s",f[1]);  /*输出菜单项，表示选中*/
   gotoxy(10,2);  /*移动光标到菜单的第一项*/

   while(key!=13)   /*所压键不是回车键时*/
   {
      while(bioskey(1)==0);  /*查询是否压下了一个键*/
      key=bioskey(0);   /*返回下一个在键盘压下的键*/
      key=key&0xff?key&0xff:key>>8; /*对所压的键进行判断*/
      gotoxy(10,i+1);
      textbackground(BLUE);/*设置背景颜色为蓝色*/
      cprintf("%s",f[i]);  /*输出菜单项*/
      if(key==72) i=i==1?16:i-1; /*如压向上光标键↑，i减1，如已到第一行再上移，则到最后一行*/
      if(key==80)i=i==16?1:i+1; /*如压向下光标键↓，i加1，如已到最后一行再下移，则到第一行*/
      gotoxy(10,i+1); /*光标移动i的下一项*/
      textbackground(LIGHTRED); /*将背景颜色设为浅红*/
      cprintf("%s",f[i]);  /*输出菜单项*/
      c=i-1;  /*给代表菜单选项的整数赋值*/
   }
   textbackground(CYAN );  /*设置背景颜色为青色*/
   window(1,1,80,25);  /*恢复原窗口大小*/
   return c;  /*返回代表菜单选项的整数值*/
}

 STUDENT *init()
{ return NULL;}
    

/*1创建链表*/
STUDENT *create()
{
   int i; int s;
   STUDENT *h=NULL,*info;  /* STUDENT指向结构体的指针*/
   for(;;)
   {
      info=(STUDENT *)malloc(sizeof(STUDENT));  /*申请空间*/
      if(!info)   /*如果指针info为空*/
      {
     printf("\nout of memory");   /*输出内存溢出*/
     return NULL;           /*返回空指针*/
      }
      inputs("enter no:",info->no,11);   /*输入学号并校验*/
      if(info->no[0]=='*') break;    /*如果学号首字符为@则结束输入*/
      inputs("enter name:",info->name,15); /*输入姓名，并进行校验*/
      printf("please input %d score \n",N);  /*提示开始输入成绩*/
      s=0;         /*计算每个学生的总分，初值为0*/
      for(i=0;i<N;i++)    /*N门课程循环N次*/
      {
     do{
        printf("score%d:",i+1);    /*提示输入第几门课程*/
        scanf("%d",&info->score[i]);    /*输入成绩*/
        if(info->score[i]>100||info->score[i]<0) /*确保成绩在0~100之间*/
        printf("bad data,repeat input\n");  /*出错提示信息*/  
     }while(info->score[i]>100||info->score[i]<0);
     s=s+info->score[i];   /*累加各门课程成绩*/
      }
      info->sum=s;    /*将总分保存*/
      info->average=(float)s/N;  /*求出平均值*/
      info->order=0;    /*未排序前此值为0*/
      info->next=h;   /*将头结点做为新输入结点的后继结点*/
      h=info;    /*新输入结点为新的头结点*/
   }
   return(h);   /*返回头指针*/
}
/*2输入字符串，并进行长度验证*/
inputs(char *prompt, char *s, int count)
{
   char p[255];
   clrscr();   /*清屏*/
   do{printf("No.  name  yu wen  shu xue  ying yu /Enter the * to return when need\n");
      printf(prompt);  /*显示提示信息*/
      scanf("%s",p);  /*输入字符串*/
      if(strlen(p)>count)printf("\n too long! \n"); /*进行长度校验，超过count值重输入*/
   }while(strlen(p)>count);
   strcpy(s,p); /*将输入的字符串拷贝到字符串s中*/
}
/*3输出链表中结点信息*/
void print(STUDENT *h)
{
   int i=0;     /* 统计记录条数*/
   STUDENT *p;  /*移动指针*/
   clrscr();     /*清屏*/
   p=h;      /*初值为头指针*/
   printf("\n\n\n***************************STUDENT SCORES**************************************\n");
   printf("| rec|nO        |      name     |yu wen|shu xue|ying yu|   sum  |  ave  |order|\n");
   printf("|----|----------|---------------|------|-------|-------|--------|-------|-----|\n");
   while(p!=NULL)
   {
       i++;
       printf("|%3d |%-10s|%-15s|%6d|%7d|%7d| %4.2f | %4.2f | %3d |\n", i, p->no,p->name,p->score[0],p->score[1],
p->score[2],p->sum,p->average,p->order);
       p=p->next;
   }
   printf("**********************************end******************************************\n");
}
/*4删除记录*/
STUDENT *delete(STUDENT *h)
{
   STUDENT *p,*q;  /*p为查找到要删除的结点指针，q为其前驱指针*/
   char s[11];     /*存放学号*/
   clrscr();       /*清屏*/
   printf("please deleted no  \n");      /*显示提示信息*/
   scanf("%s",s);   /*输入要删除记录的学号*/
   q=p=h;    /*给q和p赋初值头指针*/
   while(strcmp(p->no,s)&&p!=NULL)   /*当记录的学号不是要找的，或指针不为空时*/
   {
      q=p;       /*将p指针值赋给q作为p的前驱指针*/
      p=p->next;      /*将p指针指向下一条记录*/
   }
   if(p==NULL)     /*如果p为空，说明链表中没有该结点*/
      printf("\nlist no %s student\n",s);
   else       /*p不为空，显示找到的记录信息*/
   {
      printf("*****************************have found***********************************\n");
      printf("|no        |      name     |yu wen|shu xue|ying yu|   sum  |  ave  |order|\n");
      printf("|----------|---------------|------|-------|-------|--------|-------|-----|\n");
      printf("|%-10s|%-15s|%6d|%7d|%7d| %4.2f | %4.2f | %3d |\n", p->no,
       p->name,p->score[0],p->score[1],p->score[2],p->sum,
       p->average,p->order);
      printf("********************************end***************************************\n");
      getch();      /*压任一键后，开始删除*/
      if(p==h)    /*如果p==h，说明被删结点是头结点*/
     h=p->next;     /*修改头指针指向下一条记录*/
      else
     q->next=p->next; /*不是头指针，将p的后继结点作为q的后继结点*/
      free(p);          /*释放p所指结点空间*/
      printf("\n have deleted No %s student\n",s);
      printf("Don't forget save\n");/*提示删除后不要忘记保存文件*/
   }
   return(h);      /*返回头指针*/
}
/*5查找记录*/
void search(STUDENT *h)
{
   STUDENT *p;    /*  移动指针*/
   char s[15];    /*存放姓名的字符数组*/
   clrscr();    /*清屏幕*/
   printf("please enter name for search\n");
   scanf("%s",s);    /*输入姓名*/
   p=h;    /*将头指针赋给p*/
   while(strcmp(p->name,s)&&p!=NULL)  /*当记录的姓名不是要找的，或指针不为空时*/
   p=p->next;     /*移动指针，指向下一结点*/
   if(p==NULL)         /*如果指针为空*/
      printf("\nlist no %s student\n",s);   /*显示没有该学生*/
   else           /*显示找到的记录信息*/
   {
      printf("\n\n*****************************havefound************************************\n");
      printf("|nO        |      name     |yu wen|shu xue|ying yu|   sum  |  ave  |order|\n");
      printf("|----------|---------------|------|-------|-------|--------|-------|-----|\n");
      printf("|%-10s|%-15s|%6d|%7d|%7d| %4.2f | %4.2f | %3d |\n", p->no,
p->name,p->score[0],p->score[1],p->score[2],p->sum,p->average,p->order);
      printf("********************************end***************************************\n");
   }
}
/*6插入记录*/
STUDENT  *insert(STUDENT *h)
{
   STUDENT *p,*q,*info; /*p指向插入位置，q是其前驱，info指新插入记录*/
   char s[11];  /*保存插入点位置的学号*/
   int s1,i;
   clrscr();   /*清屏幕*/
   printf("please enter location  before the no /Enter the * to return when need\n");
   scanf("%s",s);   /*输入插入点学号*/
   printf("\nplease new record\n");      /*提示输入记录信息*/
   info=(STUDENT *)malloc(sizeof(STUDENT));   /*申请空间*/
   if(!info)
   {
      printf("\nout of memory");   /*如没有申请到，内存溢出*/
      return NULL;             /*返回空指针*/
   }
   inputs("enter no:",info->no,11); /*输入学号*/
   inputs("enter name:",info->name,15); /*输入姓名*/
   printf("please input %d score \n",N);  /*提示输入分数*/
   s1=0;    /*保存新记录的总分，初值为0*/
   for(i=0;i<N;i++)    /*N门课程循环N次输入成绩*/
   {
      do{        /*对数据进行验证，保证在0~100之间*/
     printf("score%d:",i+1);
     scanf("%d",&info->score[i]);
     if(info->score[i]>100||info->score[i]<0)
        printf("bad data,repeat input\n");
      }while(info->score[i]>100||info->score[i]<0);
      s1=s1+info->score[i];    /*计算总分*/
   }
   info->sum=s1;    /*将总分存入新记录中*/
   info->average=(float)s1/N;  /*计算均分*/
   info->order=0;         /*名次赋值0*/
   info->next=NULL;     /*设后继指针为空*/
   p=h;               /*将指针赋值给p*/
   q=h;             /*将指针赋值给q*/
   while(strcmp(p->no,s)&&p!=NULL)    /*查找插入位置*/
   {
      q=p;                 /*保存指针p，作为下一个p的前驱*/
      p=p->next;          /*将指针p后移*/
   }
   if(p==NULL)      /*如果p指针为空，说明没有指定结点*/
      if(p==h)      /*同时p等于h，说明链表为空*/
     h=info;   /*新记录则为头结点*/
      else
     q->next=info;  /*p为空，但p不等于h，将新结点插在表尾*/
   else
      if(p==h)     /*p不为空，则找到了指定结点*/
      {
     info->next=p; /*如果p等于h，则新结点插入在第一个结点之前*/
     h=info;    /*新结点为新的头结点*/
      }
      else
      {
     info->next=p;   /*不是头结点，则是中间某个位置，新结点的后继为p*/
     q->next=info;  /*新结点作为q的后继结点*/
      }
   printf("\n ----have inserted %s student----\n",info->name);    printf("---Don't forget save---\n");     /*提示存盘*/
   return(h);         /*返回头指针*/
}
/*7保存数据到文件*/
void save(STUDENT *h)
{
   FILE *fp;         /*定义指向文件的指针*/
   STUDENT *p;    /* 定义移动指针*/
   char outfile[10];  /*保存输出文件名*/
   clrscr();            /*清屏*/
   printf("Enter outfile name,for example c:\\f1\\te.txt: /Enter the * to return when need \n"); /*提示文件名格式信息*/
   scanf("%s",outfile);
   if((fp=fopen(outfile,"wb"))==NULL) /*为输出打开一个二进制文件，如没有则建立*/
   {
      printf("can not open file\n");
      exit(1);
   }
   printf("\nSaving file......\n");  /*打开文件，提示正在保存*/
   p=h;                    /*移动指针从头指针开始*/
   while(p!=NULL)        /*如p不为空*/
   {
      fwrite(p,sizeof(STUDENT),1,fp);/*写入一条记录*/
      p=p->next;        /*指针后移*/
   }
   fclose(fp);      /*关闭文件*/
   printf("-----save success!!-----\n");  /*显示保存成功*/
}
/* 8从文件读数据*/
STUDENT *load()
{
   STUDENT *p,*q,*h=NULL;    /*定义记录指针变量*/
   FILE *fp;            /* 定义指向文件的指针*/
   char infile[10];       /*保存文件名*/
   clrscr();       /*清屏*/
   printf("Enter infile name,for example c:\\f1\\te.txt:\n");   scanf("%s",infile);           /*输入文件名*/
   if((fp=fopen(infile,"rb"))==NULL)   /*打开一个二进制文件，为读方式*/
   {
      printf("can not open file\n");    /*如不能打开，则结束程序*/
      exit(1);
   }
   printf("\n -----Loading file!-----\n");
   p=(STUDENT *)malloc(sizeof(STUDENT));   /*申请空间*/
   if(!p)
   {
      printf("out of memory!\n");    /*如没有申请到，则内存溢出*/
      return h;       /*返回空头指针*/
   }
   h=p;         /*申请到空间，将其作为头指针*/
   while(!feof(fp))  /*循环读数据直到文件尾结束*/
   {
      if(1!=fread(p,sizeof(STUDENT),1,fp))
     break;  /*如果没读到数据，跳出循环*/
      p->next=(STUDENT *)malloc(sizeof(STUDENT));  /*为下一个结点申请空间*/
      if(!p->next)
      {
     printf("out of memory!\n");  /*如没有申请到，则内存溢出*/
     return h;
      }
      q=p;   /*保存当前结点的指针，作为下一结点的前驱*/
      p=p->next;   /*指针后移，新读入数据链到当前表尾*/
   }
   q->next=NULL;   /*最后一个结点的后继指针为空*/
   fclose(fp);       /*关闭文件*/
   printf("---You have success read data from file!!!---\n");
   return h;   /*返回头指针*/
}
/*9追加记录到文件*/
void append()
{
   FILE *fp;      /*定义指向文件的指针*/
   STUDENT *info;    /*新记录指针*/
   int s1,i;
   char infile[10];    /*保存文件名*/
   clrscr();       /*清屏*/
   printf("\nplease new record /Enter the * to return when need\n");
   info=(STUDENT *)malloc(sizeof(STUDENT));   /*申请空间*/
   if(!info)
   {
      printf("\nout of memory");   /*没有申请到，内存溢出本函数结束*/
      return ;
   }
   inputs("enter no:",info->no,11);    /*调用inputs输入学号*/
   inputs("enter name:",info->name,15); /*调用inputs输入姓名*/
   printf("please input %d score \n",N);   /*提示输入成绩*/
   s1=0;
   for(i=0;i<N;i++)
   {
      do{
     printf("score%d:",i+1);
     scanf("%d",&info->score[i]);  /*输入成绩*/
     if(info->score[i]>100||info->score[i]<0)printf("bad data,repeat input\n");
      }while(info->score[i]>100||info->score[i]<0); /*成绩数据验证*/
      s1=s1+info->score[i];      /*求总分*/
   }
   info->sum=s1;      /*保存总分*/
   info->average=(float)s1/N;  /*求均分*/
   info->order=0;      /*名次初始值为0*/
   info->next=NULL;  /*将新记录后继指针赋值为空*/
   printf("Enter infile name,for example c:\\f1\\te.txt:\n");    scanf("%s",infile);         /*输入文件名*/
   if((fp=fopen(infile,"ab"))==NULL)  /*向二进制文件尾增加数据方式打开文件*/
   {
      printf("can not open file\n");   /*显示不能打开*/
      exit(1);             /*退出程序*/
   }
   printf("\n -----Appending record!-----\n");
   if(1!=fwrite(info,sizeof(STUDENT),1,fp))   /*写文件操作*/
   {
      printf("-----file write error!-----\n");
      return;              /*返回*/
   }
   printf("-----append  sucess!!----\n");
   fclose(fp);       /*关闭文件*/
}
/*10文件拷贝*/
void copy()
{
   char outfile[10],infile[10];
   FILE *sfp,*tfp;        /*源和目标文件指针*/
   STUDENT *p=NULL;   /*移动指针*/
   clrscr();    /*清屏*/
   printf("Enter infile name,for example c:\\f1\\te.txt:\n");
   scanf("%s",infile);         /*输入源文件名*/
   if((sfp=fopen(infile,"rb"))==NULL)   /*二进制读方式打开源文件*/
   {
      printf("can not open input file\n");
      exit(0);
   }
   printf("Enter outfile name,for example c:\\f1\\te.txt:\n");   /*提示输入目标文件名*/
   scanf("%s",outfile);  /*输入目标文件名*/
   if((tfp=fopen(outfile,"wb"))==NULL)  /*二进制写方式打开目标文件*/
   {
      printf("can not open output file \n");
      exit(0);
   }
   while(!feof(sfp))   /*读文件直到文件尾*/
   {
      if(1!=fread(p,sizeof(STUDENT),1,sfp))
     break; /*块读*/
      fwrite(p,sizeof(STUDENT),1,tfp);   /*块写*/
   }
   fclose(sfp);    /*关闭源文件*/
   fclose(tfp);   /*关闭目标文件*/
   printf("you have success copy  file!!!\n");   /*显示成功拷贝*/
}
/*11排序*/
STUDENT *sort(STUDENT *h)
{
   int i=0;                  /*保存名次*/
   STUDENT *p,*q,*t,*h1;   /*定义临时指针*/
   h1=h->next;           /*将原表的头指针所指的下一个结点作头指针*/
   h->next=NULL;        /*第一个结点为新表的头结点*/    clrscr();       /*清屏*/
   while(h1!=NULL)    /*当原表不为空时，进行排序*/
   {
      t=h1;            /*取原表的头结点*/
      h1=h1->next;     /*原表头结点指针后移*/
      p=h;           /*设定移动指针p，从头指针开始*/
      q=h;         /*设定移动指针q做为p的前驱，初值为头指针*/
      while(t->sum<p->sum&&p!=NULL)  /*作总分比较*/
      {
     q=p;            /*待排序点值小，则新表指针后移*/
     p=p->next;
      }
      if(p==q)      /*p==q，说明待排序点值大，应排在首位*/
      {
     t->next=p;     /*待排序点的后继为p*/
     h=t;         /*新头结点为待排序点*/
      }
      else    /*待排序点应插入在中间某个位置q和p之间，如p为空则是尾部*/
      {
     t->next=p;   /*t的后继是p*/
     q->next=t;    /*q的后继是t*/
      }
   }
   p=h;               /*已排好序的头指针赋给p，准备填写名次*/
   while(p!=NULL)  /*当p不为空时，进行下列操作*/
   {
      i++;       /*结点序号*/
      p->order=i;   /*将名次赋值*/
      p=p->next;   /*指针后移*/
   }
   printf("sort sucess!!!\n");   /*排序成功*/
   return h;      /*返回头指针*/
}
/*12计算总分和均值*/
void computer(STUDENT *h)
{
   STUDENT *p;   /*定义移动指针*/
   int i=0;  /*保存记录条数初值为0*/
   long s=0;   /*总分初值为0*/
   float average=0;  /*均分初值为0*/
   clrscr();            /*清屏*/
   p=h;        /*从头指针开始*/
   while(p!=NULL)    /*当p不为空时处理*/
   {
      s+=p->sum;    /*累加总分*/
      i++;         /*统计记录条数*/
      p=p->next;   /*指针后移*/
   }
   average=(float)s/i;/* 求均分，均分为浮点数，总分为整数，所以做类型转换*/
   printf("\n--All students sum score is:%ld  average is %5.2f\n",s,average);
}
/*13索引*/
STUDENT *index(STUDENT *h)
{
   STUDENT *p,*q,*t,*h1;  /*定义临时指针*/
   h1=h->next;    /*将原表的头指针所指的下一个结点作头指针*/
   h->next=NULL;   /*第一个结点为新表的头结点*/
   clrscr();    /*清屏*/
   while(h1!=NULL)  /*当原表不为空时，进行排序*/
   {
      t=h1;        /*取原表的头结点*/
      h1=h1->next;   /*原表头结点指针后移*/
      p=h;   /*设定移动指针p，从头指针开始*/
      q=h;   /*设定移动指针q做为p的前驱，初值为头指针*/
      while(strcmp(t->no,p->no)>0&&p!=NULL)  /*作学号比较*/
      {
     q=p;           /*待排序点值大，应往后插，所以新表指针后移*/
     p=p->next;
      }
      if(p==q)   /*p==q，说明待排序点值小，应排在首位*/
      {
     t->next=p;  /*待排序点的后继为p*/
     h=t;    /*新头结点为待排序点*/
      }
      else     /*待排序点应插入在中间某个位置q和p之间，如p为空则是尾部*/
      {
     t->next=p;    /*t的后继是p*/
     q->next=t;     /*q的后继是t*/
      }
   }
   printf("index sucess!!!\n");  /*索引排序成功*/
   return h;    /*返回头指针*/
}
/*14分类合计*/
void total(STUDENT *h)
{
   STUDENT *p,*q;   /*定义临时指针变量*/
   char sno[9],qno[9],*ptr;    /*保存班级号的*/
   float s1,ave;        /*保存总分和均分*/
   int i;       /*保存班级人数*/
   clrscr();    /*清屏*/
   printf("\n\n  *******************Total*****************\n");
   printf("---class---------sum--------------average----\n");
   p=h;       /*从头指针开始*/
   while(p!=NULL)  /*当p不为空时做下面的处理*/
   {
      memcpy(sno,p->no,8);  /*从学号中取出班级号*/
      sno[8]='\0';          /*做字符串结束标记*/
      q=p->next;        /*将指针指向待比较的记录*/
      s1=p->sum;      /*当前班级的总分初值为该班级的第一条记录总分*/
      ave=p->average;  /*当前班级的均分初值为该班级的第一条记录均分*/
      i=1;          /*统计当前班级人数*/
      while(q!=NULL)   /*内循环开始*/
      {
     memcpy(qno,q->no,8);   /*读取班级号*/
     qno[8]='\0';     /*做字符串结束标记*/
     if(strcmp(qno,sno)==0)  /*比较班级号*/
     {
        s1+=q->sum;     /*累加总分*/
        ave+=q->average; /*累加均分*/
        i++;         /*累加班级人数*/
        q=q->next;   /*指针指向下一条记录*/
     }
     else
        break;  /*不是一个班级的结束本次内循环*/
      }
      printf("%s     %10.2f           %5.2f\n",sno,s1,ave/i);
      if(q==NULL)
     break;   /*如果当前指针为空，外循环结束，程序结束*/
      else
     p=q;   /*否则，将当前记录作为新的班级的第一条记录开始新的比较*/
   }
   printf("---------------------------------------------\n");
}
   void auther()  /*15版本信息*/
{      
clrscr(); /*清除屏幕*/
printf("\n\n\n\n\n"); 
printf("\t\t\t****************************\n");
printf("\t\t\t     NAME : CHEN TIAN LIN \n");
printf("\t\t\t****************************\n");
printf("\t\t\t    L.NUM : 3107006878 \n");
printf("\t\t\t DIRECTOR : TAN TAI ZHE \n");
printf("\t\t\t SOFTWARE ENGINEERING 4 \n");
printf("\t\t\t COMPUTER COLLEGE \n");
printf("\t\t\t GDUT.Guangdong.China.Asia.\n");
printf("\t\t\t TIME :2008.2.25 \n");
printf("\t\t\t****************************\n");
  printf("\t\t\t     \1\1\1 Hello Welcome \1\1\1\n");
    printf("\t\t \1\1\1\1\1\1\1\1                          \1\1\1\1\1\1\1\1   \n");
    printf("\t\t \1       *******          *       *       \1   \n");
    printf("\t\t \1          *          ******* *******    \1   \n");
    printf("\t\t \1    *************    *  *  *  * * *     \1   \n");
    printf("\t\t \1       *      *     *   *   *   *   *   \1   \n");
    printf("\t\t \1\1\1\1\1\1\1\1                          \1\1\1\1\1\1\1\1   \n");

printf("\t\t\t       \2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\n");
 
    }
