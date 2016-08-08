#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str1[1000010];
char str2[1000010];
int next[1000010];
void build_next(){
    int len = strlen(str2);
    int i = 0,j = -1;
    next[0] = -1;
    while(i<len){
        if(j == -1 || str2[i]==str2[j]) next[++i]=++j;
        else j = next[j];
    }
}
int kmp_count(){
    int i = 0;
    int j = 0;
    int len_s=strlen(str1);
    int len_f=strlen(str2);
    int ans = 0;
    while(i<len_s){
        while(j>0&&str1[i]!=str2[j])j = next[j];
        if(str1[i]==str2[j]) j++;
        if(j == len_f){
            ans++; j=next[j];
        }
        i++;
    }
    return ans;
}
int main( ){
    int ct;
    cin>>ct;
    while(ct--){
        scanf("%s",str2);
        scanf("%s",str1);
        build_next();
        printf("%d\n",kmp_count());
    }
    return 0;
}
