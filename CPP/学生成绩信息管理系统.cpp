#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

struct student                               // �ṹ������ 
 {
 	char name[20];
    int num;
 	int yingyu;
 	int gaodengshuxue;
 	int lisanshuxue;
 };
int i;

student s[30],m[3];                       //����ṹ������ 

//--------------------------------------------

void jiemian()                            //��ʼ���� 
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
   printf("\n\n\n\n\n");
   printf("\t\t  **                                                  **  \t\t\n"); 
   printf("\t\t  **                                                  **  \t\t\n"); 
   printf("\t\t  **          ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ            **  \t\t\n"); 
   printf("\t\t  **                                                  **  \t\t\n"); 
   printf("\t\t  **                                                  **  \t\t\n"); 
   printf("\t\t���س����������ϵͳ��");
   getchar();
}
 //-----------------------------------------
 void zhucaidan();                   // ���˵����������� 
 
 
 void zengjia()                      // ���Ӻ��� 
{
    system("cls");
    int a;
    printf("\n��������Ҫ���ӵ�ѧ����Ϣ��\n");
    printf("������");
	cin>>s[i].name;
	printf("Ӣ��ɼ���");
    cin>>s[i].yingyu;
   	printf("�ߵ���ѧ�ɼ���");
    cin>>s[i].gaodengshuxue;
   	printf("��ɢ��ѧ�ɼ���");
    cin>>s[i].lisanshuxue;
    s[i].num=i+1;
    ofstream outfile("�ļ�.txt",ios::binary);      //�ļ��� 
	for(a=0;a<=i;a++)
    outfile.write((char*)&s[a],sizeof(s[a]));
    i++;
    outfile.close();
    printf("���ӳɹ�����");
    getchar();
	getchar(); 
    zhucaidan();
} 
//--------------------------------------------------
void shanchu()                                //ɾ������ 
{
	system("cls");
	int a; 
	ifstream infile("�ļ�.txt",ios::binary);     //�ļ��� �Ӵ����л�ȡ���� 
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
   printf("\n\n\t\t  **                                             **  \t\t\n"); 
   printf("\t\t  **                                                 **  \t\t\n"); 
   printf("\t\t  **                ɾ��ѧ���ɼ���Ϣ                 **  \t\t\n"); 
   printf("\t\t  **                                                 **  \t\t\n"); 
   printf("\t\t  **                                                 **  \t\t\n");
   printf("\t\t������Ҫɾ����ѧ��ѧ�ţ�");
   int b,c,d,e;
    cin>>b;                                       //��ѧ�Ų�ѯ 
	for(c=0;c<=i;c++)
	if(b==s[c].num)
	{
		cout<<"������"<<s[c].name<<endl;
		cout<<"ѧ�ţ�"<<s[c].num<<endl;
		cout<<"Ӣ�"<<s[c].yingyu<<endl;
		cout<<"�ߵ���ѧ��"<<s[c].gaodengshuxue<<endl;
		cout<<"��ɢ��ѧ��"<<s[c].lisanshuxue<<endl; 
	    getchar();
		getchar();
		break;
	}
	if(b>i)
	{
	printf("�����������������룡\n");
	getchar();
	getchar();
	}
	if(b==s[c].num)
	{
		cout<<"ȷ��ɾ����ѧ����Ϣ? (Y/N) "<<endl;
		d=getchar();
		if(d=='Y')
		{
			for(e=c;e<i;e++)                    //ɾ�����ݺ���ÿ����ǰ��һλ 
			{
			 strcpy(s[e].name,s[e+1].name); 
			 s[e].yingyu=s[e+1].yingyu;
			 s[e].gaodengshuxue=s[e+1].gaodengshuxue;
			 s[e].lisanshuxue=s[e+1].lisanshuxue;
			}
			i--;
			ofstream outfile("�ļ�.txt",ios::binary);     //д����� 
	        for(a=0;a<=i;a++)
            outfile.write((char*)&s[a],sizeof(s[a]));
			printf("�ɹ�ɾ�����������\n");
			getchar();
		}
		else
		printf("δɾ���������²�����\n");
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
	ifstream infile("�ļ�.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
    printf("\n\n\t\t#                                              #\t\t\n"); 
    printf("\t\t#                                              #\t\t\n"); 
    printf("\t\t#                �޸�ѧ����Ϣ                  #\t\t\n"); 
    printf("\t\t#                                              #\t\t\n"); 
    printf("\t\t#                                              #\t\t\n");
	printf("\t\t������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
	int b,c;
    cin>>b;
	for(c=0;c<i;c++)
	if(b==s[c].num)
	{
		cout<<"������"<<s[c].name<<endl;
		cout<<"ѧ�ţ�"<<s[c].num<<endl;
		cout<<"Ӣ�"<<s[c].yingyu<<endl;
		cout<<"�ߵ���ѧ��"<<s[c].gaodengshuxue<<endl;
		cout<<"��ɢ��ѧ��"<<s[c].yingyu<<endl; 
		getchar();
	    getchar();
	    printf("\n\n�������޸���Ϣ��\n"); 
        printf("������");
	    cin>>s[c].name;
	    printf("Ӣ��ɼ���");
        cin>>s[c].yingyu;
      	printf("�ߵ���ѧ�ɼ���");
        cin>>s[c].gaodengshuxue;
      	printf("��ɢ��ѧ�ɼ���");
        cin>>s[c].lisanshuxue;
        ofstream outfile("shuju.dat",ios::binary);      //�ļ��� 
	    for(a=0;a<=i;a++)
        outfile.write((char*)&s[a],sizeof(s[a]));
        printf("�޸ĳɹ���"); 
	    getchar();
		getchar();
		break;
	}
	if(c>=i)
	{
	printf("�����������������룡\n");
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
	printf("������ѧ�ţ�"); 
	cin>>c;
	for(d=0;d<=i;d++)
	if(c==s[d].num)
	{
		cout<<"������"<<s[d].name<<endl;
		cout<<"ѧ�ţ�"<<s[d].num<<endl;
		cout<<"Ӣ�"<<s[d].yingyu<<endl;
		cout<<"�ߵ���ѧ��"<<s[d].gaodengshuxue<<endl;
		cout<<"��ɢ��ѧ��"<<s[d].lisanshuxue<<endl; 
		break;		
	}
	if(d>i)
	{
	printf("�������󣡣�\n");
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
	printf("������������"); 
	cin>>c;
	for(d=0;d<=i;d++)
	if(!strcmp(c,s[d].name))
	{
		cout<<"������"<<s[d].name<<endl;
		cout<<"ѧ�ţ�"<<s[d].num<<endl;
		cout<<"Ӣ�"<<s[d].yingyu<<endl;
		cout<<"�ߵ���ѧ��"<<s[d].gaodengshuxue<<endl;
		cout<<"��ɢ��ѧ��"<<s[d].lisanshuxue<<endl; 
		getchar();
		getchar();
		break;
	}
	if(strcmp(c,s[d].name))
	{
	printf("�������������²�����\n");
	getchar();
	getchar();
    }
    chazhao();
}
void chazhao()              
{
   system("cls");
    int a;
	ifstream infile("�ļ�.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
   printf("\n\n\n\t\t#                                              #\t\t\n"); 
   printf("\t\t#                1.��ѧ�Ų���                  #\t\t\n"); 
   printf("\t\t#                                              #\t\t\n"); 
   printf("\t\t#                2.����������                  #\t\t\n"); 
   printf("\t\t#                                              #\t\t\n"); 
   printf("\t\t#                3.�˳�����                    #\t\t\n"); 
   printf("\t\t#                                              #\t\t\n"); 
   int b;
   printf("\t\t������ѡ�");
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
    ifstream infile("�ļ�.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
   printf("\n\n����ѧ���ɼ���\n\n\n");
   for(a=0;a<i;a++)
  {
    cout<<"ѧ�ţ�"<<s[a].num<<"       ";
	cout<<"������"<<s[a].name<<"    ";	
	cout<<"Ӣ�"<<s[a].yingyu<<"    ";
	cout<<"�ߵ���ѧ��"<<s[a].gaodengshuxue<<"    ";		
	cout<<"��ɢ��ѧ��"<<s[a].lisanshuxue<<endl<<endl;
  }
  getchar();
  getchar();
  zhucaidan();
}
//----------------------------
void paixu()                                        //������ ʹ��ð�ݷ����� 
{
	system("cls");
	int a;
	ifstream infile("�ļ�.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
   printf("\n\n\t                                                \t\n");
   printf("\t                        �ɼ�����                    \t\n"); 
   printf("\t                                                    \t\n");  
   printf("\t                      1.��Ӣ��ɼ�                  \t\n"); 
   printf("\t                                                    \t\n"); 
   printf("\t                      2.���ߵ���ѧ�ɼ�              \t\n"); 
   printf("\t                                                    \t\n"); 
   printf("\t                      3.����ɢ��ѧ�ɼ�              \t\n"); 
   printf("\t                                                    \t\n");
   printf("\t                      4.�˳�����                    \t\n");  
   printf("\t                                                    \t\n"); 
   printf("\t       ������ѡ�");
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
      printf("\n��Ӣ������\n\n");
      for(d=0;d<i;d++)
      {
      	cout<<"������"<<s[d].name<<"     ";
		cout<<"ѧ�ţ�"<<s[d].num<<"   ";
		cout<<"Ӣ�"<<s[d].yingyu<<"   ";
		cout<<"�ߵ���ѧ��"<<s[d].gaodengshuxue<<"   ";
		cout<<"��ɢ��ѧ��"<<s[d].lisanshuxue<<endl<<endl; 
      }
      ifstream infile("�ļ�.txt",ios::binary);  //������������Ϊ���� 
	  for(e=0;e<=i;e++)                          //���ٴζ������ݵ����� 
	  infile.read((char*)&s[e],sizeof(s[e]));    //��ͬ
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
      printf("\n���ߵ���ѧ����\n\n");
      for(d=0;d<i;d++)
      {
      	cout<<"������"<<s[d].name<<"     ";
		cout<<"ѧ�ţ�"<<s[d].num<<"   ";
		cout<<"Ӣ�"<<s[d].yingyu<<"   ";
		cout<<"�ߵ���ѧ��"<<s[d].gaodengshuxue<<"   ";		
		cout<<"��ɢ��ѧ��"<<s[d].lisanshuxue<<endl<<endl; 
      }
      ifstream infile("�ļ�.txt",ios::binary);
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
      printf("\n����ɢ��ѧ����\n\n");
      for(d=0;d<i;d++)
      {
      	cout<<"������"<<s[d].name<<"     ";
		cout<<"ѧ�ţ�"<<s[d].num<<"   ";
		cout<<"Ӣ�"<<s[d].yingyu<<"   ";
		cout<<"�ߵ���ѧ��"<<s[d].gaodengshuxue<<"   ";
		cout<<"��ɢ��ѧ��"<<s[d].lisanshuxue<<endl<<endl;		 
      }
      ifstream infile("�ļ�.txt",ios::binary);
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
	ifstream infile("�ļ�.txt",ios::binary);
	for(a=0;a<=i;a++)
	infile.read((char*)&s[a],sizeof(s[a]));
	infile.close();
   printf("\n\n\t                                                  \t\n");
   printf("\t                         �ɼ�ͳ��                     \t\n"); 
   printf("\t                                                      \t\n");  
   printf("\t                        1.Ӣ��ɼ�                    \t\n"); 
   printf("\t                                                      \t\n"); 
   printf("\t                        2.�ߵ���ѧ�ɼ�                \t\n"); 
   printf("\t                                                      \t\n"); 
   printf("\t                        3.��ɢ��ѧ�ɼ�                \t\n"); 
   printf("\t                                                      \t\n");
   printf("\t                        4.�˳�ͳ��                    \t\n");  
   printf("\t                                                      \t\n"); 
   printf("\t       ������ѡ�");
   cin>>a;
   int b,c,d,e=0;
   switch(a)
   {
   	case 1:
   	 printf("\n\n\n������ͳ�Ƶķ����Σ����磺a,b��");
   	 scanf("%d,%d",&b,&c);
   	 printf("\n�÷�����ѧ����\n");
   	 for(d=0;d<i;d++)
		{
			if(s[d].yingyu>=b&&s[d].yingyu<=c)
			{
				cout<<"ѧ�ţ�"<<s[d].num<<"       ";
	            cout<<"������"<<s[d].name<<"    ";	
	            cout<<"Ӣ�"<<s[d].yingyu<<"    ";
				cout<<"�ߵ���ѧ��"<<s[d].gaodengshuxue<<"    ";	            		
	            cout<<"��ɢ��ѧ��"<<s[d].lisanshuxue<<endl<<endl;
	            e++;
			}
		}
	printf("\n����������");
	cout<<e; 
 	  getchar();
	  getchar();
	  tongji();break;  
   	case 2:
   	 printf("\n\n\n������ͳ�Ƶķ����Σ����磺a,b��");
   	 scanf("%d,%d",&b,&c);
   	 printf("\n�÷�����ѧ����\n");
   	 for(d=0;d<i;d++)
		{
			if(s[d].gaodengshuxue>=b&&s[d].gaodengshuxue<=c)
			{
				cout<<"ѧ�ţ�"<<s[d].num<<"       ";
	            cout<<"������"<<s[d].name<<"    ";	
	            cout<<"Ӣ�"<<s[d].yingyu<<"    ";
	            cout<<"�ߵ���ѧ��"<<s[d].gaodengshuxue<<"    ";		
	            cout<<"��ɢ��ѧ��"<<s[d].lisanshuxue<<endl<<endl;
	            e++;
			}
		}
	printf("\n����������");
	cout<<e; 
 	  getchar();
	  getchar();
	  tongji();break;
   	case 3:
   	 printf("\n\n\n������ͳ�Ƶķ����Σ����磺a,b��");
   	 scanf("%d,%d",&b,&c);
   	 printf("\n�÷�����ѧ����\n");
   	 for(d=0;d<i;d++)
		{
			if(s[d].lisanshuxue>=b&&s[d].lisanshuxue<=c)
			{
				cout<<"ѧ�ţ�"<<s[d].num<<"       ";
	            cout<<"������"<<s[d].name<<"    ";	
	            cout<<"Ӣ�"<<s[d].yingyu<<"    ";
	            cout<<"�ߵ���ѧ��"<<s[d].gaodengshuxue<<"    ";		
	            cout<<"��ɢ��ѧ��"<<s[d].lisanshuxue<<endl<<endl;
	            e++;
			}
		}
	printf("\n����������");
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
	printf("\t           a.����ѧ����Ϣ                                     \n");
	printf("\t           b.ɾ��ѧ����Ϣ                                     \n ");
	 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);  
	printf("\t           c.�޸�ѧ����Ϣ                                     \n"); 
	printf("\t           d.����ѧ����Ϣ                                     \n");
	 SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("\t           e.ѧ����������                                      \n");
	printf("\t           f.����ѧ����Ϣ                                      \n");
	printf("\t           g.ѧ���ɼ�ͳ��                                      \n"); 
	printf("\t                                                               \n");
	printf("\t  ������ѡ�");
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
	ifstream infile("�ļ�.txt",ios::binary);
    for(a=0;a<=29;a++)
    infile.read((char*)&s[a],sizeof(s[a]));
    for(i=0;s[i].num!=0;i++);
	zhucaidan();		
	return 0;
}
