#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI acos(-1.0)
using namespace std;

double area(double x1,double y1,double r1,double x2,double y2,double r2)
{
    double d = sqrt((x1 - x2)*(x1 - x2) + (y1 -y2)*(y1 - y2));
    if(r1 < r2)
    {
        double t = r1;
        r1 = r2;
        r2 = t;
    }
    if((r1 + r2) < d) ///相离
    {
        return 0;
    }
    else if((r1 - r2) >= d) ///内含
    {
        return PI*r2*r2;
    }
    else ///相交
    {
        double a = acos((r2*r2 + d*d - r1*r1)/(2 * r2 * d)); ///r1 对应的边的角度
        double b = acos((r1*r1 + d*d - r2*r2)/(2 * r1 * d)); ///r2 对应的边的角度
        return a*r1*r1/2.0 + b*r2*r2/2.0 - r1*d*sin(a);///S = a*b*sin(c)/2   c为a和b边的夹角
    }
}

int main( )
{
    double x1,x2,y1,y2,r1,r2;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2)!=EOF)
        printf("%.16f\n",area(x1,y1,r1,x2,y2,r2));
    return 0;
}
