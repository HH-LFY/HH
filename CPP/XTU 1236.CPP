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
#define eps 1e-9
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 1001;
struct point {
    int x;
    int y;
    double val;
}num[maxx * maxx];
int p = 0;

int cmd(point a, point b) {
    return a.val - b.val < eps;
}

void init() {
    num[p].x = 0;
    num[p].y = 1;
    num[p++].val = 0;
    for(int i = 1; i <= 1000; ++i) {
        for(int j = 1; j < i; ++j) {
            num[p].x = j;
            num[p].y = i;
            num[p++].val = (j*1.0)/(i*1.0);
            //printf("%f\n",num[p-1].val);
        }
    }
    sort(num,num + p, cmd);
    num[p].x = 1;
    num[p].y = 1;
    num[p].val = 1.0;
    /*
    for(int i = 0;i < p; ++i){
        printf("%f\n",num[i].val);
    }
    */
}

int gcd(int a,int b) {
    if(b==0)return a;
    return gcd(b,a%b);
}

int main() {
    //freopen("input.txt","r",stdin);
    init();
    int n;
    while(scanf("%d",&n)!=EOF) {
        while(n--) {
            double xx;
            scanf("%lf",&xx);
            int l = 0;
            int r = p;
            while(l+1 != r) {
                int mid = (l+r)/2;
                if(num[mid].val - xx > eps) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            if(fabs(num[l].val - xx) - fabs(num[r].val - xx) > eps) {
                int g = gcd(num[r].x,num[r].y);
                printf("%d/%d\n",num[r].x/g,num[r].y/g);
            } else {
                int g = gcd(num[l].x,num[l].y);
                printf("%d/%d\n",num[l].x/g,num[l].y/g);
            }
        }
    }
    return 0;
}
