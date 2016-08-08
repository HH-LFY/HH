#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI acos(-1.0)
using namespace std;

const int maxx = 1e6 + 10;
struct edge
{
    int s;
    int x,y;
}kis[maxx];
int vis[maxx/10];
bool vis1[maxx];
int i, j;
int n, m;

bool cmd(edge x,edge y)
{
    return x.s<y.s;
}

int find(int x)
{
    if(x == vis[x]) return x;
    return vis[x] = find(vis[x]);
}

int main( )
{
    scanf("%d%d",&n,&m);
    for(i = 1;i <= n; ++i)
    {
        vis[i] = i;
    }
    for(i = 0;i < m; ++i)
    {
        scanf("%d%d%d",&kis[i].x,&kis[i].y,&kis[i].s);
        vis1[i] = false;
    }
    sort(kis,kis+m,cmd);
    /*
    for(j = 0;j < m; ++j)
    {
        printf("%d %d %d \n",kis[j].x,kis[j].y,kis[j].s);
    }
    */
    vis1[0] = true;
    vis[kis[0].y] = vis[kis[0].x];
    long long ans = kis[0].s;
    for(i = 1; i < m; ++i)
    {
        if(vis1[i]) continue;
        int fx = find(kis[i].x);
        int fy = find(kis[i].y);
        if(fx!=fy)
        {
            ans += kis[i].s;
            vis1[i] = true;
            vis[fy] = fx;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
