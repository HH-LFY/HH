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
using namespace std;

int prime[110];
int vis[110];

void init(){
    memset(prime,0,sizeof(prime));
    prime[2] = 1;
    prime[3] = 1;
    for(int i = 4;i <= 100; ++i){
        int judge = 0;
        int temp = sqrt(i);
        for(int j = 2;j <= temp; ++j){
            if(i%j == 0){
                judge = 1;
                break;
            }
        }
        if(judge)continue;
        prime[i] = 1;
    }
}

int main( ){
    init();
    int num = 99;
    int num_p = 25;
    int nice = 0;
    char str[10];
    int judge = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 2;i <= 100; ++i){
        if(vis[i])continue;
        printf("%d\n",i);
        fflush(stdout);
        cin>>str;
        if(prime[i]) num_p--;
        if(strcmp(str,"yes")==0){
            judge++;
            if(judge>=2){
                break;
            }
            for(int j = i;j <= 100;j++){
                if(j%i&&!vis[j]){
                    vis[j] = 1;
                    num--;
                }
            }
        }else{
            for(int j = i; j<= 100; ++j){
                if(j%i==0&&!vis[j]){
                    vis[j] = 1;
                    num--;
                }
            }
        }
        for(int j = i+1;j <= 100; ++j){
            if(vis[j]) continue;
            printf("%3d",j);
        }
        cout<<endl;
        nice++;
        if(num == num_p){
            judge = -1;
            break;
        }
        printf("%d: %d   ---   %d \n",nice,num,num_p);
        if(nice>=20){
            nice = i+1;
            break;
        }
    }
    if(judge>=2){
        printf("composite\n");
    }else{
        printf("prime\n");
    }
}
