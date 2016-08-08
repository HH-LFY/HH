#include <stdio.h>
#include <math.h>
#define f(x) (5.0/(1 + x*x))
#define n 10

double x[n+1],y[n+1];

void data(double a, double b, int m)
{
    double h = (b - a)/n;
    int i;
    for(i = 0;i <= m; ++i)
    {
        x[i] = a + i*h;
        y[i] = f(x[i]);
    }
}

void output( )
{
    printf("\n各节点信息：\nxi:");
    int i;
    for(i = 0;i <= n; ++i)
    {
        printf("%7.0g",x[i]);
    }
    printf("\nyi:");
    for(i = 0;i <= n; ++i)
        printf("%7.4g",y[i]);
}

double lb(int k,double xx)
{
    double llb = 1;
    int i;
    for(i = 0;i <= n; ++i)
    {
        if(i != k) llb *= (xx - x[i])/(x[k] - x[i]);
    }
    return llb;
}

double L(double xx)
{
    double s = 0;
    int i;
    for(i = 0;i <= n; ++i)
    {
        s += lb(i,xx) * y[i];
    }
    return s;
}

int main( )
{
    double a = -5,b = 5;
    double mid = b - (b - a)/(2*n);
    data(a,b,n);
    output( );
    printf("\n精确值f（%.1f）= %f \n",mid,f(mid));
    printf("近似值L（%.1f）= %f \n",mid,L(mid));
    return 0;
}
