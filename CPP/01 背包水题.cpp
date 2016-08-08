#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxx=500+10;
int a[100000+100];
int w[maxx],v[maxx];
int n,m;

int main( )
{
    cin>>n>>m;
    for(int i = 1;i <= n; i++)
    {
        scanf("%d%d",&w[i],&v[i]);
    }
    for(int i = 0;i <= m; i++)
    {
        a[i]=0;
    }
    for(int i = 1;i <= n; i++)
    {
        for(int j = m; j >= w[i]; j--)
        {
            a[j]=max(a[j],a[j-w[i]]+v[i]);
        }
    }
    cout<<a[m]<<endl;
    return 0;
}
