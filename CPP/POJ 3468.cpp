#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 200000 + 10;
const int maxn = 5000 + 10;
int n;  ///数据大小
int q;  ///查询个数
int t;  ///每个块的大小
int num;///块的数量
long long a[N];///每个元素的值
int pos[N]; ///每个元素所属的块的位置
long long sum[maxn];///每个块的和
long long add[maxn];///lazy标记

void init(int x){
    sum[x] = 0;
    int ll = (x-1)*t + 1;
    int rr = min(x*t,n);
    for(int i = ll;i <= rr; ++i) sum[x] += a[i];
}

long long query(int ll,int rr){
    long long ans = 0;
    int fl = pos[ll];
    int fr = pos[rr];
    if(fl == fr){
        for(int i = ll;i <= rr; ++i) ans += (a[i] + add[fl]);
    }else{
        for(int i = ll;i <= fl*t; ++i) ans += (a[i] + add[fl]);
        for(int i = (fr-1)*t+1;i <= rr; ++i) ans += (a[i] + add[fr]);
        for(int i = fl+1;i < fr; ++i) ans += (sum[i] + (long long)(add[i]*t));
    }
    return ans;
}

void update(int ll,int rr,long long val){
    int fl = pos[ll];
    int fr = pos[rr];
    if(fl == fr){
        for(int i = ll;i <= rr; ++i) a[i] += val;
        init(fl);
    }else{
        for(int i = ll;i <= fl*t; ++i) a[i] += val;
        init(fl);
        for(int i = (fr-1)*t+1;i <= rr; ++i) a[i] += val;
        init(fr);
        for(int i = fl+1;i < fr; ++i) add[i] += val;
    }
}

int main( ){
    while(scanf("%d%d",&n,&q)!=EOF){
        memset(sum,0,sizeof(sum));
        memset(add,0,sizeof(add));
        t = sqrt(n);
        if(n%t) num = n/t + 1;
        else num = n/t;
        for(int i = 1;i <= n; ++i){
            scanf("%I64d",a+i);
            pos[i] = (i-1)/t+1;
        }
        for(int i = 1;i <= num; ++i) init(i);
        char str[10];
        while(q--){
            scanf("%s",str);
            int x, y;
            long long val;
            if(str[0] == 'Q'){
                scanf("%d%d",&x,&y);
                if(x>y) swap(x,y);
                printf("%I64d\n",query(x,y));
            }else{
                scanf("%d%d%I64d",&x,&y,&val);
                if(x>y) swap(x,y);
                update(x,y,val);
            }
        }
    }
    return 0;
}
