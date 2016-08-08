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
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI 3.141592653
using namespace std;

const int maxx = 1e5;
int a[maxx];
int n;
int m;

int main( )
{
    while(cin>>n>>m)
    {
        __int64 sum = 0;
        for(int i = 0;i < n; ++i)
        {
            scanf("%d",&a[i]);
           /// cout<<a[i]<<endl;
        }
        sort(a,a+n);
        int i = 0;
        while(m > 0)
        {
            int k = m/a[i];
            sum += k;
            if(k == 0) break;
            m = m - k*a[i];
            i++;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
