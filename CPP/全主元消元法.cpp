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

const int inf = 1e9;
const int n = 4;
double aa[n][n+1]={{1,-1,1,-4,-2},
              {5,-4,3,12,-6},
              {2, 1,1,11, 3},
              {2,-1,7,-1,-7}};
int z[n];
double x[n];

void show( )
{
    int i, j;
    for(i = 0;i < n; ++i)
    {
        for(j = 0;j <= n; ++j)
        {
            if((int)aa[i][j]==0)
                aa[i][j] = 0;
            printf("%10f",aa[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap(double &x,double &y)
{
    double t = x;
    x = y;
    y = t;
}

void swapr(int x,int y)
{
    int j;
    for(j = 0;j <= n; ++j)
    {
        swap(aa[x][j],aa[y][j]);
    }
}

void swapc(int x,int y)
{
    int i;
    for(i = 0;i < n; ++i)
    {
        swap(aa[i][x],aa[i][y]);
    }
    swap(z[x],z[y]);
}

int main( )
{
    int i, j, k, judge = 0;
    for(i = 0;i < n; ++i)
    {
        x[i] = 0;
        z[i] = i;
    }
    while(1)
    {
        if(judge == n-1) break;
        double kmax = -inf;
        int kx = inf;
        int ky = inf;
        for(i = judge;i < n; ++i)
        {
            for(j = 0;j < n; ++j)
            {
                if(aa[i][j]!=0&&aa[i][j]>kmax)
                {
                    kmax = aa[i][j];
                    kx = i;
                    ky = j;
                }
            }
        }
        if(kx != judge)
        {
            swapr(judge,kx);
        }
        if(ky != judge)
        {
            swapc(judge,ky);
        }
        kx = judge;
        ky = judge;
        for(i = judge+1;i < n; ++i)
        {
            double m = aa[i][judge]/aa[judge][judge];
            for(j = judge;j <= n; ++j)
            {
                aa[i][j] = aa[i][j] - m*aa[judge][j];
            }
        }
        show( );
        judge++;
    }
    for(k = n-1;k >= 0; --k)
    {
        x[k] = aa[k][n]/aa[k][k];
        for(j = k - 1;j >= 0; --j)
        {
            aa[j][n] = aa[j][n] - x[k]*aa[j][k];
        }
    }
    for(i = 0;i < n; ++i)
    {
        printf("  x[%d]=%10f\n",i + 1,x[z[i]]);
    }
    return 0;
}
