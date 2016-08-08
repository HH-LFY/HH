#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[10];
int vis[10];
int kis[10];
int ans[10];
int p = 0;
int ks = 0;

int check_det(int x,int y,int z){
    if(a[x]+a[y]+a[z] == 15)
        return 1;
    return 0;
}

int check(){
    if(check_det(1,2,3) && check_det(4,5,6) && check_det(7,8,9)
       && check_det(1,4,7) && check_det(2,5,8) && check_det(3,6,9)
       && check_det(1,5,9) && check_det(3,5,7))
        return 1;
    return 0;
}

void dfs(int num){
    if(num == p){
        if(check()) {ks++;
            if(ks == 1){
                for(int i = 1;i <= 9; ++i) ans[i] = a[i];
            }
        }
        return ;
    }
    int now = kis[num];
    for(int i = 1;i <= 9; ++i){
        if(vis[i] == 0){
            vis[i] = 1;
            a[now] = i;

            dfs(num+1);

            a[now] = 0;
            vis[i] = 0;
        }
    }
    return ;
}

int main(){
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= 9; ++i ){
        cin>>a[i];
        if(a[i]>0){
            vis[a[i]] = 1;
        }else{
            kis[p++] = i;
        }
    }
    dfs(0);
    if(ks != 1) printf("Too Many\n");
    else{
        for(int i = 1;i <= 9; ++i){
            if(i%3 > 0) printf("%d ",ans[i]);
            if(i%3 == 0) printf("%d\n",ans[i]);
        }
    }
    return 0;
}
