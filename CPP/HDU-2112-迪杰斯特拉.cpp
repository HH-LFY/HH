#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;

struct node{
    int s;
    int e;
    int t;
    bool operator < (const node x)const {
        return t > x.t;
    }
};
int n;
map<string,int> m;///地名映射
int p;///地名
int a[250][250];
priority_queue<node> pq;
int ss, ee;

void djs(){
    bool vis[200];
    int dis[200];
    for(int i = 0;i < p; ++i){
        vis[i] = false;
        dis[i] = 1e8;
    }
    dis[0] = 0;
    vis[0] = true;
    for(int i = 1;i < p; ++i){
        if(a[0][i] != 1e8){
            node temp;
            temp.s = 0;
            temp.e = i;
            temp.t = a[0][i];
            pq.push(temp);
        }
    }
    while(!pq.empty()){
        node now = pq.top();
        pq.pop();
        if(vis[now.s]+vis[now.e] >= 2) continue;
        vis[now.s] = vis[now.e] = 1;
        dis[now.e] = now.t;
        for(int i = 0;i < p; ++i){
            if(vis[i]) continue;
            if(dis[i]>dis[now.e]+a[now.e][i]){
                node temp;
                temp.s = 0;
                temp.e = i;
                temp.t = dis[now.e]+a[now.e][i];
                pq.push(temp);
            }
        }
    }
    if(dis[ee] == 1e8){
        puts("-1");
    }else{
        printf("%d\n",dis[ee]);
    }
}

int main( ){
    while(cin>>n){
        if(n == -1) break;
        m.clear();
        for(int i = 0;i < 250; ++i){
            for(int j = 0;j < 250; ++j){
                if(i == j) a[i][j] = 0;
                else a[i][j] = 1e8;
            }
        }
        p = 0;
        string s, e;
        cin>>s>>e;
        m[s] = p++;
        if(m.count(e)<=0)m[e] = p++;
        ss = m[s];
        ee = m[e];
        int x, y, t;
        for(int i = 0;i < n; ++i){
            cin>>s>>e>>t;
            if(m.count(s)) x = m[s];
            else{
                x = p;
                m[s] = p++;
            }
            if(m.count(e)) y = m[e];
            else{
                y = p;
                m[e] = p++;
            }
            a[x][y] = a[y][x] = t;
        }
        djs();
    }
    return 0;
}
