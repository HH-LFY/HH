#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[1000];

int main( ){
    while(scanf("%s",str)!=EOF){
        int len = strlen(str);
        if((str[len-1]-'0')%2 == 0 ||str[len-1]=='0'||str[len-1]=='5'){
            printf("YES\n");
        }else{
            int ans = 0;
            for(int i = 0;i < len; ++i){
                ans += str[i]-'0';
            }
            if(ans%3 == 0) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
