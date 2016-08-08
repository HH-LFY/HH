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

const int inf = 1e2;
int n, m;
int kmap[250][250];

int main( ){
    while(cin>>n>>m){
        int x, y;
        for(int i = 0;i < n; ++i){
            for(int j = 0;j < n; ++j){
                kmap[i][j] = inf;
                if(i == j) kmap[i][j] = 0;
            }
        }
        while(m--){
            scanf("%d%d",&x,&y);
            kmap[x][y] = kmap[y][x] = 1;
        }
        for(int k = 0;k < n; ++k){
            for(int j = 0;j < n; ++j){
                for(int i = 0;i < n; ++i){
                    kmap[i][j] = min(kmap[i][k]+kmap[k][j],kmap[i][j]);
                }
            }
        }
        int judge = 0;
        for(int i = 0;i < n; ++i){
            for(int j = 0;j < n; ++j){
                if(kmap[i][j]>7) judge = 1;
            }
        }
        if(!judge) puts("Yes");
        else puts("No");
    }
    return 0;
}
