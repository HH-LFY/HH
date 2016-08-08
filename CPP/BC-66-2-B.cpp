#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

const int maxx = 50000+10;
int p[maxx];
int kis[maxx];
int vis[maxx];
int n, m;
int T;

int main( ){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 0;i <= n+1 ; ++i) kis[i] = 0;
        for(int i = 1;i <= n; ++i){
            scanf("%d%d",&vis[i],&p[i]);
        }
        for(int i = 1;i <= m; ++i){
            int x;
            scanf("%d",&x);
            kis[1]++;
            kis[x+1]--;
        }
        int sum = 0;
        for(int i = 1;i <= n; ++i){
            sum+=kis[i];
            p[i]+=sum;
        }
        int t[2];
        t[0]=t[1]=-1;
        int ans = n;
        for(int i = n;i >= 1; --i){
            if(t[vis[i]]==-1){
                t[vis[i]] = p[i];
            }else if(t[vis[i]] < p[i]){
                t[vis[i]] = p[i];
            }
            if(t[!vis[i]]!=-1 && t[!vis[i]] > p[i]){
                ans--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
