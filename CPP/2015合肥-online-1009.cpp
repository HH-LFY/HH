#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=100010;
const int MAX=151;
const int MOD=20090717;
const int INF=1000000000;
const double EPS=0.00000001;
typedef long long ll;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int k,a[N],d[N],f[N],dp[N];
int get(int x)
{
    if (x>d[k]) return k+1;
    int l=0,r=k,mid=(l+r)/2;
    while (l+1<r)
    if (d[mid]<x) {
        l=mid;mid=(l+r)/2;
    } else {
        r=mid;mid=(l+r)/2;
    }
    return r;
}
void getin(int x)
{
    if (x>d[k]) d[++k]=x;
    else {
        int l=0,r=k,mid=(l+r)/2;
        while (l+1<r)
        if (d[mid]<x) {
            l=mid;mid=(l+r)/2;
        } else {
            r=mid;mid=(l+r)/2;
        }
        d[r]=x;
    }
}
int getf(int x)
{
    if (x<d[k]) return k+1;
    int l=0,r=k,mid=(l+r)/2;
    while (l+1<r)
    if (d[mid]<x) {
        l=mid;mid=(l+r)/2;
    } else {
        r=mid;mid=(l+r)/2;
    }
    return r;
}
void add(int x)
{
    if (d[k]>x) d[++k]=x;
    else {
        int l=0,r=k,mid=(l+r)/2;
        while (l+1<r)
        if (d[mid]>x) {
            l=mid;mid=(l+r)/2;
        } else {
            r=mid;mid=(l+r)/2;
        }
        d[r]=x;
    }
}
int main()
{
    int i,l,n,m,w,T,ans;
    scanf("%d", &T);
    for (l=1;l<=T;l++) {
        scanf("%d%d", &n, &m);
        for (i=1;i<=n;i++) scanf("%d", &a[i]);
        if (n==m) {
            printf("Case #%d: 0\n", l);continue ;
        }
        a[++n]=1000000100;
        k=ans=0;
        d[0]=-1000000100;
        memset(dp,0,sizeof(dp));
        for (i=1;i<=n;i++) {
            dp[i]=get(a[i]);
            if (i>m) getin(a[i-m]);
        }
        k=0;
        d[0]=1000001000;
        memset(f,0,sizeof(f));
        for (i=n;i>m;i--) {
            f[i]=getf(a[i]);
            add(a[i]);
        }
        //for (i=1;i<=n;i++) printf("%d  %d\n", i, dp[i]);
        //printf("\n\n");
        //for (i=1;i<=n;i++) printf("%d  %d\n", i, f[i]);
        //printf("\n");
        for (i=m+1;i<=n;i++) {
            //printf("%d  %d  %d\n", i, ans, dp[i]+f[i]-2);
            ans=max(ans,dp[i]+f[i]-2);
        }
        printf("Case #%d: %d\n", l, ans);
    }
    return 0;
}


