#include<stdio.h>
#include<math.h>
#include <conio.h>
#include <WINDOWS.H>
#include <process.h>
#define n 3//学院数目  
#define m 2//卫生项目数目 
#define w 1//早操项目数目
#define null 0
#define pf printf("系统正在加载");for(int i = 0; i < 5;i++){Sleep(500);printf(".");}printf("\n");system("cls");

typedef struct//结构体变量
{ 
	int itemnum; //项目编号
    int top;    //取名次的数目
    int range[5]; //名次
    int mark[5];  //分数
}itemnode;   //定义项目结点的类型

typedef struct
{
	int dai;
	int schoolname;
	int schoolnum;   //学院编号
    int score;    //学院总分
    int mscore;   //卫生体总分
    int wscore;   //早操体总分
    itemnode c[m+w];   //项目数组
}headnode;//定义头结点类型跟类中定义成员数据类似

headnode h[n];//定义一个头结点数组

void inputinformation()  //输入信息，建立系统
{
	int i,j,k,s;
    for(i=0;i<n;i++)
    { 
		h[i].score=0;
        h[i].mscore=0;
        h[i].wscore=0;
	}                                            //初始化头结点
    for(i=0;i<n;i++)
    { 
		printf("*****学院名称:");
        scanf("%d",&h[i].schoolname);
		printf("*****学院编号:");
        scanf("%d",&h[i].schoolnum);               //输入头结点信息
        for(j=0;j<m+w;j++)
		{  
			printf("*****项目编号:");
            scanf("%d",&h[i].c[j].itemnum);
		    printf("*****取前3名or前5名:");
            scanf("%d",&h[i].c[j].top);
            printf("*****获得几个名次：");
            scanf("%d",&k);                      //输入项目信息
            for(s=0;s<5;s++)
            h[i].c[j].range[s]=0, h[i].c[j].mark[s]=0;  //初始化排名和分数
            for(s=0;s<k;s++)
			{       
				printf("*****名次:");
                scanf("%d",&h[i].c[j].range[s]);     //输入所获名次信息
                if(h[i].c[j].top==3)
                switch(h[i].c[j].range[s])//h是headnode的对象，C是headnode中的结构体成员，ranges是itemnode中的数据成员，这就是结构体中的嵌套调用
                {
                case 0: h[i].c[j].mark[s]=0; break;
                case 1: h[i].c[j].mark[s]=5; break;
                case 2: h[i].c[j].mark[s]=3; break;
                case 3: h[i].c[j].mark[s]=2; break;
                }
                else
                switch(h[i].c[j].range[s])
				{
                 case 0: h[i].c[j].mark[s]=0; break;
                 case 1: h[i].c[j].mark[s]=7; break;
                 case 2: h[i].c[j].mark[s]=5; break;
                 case 3: h[i].c[j].mark[s]=3; break;
                 case 4: h[i].c[j].mark[s]=2; break;
                 case 5: h[i].c[j].mark[s]=1; break;
                 }
                         
                h[i].score=h[i].score+h[i].c[j].mark[s];
//按取前三名还是取前五名分别记分
                if(j<=m-1)
					h[i].mscore=h[i].mscore+h[i].c[j].mark[s];
//是卫生项目则记到卫生分数里面去
                else
			        h[i].wscore=h[i].wscore+h[i].c[j].mark[s];
//是早操项目则记到早操项目里面去
			}
		    printf("\n");
        }
    }
}

