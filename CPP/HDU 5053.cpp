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
#define PI 3.141592653
using namespace std;

int t;
__int64 a,b;

int main( )
{
    cin>>t;
    int cnt = 1;
    while(t--)
    {
        scanf("%I64d%I64d",&a,&b);
        __int64 i,sum=0;
        for(i = a;i <= b; ++i)
        {
            sum=sum+i*i*i;
        }
        printf("Case #%d: ",cnt++);
        cout<<sum<<endl;
    }
    return 0;
}
