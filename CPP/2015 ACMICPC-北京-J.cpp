#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
char str[10];

int main( ){
    while(scanf("%d",&n)!=EOF){
        int ans = 0;
        int now=0;
        while(n--){
            scanf("%s",str);

            if(str[0]=='C'||'B'==str[0]){
                int x;
                scanf("%d",&x);
                ///printf("x=%d now=%d\n",x,now);
                if(x > now){
                    now = x;
                }else{
                    ans++;
                    ///printf("now=%d ans=%d\n",now,ans);
                    now = x;
                }
            }else{
                if(now != 0){
                    now = 0;
                    ans++;
                }
                ans++;
            }

        }
        if(now != 0) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
/**
10
C 1
C 2
B 3
C 1
B 2
B 1
S
C 1
S
B 1
1
S
0
2
S
B 1
*/
