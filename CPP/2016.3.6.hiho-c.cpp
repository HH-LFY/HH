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

/**
 for (int i = 1; i <= N; i++)
     for (int v = 0; v <= V; v++)
        f[v] = max(f[v], f[v - c[i]] + w[i]);
*/

int Q;
int N, M, K, T;
int w[100+10];
int v[100+10];
long long dp[1000];

int main( ){
    cin>>Q;
    while(Q--){
        cin>>N>>M>>K>>T;
        for(int i = 0;i < M; ++i){
            cin>>w[i];
        }
        for(int i = 0;i < M; ++i){
            cin>>v[i];
        }
        long long ans = 0;
        for(int i = 0;i < N; ++i){
            if(i != 0){
                int judge = 0;
                for(int i = 0;i < M; ++i){
                    v[i] /= T;
                    if(v[i] == 0) judge++;
                }
                if(judge == M) {printf("No Answer\n"); return 0;}
            }
        }
    }
    return 0;
}
