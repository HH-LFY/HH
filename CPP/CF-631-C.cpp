#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <vector>
using namespace std;

stack<int> p;
const int maxx = 200000 + 10;
struct node{
    int t;
    int r;
}op[maxx];
int n, m;
int num[maxx];
int ans[maxx];

int main( ){
    cin>>n>>m;

    for(int i = 1;i <= n; ++i){
        cin>>num[i];
    }
    for(int i = 1;i <= m; ++i){
        cin>>op[i].t>>op[i].r;
    }
    p.push(0);
    for(int i = m; i >= 1; --i){
        if(op[i].r > op[p.top()].r){
            p.push(i);
        }
    }
    int l = 1;
    int r = op[p.top()].r;
    for(int i = r+1;i <= n; ++i){
        ans[i] = num[i];
    }
    int nowr = r;
    int nowt = op[p.top()].t;
    sort(num+1,num+r+1);
    p.pop();
    while(!p.empty()) {
        int nextr = op[p.top()].r;
        int nextt = op[p.top()].t;
        for(int i = nowr; i > nextr; --i) {
            if(nowt == 1)ans[i] = num[r--];
            else ans[i] = num[l++];
        }
        nowr = nextr;
        nowt = nextt;
        p.pop();
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d ",ans[i]);
    }
    puts("");
    return 0;
}
