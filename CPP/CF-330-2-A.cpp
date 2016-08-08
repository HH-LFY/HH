#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;

int main( ){
    cin>>n>>m;
    int ans = 0;
    for(int i = 1;i <= n; ++i){
        for(int j = 1;j <= m; ++j){
            int x, y;
            scanf("%d%d",&x,&y);
            if(x == 1||y == 1){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
