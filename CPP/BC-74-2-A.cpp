#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
using namespace std;

__int64 ans = 0;
__int64 MOD = 1e9 + 7;
int T;
int n;
int a[100000+10];

int main( ){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        int judge = 0;
        int p = 0;
        for(int i = 0;i < n-1; ++i){
            scanf("%d",a+i);
            if(a[i] > n-i-1) judge = 1;
            if(a[i] == 0) p++;
        }
        for(int i = 1; i < n-1; ++i) {
            if(a[i-1] && a[i-1] - a[i] != 1 && !judge) {
                judge = 1;
                break;
            }
        }
        if(judge) printf("0\n");
        else{
            ans = 26;
            for(int i = 0; i < p; ++i) {
                ans = (ans*25)%MOD;
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
