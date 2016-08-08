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
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 100 + 10;
long long a[maxx];
int T;

int main()
{
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i = 0;i < n; ++i){
            scanf("%lld",&a[i]);
        }
        sort(a,a + n);
        if(a[0] == a[1]){
            cout<<a[n - 1]<<endl;
        }else{
            cout<<a[0]<<endl;
        }
    }
    return 0;
}
