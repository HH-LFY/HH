#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cmath>
#define PI 3.141592653
using namespace std;

const int maxx=110;
int n,m;
int map[maxx][maxx];
int sum;
char c;

void dfs(int x,int y)
{
    map[x][y] = 0;
    int i,j;
    for(i = -1;i <= 1; ++i)
    {
        for(j = -1;j <= 1; ++j)
        {
            if(map[x+i][y+j]==1)
                dfs(x+i,y+j);
        }
    }
    return ;
}

int main( )
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        getchar( );
        sum = 0;
        int i,j;
        for(i = 0;i <= n+1; ++i)
        {
            for(j = 0;j <= m+1; ++j)
            {
                map[i][j] = 0;
            }
        }
        for(i = 1;i <= n; ++i)
        {
            for(j = 1;j <= m; ++j)
            {
                c = getchar( );
                if(c=='W')
                {
                    map[i][j] = 1;
                }
            }
            getchar( );
        }
        /*
                for(i = 0;i <= n+1; ++i)
                {
                    for(j = 0; j <= m+1; ++j)
                    {
                    if(map[i][j]==0)
                        cout<<".";
                    else
                        cout<<"W";
                    }
                    cout<<endl;
                }
        */
        for(i = 1;i <= n; ++i)
        {
            for(j = 1;j <= m; ++j)
            {
                if(map[i][j]==1)
                {
                    dfs(i,j);
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
