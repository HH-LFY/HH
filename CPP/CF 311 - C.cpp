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

const int maxx = 1e5 + 10;
struct node{
    int l;
    int d;
}a[maxx];
int sum[maxx];
int num[maxx];
int k[210];
int n;
int kmin;

void init(){
    for(int i = 0;i < 210; ++i){
        k[i] = 0;
    }
    kmin = inf;
}

inline void input(){
    for(int i = 0;i < n; ++i){
        scanf("%d",&a[i].l);
    }
    for(int i = 0;i < n; ++i){
        scanf("%d",&a[i].d);
    }
}

int cmd(node x,node y){
    return x.l<y.l;
}

void solved(){
    sort(a,a+n,cmd);
    sum[0] = a[0].d;
    int p = 0;
    int x = a[0].l;
    int kcount = 1;
    for(int i = 1;i < n; ++i){
        sum[i] = sum[i - 1] + a[i].d;
        if(a[i].l == x){
            kcount++;
        }else{
            num[p++] = kcount;
            kcount = 1;
            x = a[i].l;
        }
    }
    num[p++] = kcount;
    int ksum = sum[n-1];
    int now = 0;
    for(int i = 0;i < p; ++i){
        int ans = ksum - sum[now+num[i]-1];
        int know = now;
        if(num[i] <= know){
            for(int j = 1;j <= 200; ++j){
                if(k[j]){
                    if(know - k[j] < num[i]){
                        ans += (know - num[i] + 1)*j;
                        break;
                    }else{
                        ans += (k[j])*j;
                        know -= k[j];
                    }
                }
            }
        }
        kmin = min(ans,kmin);
        for(int j = now;j < now+num[i]; ++j){
            k[a[j].d]++;
        }
        now += num[i];
    }
    printf("%d\n",kmin);
}

int main(){
    //freopen("input.txt","r",stdin);
    while(cin>>n){
        init();
        input();
        solved();
    }
    return 0;
}
