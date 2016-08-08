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

int main()
{
    long long n;
    int ans[1000];
    cin>>n;
    int p = 1;
    while(n)
    {
        int x = n%10;
        ans[p++] = x;
        n = n / 10;
    }
    if(ans[p - 1] == 9 )
    {
        cout<<"9";
    }
    else
    {
        cout<<min(ans[p - 1],9 - ans[p - 1]);
    }
    for(int i = p - 2;i >=1 ; --i)
    {
        int kmin = min(ans[i], 9 - ans[i]);
        cout<<kmin;
    }
    cout<<endl;
    return 0;
}
