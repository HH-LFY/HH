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
const int  inf =  (1<<30) - 10;
using namespace std;

int main() {
    //freopen("input.txt","r",stdin);

    double x, y;
    double n, m;
    double L;
    double v;
    double s;
    double ans;
    cin>>x>>y>>m>>n>>L;

    if(m > n) {
        v = m - n;
        if(x < y) {
            s = y - x;
        } else {
            s = L - fabs(x - y);
        }
        ans = s/v;

        if(((int)(ans)) > 0) ans = ans + 1;

        printf("%.0f\n",ans);
    } else if(n - eps <= m && m <= n + eps) {
        printf("Impossible\n");
    } else {

        v = n - m;
        if(x < y) {
            s = L - fabs(y - x);
        } else {
            s = x - y;
        }
        ans = s/v;

        if((ans - (int)(ans)) > 0) ans = ans + 1;

        printf("%.0f\n",ans);
    }
    return 0;
}
