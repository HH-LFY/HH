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

double N(double xx)
{
    int i , j;
    double matrix[n + 1][n + 1];
    for(i = 0;i <= n; ++i)
        matrix[i][0] = y[i];
    for(i = 1;i <= n ;++i)
    {
        for(j = i;j <= n; ++j)
        {
            matrix[j][i] = (matrix[j][i-1] - matrix[j-1][i-1])/(x[j] - x[j - i]);
        }
      ///  printf("%g\n",matrix[i][i]);
    }
    double s = matrix[0][0];
    double ans = 1;
    for(i = 1;i <= n; ++i)
    {
        ans *= (xx - x[i - 1]);
        s += ans*matrix[i][i];
    }
    return s;
}

int main( )
{
    double a = -5,b = 5;
    double mid = b - (b - a)/(2*n);
    data(a,b,n);
    output( );
    printf("\n近似值L（%.1f）= %g \n",mid,N(mid));
    printf("精确值f（%.1f）= %f \n",mid,f(mid));
    return 0;
}
