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

double l, r;
double a, b, c, d;
vector<double> p;

double f(double x)
{
    return a*x*x*x + b*x*x + c*x + d;
}

int main()
{
    cin>>a>>b>>c>>d;
    l = -100;
    r = l + 1;
    for(int count = 1; count <= 3; ++count)
    {
        while(f(l)*f(r) > 0)
        {
            r+=0.5;

        }
        double L = l;
        double R = r;
        while(L <= R)
        {
            double mid = (L + R)/2.0;
            if(f(mid) == 0 || fabs(L-R)< 0.000000005)
            {
                p.push_back(mid);
                l = mid+0.2;
                r = l + 1;
                break;
            }
            if(f(mid) * f(R) > 0)
            {
                R = mid;
            }
            else
            {
                L = mid;
            }
        }

    }
    for(int i = 0; i < p.size() - 1; ++i)
    {
        printf("%.2f ",p[i]);
    }
    printf("%.2f\n",p[p.size() - 1]);
    return 0;
}
