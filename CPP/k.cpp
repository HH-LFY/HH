#include <iostream>
#include <cstdio>
using namespace std;

#define max 100010
int sum[max];
int kx,ky;
int t,n;

int main( )
{
    cin>>t;
    for(int o = 1;o <= t; o++)
    {
        int x,p;
        cin>>n;
        cin>>sum[1];
        sum[0]=0;
        for(int i = 2;i <= n; i++)
        {
            cin>>x;
            sum[i] = sum[i-1] + x;
        }
        int minn=10000;
        int maxx=-10000;
        for(int i = 1;i <= n; i++)
        {
            if(sum[i-1]<minn)
            {
                minn=sum[i-1];
                p=i;
            }
            if(maxx<(sum[i]-minn))
            {
                maxx = sum[i] - minn;
                kx = p;
                ky = i;
            }
        }
        printf("Case %d:\n",o);
        cout<<maxx<<" "<<kx<<" "<<ky<<endl;
        if(t!=o)
        {
            cout<<endl;
        }
    }
    return 0;
}
