#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool ok(int x){
    int a = x/100;
    int b = (x/10)%10;
    int c = x%10;
    if((a<b&&b>=c)||(b<c&&a>=b)){
        return true;
    }
    return false;
}

int main( ){
    int ans = 0;
    for(int i = 123;i <= 321; ++i){
        if(ok(i)){
            printf("%d\n",i);
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
