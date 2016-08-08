#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long
#define bug printf("asdda");
using namespace std;

LL data[70];
int vis[2][100];
int vlen[2];

void init(){
    data[0] = 1;
    for(int i = 1;i <= 60; ++i){
        data[i]=data[i-1]*2;
        //cout<<data[i]<<endl;
    }
}

void solved(LL k,int id){
    vlen[id] = 0;
    while(k>0){
        vis[id][vlen[id]++] = k%2;
        k /= 2;
        ///bug;
    }
    for(int i = vlen[id];i <= 60; ++i){
        vis[id][i] = 0;
    }
    vlen[id]=61;
    /**
    for(int i = 0;i < vlen[id]; ++i){
        printf("%d",vis[id][i]);
    }
    printf("\n");
    */
}

int main(){
    init();
    int T;
    LL x,y;
    cin>>T;
    while(T--){
        scanf("%I64d%I64d",&x,&y);
        solved(x,0);
        solved(y,1);
        LL ans = 0;
        int now = 0;
        for(int i = 0;i <= 60; ++i){
            if(vis[0][i] == 1) continue;
            if(vis[0][i] == 0){
                if(vis[1][now] == 1){
                    ans += data[i];
                }
                now++;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
