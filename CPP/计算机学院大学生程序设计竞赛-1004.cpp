#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

struct node{
    int len;
    int id;
    bool operator<(const node a)const{
        return len<a.len;
    }
};
const int maxx = 111;
priority_queue<node> kmap[maxx];
vector<int> p;
int vis[maxx];
int N;

int main(){
    while(cin>>N){
        p.clear();
        for(int i = 0;i <= N; ++i){
            while(!kmap[i].empty())kmap[i].pop();
            vis[i]=0;
        }
        for(int i = 1;i <= N; ++i){
            for(int j = 1;j <= N; ++j){
                int x;
                scanf("%d",&x);
                node temp;
                temp.len = x;
                temp.id = j;
                kmap[i].push(temp);
            }
        }
        long long ans = 0;
        vis[1]=1;
        p.push_back(1);
        int inf = (1<<16)<<14;
        for(int i = 1;i <= N; ++i){
            int kmax = -inf;
            int kid = -1;
            for(int j = 0;j < p.size(); ++j){
                int now = p[j];
                while(!kmap[now].empty()){
                    node t = kmap[now].top();
                    if(vis[t.id] == 0){
                        if(kmax < t.len){
                            kmax = t.len;
                            kid = t.id;
                        }
                        break;
                    }
                    kmap[now].pop();
                }
            }
            if(kid!=-1){
                ans+=kmax;
                vis[kid]=1;
                p.push_back(kid);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
