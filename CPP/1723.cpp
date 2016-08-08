#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main( )
{
    int a[50];
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        memset(a,0,sizeof(a));
        a[1]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j = 1;j <= m; j++)
            {
                if(i+j<=n)
                {
                    a[i+j]+=a[i];
     ///               cout<<a[i+j]<<" ";
                }
            }
     ///       cout<<endl;
        }
        for(int i=1;i<=n;i++)
            cout<<" "<<a[i];
     ///   cout<<a[n]<<endl;
    }
    return 0;
}
