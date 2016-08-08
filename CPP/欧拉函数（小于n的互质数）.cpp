#include<iostream>
#include<cstdio>
using namespace std;

int main( )
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        int sum=n;
        for(int i=2;i <= n; i++)
        {
            if(n%i==0)
            {
                sum=sum-sum/i;
                while(n%i==0)
                {
                    n=n/i;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

