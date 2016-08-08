/**


   Ïß¶ÎÊ÷ + lazy


**/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 200000 + 10;
struct node{
    int l;
    int r;
    int mid;
    int val;
    int sum;
}t[maxn<<2];
int n, m;

void push_up(int i){
    t[i].sum = t[i<<1].sum + t[i<<1|1].sum;
}

void push_down(int i){
    if(t[i].val != -1){
        t[i].sum = 0;
        t[i<<1].val = t[i<<1|1].val = 0;
        t[i<<1].sum = t[i<<1|1].sum = 0;
    }
}

void build(int i,int l,int r){
    t[i].l = l;
    t[i].r = r;
    t[i].mid = (l+r)>>1;
    t[i].val = -1;
    if(l == r){
        t[i].sum=1;
        return ;
    }
    build(i<<1,l,t[i].mid);
    build(i<<1|1,t[i].mid+1,r);
    push_up(i);
}

void update(int i,int ll,int rr){
    if(t[i].l >= ll && t[i].r <= rr){
        t[i].val = 0;
        t[i].sum = 0;
        return ;
    }
    push_down(i);
    if(ll <= t[i].mid) update(i<<1,ll,rr);
    if(rr>t[i].mid) update(i<<1|1,ll,rr);
    push_up(i);
}

int main( ){
    while(cin>>n>>m){
        build(1,1,n);
        int x, y;
        while(m--){
            scanf("%d%d",&x,&y);
            update(1,x,y);
            printf("%d\n",t[1].sum);
        }
    }
    return 0;
}
