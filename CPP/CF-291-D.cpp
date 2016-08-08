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

int n, m , k;
int a[1000000 + 10][6];
int ans[6];
deque<int> p[6];
long long t;

int searchc(int mid)
{
    for(int i = 1;i <= m; ++i)
        while(!p[i].empty())
            p[i].pop_back();
    for(int i = 1;i <= n; ++i)
    {
        for(int j = 1;j <= m; ++j)
        {
            while(!p[j].empty() && p[j].back() < a[i][j])
            {
                p[j].pop_back();
            }
            p[j].push_back(a[i][j]);
        }
        if(i < mid)
            continue;
        t = 0;
        for(int j = 1;j <= m; ++j)
        {
            t += p[j].front();
        }
        if(t <= k)
        {
            for(int j = 1;j <= m; ++j)
            {
                ans[j] = p[j].front();
            }
            return 1;
        }
        for(int j = 1;j <= m; ++j)
        {
            if(p[j].front() == a[i - mid + 1][j])
                p[j].pop_front();
        }
    }
    return 0;
}

void show()
{
    for(int i = 1;i <= m; ++i)
        cout<<ans[i]<<" ";
    cout<<endl;
}

int main()
{
    cin>>n>>m>>k;
    for(int i = 1;i <= n; ++i)
        for(int j = 1;j <= m; ++j)
            scanf("%d",&a[i][j]);
    int l = 1, r = n;
    searchc(1);
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(searchc(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    show();
    return 0;
}
