#include <iostream>
#include <cstdio>
using namespace std;

int main( )
{
    int a,b,n;
    int f[2000];
    f[1]=f[2]=1;
    while(cin>>a>>b>>n)
    {
        if(a==0&&b==0&&n==0) break;
        for(int i = 3;i <= 1008; i++)
        {
            f[i]=(a*f[i-1] + b*f[i-2])%7;
        }
        cout<<f[(n-1)%1008+1]<<endl;
    }
    return 0;
}
