#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
int T, n;
int a[maxn];

int main( ){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i = 1;i <= n; ++i){
            scanf("%d",a+i);
        }
    }
    return 0;
}
/**

1000
3
2 1 7
3
3 2 1
5
3 1 4 1 5
5
5 5 1 2 3
5
5 1 2 3 4
5
5 4 1 2 3
6
1 2 3 -1 4 5
7
1 -1 1 2 3 4 5
5
1 1 -1 -1 1

**/
