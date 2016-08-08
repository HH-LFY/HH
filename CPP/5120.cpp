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

int T;
double ans;

double area(double x1,double y1,double r1,double x2,double y2,double r2)
{
    double d = sqrt((x1 - x2)*(x1 - x2) + (y1 -y2)*(y1 - y2));
    ///cout<<d<<endl;
    if(r1 < r2)
    {
        double t = r1;
        r1 = r2;
        r2 = t;
    }
    if((r1 + r2) <= d) ///相离
    {
        return 0;
    }
    else if((r1 - r2) >= d) ///内含
    {
        return PI*r2*r2;
    }
    else ///相交
    {
        double a = acos((r2*r2 + d*d - r1*r1)/(2.0 * r2 * d)); ///r1 对应的边的角度
        double b = acos((r1*r1 + d*d - r2*r2)/(2.0 * r1 * d)); ///r2 对应的边的角度
        return b*r1*r1 + a*r2*r2 - r1*d*sin(b);///S = a*b*sin(c)/2   c为a和b边的夹角
    }
}

int main( )
{
    int count = 1;
    cin>>T;
    while(T--)
    {
        double x1 , x2 , y1 , y2;
        double r , R;
        ans = 0;
        scanf("%lf%lf",&r,&R);
        scanf("%lf%lf",&x1,&y1);
        scanf("%lf%lf",&x2,&y2);
        ans = area(x1,y1,R,x2,y2,R);
        ///printf("ans1 = %f\n",ans);
        ans -= area(x1,y1,R,x2,y2,r);
        ans -= area(x1,y1,r,x2,y2,R);
        ///printf("ans2 = %f\n",ans);
        ans += area(x1,y1,r,x2,y2,r);
        if(ans < 0) ans = -ans;
        printf("Case #%d: %.6f\n",count++,ans);
    }
    return 0;
}
