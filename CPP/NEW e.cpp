#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
__int64 a[1000100];

int main( )
{
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
    {
        scanf("%I64d",&a[i]);
    }
    int s = 1;
    int d = n;
    int k = 2;
    __int64 sum = 0;
    while(d - s > 2 * m)
    {
        sum += k*(a[s+m]-a[s]);
        sum += k*(a[d]-a[d-m]);
        k += 2;
        s += m;
        d -= m;
    }
    sum += k*(a[d]-a[s]);
    printf("%I64d\n",sum);
    return 0;
}
