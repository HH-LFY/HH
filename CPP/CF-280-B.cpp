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

set<double> p;
double a[1010];
int n, l;

int main( )
{
    double x;
    cin>>n>>l;
    for(int i = 0;i < n; ++i)
    {
        cin>>x;
        p.insert(x);
    }
    int judge1 = 1, judge2 = 1;
    double ANS = 0;
    int k = 0;
    for(set<double>::iterator q = p.begin(); q != p.end(); q++)
        a[k++] = *q;
    for(int i = 1;i < k; ++i)
    {
        ANS = max(ANS , (a[i] - a[i - 1])/2.0);
    }
    if((int)a[0] != 0)
    {
        ANS = max(ANS , a[0]);
    }
    if((int)a[k-1] != l)
    {
        ANS = max(ANS , l - a[k-1]);
    }
    printf("%.10f\n",ANS);
    return 0;
}

/**

7 15
15 5 3 7 9 14 0

2.5

2 5
2 5

2.0

*/
