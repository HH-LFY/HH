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

int main(){
    int T;
    int count  = 1;
    cin>>T;
    while(T--){
        int n;
        double a, b;
        cin>>n;
        a = 1.0 + (19.0*(n-2))/27.0;
        b = (n+(19.0*(n-2))/27.0)/a;

        printf("Case #%d:\n",count++);
        printf("%.6f %.6f\n",a,b);
    }
    return 0;
}
