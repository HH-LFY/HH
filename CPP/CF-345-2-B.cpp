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

const int maxx = 1000 + 10;
int a[maxx];
int n;

int main( ){
    cin>>n;
    memset(a,0,sizeof(a));

    int x;
    for(int i = 0;i < n; ++i){
        scanf("%d",&x);
        a[x]++;
    }
    int ans = 0;
    while(true){
        int sum = 0;
        for(int i = 1;i <= 1000; ++i){
            if(a[i]){
                a[i]--;
                sum++;
            }
        }
        if(sum){
            ans += (sum-1);
        }else{
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
