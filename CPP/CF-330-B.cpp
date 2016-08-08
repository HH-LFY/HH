#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxx = 100000 + 10;
const int inf = 1e9 + 7;
long long n, k;
long long a[maxx];
long long b[maxx];
long long vis[maxx];
long long ka[11];

int main( ){
    cin>>n>>k;
    ka[0] = 1;
    for(int i = 1;i <= 9;i++ ){
        ka[i] = 10 * ka[i-1];
    }
    for(int i = 1;i <= n/k; ++i){
        scanf("%lld",&a[i]);
        vis[i] = (ka[k]-1)/a[i] + 1;
    }
    for(int i = 1;i <= n/k; ++i){
        scanf("%lld",&b[i]);
        long long x1 = (ka[k-1]*(b[i]+1)-1)/a[i];
        long long x2 = (ka[k-1]*b[i] - 1)/a[i];
        x2 = x2>0?x2:0;
        vis[i] = vis[i] - x1 + x2;
        if(b[i]==0){
            vis[i]--;
        }
       /// printf(" %I64d %I64d \n",ka[k-1]*(b[i]+1)-1,ka[k-1]*b[i] - 1);
       /// printf(" %I64d %I64d %I64d\n",x1,x2,vis[i]);
    }
    long long ans = 1;
    for(int i = 1;i <= n/k; ++i){
        ///cout<<vis[i]<<" "<<endl;
        ///printf("%I64d\n",ans);
        ans = (ans*vis[i])%inf;
    }
    printf("%I64d\n",ans);
    return 0;
}
