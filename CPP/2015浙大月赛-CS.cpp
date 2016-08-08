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
using namespace std;

const int maxx = 1e6 + 15;
const int maxn = 1e7 + 10;
bool vis[maxn];
int prime[maxx*10];
int n, Q;
struct node{
    int l;
    int r;
    int sum;
    int val;
    int update;
}tree[maxx<<2];

void init(){
    memset(vis,0,sizeof(vis));
    int num=0;
    vis[0]=vis[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            prime[++num]=i;
        }
        for(int j=1;j<=num&&i*prime[j]<maxn;j++){
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
    for(int i=1;i<maxn;i++) vis[i]=!vis[i];
}

void pushup(int i){
    tree[i].sum = tree[i<<1].sum+tree[i<<1|1].sum;
}
void PushDown(int i,int L){
    int mark = tree[i].update;
    if(mark != -1){
        tree[i<<1].update = tree[i<<1|1].update = mark;
        tree[i<<1].val=tree[i<<1|1].val=mark;
        tree[i<<1].sum = vis[mark]?(L-(L>>1)):0;
        tree[i<<1|1].sum = vis[mark]?(L>>1):0;

    }
    tree[i].update = -1;
}
void build(int i,int l,int r){
    tree[i].l = l;
    tree[i].r = r;
    tree[i].update = -1;
    tree[i].sum=-1;
    tree[i].val=-1;
    if(l == r){
        scanf("%d",&tree[i].val);
        tree[i].sum = vis[tree[i].val];
        return ;
    }
    int mid = (l+r)>>1;
    build(i<<1,l,mid);
    build(i<<1|1,mid+1,r);
    pushup(i);
}
void add(int i,int id,int v){
    if(tree[i].l == id && id ==  tree[i].r){
        tree[i].val += v;
        tree[i].sum = vis[tree[i].val];
        return ;
    }
    int mid = (tree[i].l+tree[i].r)>>1;
    PushDown(i,tree[i].r-tree[i].l+1);
    if(id<=mid) add(i<<1,id,v);
    else     add(i<<1|1,id,v);
    pushup(i);
}
void update(int i,int l,int r,int a){
    if(tree[i].l >= l && tree[i].r <= r){
        tree[i].sum = vis[a]?(tree[i].r-tree[i].l+1):0;
        tree[i].update = a;
        tree[i].val = a;
        return ;
    }
    PushDown(i,tree[i].r-tree[i].l+1);
    int mid = (tree[i].l+tree[i].r)>>1;
    if(l<=mid) update(i<<1,l,r,a);
    if(r>mid) update(i<<1|1,l,r,a);
    pushup(i);
}
int query(int i,int l,int r){
    if(tree[i].l >= l && tree[i].r <= r){
        return tree[i].sum;
    }
    PushDown(i,tree[i].r-tree[i].l+1);
    int ans = 0;
    int mid = (tree[i].l+tree[i].r)>>1;
    if(l<=mid)ans += query(i<<1,l,r);
    if(r>mid) ans += query(i<<1|1,l,r);
    return ans;
}
int main(){
    init();
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&Q);
        build(1,1,n);
        char str[5];
        int v,a,l,r;
        while(Q--){
            scanf("%s",str);
            if(str[0] == 'A'){
                scanf("%d%d",&v,&l);
                add(1,l,v);
            }else if(str[0] == 'Q'){
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,l,r));
            }else{
                scanf("%d%d%d",&a,&l,&r);
                update(1,l,r,a);
            }
        }
    }
    return 0;
}
