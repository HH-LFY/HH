#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxx = 50000+500;
struct node{
    int id;
    int num;
}a[maxx];
int vis[maxx];
long long b[maxx];
int T;
int N;
int p;
int ans[maxx];

bool cmd(node x,node y){
    if(x.num == y.num) return x.id < y.id;
    return x.num > y.num;
}

void show(){
    for(int i = 1;i <= N; ++i) printf("%d ",a[i].num);
    puts("");
}

void show1(){
    for(int i = 0;i <p; ++i) printf("%d ",vis[i]);
    puts("");
}

int main( ){
    cin>>T;
    while(T--){
        p = 0;
        scanf("%d",&N);
        for(int i = 1;i <= N; ++i){
            a[i].id = i;
            scanf("%I64d",&b[i]);
        }
        a[1].num = 0;
        vis[p++] = 1;
        for(int i = 2;i <= N; ++i){
            a[i].num = b[i]-b[i-1];
            if(a[i].num == 0) vis[p++] = i;
        }
        int kn = 1;
       /// show();
        ///show1();
        sort(a+1,a+N+1,cmd);
        for(int j=1; j <= N; ++j){
            ans[a[j].id] = kn++;
        }
        for(int i = 1;i < N; ++i){
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[N]);
    }
    return 0;
}
