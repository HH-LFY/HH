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
#define PI 3.141592653
using namespace std;

const int maxx=1e5+10;
int a[maxx];
int n,m,l;
int t,x;

int main( )
{
    cin>>t;
    for(int o = 1;o <= t; ++o)
    {
        scanf("%d%d%d",&n,&m,&l);
        int now = 0;
        for(int i = 1;i <= n; ++i)
        {
            scanf("%d",&a[i]);
        }
        a[0]=0;
        a[n+1]=m;
        sort(a,a+n+2);
        int kp = 0;
        int ksum = 0;
        int sum=0;
        int cnt = 1;
        while(now < l)
        {
        }
        printf("Case #%d: %d\n",o,sum);
    }
    return 0;
}
