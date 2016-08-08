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
#define eps 1e-8
const int  inf =  1e9 + 7;
using namespace std;

const int maxx = 1e6 + 10;
long long dp[maxx][2];
long long num[maxx];

void init(){
    num[0] = 1;
    for(int i = 1;i < maxx; ++i){
        num[i] = (long long)(2*num[i-1])%inf;
    }
}

int main(){
    //freopen("input.txt","r",stdin);
    init();
    int T;
    int n, m;
    while(cin>>T){
        while(T--){
            scanf("%d%d",&n,&m);
            dp[m][0] = 1;
            dp[m][1] = num[m] - dp[m][0];
            for(int i = 0;i < m; ++i){
                dp[i][1] = num[i];
            }
            for(int i = m + 1; i <= n; ++i){
                dp[i][0] = ((dp[i-1][0]*2)%inf + dp[i-1-m][1] +inf)%inf;
                dp[i][1] = (num[i] - dp[i][0])%inf;
            }
            printf("%lld\n",dp[n][0]);
        }
    }
    return 0;
}
