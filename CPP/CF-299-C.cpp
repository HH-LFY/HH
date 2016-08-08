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
#include <vector>
#include <sstream>
#define PI acos(-1.0)
#define S(i) (i*a)+ b * ((i - 1)*i)/2
#define s(i) a + b*(i - 1)
const int  inf =  (1<<30) - 10;
using namespace std;

long long a, b, n;
long long l, t, m;

int main()
{
    cin>>a>>b>>n;
    for(int i = 0;i < n; ++i){
        cin>>l>>t>>m;
        long long r = 1e7 + 10;
        long long L = l - 1;
        long long sum = m*t;
        int judge = 0;
        while(l <= r)
        {
            ///printf("%I64d %I64d\n",l,r);
            long long mid = (l + r)/2;

            if(sum >= S(mid) - S(L) && s(mid) <= t && s(L) <= t)
            {
                l = mid + 1;
                judge = 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        if(judge)
        {
            cout<<r<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
