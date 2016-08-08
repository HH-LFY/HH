#include <iostream>
using namespace std;

int t;
int x,d,m;

int main( )
{
    cin>>t;
    while(t--)
    {
        cin>>x>>m>>d;
        if((d+m)%2==0||(d==30&&(m==11||m==9)))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
