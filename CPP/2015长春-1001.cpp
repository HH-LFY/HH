#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int maxx = 150000 + 10;
struct node{
    char name[210];
    int val;
    int id;
    bool operator < (const node& x) const {
        if(this->val == x.val) return this->id > x.id;
        return this->val < x.val;
    }
}a[maxx];
priority_queue<node> p;

struct time{
    int t;
    int p;
}num[maxx];
bool cmp(time x,time y){
    return x.t < y.t;
}
int ans[maxx];

int main(){
    int T;
    cin>>T;
    while(T--){
        while(!p.empty()) p.pop();
        int k, m, q;
        scanf("%d%d%d",&k,&m,&q);
        for(int i = 1;i <= k; ++i){
            scanf("%s%d",a[i].name,&a[i].val);
            a[i].id = i;
        }
        for(int i = 0;i < m; ++i){
            scanf("%d%d",&num[i].t,&num[i].p);
        }
        sort(num,num+m,cmp);
        num[m].t = k;
        num[m].p = k;
        int now = 1;
        int kp = 1;
        int kcount = 0;
        for(int i = 0;i <= m; ++i){
            while(now <= num[i].t&&now<=k){
                p.push(a[now]);
                now++;
            }
            kcount = num[i].p;
            while(!p.empty() && kcount>0){
                ans[kp++] = p.top().id;
                kcount--;
                p.pop();
            }
        }
        int x;
        for(int i = 1;i <= q ; ++i){
            scanf("%d",&x);
            if(i != q) printf("%s ",a[ans[x]].name);
            else printf("%s\n",a[ans[x]].name);
        }
    }
    return 0;
}
