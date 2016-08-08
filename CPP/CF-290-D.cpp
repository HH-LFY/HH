#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 1e3;
int n;
int l[maxx], c[maxx];
map<int,int> a;
map<int,int>::iterator p;

int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

int main()
{
    cin>>n;
    for(int i = 1;i <= n; ++i)
    {
        scanf("%d",&l[i]);
    }
    for(int i = 1;i <= n; ++i)
    {
        scanf("%d",&c[i]);
    }
    a[0] = 0;

    for(int i = 1;i <= n; ++i)
    {
        for(p = a.begin();p != a.end(); ++p)
        {
            int value = gcd(l[i], p->first);
            if(a.count(value))
            {
                a[value] = min(a[value],p->second + c[i]);
            }
            else
            {
                a[value] = p->second + c[i];
            }
        }
    }
    if(a.count(1))
    {
        cout<<a[1]<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}
