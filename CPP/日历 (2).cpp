//�����׼ͷ�ļ�
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
//�Զ��庯��
int IsLeapYear(int year );
int qudeDay(int year,int month);
int  main()
{
int a;a=1;
int IsLeapYear(int);// �ú����ж��Ƿ�Ϊ����
 int i;
 int day;
 int year,month;
 int temp;
 int temp_i;
 long int Year_days = 0;/*ͳ�ƴӹ�Ԫ��һ��������*/
 long int Year_Start = 1;//�ӹ�Ԫ1�꿪ʼ
int Per_Year_Days;
int month_day[]={31,28,31,30,31,30,31,31,30,31,30,31,29};// ������洢ÿ���µ�����,��Ϊ����,����������һ������ʾ
char str1[]="123456";
char str2[7];
char str3[7];
    printf("������������֤\n");
	for(i=0;i<3;i++)
	{   gets(str2);
		if(strcmp(str1,str2)==0)
		{printf("��ӭʹ������ϵͳ\n");break;}
         else
	        printf("����������\n");
	}
    if(i==3)
	{printf("��������㲻��ʹ������ϵͳ�������µ���\n");
	return 0;}//ͨ��������֤������ϵͳ��������������������ܽ���ϵͳ

do
{
printf("\n\t\t********************************************** \n");
printf("\n\t\t*****************����ϵͳ********************** \n");
printf("\n\t\t***************1.������ѯ********************* \n");
printf("\n\t\t***************2.�޸����� ********************* \n");
printf("\n\t\t***************3.�˳�************************* \n");
printf("\n\t\t********************************************** \n\n\n");
printf("������ѡ�1-3����");
scanf("%d",&a);
switch(a)
{
case 1:

 printf("������ѯ\n");
 printf("Please enter the year,the temp : ");
 scanf("%d%d",&year,&month);// ������ݺ��·�
 while(Year_Start < year) //�ӹ�Ԫ1�꿪ʼִ��whileѭ��, �����һ��һ��Ϊ����һ

 {
  if( IsLeapYear( Year_Start ) )
   Per_Year_Days = 366; //���������, ��һ����366��
  else
   Per_Year_Days = 365; //�����������, ��һ����365��

  Year_days = Year_days + Per_Year_Days; //Year_daysΪ�ӹ�Ԫ1�굽������ݵ�ǰһ//����������ܺ�

  Year_Start++;
 }

 for( temp = 1; temp <month; temp++ ) //temp��1�µ�ָ�����ҵ��·�֮ǰ�����и���, //��Ӧ�ۼ�����

 {
	 day=1;
	 if( IsLeapYear(year) && temp == 2) //��Ϊ������Ϊ2�£����������Ϊ29��
   while( day <= month_day[12] )
   {
    Year_days++;
	day++;
    }
  else
   while (day <= month_day[temp-1])
   {
    Year_days++;
	day++;

   }
 }
  i = Year_days % 7; //ÿ��������7��, ����ÿ���������7ȡ��//��Ϊ��Ԫ//1���1��1��Ϊ����һ,������������Year_days����7����//���������Ǹ����������,����Ϊ0��Ϊ������

  printf("Mon Tue Wed Thu Fri Sat Sun\n");//��ӡһ�����Ŀո�,�Ա������Ӧ������
if( i != 0 )//���������Ϊ��
   for( temp_i = 0; temp_i < i; temp_i++)
    printf("    ");//���ӡ�ո�ո���Ϊi
  day = 1;//��ʼ��dayΪ1, Ϊ�����whileѭ����׼��
  if( IsLeapYear(year) && month == 2)//�����������������, �����·�Ϊ2
   while( day <= month_day[12] )//dayΪһѭ������, ȡֵΪ1-365(����Ļ�Ϊ1-366)
   {
    if( day >1 )//�����������һ
     if( Year_days % 7 == 0 )//�����������, ����
      printf("\n");
    if( day >= 10 )//��ӡ����+�ո�
    // %3dΪ��ʽ��������,%d��ʾ�������ʮ������
    // ����d��ǰ�����һ������,���ʾ�ø����ֵĿ����
    // �����Ӧ������ʾ������,�����������ֵĶ���
     printf("%d  ",day);
    else//���������"��������������, �����·�Ϊ2"
     printf("%d   ",day);
    Year_days++;// ÿ���һ��,������������1
    day++; // ���µ���������1
   }
  else
   while (day <= month_day[month-1])
   {
    if( day > 1 )
     if( Year_days % 7 == 0 )
      printf("\n");
    if( day >=10 )
     printf("%d  ",day);
    else
     printf("%d   ",day);
    Year_days++;
    day++;
   }
  printf("\n");
  getch();

	system("pause");
	system("cls");
	break;
case 2:
    printf("���������޸ĵ�����\n");
    fflush(stdin);//���֮ǰ���洢������
    gets(str3);
    strcpy(str1,str3);//�������븴�Ƹ�str1
	printf("���������Ϊ��%s\n",str1);
	system("pause");
	system("cls");
	break;

case 3:
     printf("�˳�");
	 break;
}
}while(a!=3);
}
int IsLeapYear ( int year ) //�ж��Ƿ�Ϊ����, ���򷵻�1, ���򷵻�0
//����������Ҫ��������������棩
{
 if ((year %4 == 0) && (year % 100 != 0) || (year % 400 == 0) )
 return 1;
 else
  return 0;
}


int chaxunday (int year,int month, int day)//��ѯ����

{

system("cls");

printf("��������Ҫ��ѯ������(��2012 3 )��");

scanf("%d%d",&year,&month);
return 0;
}
