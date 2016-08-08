#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int T;

const int maxx = 20000 + 10;
char str[maxx*2];
int n;
int min_str(){
    int i = 0, j = 1, k;
    while(j<2*n){
        if(str[i] > str[j]){
            i = j;
            j = i + 1;
        }else if(str[i] < str[j]){
            j++;
        }else{
            k = 0;
            while(k < n){
                if(str[i+k] < str[j+k]){
                    j+=k;
                    break;
                }else if(str[i+k] > str[j+k]){
                    i = j;
                    j +=k;
                    break;
                }
                k++;
            }
            if(k == n){
                return i;
            }
        }
    }
    return i-n;
}

int main( ){
    cin>>T;
    while(T--){
        scanf("%s",str);
        n = strlen(str);
        for(int i = 0;i < n; ++i){
            str[i+n] = str[i];
        }
        str[2*n] = '\0';
        printf("%d\n",min_str()+1);
    }
    return 0;
}

/**


*/
