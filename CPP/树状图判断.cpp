#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxx 1010
int map[maxx][maxx];

int main( )
{
    int a,b;
    int k = 1;
    while(cin>>a>>b)
    {
        for(int i = 0;i < maxx; i++)
            for(int j = 0; j< maxx; j++)
            map[i][j] = 0;
        if(a<0&&b<0) break;
        else
        {
            int x,y;
            map[a][b]++;
            map[b][a]++;
        }
    }
    return 0;
}
