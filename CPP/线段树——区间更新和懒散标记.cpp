/***
*
*POJ 3468
*
*/
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
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 100000 + 10;
long long add[maxx<<2];
long long sum[maxx<<2];

void PushDown(int num,int k){
    if(add[num]){
        add[num<<1] += add[num];
        add[num<<1|1] += add[num];
        sum[num<<1] += add[num] * (k - (k>>1));
        sum[num<<1|1] += add[num]*(k>>1);
        add[num] = 0;
    }
}

void build(int l,int r,int num){
    add[num] = 0;
    if(l == r){
        scanf("%lld",&sum[num]);
        return ;
    }
    int mid = (l + r)>>1;
    build(l,mid,num<<1);
    build(mid+1,r,num<<1|1);
    sum[num] = sum[num<<1] + sum[num<<1|1];
}

void update(int ll,int rr,int c,int l,int r,int num){
    if(ll <= l && r<= rr){
        add[num] += c;
        sum[num] += (long long) c*(r - l + 1);
        return ;
    }
    PushDown(num,r - l + 1);
    int mid = (l + r) >> 1;
    if(ll <= mid) update(ll, rr, c, l, mid, num<<1);
    if(rr > mid) update(ll, rr, c, mid + 1, r, num<<1|1);
    sum[num] = sum[num<<1] + sum[num<<1|1];
}

long long query(int ll,int rr,int l,int r,int num){
    long long ans = 0;
    if(l >= ll && r <= rr){
        ans += sum[num];
        return ans;
    }
    PushDown(num,r - l + 1);
    int mid = (l + r)>>1;
    if(ll <= mid) ans += query(ll,rr,l,mid,num<<1);
    if(rr > mid)  ans += query(ll,rr,mid+1,r,num<<1|1);
    return ans;
}

int main(){
    int n, Q;
    scanf("%d%d",&n,&Q);
    build(1,n,1);
    while(Q--){
        char str[20];
        int a, b, c;
        scanf("%s",str);
        if(str[0] == 'Q'){
            scanf("%d%d",&a,&b);
            printf("%lld\n",query(a, b, 1, n, 1));
        }else{
            scanf("%d%d%d",&a,&b,&c);
            update(a, b, c, 1, n, 1);
        }
    }
    return 0;
}
