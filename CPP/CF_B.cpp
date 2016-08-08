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

int main( )
{
    int a, b;
    int i, j;

    while(cin>>a>>b)
    {


        int k = a - b;
        int ans = 0;
        if(a == 1 && b==1)
        {
            printf("infinity\n");
            continue ;
        }
        if(k < 0)
        {
            printf("0\n");
            continue ;
        }
        if(k == 0)
        {
            printf("infinity\n");
            continue ;
        }
        for(i = 1; i*i < k; ++i)
        {
            if(k % i == 0)
            {
                if(i > b)ans++;
                if(k/i > b)ans++;
            }
        }
        if(k == i*i && i > b) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
