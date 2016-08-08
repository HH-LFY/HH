#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long a, b, c;
long long l, r;

int main( ){
    int T;
    cin>>T;
    while(T--){
        scanf("%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&l,&r);
        long long kmin ,kmax;
        kmin =  kmax = a*l*l+b*l+c;
        for(int i = l+1;i <= r; ++i){
            long long temp = a*i*i + b*i+c;
            kmin = min(kmin,temp);
            kmax = max(kmax,temp);
        }
        printf("%I64d %I64d\n",kmax,kmin);
    }
    return 0;
}
