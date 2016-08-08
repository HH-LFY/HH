#include <iostream>
#include <cstdio>
using namespace std;

void f1( ) throw(int , double )
{
    double a;
    int k;
    throw k;
    throw a;
}

int main( )
{
    try
    {
        f1( );
    }
    catch(double)
    {
        cout<<"int hehe!!!"<<endl;
    }
    catch(...)
    {
        cout<<"int 2hehe!!"<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}
