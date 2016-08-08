#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main( )
{
    __int64 n,m,k;
    cin>>n>>m>>k;
    if(k>m+n-2)
    {
        cout<<"-1"<<endl;
    }
    else
    {
        __int64 maxx=-1;
        if(k<m)
        {

            maxx=max(maxx,n*(m/(k+1)));
        }
        if(k<n)
        {
            maxx=max(maxx,m*(n/(k+1)));
        }
        if(k>=m)
        {
            maxx=max(maxx,n/(k-m+2));
        }
        if(k>=n)
        {
            maxx=max(maxx,m/(k-n+2));
        }
        cout<<maxx<<endl;
    }
    return 0;
}
