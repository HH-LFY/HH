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

int n, m, k;
bool vis[1010][1010];

bool ok(int x,int y)
{
    if(vis[x+1][y])
    {
        if(vis[x+1][y+1]&&vis[x][y+1])
        {
            return true;
        }
        else if(vis[x+1][y-1]&&vis[x][y-1])
        {
            return true;
        }
    }
    else if(vis[x-1][y])
    {
        if(vis[x-1][y-1]&&vis[x][y-1])
        {
            return true;
        }
        else if(vis[x-1][y+1]&&vis[x][y+1])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>n>>m>>k;
    for(int i = 0;i <= n+1; ++i)
    {
        for(int j = 0;j <= m+1; ++j)
        {
            vis[i][j] = false;
        }
    }
    int x, y;
    int judge = 0;
    for(int i = 1;i <= k; ++i)
    {
        scanf("%d%d",&x,&y);
        vis[x][y] = true;
        if(!judge && ok(x,y))
            judge = i;
    }
    cout<<judge<<endl;
    return 0;
}
