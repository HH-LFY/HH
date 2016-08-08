#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main( )
{
    int year,day,m;
    while(scanf("%d-%d-%d",&year,&m,&day)!=EOF)
    {
        int add;
        int k=0;
        for(int i = 0; i < year; i+=400)
        {
            k++;
        }
        if(year%400==0&&(m>=3))
            k++;
        add=year/100-k;
        int judge=0;
        if((year%4==0&&year%100!=0)||year%400==0)
            judge=1;
        day+=add;
        while(1)
        {
            if(day>28)
            {
                if(m==2)
                {
                    if(judge==1&&day>29)
                    {
                        m++;
                        day=day-29;
                    }
                    else if(judge==0&&day>28)
                    {
                        m++;
                        day=day-28;
                        if(year%100==0&&year%400!=0)
                            day--;
                    }
                }
                else if(m==1||m==3||m==5||m==7||m==8||m==10)
                {
                    if(day>31)
                    {
                        day=day-31;
                        m++;
                    }
                }
                else if(m==4||m==6||m==9||m==11)
                {
                    if(day>30)
                    {
                        day=day-30;
                        m++;
                    }
                }
                else if(m==12)
                {
                    if(day>31)
                    {
                        day=day-31;
                        m=1;
                        year++;
                    }
                }
            }
            else break;
        }
        cout<<year<<"-";
        if(m<10)
            cout<<"0"<<m<<"-";
        else
            cout<<m<<"-";
        if(day<10)
            cout<<"0"<<day<<endl;
        else
            cout<<day<<endl;
    }
    return 0;
}
