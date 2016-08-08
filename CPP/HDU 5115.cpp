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
#define PI 3.141592653
using namespace std;

const int inf = 1<<30;
const int maxx = 300 + 10;
int T, n;
int a[maxx],b[maxx];
int dp[maxx][maxx];

int kdp(int L,int R)
{
    if(L + 1 >= R)  return 0; ///剪枝1：当（L,R）区间为空时，直接返回0
    if(dp[L][R] != inf)  return dp[L][R]; ///剪枝2：避免重复计算
    for(int i = L+1;i < R; ++i) ///枚举可能最后杀掉的狼的位置
    {
        dp[L][R] = min(dp[L][R],kdp(L,i)+kdp(i,R)+a[i]+b[L]+b[R]);
    }
    return dp[L][R];
}

int main( )
{

    cin>>T;
    int i, j;
    int count = 1;
    while(T--)
    {
        scanf("%d",&n);
        for(i = 0;i <= 300;++i)
            for( j = 0;j <= 300; ++j)
                dp[i][j] = inf;
        for(i = 1;i <= n; ++i)
            scanf("%d",&a[i]);
        for(i = 1;i <= n; ++i)
            scanf("%d",&b[i]);
        printf("Case #%d: %d\n",count++,kdp(0,n+1)); ///注意0和n+1位置上是没有狼的
    }
    return 0;
}
