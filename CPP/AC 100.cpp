#include <iostream>
using namespace std;


void SwapInt(int *a,int *b)
{
    int x;
    x=*a;
    *a=*b;
    *b=x;
}

int main( )
{
    int a=3,b=4;
    SwapInt(&a,&b);
    cout<<a<<b<<endl;
    return 0;
}
