#include<stdio.h>
#include<math.h>
#include <conio.h>
#include <process.h>
#define n 3//ѧУ��Ŀ  
#define m 2//������Ŀ��Ŀ 
#define w 1//Ů����Ŀ��Ŀ
#define null 0

typedef struct
{ 
	int itemnum; //��Ŀ���
    int top;    //ȡ���ε���Ŀ
    int range[5]; //����
    int mark[5];  //����
}itemnode;   //������Ŀ��������

typedef struct
{
	int dai;
	int schoolname;
	int schoolnum;   //ѧУ���
    int score;    //ѧУ�ܷ�
    int mscore;   //�������ܷ�
    int wscore;   //Ů�����ܷ�
    itemnode c[m+w];   //��Ŀ����
}headnode;//����ͷ�������

headnode h[n];//����һ��ͷ�������

void inputinformation()  //������Ϣ������ϵͳ
{
	int i,j,k,s;
    for(i=0;i<n;i++)
    { 
		h[i].score=0;
        h[i].mscore=0;
        h[i].wscore=0;
	}                                            //��ʼ��ͷ���
    for(i=0;i<n;i++)
    { 
		printf("*****ѧУ����:");
        scanf("%s",&h[i].schoolname);
		printf("*****ѧУ���:");
        scanf("%d",&h[i].schoolnum);               //����ͷ�����Ϣ
        for(j=0;j<m+w;j++)
		{  
			printf("*****��Ŀ���:");
            scanf("%d",&h[i].c[j].itemnum);
		    printf("*****ȡǰ3��orǰ5��:");
            scanf("%d",&h[i].c[j].top);
            printf("*****��ü������Σ�");
            scanf("%d",&k);                      //������Ŀ��Ϣ
            for(s=0;s<5;s++)
            h[i].c[j].range[s]=0, h[i].c[j].mark[s]=0;  //��ʼ�������ͷ���
            for(s=0;s<k;s++)
			{       
				printf("*****����:");
                scanf("%d",&h[i].c[j].range[s]);     //��������������Ϣ
                if(h[i].c[j].top==3)
                switch(h[i].c[j].range[s])
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
//��ȡǰ��������ȡǰ�����ֱ�Ƿ�
                if(j<=m-1)
					h[i].mscore=h[i].mscore+h[i].c[j].mark[s];
//��������Ŀ��ǵ����ӷ�������ȥ
                else
			        h[i].wscore=h[i].wscore+h[i].c[j].mark[s];
//��Ů����Ŀ��ǵ�Ů����Ŀ����ȥ
			}
		    printf("\n");
        }
    }
}

void output()     //�������
{ 
    int choice,i,j,k;
    
    int sign;
    do
    {
        printf("*******************1.��ѧУ������.*******************\n");
        printf("*******************2.��ѧУ�������.*******************\n");
        printf("*******************3.��ѧУ�ܷ����.*******************\n");
        printf("*******************4.�������ܷ����.*******************\n");
        printf("*******************5.��Ů���ܷ����.*******************\n");
        printf("\n\n******************* ��ѡ����*************************\n\n:");
        scanf("%d",&choice);
        switch(choice)
        { 
        case 1:
            printf("ѧУ���  ѧУ����  ѧУ�ܷ�  �����ܷ�  Ů���ܷ�\n");
            for(i=0;i<n;i++)
            { 
                printf("%8d %8s %8d %8d %8d\n",h[i].schoolnum,h[i].schoolname,h[i].score,h[i].mscore,h[i].wscore);
             
            }                                    //�����˳�����
            break;

        case 2:    
            printf("ѧУ����  ѧУ���  ѧУ�ܷ�  �����ܷ�  Ů���ܷ�\n");
            for(i=0;i<n;i++)
            { 
                printf("%8s %8d %8d %8d %8d\n",h[i].schoolname,h[i].schoolnum,h[i].score,h[i].mscore,h[i].wscore);

        	
            }                                   //��ѧУ�������
            break;    
        	
        case 3:      
            printf("ѧУ����  ѧУ�ܷ�  ѧУ����  ѧУ���  �����ܷ�  Ů���ܷ�\n");
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
                            printf("��%d�� %12d %8s %8d %8d %8d \n",i+1,h[j].score,h[j].schoolname,h[j].schoolnum,h[j].mscore,h[j].wscore);
        	}
                                   //��ѧУ�ܷ����
            break;


        case 4:      
            printf("ѧУ����  �����ܷ�    ѧУ����  ѧУ���  ѧУ�ܷ�  Ů���ܷ�\n");
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
                            printf("��%d�� %12d %8s %8d %8d %8d \n",i+1,h[j].mscore,h[j].schoolname,h[j].schoolnum,h[j].score,h[j].wscore);
        	}
                                              //�������ܷ����
            break;

       case 5:       
           printf("ѧУ����  Ů���ܷ�    ѧУ����  ѧУ���  ѧУ�ܷ�  �����ܷ�\n");
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
                            printf("��%d�� %12d %8s %8d %8d %8d \n",i+1,h[j].mscore,h[j].schoolname,h[j].schoolnum,h[j].score,h[j].mscore);
        	}
           break;                                //��Ů���ܷ����
        }
        printf("��ѡ��  2 ����,0 ����\n");
        scanf("%d",&sign);
    }while(sign==2);                             //ѭ��ִ��������
}


