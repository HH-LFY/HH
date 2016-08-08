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

const int maxx = 1e5 + 10;
struct node
{
    int x;
    int y;
};
node a[maxx],b[maxx];
long long sum[maxx];
int t;
int n, m;

int cmd(node cs1,node cs2)
{
    return cs1.x < cs2.x;
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i = 0; i < n; ++i)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d",&b[i].x,&b[i].y);
        }
        sort(a,a+n,cmd);
        sort(b,b+m,cmd);
        sum[0] = b[0].y;
        b[m].x = inf;
        for(int i = 1; i < m; ++i)
        {
            sum[i] = sum[i - 1] + b[i].y;
            ///printf("%I64d\n\n",sum[i]);
        }
        sum[m] = sum[m - 1];
        int p = 0;
        long long ans = 0;
        for(int i = 0; i < n; ++i)
        {
            while(1)
            {
                if(a[i].x <= b[p].x)
                {
                    p--;
                    break;
                }
                if(a[i].x > b[p].x)
                {
                    p++;
                }
            }
            ans += a[i].y * sum[p];
           /// printf("%d %d\n",a[i].y , sum[p]);

        }
        cout<<ans<<endl;
    }
    return 0;
}
