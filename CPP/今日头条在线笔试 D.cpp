#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <vector>
#define bug(x) printf("bug_%d_\n",x);
using namespace std;

long long x;
long long k;
char x_str[2][100];

void get_x(int vis){
    char str[100];
    int len = 0;
    long long kx = x;
    if(vis == 1) kx = k;
    while(kx){
        if(kx%2){
            str[len++] = '1';
        }else{
            str[len++] = '0';
        }
        kx = kx/2;
    }
    len--;
    int i;
    for(i = 0; len>=0; ++i,--len){
        x_str[vis][i] = str[len];
    }
    x_str[vis][i] = '\0';
}

void get_ans(){
    char ans[100];
    int len[2];
    len[0] = strlen(x_str[0]);
    len[1] = strlen(x_str[1]);
/**
    for(int i = 0;i < len[0] ; ++i){
        printf("%c",x_str[0][i]);
    }
    puts("");
    for(int i = 0;i < len[1] ; ++i){
        printf("%c",x_str[1][i]);
    }
    puts("");
*/

    int ans_len = 0;
    for(int i = len[0]-1,j = len[1]-1 ;j >=0 ;){
        if(i < 0 || x_str[0][i] == '0'){
            ans[ans_len++] = x_str[1][j];
            i--;
            j--;
            //bug(1);
        }else{
           /// bug(2);
            ans[ans_len++] = '0';
            i--;
        }
    }
    long long bit = 1;
    long long num_ans = 0;
    for(int i = 0;i < ans_len; ++i){
       // printf("%c",ans[i]);
        if(ans[i] == '1'){
            num_ans += bit;
        }
        bit *= 2;
    }
    printf("%lld\n",num_ans);
}

int main( ){
    cin>>x>>k;
    get_x(0);
    get_x(1);
    get_ans();
    return 0;
}
