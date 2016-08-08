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

int n,m;

int main( )
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int x;
        set<int>p;
        set<int>::iterator k;
        set<int>::iterator k1;
        while(n--)
        {
            scanf("%d",&x);
            p.insert(x);
        }
        while(m--)
        {
            scanf("%d",&x);
            p.insert(x);
        }
        k1=p.end();
        k1--;
        for(k=p.begin();k!=k1;++k)
        {
            printf("%d ",*k);
        }
        printf("%d\n",*k);
    }
    return 0;
}
