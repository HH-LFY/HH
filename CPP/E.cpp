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
const int  inf =  1000000007;
using namespace std;

int vis[11];
long long kis[155];

void hehe(){
    kis[0] = 1;
    kis[1] = 1;
    for(int i = 2;i < 151; ++i){
        kis[i] = (kis[i - 1] * i)%inf;
    }
}

int main()
{
    int n;
    char str[70];
    hehe();
    while(scanf("%d",&n)!=EOF){
        getchar();
        for(int i = 0;i < n; ++i){
            str[i] = getchar();
        }
        vis[2] = vis[3] = vis[5] = vis[7] = 0;
        for(int i = 0;i < strlen(str); ++i){
                if(str[i] == '2'){
                    vis[2]++;
                }else if(str[i] == '3'){
                    vis[3]++;
                }else if(str[i] == '4'){
                    vis[2]+=2;
                }else if(str[i] == '5'){
                    vis[5]++;
                }else if(str[i] == '6'){
                    vis[2]++;
                    vis[3]++;
                }else if(str[i] == '7'){
                    vis[7]++;
                }else if(str[i] == '8'){
                    vis[2]+=3;
                }else if(str[i] == '9'){
                    vis[3]+=2;
                }
        }
        if(!vis[2] && !vis[3] && !vis[5] &&!vis[7]){
            printf("0\n");
            continue;
        }
        long long ans = 0;
        for(int i = 0;i <= 50; ++i){
                if(i*2 > vis[2]) break;
            for(int j = 0; j <= 100; ++j){
                if(i*2 + j > vis[2] || j > vis[3]) break;
                for(int k = 0;k <= 50; ++k){
                    if(i*2 + j + 3*k > vis[2]) break;
                    for(int t = 0;t <= 50 ; ++t){
                        int vis2 = i*2 + j + 3*k;
                        int vis3 = j + 2*t;
                        if(vis2 > vis[2] || vis3 > vis[3]) break;

                        ans += ((kis[vis[2]+vis[3]+vis[5]+vis[7]-vis2-vis3+i+j+k+t])/
                                (((kis[vis[2] - vis2]*kis[vis[3] - vis3])*
                                  (kis[i]*kis[j]%inf)*
                                  (kis[k]*kis[t]%inf)*
                                  (kis[vis[5]]*kis[vis[7]]))%inf));

                        ans = ans%inf;
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
