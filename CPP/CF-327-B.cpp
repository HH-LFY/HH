#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 200000 + 10;
int str[maxn];
char kstr[maxn];
int vis[30];
int n, m;

int main( ){
    for(int i = 0;i < 30; ++i){
        vis[i] = i;
    }
    cin>>n>>m;
    scanf("%s",kstr);
    for(int i = 0;i < n; ++i){
        str[i] = kstr[i]-'a';
    }

    while(m--){
        getchar();
        char x, y;
        x=getchar();
        getchar();
        y=getchar();
        //printf("%c%c\n",x,y);
        int kx = x-'a';
        int judge1 = 0;
        int judge2 = 0;
        int ky = y-'a';
        for(int i = 0;i <= 26; ++i){
            if(kx == vis[i]&&judge1 == 0){
                kx = i;
                judge1 = 1;
            }
            if(ky == vis[i]&&judge2 == 0){
                ky = i;
                judge2 = 1;
            }

        }
        //printf("%d %d\n",kx,ky);
        swap(vis[kx],vis[ky]);
    }
    for(int i = 0;i < n; ++i){
        printf("%c",'a'+vis[str[i]]);
    }
    puts("");
    return 0;
}
