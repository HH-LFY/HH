#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxx = 500000 + 10;
int num[maxx];
int sum[maxx];
int kis[maxx];
int n, p;
int ans;

void show(){
    printf("%d\n",ans);
    for(int i = 0;i < n; ++i){
        printf("%d ",num[i]);
    }
    puts("");
}

int color(int l,int r,int co){
    int ret = 0;
    for(int i = l;i <= r; ++i){
        if(num[i] != co){
            ret++;
            num[i] = co;
        }
    }
    return ret;
}

int main( ){
    scanf("%d",&n);
    for(int i = 0;i < n; ++i){
        scanf("%d",num+i);
    }
    kis[0] = 0;
    int pos = 1;
    while(num[pos]==num[pos-1]&&pos<n)pos++;
    p = 1;
    if(pos!=1) kis[p++] = pos-1;
    for(int i = pos+1;i < n; ++i){
        if(num[i] == num[i-1]){
            kis[p++] = i-1;
            while(num[i] == num[i-1] && i < n) i++;
            kis[p++] = i-1;
        }
    }
    if(kis[p-1]!=n-1){
        kis[p++] = n-1;
    }
    /*
9
1 1 0 1 0 1 1 1 0

    printf("%d\n",p);
    for(int i = 0;i < p; ++i){
        printf("%d ",kis[i]);
    }
    puts("");*/
    ans = 0;
    for(int i = 1;i < p; ++i){
        int l = kis[i-1];
        int r = kis[i];
        int x = num[l];
        int y = num[r];
        if(x == y){
            ans=max(color(l,r,x),ans);
        }else{
            int mid = (l+r)>>1;
            color(l,mid,x);
            color(mid+1,r,y);
            ans=max((r-l)/2,ans);
        }
    }
    show();
    return 0;
}
