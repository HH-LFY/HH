#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxx = 2000;
char str[maxx][maxx];
int vis[maxx];
int N;

int check(char s1[],char s2[]){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 != len2){
        return 0;
    }
    int judge = 0;
    for(int i = 0;i < len1; ++i){
        if(s1[i] == s2[i]){
            judge++;
            if(judge > 2) return 1;
        }
    }
    return 0;
}

int main(){
    while(cin>>N){
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < N; ++i){
            scanf("%s",str[i]);
        }
        for(int i = 0;i < N; ++i){
            for(int j = 0; j < strlen(str[i]); ++j){
                if(str[i][j]>='A'&&str[i][j]<='Z'){
                    str[i][j] = str[i][j]-'A'+'a';
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < N; ++i){
            for(int j = i+1;j < N; ++j){
                if(check(str[i],str[j]) == 1){
                    //printf("%s %s\n",str[i],str[j]);
                    vis[i] = 1;
                    vis[j] = 1;
                }
            }
        }
        for(int i = 0;i < N; ++i){
            ans += vis[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}
