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

const int maxx = 1e5 + 100;
int a[maxx*2];
int n;
double w;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>w;
    for(int i = 0;i < 2*n; ++i){
        scanf("%d",&a[i]);
    }
    sort(a,a+2*n);
    double k1 = (double)(a[0]*1.0);
    double k2 = (double)((a[n]*1.0)/2.0);
    double kmin = min(k1,k2);
    double ans = (double)(kmin*3.0*n);
    ans = ans>w?w:ans;
    printf("%.6f\n",ans);
    return 0;
}
