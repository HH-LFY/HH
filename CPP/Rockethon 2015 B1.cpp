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

int n , sum, ans[60];
long long m;

void solved(int l, int r)
{
    if(l == r)
    {
        ans[l] = sum++;
        return ;
    }
    long long temp = (1ll << (r - l - 1));
    if(temp >= m)
    {
        ans[l] = sum++;
        solved(l+1,r);
    }
    else
    {
        ans[r] = sum++;
        m -= temp;
        solved(l,r - 1);
    }

}

int main()
{
    while(cin>>n>>m)
    {
        sum = 1;
        solved(1,n);
        for(int i = 1;i <= n; ++i)
        {
            printf("%d ",ans[i]);
        }
        cout<<endl;
    }
    return 0;
}
