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

double h,u,d,f;

int main( )
{
    while(scanf("%lf%lf%lf%lf",&h,&u,&d,&f)!=EOF)
    {
        if(h==0) break;
        int count = 0;
        double now = 0;
        double fd = f*u/100.0;
        double ku = u;
        while(1)
        {
            count++;
            now = now + ku;
            if(now > h)
            {
                printf("success on day %d\n",count);
                break;
            }
            ku = ku - fd;
            now = now - d;
            if(now < 0)
            {
                printf("failure on day %d\n",count);
                break;
            }
        }
    }
    return 0;
}
