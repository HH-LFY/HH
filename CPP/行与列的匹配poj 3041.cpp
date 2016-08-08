#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI 3.141592653
using namespace std;

const int maxx = 500 + 50;
int link[maxx][maxx];
int vis[maxx];
int used[maxx];
int n , k;
int sum;

bool find(int x)
{
    int i, j;
    for(i = 1;i <= n; ++i)
    {
        if(!vis[i]&&link[x][i])
        {
            vis[i] = 1;
            if(!used[i]||find(used[i]))
            {
                used[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main( )
{
    while(scanf("%d%d",&n, &k)!=EOF)
    {
        sum = 0;
        int i , j;
        for(i = 0;i <= n; ++i)
        {
            used[i] = 0;
            for(j = 0;j <= n; ++j)
            {
                link[i][j] = 0;
            }
        }
        int x , y;
        for(i = 0;i < k; ++i)
        {
            scanf("%d%d",&x,&y);
            link[x][y] = 1;
        }
        //cout<<"hehe"<<endl;
        for(i = 1;i <= n; ++i)
        {
            memset(vis,0,sizeof(vis));
            if(find(i)) sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
