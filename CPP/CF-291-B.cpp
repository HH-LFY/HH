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

map<double,int> p;

int main()
{
    int n , judge = 0;;
    double x, y;
    double x1, y1;
    cin>>n>>x>>y;
    for(int i = 0;i < n; ++i)
    {
        cin>>x1>>y1;
        if(x1==x)
        {
            judge = 1;
            continue;
        }
        double k = (y1 - y)/(x1 - x);
        p[k] = 1;
    }
    int sum = 0;
    sum = p.size();
    cout<<sum+judge<<endl;
    return 0;
}
