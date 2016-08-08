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
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#define PI 3.141592653
using namespace std;

const int maxx = 1e6 + 10;
int a[maxx];
int b[maxx];
int vis[maxx];
int kis[maxx];
deque<int> p, q;
int n;

int main( )
{
    int x, y;
    int i, j;
    cin>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(vis,0,sizeof(vis));
    for(i = 1;i <= n; ++i)
    {
        scanf("%d %d", &x, &y);
        vis[x] = vis[y] = 1;
        a[x] = y;
        b[y]++;
    }
    int k = 0;
    while(a[k])
    {
        p.push_back(a[k]);
        k = a[k];
    }
    p.push_back(-1);
    for(i = 1;i < maxx; ++i)
    {
        if(vis[i] && !b[i])
        {
            int k = i;
            while(k)
            {
                q.push_back(k);
                k = a[k];
            }
            break;
        }
    }
    q.push_back(-1);
    for(i = 1;i < n;)
    {
        kis[i++] = q.front();
        q.pop_front();
        kis[i++] = p.front();
        p.pop_front();
    }
    if(n%2)
    {
        if(q.front() == -1)
        {
            kis[n] = p.front();
        }
        else
        {
            kis[n] = q.front();
        }
    }
    for(i = 1;i <= n; ++i)
    {
        printf("%d ",kis[i]);
    }
    printf("\n");
    return 0;
}
