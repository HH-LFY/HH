#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxx=5000+10;
int a[maxx];
int n;

int main( )
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0;i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        int kmin=0;
        for(int i = 0;i < n; i++)
        {
            for(int j = i+1;j < n; j++)
            {
                if(a[j]<a[i])
                {
                    kmin++;
                }
            }
        }
        int sum=kmin;
        for(int i = 0;i < n; i++)
        {
            sum=sum-2*a[i]+n-1;
            kmin=min(kmin,sum);
        }
        cout<<kmin<<endl;
    }
    return 0;
}
