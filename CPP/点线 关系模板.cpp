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
#define eps 1e-8
const int  inf =  (1<<30) - 10;
using namespace std;

struct Point{
    double x;
    double y;
};

/**���**/
double cross(Point u1,Point u2,Point v1,Point v2){
    return (u1.x - u2.x)*(v1.y - v2.y) - (v1.x - v2.x)*(u1.y - u2.y);
}

/**ֱ��ƽ���ж�**/
bool Parallel(Point u1,Point u2,Point v1,Point v2){
    return fabs((u1.x-u2.x)*(v1.y - v2.y) - (v1.x - v2.x)*(u1.y - u2.y))<eps;
}

/**���� P0P1 X P0P2**/
double Xmult(Point p1,Point p2,Point p0){
    return (p1.x - p0.x)*(p2.y - p0.y) - (p2.x - p0.x)*(p1.y - p0.y);
}
/**��������֮��ľ���**/
double Distance(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

/***����㵽ֱ�ߵľ���**/
double Distance2(Point p,Point v1,Point v2){
    return fabs(Xmult(p,v1,v2))/Distance(v1,v2);
}

/***������ֱ�߽��㣬ע�⣺���ж�ֱ���Ƿ�ƽ��or�غ�***/
Point Intersection(Point u1,Point u2,Point v1,Point v2){
    Point ret = u1;
    double t = (cross(u1,v1,v1,v2))/(cross(u1,u2,v1,v2));
    ret.x += (u2.x - u1.x) * t;
    ret.y += (u2.y - u1.y) * t;
    return ret;
}

int main()
{
    int T;
    cin>>T;
    printf("INTERSECTING LINES OUTPUT\n");
    Point p1,p2,p3,p4;
    while(T--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y,&p3.x,&p3.y,&p4.x,&p4.y);
        if(Parallel(p1,p2,p3,p4)){
                if(Distance2(p1,p3,p4) < eps){
                    printf("LINE\n");
                }else{
                    printf("NONE\n");
                }
        }else{
            Point ans = Intersection(p1,p2,p3,p4);
            printf("POINT %.2f %.2f\n",ans.x,ans.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
