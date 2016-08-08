#include <iostream>
using namespace std;

inline void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int main( )
{
    int a=3;
    int b=5;
    swap(&a,&b);
    cout<<a<<" "<<b;
    return 0;
}
