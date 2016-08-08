#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x>y?x:y)
#define LL long long
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;
#define N 100010
LL p[N],mod,x,a,b;
int main()
{
    int q,T;
    scanf("%d",&T);
    for(int j=1; j<=T; j++)
    {
        printf("Case #%d:\n",j);
        x=1;
        scanf("%d%I64d",&q,&mod);
        for(int i=1; i<=q; i++)
        {
            scanf("%I64d%I64d",&a,&b);
            if(a==1) x*=b;
            else x/=p[b];
            if(x <= 0) x = 1;
            p[i]=b;
            x%=mod;
            printf("%I64d\n",x);
        }

    }
    return 0;
}
