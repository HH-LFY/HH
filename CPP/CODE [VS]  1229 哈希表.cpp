#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
int a[20];
bool vis[20];
set<long long> p;
set<long long>::iterator it;

void dfs(int x,long long sum){
    if(x == n){
        p.insert(sum);
        return ;
    }
    for(int i = 1;i <= n; ++i){
        if(!vis[i]){
            sum = sum*10 + a[i];
            vis[i] = true;
            dfs(x+1,sum);
            sum = sum/10;
            vis[i] = false;
        }
    }
}

int main( ){
    cin>>n>>m;
    for(int i = 1;i <= n; ++i){
        scanf("%d",&a[i]);
        vis[i] = false;
    }
    p.clear();
    dfs(0,0);
    while(m--){
        int x, k;
        scanf("%d%d",&x,&k);
        int judge = 0;
        for(it=p.begin();it != p.end(); it++){
            if((*it+x)%k==0){
                printf("%lld\n",*it);
                judge=1;
                break;
            }
        }
        if(!judge) printf("None\n");
    }
    return 0;
}
