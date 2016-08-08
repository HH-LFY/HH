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

const int maxx = 5000 + 10;
int N,M;
struct node{
    int color;
    int k;
}rc[2][maxx];
int k;///op

int new_max(node x,node y){
    if(x.k > y.k){
        return x.color;
    }else{
        return y.color;
    }
}

int main( ){
    cin>>N>>M>>k;
    int op,op_count,color;
    for(int i = 0;i < k; ++i){
        rc[1][op_count].color = 0;
        rc[1][op_count].k = 0;
        rc[0][op_count].color = 0;
        rc[0][op_count].k = 0;
    }
    for(int i = 1;i <= k; ++i){
        cin>>op>>op_count>>color;
        rc[op-1][op_count].color = color;
        rc[op-1][op_count].k = i;
    }
    for(int i = 1;i <= N; ++i){
        for(int  j = 1;j <= M; ++j){
            printf("%d",new_max(rc[0][i],rc[1][j]));
            if(j!=M) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
