#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str1[1003][81],str2[1003][81];
int n;

int main( )
{
    while(cin>>n)
    {
    getchar();
    for(int i = 1; i <= n; i++)
    {
        gets(str1[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        gets(str2[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        if(strcmp(str1[i],str2[i])!=0)
        {
            cout<<i<<endl;
            cout<<str1[i]<<endl;
            cout<<str2[i]<<endl;
        }
    }
    }
    return 0;
}
