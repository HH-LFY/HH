/**
*  POJ 2528
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

const int maxx = 111111;
bool hash[maxx];
int li[maxx], ri[maxx];
int x[maxx * 3];
int color[maxx<<4];
int cnt;

void PushDown(int num){
    if(color[num] != -1){
        color[num<<1] = color[num<<1|1] = color[num];
        color[num] = -1;
    }
}

void update(int ll,int rr,int c,int l,int r,int num){
    if(ll <= l && r <= rr){
        color[num] = c;
        return ;
    }
    PushDown(num);
    int mid = (l + r) >> 1;
    if(ll <= mid) update(ll,rr,c,l,mid,num<<1);
    if(rr > mid)  update(ll,rr,c,mid+1,r,num<<1|1);
}

void query(int l,int r,int num){
    if(color[num] != -1){
        if(!hash[color[num]])cnt++;
        hash[color[num]] = true;
        return ;
    }
    if(l == r) return ;
    int mid = (l + r) >> 1;
    query(l, mid, num<<1);
    query(mid + 1, r, num<<1|1);
}

int twofen(int key,int n,int x[]){
    int l = 0;
    int r = n - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(x[mid] == key) return mid;
        if(x[mid] > key) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main()
{
    int t, n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int p = 0;
        for(int i = 0;i < n; ++i){
            scanf("%d%d",&li[i],&ri[i]);
            x[p++] = li[i];
            x[p++] = ri[i];
        }
        sort(x, x + p);
        int m = 1;
        for(int i = 1;i < p; ++i){
            if(x[i] != x[i - 1]) x[m++] = x[i];
        }
        for(int i = m - 1;i > 0; --i){
            if(x[i] != x[i - 1] + 1) x[m++] = x[i - 1] + 1;
        }
        sort(x, x + m);
        memset(color, -1, sizeof(color));
        for(int i = 0;i < n; ++i){
            int l = twofen(li[i], m, x);
            int r = twofen(ri[i], m, x);
            update(l , r, i, 0, m, 1);
        }
        cnt = 0;
        memset(hash, false, sizeof(hash));
        query(0, m, 1);
        printf("%d\n",cnt);
    }
    return 0;
}
