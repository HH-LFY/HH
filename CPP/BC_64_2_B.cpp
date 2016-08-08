#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<cstdlib>
#include<cmath>
#define PI 2*asin(1.0)
#define LL long long
#define pa pair<int,int>
#define pb push_back
#define clr(a,b) memset(a,b,sizeof(a))
#define lson lr<<1,l,mid
#define rson lr<<1|1,mid+1,r
#define bug(x) printf("%d++++++++++++++++++++%d\n",x,x)
const int  MOD = 1000000007;
const int N = 1e5 + 15;
const int maxn = 2e5 + 14;
const int INF = (1 << 30) - 1;
const int letter = 130;
const double pi=acos(-1.0);
const double eps=1e-8;
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
LL a[N],b[N];
LL f(LL x){
    return (x*1890+143)%10007;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        clr(a,0),clr(b,0);
        LL ans=0,kmin=0,kans;
        for(int i=1;i<=n;i++) {
            scanf("%d",&a[i]);
            b[i]=f(a[i]);
            b[i]-=a[i];
            ans+=a[i];
            b[i]+=b[i-1];
        }
        kans=ans;
        for(int i=1;i<=n;i++){
            kans=max(kans,ans+b[i]-kmin);
            kmin=min(kmin,b[i]);
        }
        printf("%I64d\n",kans);
    }
    return 0;
}
