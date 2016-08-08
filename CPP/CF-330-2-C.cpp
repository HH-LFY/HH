#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct node{
    int x, y;
};
const int maxx = 220;
vector<node> vis[maxx];
vector<node> p;
int kis[maxx];
int K, kp;
bool m[2010][2010];
int N, M;

bool ok(int kk){
    for(int i = 0;i < p.size(); ++i){
        int flag = 1;
        for(int j = 0;j < vis[kk].size(); ++j){
            int dx = p[i].x + vis[kk][j].x;
            int dy = p[i].y + vis[kk][j].y;
            if(dx<0||dx>=2010){flag=0;break;}
            if(dy<0||dy>=2010){flag=0;break;}
            if(!m[dx][dy]) {flag=0;break;}
        }
        if(flag) return true;
    }
    return false;
}

void solved(){
    for(int i = 0;i < kp; ++i){
        if(kis[i]==true){
            puts("Yes");
            continue;
        }
        if(ok(i)){
            puts("Yes");
        }else{
            puts("No");
        }
    }
}

int main( ){
    scanf("%d",&K);
    memset(kis,0,sizeof(kis));
    memset(m,false,sizeof(m));
    for(kp = 0;kp < K; ++kp){
        int dx = -1;
        int dy = -1;
        int h, w;
        scanf("%d%d",&h,&w);
        for(int i = 1;i <= h; ++i){
            getchar();
            for(int j = 1;j <= w; ++j){
                char c = getchar();
                if(c == '.') continue;
                if(dx != -1){
                    node xx;
                    xx.x = i-dx;
                    xx.y = j-dy;
                    vis[kp].push_back(xx);
                }else{
                    dx = i;
                    dy = j;
                }
            }
        }
        if(dx == -1) kis[kp]=2;
        else kis[kp] = 0;
    }
    scanf("%d%d",&N,&M);
    for(int i = 1;i <= N; ++i){
        getchar();
        for(int j = 1;j <= M; ++j){
            char c = getchar();
            if(c == '#'){
                m[i][j]=true;
                node xx;
                xx.x=i;
                xx.y=j;
                p.push_back(xx);
            }
        }
    }
    solved();
    return 0;
}
