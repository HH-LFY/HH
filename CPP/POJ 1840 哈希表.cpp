#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

const int maxx = 50*50*50*50*4 + 10;
short p[maxx];
int a[10];

int main( ){
    int inf = 50*50*50*50*2 + 5;
    while(scanf("%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5])!=EOF){
        memset(p,0,sizeof(p));
        for(int i = -50;i <= 50; ++i){
            for(int j = -50;j <= 50; ++j){
                if(i == 0 || j == 0)continue;
                p[i*i*i*a[1]+j*j*j*a[2]+inf]++;
            }
        }
        int ans = 0;
        for(int i = -50;i <= 50; ++i){
            for(int j = -50;j <= 50; ++j){
                for(int k = -50;k <= 50; ++k){
                    if(i == 0 || j == 0 || k == 0) continue;
                    int kx = -i*i*i*a[3]-j*j*j*a[4]-k*k*k*a[5]+inf;
                    if(kx > maxx || kx < 0) continue;
                    ans += p[kx];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
