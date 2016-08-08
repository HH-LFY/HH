#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxx = 100000 + 10;
struct node{
    int num;
    int val;
}a[maxx];
int T;
int n;
int ans[maxx];

bool cmp(node x,node y){
    return x.num>y.num;
}

int main( ){
    cin>>T;
    int kcount = 1;
    while(T--){
        scanf("%d",&n);
        for(int i = 0;i < n; ++i){
            scanf("%d%d",&a[i].num,&a[i].val);
        }
        printf("Case #%d:",kcount++);
        sort(a,a+n,cmp);
        int cnt = 0;
        int judge= 0;
        for(int i = 0;i < n; ++i){
            if(a[i].val>cnt){
                judge=1;
                break;
            }
            int pos = min(a[i].val,cnt-a[i].val);
            cnt++;
            for(int j = cnt-1;j >= pos+1; --j){
                ans[j] = ans[j-1];
            }
            ans[pos] = a[i].num;
        }
        if(judge||(cnt==0&&a[0].val>=0)){
            puts(" impossible");
            continue;
        }
        ///printf("%d\n",cnt);
        for(int i = 0;i < cnt; ++i){
            printf(" %d",ans[i]);
        }
        puts("");
    }
    return 0;
}
