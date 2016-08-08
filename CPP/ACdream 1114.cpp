#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

const int maxx = 222222+10;
int n;
int a[maxx];

int get_int( )
{
    int result=0;
    char c;
    while((c=getchar( ))!=' '&&c!='\n')
        result = result*10 + c - '0';
    return result;
}

int gcd(int x,int y)
{
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}

int main( )
{
    while(scanf("%d",&n)!=EOF)
    {
        getchar( );
        for(int i = 1;i <= n; ++i)
        {
            a[i]=get_int( );
        }
        int sum = 0;
        for(int i = 1;i <= n; ++i)
        {
            for(int j = i+1;j <= n; ++j)
            {
                if(gcd(a[i],a[j])==1)
                {
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
