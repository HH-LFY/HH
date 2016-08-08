#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 4000 + 10;
struct node{
    int w;
    int h;
}num[maxn];
int n;
int kw[maxn],kh[maxn];
long long sum[maxn][maxn];

int main( ){
    cin>>n;
    for(int i = 0;i < n; ++i){
        scanf("%d%d",&num[i].w,&num[i].h);
        if(num[i].w>num[i].h) swap(num[i].w,num[i].h);
        kw[i] = num[i].w;
        kh[i] = num[i].h;
    }
    sort(kw,kw+n),sort(kh,kh+n);
    int x = unique(kw,kw+n)-kw;
    int y = unique(kh,kh+n)-kh;
    for(int i = 0;i < n; ++i){
        num[i].w = lower_bound(kw,kw+x,num[i].w)-kw;
        num[i].h = lower_bound(kh,kh+y,num[i].h)-kh;
        sum[num[i].w][num[i].h]++;
        ///printf("%d %d\n",num[i].w,num[i].h);
    }
    long long ans = 0;
    int answ=0;
    int ansh=0;
    for(int i = x-1;i >= 0; --i){
        for(int j = y-1;j >= 0; --j){
            sum[i][j] += (sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1]);
            long long kans = 0;
            kans = sum[i][j]*(long long)kw[i]*(long long)kh[j];
            if(kans>ans){
                ans = kans;
                answ = kw[i];
                ansh = kh[j];
            }
        }
    }
    printf("%I64d\n",ans);
    printf("%d %d\n",answ,ansh);
    return 0;
}
