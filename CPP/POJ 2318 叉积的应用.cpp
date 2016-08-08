#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

struct Point
{
    int x;
    int y;
};

struct edge
{
    Point a, b;
}edges[5000+10];

int n, m, x1, y1, x2, y2;
int ans[5000+10];
int x, y;

int chafen(Point a,Point b,Point c)
{
    return (a.x - c.x)*(b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}

void twofen(Point p)
{
    int l = 0;
    int r = n;
    while(l != r)
    {
        int mid = (l + r)/2;
        if(chafen(p,edges[mid].a,edges[mid].b) < 0) r = mid;
        else l = mid + 1;
    }
    ans[r]++;
}

int main()
{
    while(scanf("%d",&n)&&n)
    {
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for(int i = 0;i < n; ++i)
        {
            scanf("%d%d",&x,&y);
            edges[i].a.x = x;
            edges[i].a.y = y1;
            edges[i].b.x = y;
            edges[i].b.y = y2;
            ans[i] = 0;
        }
        ans[n] = 0;
        Point sx;
        for(int i= 0;i < m; ++i)
        {
            scanf("%d%d",&sx.x,&sx.y);
            twofen(sx);
        }
        for(int i = 0;i <= n; ++i)
        {
            printf("%d: %d\n",i,ans[i]);
        }
        printf("\n");
    }
    return 0;
}
