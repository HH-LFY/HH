#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

const int maxx = 100000 + 10;
int f[maxx];
bool vis[maxx];
/**
int find(int x){

    if(x == f[x]) return x;
    return f[x] = find(f[x]);

}*/
int find(int x)
{
    int p = x, t;
    while (f[p] != p) p = f[p];
    while (x != p) { t = f[x]; f[x] = p; x = t; }
    return x;
}
int join(int x,int y){
    int fx = find(x);
    int fy = find(y);
    if(fx == fy) {
        return -1;
    }
    f[fx] = fy;
    return 0;
}

int main( ){
    int m, n;
    while(scanf("%d%d",&m,&n)!=EOF){
        if(m == -1 || n==-1) break;
        if(m == 0 || n==0){
            printf("Yes\n");
            continue;
        }
        for(int i = 0;i < maxx; ++i){
            f[i] = i;
        }
        memset(vis,false,sizeof(vis));
        int kmax = max(m,n);
        vis[m] = vis[n] = true;
        join(m,n);
        int x, y;
        int judge = 1;
        while(scanf("%d%d",&x,&y)){
            if(x == 0 || y==0) break;

            if(join(x,y) == -1){
                judge = -1;
            }
            if(x>kmax) kmax = x;
            if(y>kmax) kmax = y;
            vis[x]=vis[y]=true;
        }
        if(judge == 1){
            for(int i = 1;i <= kmax; ++i){
                if(vis[i] && f[i]==i){
                    judge--;
                    ///printf("%d \n",i);
                }
            }
        }
        if(judge <= -1){
            printf("No\n");
        }else{
            printf("Yes\n");
        }
    }
    return 0;
}
