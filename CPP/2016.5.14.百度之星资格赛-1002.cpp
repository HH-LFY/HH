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

long long num[220];

void init(){
    num[1] = 1;
    num[2] = 2;
    for(int i = 3;i <= 200; ++i){
        num[i] = num[i-1] + num[i-2];
    }
}

int main( ){
    int n;
    init();
    while(cin>>n){
        printf("%I64d\n",num[n]);
    }
    return 0;
}
