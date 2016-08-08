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
using namespace std;

int t;
int n;
double sum,a[550];

double p(int x)
{
    double sum=1;
    for(int i = 1;i <= x; i++)
    {
        sum=sum*0.95;
    }
    return sum;
}

int cmd(int x,int y)
{
    return x>y;
}

int main( )
{
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        sum = 0;
        for(int i = 0;i < n; i++)
        {
            scanf("%lf",&a[i]);
        }
        sort(a,a+n,cmd);
        for(int i = 0;i < n; i++)
        {
            sum = sum+a[i]*p(i);
        }
        printf("%.10lf\n",sum);
    }
    return 0;
}
