#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxx=550;
typedef __int64 LL;
LL a[maxx];
LL b[maxx];
LL c[maxx];
LL ab[maxx*maxx];
LL l,n,m,s;

int main( )
{
    LL count=1;
    while(cin>>l>>n>>m)
    {
        LL i,j;
        int k=0;
        for(i = 0;i < l; ++i)
        {
            scanf("%I64d",&a[i]);
        }
        for(i = 0;i < n; ++i)
        {
            scanf("%I64d",&b[i]);
        }
        for(i = 0;i < m; ++i)
        {
            scanf("%I64d",&c[i]);
        }
        for(i = 0;i < l; ++i)
        {
            for(j = 0;j < n; ++j)
            {
                ab[k++]=a[i]+b[j];
            }
        }

        sort(ab,ab+k);
        sort(c,c+m);

        printf("Case %I64d:\n",count++);
        cin>>s;
        LL x;
        while(s--)
        {
            int judge=0;
            scanf("%I64d",&x);
            LL km;
            if(ab[k-1]+c[m-1]<x||ab[0]+c[0]>x)
            {
                printf("NO\n");
                continue;
            }
            for(i = 0;i < m; ++i)
            {
                km = x-c[i];
                LL l = 0;
                LL r = k-1;
                while(l <= r)
                {
                    LL mid=(l+r)/2;
                    if(km==ab[mid])
                    {
                        judge=1;
                        break;
                    }

                    if(km<ab[mid])
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                    }

                }
                if(judge==1)
                    break;
            }
            if(judge==1)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}
