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
vector<int> edge[maxx];
int vis[maxx];
long long kis[3];
long long n, m;

int bfs(int x){
    queue<int> p;
    p.push(x);
    vis[x] = 1;
    kis[1]++;
    while(!p.empty()){
        int k = p.front();
        p.pop();
        for(int i = 0;i < edge[k].size(); ++i){
            int q = edge[k][i];
            if(vis[q] == 0){
                p.push(q);
                vis[q] = 3 - vis[k];
                kis[vis[q]]++;
            }else if(vis[k] == vis[q]){
               // cout<<vis[k]<<" "<<vis[q]<<endl;
                return 1;
            }
        }

    }
    return 0;
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i = 0;i < m; ++i){
        int x, y;
        scanf("%d%d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int kmax = 0;
    for(int i = 1;i <= n; ++i){
        if(edge[i].size() > kmax){
            kmax = edge[i].size();

        }
        vis[i] = 0;
        ///cout<<edge[i].size()<<endl;
    }

    long long ans = 0;
    if(kmax == 0){

        ans = (long long)((n*(n-1)*(n-2))/6);
        printf("3 %I64d\n",ans);
    }else if(kmax == 1){
        ans = (long long)((n-2)*m);
        printf("2 %I64d\n",ans);
    }else{
        int judge = 0;
        for(int i = 1;i <= n; ++i){
            kis[1] = 0;
            kis[2] = 0;
            if(vis[i] == 0){
                if(bfs(i)){
                    judge = 1;
                    break;
                }
                ans += (long long)(kis[1]*(kis[1]-1))/2; ///标记为1的点的个数
                ans += (long long)(kis[2]*(kis[2]-1))/2; ///标记为-1的点的个数
            }
        }
        if(judge){
            printf("0 1\n");
        }else{
            printf("1 %I64d\n",ans);
        }
    }
    return 0;
}
