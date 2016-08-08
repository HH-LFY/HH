#include <iostream>
#include <cstdio>
using namespace std;

const int maxx=2;
int pp=1;

struct node
{
    int count;
    node *next[maxx];
    node( )
    {
        count = 1;
        for(int i = 0;i < maxx;i++)
        {
            next[i] = NULL;
        }
    }
};

int main( )
{
    while(pp==1||)
    {

    }
    return 0;
}
