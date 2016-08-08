#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define eps 1e-6
using namespace std;

const int maxx = 50000 + 10;
int T;
int N;
double x[maxx];
double s[maxx];


double kmin,kmax;
double cal(double xx)
{
}

double solve()
{
    double L, R;
    double mid, midmid;
    L = kmin; R = kmax;
    while (L + eps <= R)
    {
        mid = (L + R) / 2.0;
        midmid = (mid + R) / 2.0;
        if (cal(mid)<=cal(midmid))  R = midmid;
        else  L = mid;
    }
    return L;
}



int main( ){
    cin>>T;
    int kcount = 1;
    while(T--){
        scanf("%d",&N);
        kmin = 1e8;
        kmax = -kmin;
        for(int i = 0;i < N; ++i){
            scanf("%lf%lf",&x[i],&s[i]);
            kmin = min(x[i],kmin);
            kmax = max(x[i],kmax);
        }
        double ans = solve();
        printf("Case #%d: %I64d\n",kcount++,(long long)(ans+0.5));
    }
    return 0;
}
