#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 2015 + 10;
int T;
int n;
int f[maxn];

int getcount(int sum,int x)
{
    int ans = 0;
    sum -= x*2;
    if(sum>=0)ans++;
    else return ans;
    ans = ans + (sum/((x-1)*2));
    return ans;
}

int main( )
{
    cin>>T;
    while(T--)
    {
        scanf("%d",&n);
        int sum = n*2 - 2;
        n--;
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d",&f[i]);
        }
        int ans = 0;
        for(int i = n; i > 1; --i)
        {
            int ksum = sum;
            int flag = getcount(ksum,i);
            ans = max(ans,flag*f[i]+f[1]*(n - flag + 1));
            ///printf("%d %d\n",flag,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
