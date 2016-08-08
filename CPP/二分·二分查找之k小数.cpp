#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 1000000 + 10;
int n, k;
int a[maxx];
int b[maxx];

int twofen(int l, int r,int t)
{

    int L = 1;
    int R = r - l + 1;

    int mid = (l + r)/2;
    for(int i = l;i <= r; ++i)
    {
        if(a[i] < a[mid])
        {
            b[L++] = a[i];
        }
        else if(a[i] > a[mid])
        {
            b[R--] = a[i];
        }
    }
    b[L] = a[mid];
    int p = 1;
    for(int i = l;i <= r; ++i)
    {
        a[i] = b[p++];
    }
    if(L == t)
        return b[L];
    else if(L > t)
        return twofen(l,l+L-1,t);
    else
        return twofen(l+L,r,t - L );
}

int main()
{
    cin>>n>>k;
    for(int i = 1;i <= n; ++i)
    {
        scanf("%d",&a[i]);
    }
    int ans = twofen(1,n,k);
    cout<<ans<<endl;
    return 0;
}
