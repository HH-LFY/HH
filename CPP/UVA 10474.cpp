#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxx = 1e6;
int a[maxx];
int n,m;

int main( )
{
    int count=1;
    while(scanf("%d%d",&n,&m)==2&&n)
    {
        printf("CASE# %d:\n",count++);
        for(int i = 0;i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        while(m--)
        {
            int x;
            scanf("%d",&x);
            int p=lower_bound(a,a+n,x)-a;
            if(a[p]==x)
            {
                printf("%d found at %d\n",x,p+1);
            }
            else
            {
                printf("%d not found\n",x);
            }
        }
    }
    return 0;
}
