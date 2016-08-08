#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#define PI acos(-1.0)
#define eps 1e-8
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 1e3 + 10;
int l[maxx], r[maxx];
char str[maxx * 100];
bool vis[maxx * 100];
int k[maxx];
int N, M, Q;

void input(){
    scanf("%s",str);
    for(int i = 0;i < M; ++i){
        scanf("%d%d",&l[i],&r[i]);
    }
    for(int i = 0;i < Q; ++i){
        scanf("%d",&k[i]);
    }
}

void output(){
    for(int i = 0;i < Q; ++i){
        int t = k[i];
        for(int j = M-1;j >= 0; --j){
            if(t >= l[j] && r[j] >= t){
                t = l[j] + r[j] - t;
            }
            else continue;
        }
        putchar(str[t-1]);
    }
    puts("");
}

void solved(){
}



int main(){
    while(scanf("%d%d%d",&N,&M,&Q)!=EOF){
        input();
        solved();
        output();
    }
    return 0;
}
