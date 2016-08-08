#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 55;
char kmap[maxx][maxx];
bool vis[maxx][maxx];
int n, m;
int kx, ky;
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
char kc;

int judge(int x,int y)
{
    if(x < 0 || y < 0)
        return 0;
    if(x >= n || y >= m)
        return 0;
    if(kmap[x][y] != kc)
        return 0;
    return 1;
}

int dfs(int x,int y,int oldx,int oldy)
{
    vis[x][y] = true;
    for(int i = 0;i < 4; ++i)
    {
        int dx = dir[i][0] + x;
        int dy = dir[i][1] + y;
        if(judge(dir[i][0] + x, dir[i][1] + y)&&(dx != oldx || dy != oldy))
        {
            ///printf("i:%d j:%d c:%c \n",dx, dy,kmap[dx][dy]);
            if(vis[dx][dy])
            {
                return 1;
            }
            else if(dfs(dx ,dy ,x , y))
            {
                return 1;
            }
        }
    }
    vis[x][y] = false;
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int i = 0;i < n; ++i)
    {
        scanf("%s",kmap[i]);
    }
    /*
    for(int i = 0;i < n; ++i)
    {
        printf("%s\n",kmap[i]);
    }
    */
    for(int ki = 0;ki <= n; ++ki)
        for(int kj = 0;kj <= m; ++kj)
            vis[ki][kj] = false;
    for(int i = 0;i < n; ++i)
    {
        for(int j = 0;j < m; ++j)
        {
            ///cout<<kmap[i][j]<<endl;
            kx = i;
            ky = j;
            kc = kmap[i][j];
            if(dfs(i,j,-1,-1))
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
