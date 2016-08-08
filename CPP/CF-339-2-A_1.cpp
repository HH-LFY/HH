#include <bits/stdc++.h>
using namespace std ;

int dfs(int a[],int num){
    if(num == 5){
        if(a[0]+a[1]+a[2]+a[3]+a[4] == a[1]*a[3] &&
           a[0]*a[4]+a[2]*a[3] == a[2]*a[2] &&
           a[1] + a[0] == a[2]){
            for(int i = 0;i < 5; ++i){
                printf("%d ",a[i]);
            }

            puts("");
           }
        return 1;
    }
    for(int i = 0;i < 5; ++i){
        a[num] = i;
        dfs(a,num+1);
    }
}

int main()
{

    int a,b,c,d,e;
    for(a = 0; a < 5; ++a){
        for(b = 0;b < 5; ++b){
            for(c = 0;c < 5; ++c){
                for(d = 0; d < 5; ++d){
                    for(e = 0;e < 5; ++e){
                        if((a+b+c+d+e)==(b*d) && (a*e+c*d)==c*c && (a+b==c)){
                            printf("%d %d %d %d %d\n",a,b,c,d,e);
                        }
                    }
                }
            }
        }
    }

    //int a[6];
    //dfs(a,0);
    return 0;
}
