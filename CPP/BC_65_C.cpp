#include <iostream>
#include <cstdio>
#include <algorithm>
#define bug1 printf("bug1\n")
#define lson rt<<1
#define rson rt<<1|1
using namespace std;

const int maxx = 50010;
struct stree{
    int l;
    int r;
    int val;
}a[maxx*4];

void push_up(int rt){
    a[rt].val = a[lson].val + a[rson].val;
}

void build(int rt,int l,int r){
    a[rt].l = l;
    a[rt].r = r;
    if(l == r){
        a[rt].val = 1;
        return ;
    }
    int mid = (l+r)>>1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    push_up(rt);
}

void update(int rt,int k){
    if(a[rt].l == a[rt].r){
        a[rt].val = 0;
        return ;
    }
    int mid = (a[rt].l + a[rt].r)>>1;
    if(k<=mid) update(lson,k);
    else update(rson,k);
    push_up(rt);
}

int query(int rt,int k){
   if(a[rt].l==a[rt].r){
        return a[rt].l;
   }
   int mid = (a[rt].l+a[rt].r)>>1;
   if(a[lson].val>=k) return query(lson,k);
   else return query(rson,k-a[lson].val);
}

int T, N;
int ans[maxx];
int num[maxx];

int main( ){
    cin>>T;
    num[0] = 0;
    while(T--){
        cin>>N;
        build(1,1,N);
        for(int i = 1;i <= N; ++i){
            scanf("%d",&num[i]);
        }
        for(int i = N;i >= 1; --i){
            num[i]=num[i]-num[i-1];
        }
        for(int i = N; i >= 1; --i){
            ans[i] = query(1,i-num[i]);
            update(1,ans[i]);
        }
        for(int i = 1;i < N; ++i){
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[N]);
    }
    return 0;
}
