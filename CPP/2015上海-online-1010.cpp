#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxx = 100+10;
struct node{
    int l;
    int r;
}num[maxx];
int T;
int n, a, b, L;

bool cmd(node x,node y){
    return x.l<y.l;
}

int main( ){
    cin>>T;
    int count = 1;
    while(T--){
        scanf("%d%d%d%d",&n,&a,&b,&L);
        for(int i = 0;i < n; ++i){
            scanf("%d%d",&num[i].l,&num[i].r);
        }
        sort(num,num+n,cmd);
        int ans = 0;
        int kans = 0;
        int now = 0;
        for(int i = 0;i < n; ++i){
            if(now<num[i].l){
                kans+=(num[i].l-now)*b;
                now = num[i].l;
            }
            kans -= (num[i].r-num[i].l)*a;
            now = num[i].r;
            ans = max(-kans,ans);
        }
        printf("Case #%d: %d\n",count++,ans);
    }
    return 0;
}
