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

long long l, r, k;
long long a[1000];

/**
1 1000000000000000000 100000549

1 100000549 10000109800301401

1 100000549 10000109800301401 27110551962814173

1 1000000000000000000 100000000000000073
1 100000000000000073
*/

int main( ){
    cin>>l>>r>>k;
    int p = 0;
    if(l == 1){
        a[p++]=1;
    }
    long long ans = 1;
    for(int i = 1;i < 100; ++i){
        if(ans>r/k) break;
        ans = ans*k;
        if(ans>=l){
            a[p++] = ans;
        }
    }
    if(p){
        for(int i = 0;i < p; ++i){
            cout<<a[i]<<" ";
        }
    }else{
        cout<<"-1";
    }
    cout<<endl;
    return 0;
}
