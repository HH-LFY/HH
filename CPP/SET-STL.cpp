#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <set>
#include <cmath>
#define PI 3.141592653
using namespace std;

int main( )
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        set<int> a;
        int x;
        for(int i = 1;i <= n+m; i++)
        {
            scanf("%d",&x);
            a.insert(x);
        }
    }
    return 0;
}
