#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;///�ַ�������


void dfs(char str[],int k,int len){
    if(len-1 == k){
        for(int i = 0;i < len; ++i) putchar(str[i]);
        puts("");
        return ;
    }
    for(int i = k; i < len; ++i){
        swap(str[k],str[i]);
        dfs(str,k+1,len);
        swap(str[k],str[i]);
    }
}

int main( ){
    char str[100];
    scanf("%s",str);
    n = strlen(str);
    printf("�ַ���%s��ȫ�������£�\n",str);
    dfs(str,0,n);
    return 0;
}
