#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
typedef long long LL;
#define EPS 1e-8
const int N = 50000 + 50;
double kmin , kmax;
double s[N] , w[N];
double Left, Right;
double mid, midmid;
int n;
double Calc(double x){
    double ans = 0;
    for(int i=1; i<=n; ++i) {
        double t = (s[i] - x);
        ans += fabs(t * t * t) * w[i];
    }
    return ans;
}

void Solve(){
    double mid_value, midmid_value;
    Left = kmin; Right = kmax;
    while (Left + EPS <= Right){
        mid = (Left + Right) / 2.0;
        midmid = (mid + Right) / 2.0;
        double mid_area = Calc(mid);
        double midmid_area = Calc(midmid);
        // 假设求解最大极值.
        if (mid_area <= midmid_area) Right = midmid;
        else Left = mid;
    }
}

int main() {
    int T , Cas = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        kmin = 10000000; kmax = -10000000;
        for(int i=1; i<=n; ++i) {
            scanf("%lf%lf", &s[i], &w[i]);
            if(s[i] > kmax) kmax = s[i];
            if(s[i] < kmin) kmin = s[i];
        }
        Solve();
        printf("Case #%d: ", Cas++);
        printf("%I64d\n", (LL)(Calc(Left)+0.5));
    }
    return 0;
}
