#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxx = 1e6 + 10;
long long lnum[5*maxx]; ///-
long long rnum[5*maxx]; ///+
long long ans[10];
int n, T;
int a, b;
long long kans;

void solved(long long knum[],int len){
    for(int i = 0;i < len; ++i){
        for(int j = 0;j < len; ++j){
            if(i == j) continue;
            kans = max(kans,(long long)(a*knum[i]*knum[i]+b*knum[j]));
        }
    }
}

int main( ){
    cin>>T;
    int kcount  = 1;
    long long inf = 1;
    for(int i = 0;i < 61; ++i){
        inf = 2* inf;
    }
    while(T--){
        kans = -inf;
        ///printf("%lld\n",kans);
        scanf("%d%d%d",&n,&a,&b);
        if(n <= 8){
            for(int i = 0;i < n; ++i){
                scanf("%lld",&rnum[i]);
            }
            solved(rnum,n);
        }else{
            long long x;
            int lp = 0;
            int rp = 0;
            for(int i = 0;i < n; ++i){
                scanf("%lld",&x);
                if(x >= 0){
                    rnum[rp++] = x;
                }else{
                    lnum[lp++] = x;
                }
            }
            int p = 0;
            sort(rnum,rnum+rp);
            sort(lnum,lnum+lp);

            if(rp >= 4){
                ans[p++] = rnum[0];
                ans[p++] = rnum[1];
                ans[p++] = rnum[rp-1];
                ans[p++] = rnum[rp-2];
            }else{
                for(int i = 0;i < rp; ++i){
                    ans[p++] = rnum[i];
                }
            }
            if(lp >= 4){
                ans[p++] = lnum[0];
                ans[p++] = lnum[1];
                ans[p++] = lnum[lp-1];
                ans[p++] = lnum[lp-2];
            }else{
                for(int i = 0;i < lp; ++i){
                    ans[p++] = lnum[i];
                }
            }
            solved(ans,p);
        }
        printf("Case #%d: %lld\n",kcount++,kans);
    }
    return 0;
}
/**

10

3 2 1
1 2 3

5 -1 0
-3 -3 0 3 3

2 1 5
1 0

10 1 2
10 10 -1 1 -1 5 6 -2 0 -10


*/
