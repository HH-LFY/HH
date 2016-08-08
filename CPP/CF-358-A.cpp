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

int n, m;

int main( ){
    cin>>n>>m;
    long long sum = 0;
    for(int i = 1;i <= n; ++i){
        int ll = i;
        int rr = i+m;
        sum = sum - (ll/5) + (rr/5);
        //cout<<i<<":"<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
