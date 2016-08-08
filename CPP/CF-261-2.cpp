#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct vis
{
    int x;
    int y;
};

int abc(int x)
{
    return x>0?x:-x;
}

int main( )
{
    vis a1,a2,a3,a4;
    cin>>a1.x>>a1.y>>a2.x>>a2.y;
    if(0==(a1.x-a2.x))
    {
        a3.x=a4.x=a1.x+abc(a1.y-a2.y);
        a3.y=a1.y;
        a4.y=a2.y;
        printf("%d %d %d %d\n",a3.x,a3.y,a4.x,a4.y);
    }
    else if(0==(a1.y-a2.y))
    {
        a3.y=a4.y=a1.y+abc(a1.x-a2.x);
        a3.x=a1.x;
        a4.x=a2.x;
        printf("%d %d %d %d\n",a3.x,a3.y,a4.x,a4.y);
    }
    else if(abc(a1.y-a2.y)!=abc(a1.x-a2.x))
    {
        printf("-1\n");
    }
    else
    {
        a3.y=a1.y;
        a3.x=a2.x;
        a4.y=a2.y;
        a4.x=a1.x;
        printf("%d %d %d %d\n",a3.x,a3.y,a4.x,a4.y);
    }
    return 0;
}
