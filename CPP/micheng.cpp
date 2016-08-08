#include<iostream>
using namespace std;

int a,b;

int micheng(int n,int m )
{
    int result=1;
    int x=n,y=m;
    while(y>0)
    {
        if(y%2)
        {
            result = (result*x)%10;
        }
        x=(x%10)*(x%10);
        y/=2;
    }
    return result;
}

int main( )
{
    while(cin>>a>>b)
    {
        cout<<micheng(a,b)<<endl;
    }
    return 0;
}
