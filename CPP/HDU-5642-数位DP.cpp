#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int maxx = 2000 + 10;
int T;
int n;
long long dp[maxx][4];

void init(){
    dp[1][1] = 26;
    for(int i = 2;i < maxx; ++i){
        dp[i][1] = ((dp[i-1][1]+dp[i-1][2]+dp[i-1][3])*25)%MOD;
        dp[i][2] = dp[i-1][1];
        dp[i][3] = dp[i-1][2];
    }
}

int main( ){
    init();///´ò±í
    cin>>T;
    while(T--){
        cin>>n;
        long long ans = (dp[n][1]+dp[n][2]+dp[n][3])%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
