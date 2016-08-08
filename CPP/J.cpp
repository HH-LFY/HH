#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[10010];

int main( )
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0;i < n; i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        cout<<a[n/2]<<endl;
    }
    return 0;
}