void inquiry()                                            //��ѯ����
{
	int  choice;
	int  i,j,k,s;
	printf("\n*****1:��ѧУ��Ų�ѯ\n");
	printf("\n*****2:����Ŀ��Ų�ѯ\n");
	printf("\n\n*****��ѡ���ѯ��ʽ:");                //�ṩ���ֲ�ѯ��ʽ
    scanf("%d",&choice);
    switch(choice)
    {  
	 case 1:
        do
		{ 
			printf("Ҫ��ѯ��ѧУ���:");
			scanf("%d",&i);
			if(i>n)
				printf("�������ѧУû�вμӴ˴��˶���!\n\n\n");
		    else
			{
				printf("Ҫ��ѯ����Ŀ���:");
                scanf("%d",&j);
			    if(j>m+w||j==0)
				    printf("�˴��˶���û�������Ŀ\n\n\n");
//ѧУ��ų�����Χ�����������
			    else
				{  
printf("�����Ŀȡǰ %d��,��ѧУ�ĳɼ�����:\n", h[0].c[j-1].top);
				    for(k=0;k<5;k++)
				        if(h[i-1].c[j-1].range[k]!=0)
				            printf("����:%d\n",h[i-1].c[j-1].range[k]);
//���Ҫ��ѯѧУ��Ŀ�ĳɼ�
				 }
			}
            printf("��ѡ�� 2 ���� , 0 ����\n");
			scanf("%d",&s);
			printf("\n\n\n");
		}while(s==2);                       //ѭ��ִ��������
        break;                     
           
	case 2:
        do
		{ 
			printf("Ҫ��ѯ����Ŀ���:");
			scanf("%d",&s);
			if(s>m+w||s==0)
				printf("�˴��˶��᲻���������Ŀ.\n\n\n");
//��Ŀ��ų�����Χ���������
			else
			{
				printf("����Ŀȡǰ %d��,ȡ�����ε�ѧУ\n",h[0].c[s-1].top);
				for(i=0; i<n;i++)
				   for(j=0;j<5;j++)
				      if(h[i].c[s-1].range[j]!=0)
				      printf("ѧУ���:%d,����:%d\n",h[i].schoolnum,
h[i].c[s-1].range[j]);
            }                         //�������Ŀȡ������ѧУ�ĳɼ�
		    printf("\n\n\n���� 2,���� 0\n");
			scanf("%d",&i);
			printf("\n\n\n");

		}while(i==2);
	    break;
}
}

int  main()
{ 
	int choice;
	printf("======================��ӭʹ��======================\n");    printf("\n\n*****************�˶������ͳ��ϵͳ********************\n");
   printf("\n\n********************1.������Ϣ*************************\n");
printf("********************2.�����Ϣ*************************\n");
printf("********************3.��ѯ��Ϣ*************************\n");
   printf("********************4.�˳�ϵͳ*************************\n\n\n");
printf("================================================\n\n");
	printf("********��ѡ��Ҫʵ�ֲ���ı��:\n\n");
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
		printf("�����������������!");
		
    }
}

