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

const int maxx = 1e3 + 10;
int f[maxx];
int ans;

int find(int x){
    if(f[x] == x) return x;
    return f[x]=find(f[x]);
}

void join(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx != fy){
        ans--;
        f[fx] = fy;
    }
}

int main( ){
    int T;
    int n, m;
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&m);
        ans = n;
        for(int i = 1;i <= n; ++i){
            f[i] = i;
        }
        int x, y;
        for(int i = 0;i < m; ++i){
            scanf("%d%d",&x,&y);
            join(x,y);
        }
        printf("%d\n",ans);
    }
    return 0;
}
