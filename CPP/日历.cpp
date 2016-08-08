#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <string.h>
#include <iostream>
#include <windows.h>
using namespace std;

#define jz  for(int i = 0;i <5; i++){printf(".");Sleep(500);}
#define cxjz printf("系统正在为您查询");jz;system("cls");
#define jr printf("系统正在进行加载");jz;system("cls");


int a=1;
int IsLeapYear(int);// 该函数判断是否为闰年
int i;
int day;
int year,month;
int temp;
int temp_i;
long int Year_days = 0;/*统计从公元起一共多少天*/
long int Year_Start = 1;//从公元1年开始
int Per_Year_Days;
int month_day[]= {31,28,31,30,31,30,31,31,30,31,30,31,29}; // 该数组存储每个月的天数,若为闰年,则二月由最后一个数表示

int IsLeapYear(int year );

int qudeDay(int year,int month);


void nianyue(int year,int month )
{
    // 输入年份和月份
    while(Year_Start < year) //从公元1年开始执行while循环, 该年的一月一号为星期一

    {
        if( IsLeapYear( Year_Start ) )
            Per_Year_Days = 366; //如果是闰年, 则一年有366天
        else
            Per_Year_Days = 365; //如果不是闰年, 则一年有365天

        Year_days = Year_days + Per_Year_Days; //Year_days为从公元1年到输入年份的前一//年的天数的总和

        Year_Start++;
    }

    for( temp = 1; temp <month; temp++ ) //temp从1月到指定查找的月份之前的所有个月, //对应累加天数

    {
        day=1;
        if( IsLeapYear(year) && temp == 2) //若为闰年且为2月，则该月天数为29天
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
    i = Year_days % 7; //每个星期有7天, 故用每年的天数对7取余//因为公元//1年的1月1日为星期一,所以用总天数Year_days除以7所得//的余数就是该天的星期数,余数为0则为星期天

    printf("Mon Tue Wed Thu Fri Sat Sun\n");//打印一定量的空格,以便对齐相应的星期
    if( i != 0 )//如果余数不为零
    {

        for( temp_i = 0; temp_i < i; temp_i++)
            printf("    ");//则打印空格空格数为i
    }
    day = 1;//初始化day为1, 为下面的while循环做准备
    if( IsLeapYear(year) && month == 2)//如果输入的年份是闰年, 并且月份为2
    {
        while( day <= month_day[12] )//day为一循环变量, 取值为1-365(闰年的话为1-366)
        {
            if( day >1 )//如果天数大于一
                if( Year_days % 7 == 0 )//如果是星期日, 则换行
                    printf("\n");
            if( day >= 10 )//打印天数+空格
                // %3d为格式化输出语句,%d表示输出的是十进制数
                // 若在d的前面加上一个数字,则表示用该数字的宽度来
                // 输出相应参数表示的内容,这样便于数字的对齐
                printf("%d  ",day);
            else//如果不满足"输入的年份是闰年, 并且月份为2"
                printf("%d   ",day);
            Year_days++;// 每输出一天,则总天数增加1
            day++; // 该月的天数增加1
        }
    }
    else
    {
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
    }
}

void nian(int year )
{
    system("cls");
    for(int i = 1; i <= 12; i++)
    {
        printf("\n%10d月\n",i);
        nianyue(year,i);
    }
    system("pause");
    system("cls");
}

void nianyueshu(int year,int t1,int t2)
{
    system("cls");
    for(int i = t1; i <= t2; i++)
    {
        printf("\n%10d月\n",i);
        nianyue(year,i);
    }
    system("pause");
    system("cls");
}

int main()
{
    int year,month;
    char str1[]="123456";
    char str2[7];
    char str3[7];
    printf("\n\n\n\t\t    欢迎进入日历查询系统");
    printf("\n\n\t\t\t请输入密码:");
    for(i=0; i<3; i++)
    {
        gets(str2);
        if(strcmp(str1,str2)==0)
        {
            system("cls");
            system("color 0d");
            jr;
            printf("欢迎使用日历系统\n");
            break;
        }
        else
            printf("\t\t密码错误！请重新输入：");
    }
    if(i==3)
    {
        system("color 0c");
        printf("密码错误，你不能使用日历系统，请重新登入\n");
        return 0;
    }//通过密码验证来进入系统，输入密码错误三次则不能进入系统
    do
    {
        system("color 0d");
        printf("\n\t\t********************************************** \n");
        printf("\n\t\t*****************日历系统********************* \n");
        printf("\n\t\t***************1.按年月查询******************* \n");
        printf("\n\t\t***************2.按年份查询******************* \n");
        printf("\n\t\t***************3.按范围查询 ****************** \n");
        printf("\n\t\t***************4.修改密码 ******************** \n");
        printf("\n\t\t***************5.退出************************* \n");
        printf("\n\t\t********************************************** \n\n\n");
        printf("请输入选项（1-5）：");
        scanf("%d",&a);
        switch(a)
        {
        case 1:
            system("cls");
            system("color 02");
            printf("日历查询\n");
            printf("请输入年&月: ");
            cin>>year>>month;
            system("cls");
            cxjz;
            printf("查询结果为：\n");
            nianyue(year,month);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            system("color 04");
            printf("请输入想修改的密码\n");
            fflush(stdin);//清除之前所存储的数据
            gets(str3);
            strcpy(str1,str3);//把新密码复制给str1
            printf("你的新密码为：%s\n",str1);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            system("color 03");
            printf("请输入您要查询的年份：");
            cin>>year;
            cxjz;
            nian(year);
            break;
        case 3:
            system("cls");
            system("color 05");
            printf("请输入年份：");
            cin>>year;
            printf("请输入您要查询的月份范围：");
            int t1,t2;
            cin>>t1>>t2;
            cxjz;
            nianyueshu(year,t1,t2);
            system("cls");
            break;
        case 5:
            printf("退出");
            break;
        }
    }
    while(a!=5);
    return 0;
}

int IsLeapYear ( int year ) //判断是否为闰年, 是则返回1, 否则返回0
{
    if ((year %4 == 0) && (year % 100 != 0) || (year % 400 == 0) )
        return 1;
    else
        return 0;
}

int chaxunday (int year,int month, int day)//查询日历
{

    system("cls");

    printf("请输入你要查询的日期(如2012 3 )：");

    scanf("%d%d",&year,&month);
    return 0;
}
