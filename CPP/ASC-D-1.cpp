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

const int maxx = 10000+10;
int a[maxx];
int n,m;
int x,y;

int main( )
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j;
        scanf("%d %d",&n,&m);
        for(i = 1; i <= n; ++i)
        {
            a[i] = 0;
        }
        for(i = 1; i <= m; ++i)
        {
            scanf("%d %d",&x,&y);
            a[x]++;
            a[y]++;
        }
        long long ksum=0;
        for(i = 1; i <= n; ++i)
        {
            ksum += a[i]*(a[i]-1);
        }
        ksum += 2*m;
        cout<<ksum<<endl;
        if(t) cout<<endl;
    }
    return 0;
}
