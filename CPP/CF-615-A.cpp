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
int a[110];

int main( ){
    memset(a,0,sizeof(a));
    cin>>n>>m;
    while(n--){
        int k;
        cin>>k;
        while(k--){
            int x;
            cin>>x;
            a[x]=1;
        }
    }
    for(int i = 1;i <= m; ++i){
        if(!a[i]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
