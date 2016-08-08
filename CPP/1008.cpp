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

const int maxx=100000+10;
int n;
int a[maxx];
int b[maxx];
int vis[maxx];

int main( )
{
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        for(int i = 0;i <= n; i++)
            vis[i]=0;
        for(int i = n;i >= 0; i--)
        {
            if(!vis[i])
            {
                vis[i]=1;
                int kmax=-1;
                int kj;
                for(int j = 0;j <= n; j++)
                {
                    if(!vis[j]&&i^j>kmax)
                    {
                        kmax=i^j;
                        kj=j;
                    }
                }
                if(kmax!=-1)
                {
                    sum+=2*kmax;
                    vis[kj]=1;
                    b[i]=kj;
                    b[kj]=i;
                }
            }
        }
        for(int i = 0;i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        printf("%d\n",sum);
        for(int i = 0;i < n; i++)
        {
            printf("%d ",b[a[i]]);
        }
        printf("%d\n",b[a[n]]);
    }
    return 0;
}
