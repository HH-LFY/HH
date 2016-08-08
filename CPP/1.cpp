#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main( )
{
    int t;
    int a[8];
    cin>>t;
    while(t--)
    {
        for(int i = 0;i < 6;i++)
            scanf("%d",&a[i]);
        sort(a,a+6);
        int kmax=a[5]+a[4];
        int kmin=a[3]+a[2]+a[1];
        if(kmax>kmin)
        {
            printf("Grandpa Shawn is the Winner!\n");
        }
        else
        {
            printf("What a sad story!\n");
        }
    }
    return 0;
}

