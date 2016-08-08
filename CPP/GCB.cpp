#include <iostream>
using namespace std;


int main( )
{
    int n,m,k;
    cin>>m>>n;
    k = m%n;
    while( k )
    {
        m = n;
        n = k;
        k = m%n;
    }
    cout<<n<<endl;
    return 0;
}
