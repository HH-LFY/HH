#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 100000;
__int64 map[55][55][55];
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int i,j,k,n;
int a,b,c,t;

int main( )
{
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>t;
        for(i = 0; i <= a+1; i++)
        {
            for(j = 0; j <= b+1; j++)
            {
                for(k = 0; k <= c+1; k++)
                {
                    map[i][j][k] = 1;
                }
            }
        }
        for(i = 1; i <= a; i++)
        {
            for(j = 1; j <= b; j++)
            {
                for(k = 1; k <= c; k++)
                {
                    cin>>map[i][j][k];
                }
            }
        }
        for(i = 0; i <= a+1; i++)
        {
            for(j = 0; j <= b+1; j++)
            {
                for(k = 0   ; k <= c+1; k++)
                {
                    cout<<map[i][j][k];
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
