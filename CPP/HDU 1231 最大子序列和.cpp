#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 10;
long long a[maxn];
long long sum[maxn];

int main( ){
    int n;
    while(cin>>n){
        if(n==0) break;
        long long l,r,ans_l;
        long long kmin,kmax;
        for(int i = 0;i < n; ++i){
            scanf("%lld", &a[i]);
        }
        int judge = 0;
        sum[0] = a[0];
        kmax = sum[0];
        kmin = sum[0];
        l = 0;
        r = 0;
        ans_l = -1;
        judge = a[0]>0?1:0;
        for(int i = 1;i < n; ++i){
            sum[i] = a[i] + sum[i-1];
            if(sum[i] - kmin > kmax && sum[i] - kmin >= 0){
                r = i;
                ans_l = l;
                kmax = sum[i]-kmin;
                judge = 1;
            }
            if(sum[i] < kmin){
                kmin = sum[i];
                l = i;
            }
        }
        if(judge)printf("%lld %lld %lld\n",kmax==-1?0:kmax,a[ans_l+1],a[r]);
        else printf("%d %lld %lld\n",0,a[0],a[n-1]);
    }
    return 0;
}
