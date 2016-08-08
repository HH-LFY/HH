#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <set>
#define PI 3.141592653
using namespace std;

const __int64 inf = 1e9;
__int64 t;
__int64 n;
__int64 kmax;
__int64 knn;

void dfs(__int64 x,__int64 k)
{
    if(x>n)
        return ;
    __int64 i,j;
    for(i = 0;i <= 9; ++i)
    {
        __int64 a = x+i*k;
        __int64 aa = (a*a)%(k*10);
        __int64 kn = n%(k*10);
        __int64 kq = a*a;
        if(aa==kn)
        {
            if(a*a==n)
            {
                kmax = min(kmax,a);
            }
            else if(aa==n)
            {
                kmax = min(kmax,a);
            }
            else if(kq%knn==n)
            {
                kmax = min(kmax,a);
            }
            else
            {
                dfs(a,k*10);
            }
        }
    }
}

int main( )
{
    cin>>t;
    while(t--)
    {
        scanf("%I64d",&n);
        kmax = inf;
        if(n==0)
        {
            printf("0\n");
            continue ;
        }
        if(n==inf)
        {
            printf("None\n");
            continue ;
        }
        knn=1;
        int m=n;
        while(m)
        {
            knn=knn*10;
            m=m/10;
        }
        //cout<<knn<<endl;
        dfs(0,1);
        if(kmax == inf)
            printf("None\n");
        else
            printf("%I64d\n",kmax);
    }
    return 0;
}
