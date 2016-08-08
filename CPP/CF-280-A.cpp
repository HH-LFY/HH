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

const int maxn = 10000;
int a[maxn];
int n;

void init( )
{
    int i;
    a[0] = 0;
    int k = 0;
    for(i = 1;a[i - 1] < 10000; ++i)
    {
        k += i;
        a[i] = a[i - 1] + k;
        ///cout<<a[i]<<endl;
    }
}

int main( )
{
    init();
    while(scanf("%d",&n) != EOF)
    {
        int i;
        for(i = 1;i < maxn; ++i)
        {
            if(n < a[i])
            {
                printf("%d\n",i - 1);
                break;
            }
        }
    }
    return 0;
}
