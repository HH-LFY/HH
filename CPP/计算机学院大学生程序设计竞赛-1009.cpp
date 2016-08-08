#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

char choose;
int wl,wa,wd;
int bl,ba,bd;

int main(){
    while(cin>>choose){
        scanf("%d%d%d",&wl,&wa,&wd);
        scanf("%d%d%d",&bl,&ba,&bd);
        int ws = ba-wd;
        if(ws<0) ws = 0;
        int bs = wa-bd;
        if(bs<0) bs = 0;
        if(ws == 0 && bs == 0){
            printf("Warrior loses\n");
        }else if(ws==0&&bs!=0){
            printf("Warrior wins\n");
        }else if(ws!=0&&bs==0){
            printf("Warrior loses\n");
        }else{
            int turnw = wl/ws;
            int turnb = bl/bs;
            if(choose == 'W'){
                if(turnw>=turnb){
                    printf("Warrior wins\n");
                }else{
                    printf("Warrior loses\n");
                }
            }else{
                if(turnb>=turnw){
                    printf("Warrior loses\n");
                }else{
                    printf("Warrior wins\n");
                }
            }
        }
    }
    return 0;
}
