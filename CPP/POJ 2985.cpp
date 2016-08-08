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
#include <vector>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 200000 + 10;
int f[maxx];
int sum[maxx];
int c[maxx];
int n, m;

int find(int x)
{
    if(f[x] == x) return x;
    else return f[x] = find(f[x]);
}

int lowbit(int x)
{
    return x&(-x);
}

void add(int k, int val)
{
    while(k <= maxx)
    {
        c[k]+=val;
        k+=lowbit(k);
    }
}

int query(int k)
{
    int s = 0;
    while(k > 0)
    {
        s += c[k];
        k -=lowbit(k);
    }
    return s;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i = 0;i <= n; ++i)
        {
            c[i] = 0;
            f[i] = i;
            sum[i] = 1;
        }
        add(1,n);
        int num = n;
        for(int i = 0;i < m; ++i)
        {
            int c;
            scanf("%d",&c);
            if(c == 0)
            {
                int x, y;
                scanf("%d%d",&x,&y);
                int fx = find(x);
                int fy = find(y);
                if(fx == fy) continue;
                add(sum[fx],-1);
                add(sum[fy],-1);
                add(sum[fx] = sum[fx] + sum[fy],1);
                f[fy] = fx;
                num--;

            }
            else
            {
                int k;
                scanf("%d",&k);
                k = num + 1 - k;
                int l = 1;
                int r = n;
                while(l <= r)
                {
                    int mid = (l + r) >> 1;
                    if(query(mid) >= k) r = mid - 1;
                    else l = mid + 1;
                }
                printf("%d\n",l);
            }
        }
    }
    return 0;
}
