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

const int maxx = 20000 + 12;
struct node
{
    int x;
    int y;
    int value;
};
node edge[100000+10];
int f[maxx*2];
int n, m;
int ans;

bool cmd(node x,node y)
{
    return x.value > y.value;
}

void input()
{
    int a, b, c;
    cin>>n>>m;
    for(int i = 0;i < m; ++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        edge[i].x = a;
        edge[i].y = b;
        edge[i].value = c;
    }

}

int find(int x)
{
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}

void solved()
{
    sort(edge,edge+m,cmd);
    ans = 0;
    for(int i = 1;i <= n*2; ++i)
    {
        f[i] = i;
    }
    for(int i = 0;i < m; ++i)
    {
        int x = edge[i].x;
        int y = edge[i].y;
        int fx = find(x);
        int fy = find(y);
        if(fx == fy)
        {
            ans = edge[i].value;
            break;
        }
        else
        {
            f[fx] = find(y + n);
            f[fy] = find(x + n);
        }
    }

    cout<<ans<<endl;
}

int main()
{
    input();
    solved();
    return 0;
}