void output()     //输出函数
{ 
    int choice,i,j,k;
    
    int sign;
    do
    {
        printf("*******************1.按学院编号输出.*******************\n");
        printf("*******************2.按学院名称输出.*******************\n");
        printf("*******************3.按学院总分输出.*******************\n");
        printf("*******************4.按卫生总分输出.*******************\n");
        printf("*******************5.按早操总分输出.*******************\n");
        printf("\n\n******************* 请选择编号*************************\n\n:");
        scanf("%d",&choice);
        switch(choice)
        { 
        case 1:
            printf("学院编号  学院名称  学院总分  卫生总分  早操总分\n");
            for(i=0;i<n;i++)
            { 
                printf("%8d %8d %8d %8d %8d\n",h[i].schoolnum,h[i].schoolname,h[i].score,h[i].mscore,h[i].wscore);
             
            }                                    //按编号顺序输出
            break;

        case 2:    
            printf("学院编号  学院名称  学院总分  卫生总分  早操总分\n");
            for(i=0;i<n;i++)
            { 
                printf("%8d %8d %8d %8d %8d\n",h[i].schoolname,h[i].schoolnum,h[i].score,h[i].mscore,h[i].wscore);

        	
            }                                   //按学院名称输出
            break;    
        	
        case 3:      
            printf("学院名次  学院总分  学院名称  学院编号  卫生总分  早操总分\n");
            for(i=0;i<n;i++)
        	{
                h[i].dai=h[i].score;
        	}
            
            for(i=0;i<n;i++)
            { 
                for(j=0;j<n-i;j++)
                    if(h[j].dai<h[j+1].dai)
        			{
                        k=h[j].dai;h[j].dai=h[j+1].dai;h[j+1].dai=k;
        			}
            }
            
            for(i=0;i<n;i++)
        	{
                for(j=0;j<n;j++)
                    if(h[j].score==h[i].dai)
                            printf("第%d名 %12d %8d %8d %8d %8d \n",i+1,h[j].score,h[j].schoolname,h[j].schoolnum,h[j].mscore,h[j].wscore);
        	}
                                   //按学院总分输出
            break;
        case 4:      
            printf("学院名次  卫生总分    学院名称  学院编号  学院总分  早操总分\n");
            for(i=0;i<n;i++)
            h[i].dai=h[i].mscore;
            for(i=0;i<n;i++)
            { 
                for(j=0;j<n-i;j++)
                    if(h[j].dai<h[j+1].dai)
                        k=h[j].dai;h[j].dai=h[j+1].dai;h[j+1].dai=k;
            }
            for(i=0;i<n;i++)
        	{
                for(j=0;j<n;j++)
                    if(h[j].mscore==h[i].dai)
                            printf("第%d名 %12d %8d %8d %8d %8d \n",i+1,h[j].mscore,h[j].schoolname,h[j].schoolnum,h[j].score,h[j].wscore);
        	}
                                              //按卫生总分输出
            break;

       case 5:       
           printf("学院名次  早操总分    学院名称  学院编号  学院总分  卫生总分\n");
           for(i=0;i<n;i++)
            h[i].dai=h[i].wscore;
            for(i=0;i<n;i++)
            { 
                for(j=0;j<n-i;j++)
                    if(h[j].dai<h[j+1].dai)
                        k=h[j].dai;h[j].dai=h[j+1].dai;h[j+1].dai=k;
            }
            for(i=0;i<n;i++) 
        	{
                for(j=0;j<n;j++)
                    if(h[j].wscore==h[i].dai)
                            printf("第%d名 %12d %d %8d %8d %8d \n",i+1,h[j].mscore,h[j].schoolname,h[j].schoolnum,h[j].score,h[j].mscore);
        	}
           break;                                //按早操总分输出
        }
        printf("请选择  2 继续,0 跳出\n");
        scanf("%d",&sign);
    }while(sign==2);                             //循环执行输出语句
}


void inquiry()                                            //查询函数
{
	int  choice;
	int  i,j,k,s;
	printf("\n*****1:按学院编号查询\n");
	printf("\n*****2:按项目编号查询\n");
	printf("\n\n*****请选择查询方式:");                //提供两种查询方式
    scanf("%d",&choice);
    switch(choice)
    {  
	 case 1:
        do
		{ 
			printf("要查询的学院编号:");
			scanf("%d",&i);
			if(i>n)
				printf("错误：这个学院没有参加此次卫生竞赛!\n\n\n");
		    else
			{
				printf("要查询的项目编号:");
                scanf("%d",&j);
			    if(j>m+w||j==0)
				    printf("此次卫生竞赛没有这个项目\n\n\n");
//学院编号超出范围，则输出警告
			    else
				{  
printf("这个项目取前 %d名,该学院的成绩如下:\n", h[0].c[j-1].top);
				    for(k=0;k<5;k++)
				        if(h[i-1].c[j-1].range[k]!=0)
				            printf("名次:%d\n",h[i-1].c[j-1].range[k]);
//输出要查询学院项目的成绩
				 }
			}
            printf("请选择 2 继续 , 0 跳出\n");
			scanf("%d",&s);
			printf("\n\n\n");
		}while(s==2);                       //循环执行输出语句
        break;                     
           
	case 2:
        do
		{ 
			printf("要查询的项目编号:");
			scanf("%d",&s);
			if(s>m+w||s==0)
				printf("此次卫生竞赛不包括这个项目.\n\n\n");
//项目编号超出范围则输出警告
			else
			{
				printf("该项目取前 %d名,取得名次的学校\n",h[0].c[s-1].top);
				for(i=0; i<n;i++)
				   for(j=0;j<5;j++)
				      if(h[i].c[s-1].range[j]!=0)
				      printf("学院编号:%d,名次:%d\n",h[i].schoolnum,
h[i].c[s-1].range[j]);//结构题的嵌套调用
            }                         //输出该项目取得名次学院的成绩
		    printf("\n\n\n继续 2,跳出 0\n");
			scanf("%d",&i);
			printf("\n\n\n");

		}while(i==2);
	    break;
}
}

int  main()
{ 
	pf;
	int choice;
	printf("======================欢迎使用======================\n");   
	printf("\n\n*****************卫生分数统计系统********************\n"); 
	printf("\n\n********************1.输入信息*************************\n"); 
	printf("********************2.输出信息*************************\n");  
	printf("********************3.查询信息*************************\n"); 
	printf("********************4.退出系统*************************\n\n\n"); 
	printf("================================================\n\n"); 
	printf("********请选择要实现步骤的编号:\n\n");
	scanf("%d",&choice);
	
	switch(choice)
	{ 
	case 1: 
		inputinformation();main();
    case 2: 
		output();main();
    case 3: 
		inquiry();main();
    case 4: 
		exit(0);
    default: 
		printf("输入错误请重新输入!");
		
    }
	return 0;
}
