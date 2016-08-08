#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int T;
long long n, x, y, z, t;
long long ans;

long long solve()
{
    long long kans = -1;
    for(long long r = 0;r <= n; ++r){
        for(long long b = 0;b <= n-r; ++b){
           long long g = n - r - b;
           long long time1 = t;
           long long sum1 = 0;
           sum1 +=(((g-1)*g)/2)*time1*y;  ///green
           sum1 += ((b)*time1+z*((b+1)*(b))/2)*(g*y);
           sum1 += (time1+b*z)*r*(x+g*y);
           kans = max(sum1,kans);

           long long time2 = t+b*z;
           long long sum2 = 0;
           sum2 +=(((g-1)*g)/2)*time2*y;  ///green
           sum2 += time2*r*(x+g*y);
           kans = max(sum2,kans);

        }
    }
    return kans;
}

int main( ){
    cin>>T;
    ///freopen("C:\\Users\\Administrator\\Desktop\\put.txt","w",stdout);
    int cas = 1;
    while(T--){
        cin>>n>>x>>y>>z>>t;
        ans = -1;
        ans = max(solve(),ans);
        printf("Case #%d: %I64d\n",cas++,ans);
    }
    return 0;
}

/**
5
5 5 5 5 1
3 5 5 5 1
5 0 1 0 1
*/
