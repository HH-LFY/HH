#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main( )
{
    int n;
    int a[250][250];
    cin>>n;
    int i,j;
    for(i = 1;i <= n; i++)
    {
        for(j = 1;j <= i; j++)
        {
            cin>>a[i][j];
        }
    }
    for(i = n-1;i >= 1; i--)
    {
        for(j = 1;j <= i; j++)
        {
            a[i][j]= max(a[i+1][j],a[i+1][j+1])+a[i][j];
        }
    }
    cout<<a[1][1]<<endl;
    return 0;
}
