#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxx = 110;
int T;
char str1[maxx],str2[maxx];
int N;

int main( ){
    cin>>T;
    while(T--){
        scanf("%d",&N);
        scanf("%s",str1);
        scanf("%s",str2);
        int flag = 1;
        for(int i = 0;i < N; ++i){
            if((str1[i] == 'A' && 'U'==str2[i])||
               (str1[i] == 'T' && 'A'==str2[i])||
               (str1[i] == 'C' && 'G'==str2[i])||
               (str1[i] == 'G' && 'C'==str2[i])){
                continue;
               }else{
                flag = 0;
                break;
               }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}
