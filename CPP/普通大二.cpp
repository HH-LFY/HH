#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct node{
    int x,y;
};
int vis[10];
int dis[10];
node t[10];

int get2(node a,node b){
    return (a.x-b.x)*(a.x-b.x)+(b.y-a.y)*(b.y-a.y);
}

bool dfs(int x,int num){
    for(int i = 0;i < 3; ++i){
        if(vis[i]) continue;
        vis[i] = 1;
        for(int j = 0;j < 3; ++j){
            if(vis[j])continue;
            vis[j] = 1;
            if(dis[i]*dis[j] == x){
                if(num == 2){
                    return true;
                }else{
                    dfs(x,num+1);
                }
            }
            vis[j] = 0;
        }
        vis[i] = 0;
    }
    return false;
}

bool solved(){
    int k1 = 0;
    for(int i = 0;i < 3; ++i)
        for(int j = i+1;j < 3; ++j)
            dis[k1++]=get2(t[i],t[j]);
    for(int i = 3;i < 6; ++i)
        for(int j = i+1;j < 6; ++j)
            dis[k1++]=get2(t[i],t[j]);
    vis[0] = 1;
    for(int i = 3;i < 6; ++i){
        vis[i] = 1;
        if(dfs(dis[0]*dis[i],1)){
            return true;
        }
        vis[i] = 0;
    }
    return false;
}

int main( ){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(scanf("%d%d",&t[0].x,&t[0].y)!=EOF){
        for(int i = 1;i < 6; ++i){
            scanf("%d%d",&t[i].x,&t[i].y);
        }
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        if(solved()){
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}
