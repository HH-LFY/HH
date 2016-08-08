#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct node{
    int id;
    int kis[4];
}vis[15][15];
char m[15][15];
int w, h;
int ans;

bool ok(int x,int y){
    if(x < 0 || x >= w) return false;
    if(y < 0 || y >= h) return false;
    if(m[x][y] != '*') return true;
    return false;
}

void dfs(int x,int y,int kd){
    ///printf("%d %d %d\n",x,y,kd);
    if(vis[x][y].kis[kd]){
        return ;
    }

    vis[x][y].kis[kd] = 1;
    for(int i = 0;i < 4; ++i){
        int kx = x + dir[(kd+i)%4][0];
        int ky = y + dir[(kd+i)%4][1];
        if(ok(kx,ky)){
            vis[kx][ky].id = 1;
            dfs(kx,ky,(kd+i)%4);
            return ;
        }
    }
}

int main( ){
    cin>>w>>h;
    ans = 0;
    for(int i = 0;i < 15; ++i){
        for(int j = 0;j < 15; ++j){
            vis[i][j].id = 0;
            vis[i][j].kis[0] = vis[i][j].kis[1] =vis[i][j].kis[2] = vis[i][j].kis[3] = 0;
        }
    }
    int s, t;
    int sdir;
    for(int i = 0;i < w; ++i){
        getchar();
        for(int j = 0;j  < h; ++j){
            m[i][j] = getchar();
            ///printf("%c\n",m[i][j]);
            if(m[i][j] == '.' || m[i][j] == '*'){
                continue;
            }
            if(m[i][j] == 'U'){
                sdir = 0;
                s = i;
                t = j;
            }else if(m[i][j] == 'R'){
                sdir = 1;
                s = i;
                t = j;
            }else if(m[i][j] == 'L'){
                sdir = 3;
                s = i;
                t = j;
            }else if(m[i][j] == 'D'){
                sdir = 2;
                s = i;
                t = j;
            }
        }
    }
    ///printf("%d %d\n",s,t);
    vis[s][t].id = 1;
    dfs(s,t,sdir);
    for(int i = 0;i < 15; ++i){
        for(int j = 0;j < 15; ++j){
            if(vis[i][j].id == 1) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
