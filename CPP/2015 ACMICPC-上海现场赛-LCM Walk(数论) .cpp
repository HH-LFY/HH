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

int T;
int x,y;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main( ){
    int kcount = 1;
    cin>>T;
    while(T--){
        cin>>x>>y;
        int ans = 1;
        while(1){
            int k = gcd(x,y);
            if(x>y){
                swap(x,y);
            }
            if(y%(k+x) != 0) break;
            y = y/(1+x/k);
            ans++;
        }
        printf("Case #%d: %d\n",kcount++,ans);
    }
    return 0;
}
