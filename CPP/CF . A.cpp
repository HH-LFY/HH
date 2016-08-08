#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[5][110];
int s[5];

int main( )
{
    int judge=3;
    s[1]=s[2]=s[3]=s[4]=0;
    scanf("%s",str[1]);
    scanf("%s",str[2]);
    scanf("%s",str[3]);
    scanf("%s",str[4]);
    for(int i = 2; i <= 100; i++)
    {
        if((str[1][i]>='a'&&str[1][i]<='z')||(str[1][i]>='A'&&str[1][i]<='Z')||str[1][i]=='_')
            s[1]++;
        if((str[2][i]>='a'&&str[2][i]<='z')||(str[2][i]>='A'&&str[2][i]<='Z')||str[2][i]=='_')
            s[2]++;
        if((str[3][i]>='a'&&str[1][i]<='z')||(str[3][i]>='A'&&str[3][i]<='Z')||str[3][i]=='_')
            s[3]++;
        if((str[4][i]>='a'&&str[1][i]<='z')||(str[4][i]>='A'&&str[4][i]<='Z')||str[4][i]=='_')
            s[4]++;
    }
    int count=0;
    for(int i = 1; i <= 4; i++)
    {
        int k1=0,k2=0;
        for(int j = 1; j <= 4; j++)
        {
            if(i!=j&&s[i]*2<=s[j])
            {
                k1++;
            }
            if(i!=j&&s[i]>=2*s[j])
            {
                k2++;
            }
        }
        if(k1==3||k2==3)
        {judge=i;count++;}
    }
    if(count==1)
    {
    if(judge==1)
        cout<<"A"<<endl;
    else if(judge==2)
        cout<<"B"<<endl;
    else if(judge==3)
        cout<<"C"<<endl;
    else
        cout<<"D"<<endl;
    }
    else
        cout<<"C"<<endl;
    return 0;
}
