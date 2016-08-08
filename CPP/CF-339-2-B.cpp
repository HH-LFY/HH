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

int n;
int z_c;
int tsj;
char ts[100010];
char str[100010];

int main( ){
    cin>>n;
    z_c = 0;
    tsj = 0;
    int judge = 1;
    while(n--){
        scanf("%s",str);
        if(str[0] == '0' || judge == 0){
            judge = 0;
        }else if(tsj){
            z_c += (strlen(str)-1);
        }
        else{
            int kcount = 0;
            int len = strlen(str);
            int one = 0;
            int no_one = 0;
            for(int i = 0;i < len; ++i){
                if(str[i] == '0') continue;
                if(str[i] == '1'){
                    one++;
                }else{
                    no_one++;
                }
            }
            int kj = 0;
            if(one>1){
                kj = 1;
            }else if(no_one>0){
                kj = 1;
            }
            if(kj){
                for(int i = 0;i < len; ++i){
                    ts[i] = str[i];
                }
                tsj = len;
            }else{
                z_c += (len-1);
            }
        }
    }
    if(judge){
        if(tsj == 0){
            printf("1");
            for(int  i = 1;i <= z_c; ++i){
                printf("0");
            }
            printf("\n");
        }else{
            for(int i = 0;i < tsj; ++i){
                printf("%c",ts[i]);
            }
            for(int i = 1;i <= z_c; ++i){
                printf("0");
            }
        }
    }else{
        printf("0");
    }
    printf("\n");
    return 0;
}
