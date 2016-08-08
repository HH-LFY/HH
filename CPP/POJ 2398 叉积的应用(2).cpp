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
int ans[5000+10],sum[5000+10];
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

int cmp(edge k1,edge k2)
{
    return k1.a.x < k2.a.x;
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
            sum[i] = 0;
        }
        sort(edges,edges+n,cmp);
        ans[n] = 0;
        sum[n] = 0;
        Point sx;
        for(int i= 0;i < m; ++i)
        {
            scanf("%d%d",&sx.x,&sx.y);
            twofen(sx);
        }
        for(int i = 0;i <= n; ++i)
        {
            if(ans[i])
            {
                sum[ans[i]]++;
            }
        }
        printf("Box\n");
        for(int i = 0;i <= n; ++i)
        {
            if(sum[i]!=0)
            printf("%d: %d\n",i,sum[i]);
        }
    }
    return 0;
}
