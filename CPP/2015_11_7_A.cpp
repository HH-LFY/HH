#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxx = 55;
int num[maxx*maxx*maxx*2][maxx];
int a[maxx];
int T;
int N;
int L, R;
int now;
int flag;

bool ok(int x){
    for(int i = 1;i <= 52; ++i){
        if(a[i] != num[x][i])return false;
    }
    return true;
}

void solved(){
    int kp = 1;
    for(int i = L;i <= R; ++i)num[now][kp++] = num[now-1][i];
    for(int i = 1;i < L; ++i) num[now][kp++] = num[now-1][i];
    for(int i = R+1;i <= 52; ++i) num[now][kp++] = num[now-1][i];
    if(ok(now)){
        flag = now;
    }
}

int main( ){
    cin>>T;
    int kcount = 1;
    while(T--){
        now = 1;
        flag = -1;
        for(int i = 1;i <= 52; ++i){
            scanf("%d",&a[i]);
            num[0][i] = a[i];
        }
        scanf("%d%d%d",&N,&L,&R);
        if(N == 0){
            printf("Case #%d:",kcount++);
            for(int i = 1;i <= 52; ++i){
                printf(" %d",num[0][i]);
            }
            printf("\n");
            continue;
        }
        while(1){
            solved();
            now++;
            ///printf("%d\n",now);
            if(flag>0) break;
        }
        N = N%flag;
        printf("Case #%d:",kcount++);
        for(int i = 1;i <= 52; ++i){
            printf(" %d",num[N][i]);
        }
        printf("\n");
    }
    return 0;
}
