#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
using namespace std;

int n,m;
int l[350];
int v[50],w[50];

int main( )
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(l,0,sizeof(l));
        for(int i = 1;i <= n; i++)
        {
            scanf("%d%d",&v[i],&w[i]);
        }
        for(int i = 1;i <= m; ++i)
        {
            for(int j = 1;j <= n; ++j)
            {
                l[i+v[j]]=max(l[i]+w[j]*i,l[i+v[j]]);
            }
        }
        int i;
        for(i = 1;i <= 350; i++)
        {
            if(l[i]>=m)
            {
                break;
            }
        }
        cout<<i<<endl;
    }
    return 0;
}
