#include <iostream>
using namespace std;

int main( )
{
    __int64 n,m,a;
    while(cin>>n>>m>>a)
    {
        __int64 km,kn,sum;
        km = m/a;
        kn = n/a;
        if(n%a) kn++;
        if(m%a) km++;
        sum = km*kn;
        cout<<sum<<endl;
    }
    return 0;
}
