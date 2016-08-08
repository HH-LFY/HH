#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t;
int n;
double a[55];
double w[55];
double v[55];
double kmax;

void dfs(double x,double *w)
{
    for(int i = 1;i < n; i++)
    {
        if(w[i]>=x)
        {
            w[i]-=x;
        }
        else if(w[i+1]>x)
        {
            w[i+1]-=x;
        }
        else if(w[i+1]==x)
        {
            i++;
        }
        else if(i==n-1)
        {
            continue ;
        }
        else
        {
            return ;
        }
    }
    kmax=max(kmax,x);
}

int main ( )
{
    cin>>t;
    while(t--)
    {
        kmax=-1.0;
        scanf("%d",&n);
        for(int i = 0;i < n; i++)
        {
            scanf("%lf",&a[i]);
        }
        sort(a,a+n);
        for(int i=1;i < n; i++)
        {
            w[i]=a[i]-a[i-1];
        }
        for(int i = 1;i < n; i++)
        {
            for(int j = 1;j < n; j++)
            {
                v[j]=w[j];
            }
            dfs(w[i],v);
        }
        printf("%.3f\n",kmax);
    }
    return 0;
}
