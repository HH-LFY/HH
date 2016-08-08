#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

const int inf=99999;
int t;
double x[5][15];
double y[5][15];

int main( )
{
    cin>>t;
    for(int i = 1;i <= t; i++)
    {
        cin>>x[1][i]>>y[1][i]>>x[2][i]>>y[2][i]>>x[3][i]>>y[3][i]>>x[4][i]>>y[4][i];
    }
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    for(int i = 1;i <= t; i++)
    {
        double k1=inf,k2=inf;
        double kx,ky;
        double a1=y[1][i]-y[2][i];
        double a2=y[3][i]-y[4][i];
        double b1=x[1][i]-x[2][i];
        double b2=x[3][i]-x[4][i];
        double c1,c2;
        if(b1==0&&b2==0)
        {
            if(x[1][i]==x[3][i])
            {
                cout<<"LINE"<<endl;
                continue ;
            }
            else
            {
                cout<<"NONE"<<endl;
                continue ;
            }
        }
        if(a1==0&&a2==0)
        {
            if(y[1][i]==y[3][i])
            {
                cout<<"LINE"<<endl;
                continue ;
            }
            else
            {
                cout<<"NONE"<<endl;
                continue ;
            }
        }
        if(b1==0)
        {
            kx=x[1][i];
        }
        else if(a1==0)
        {
            k1=0;
            ky=y[1][i];
        }
        else
        {
            k1=a1/b1;
        }
        if(b2==0)
        {
            kx=x[3][i];
        }
        else if(a2==0)
        {
            k2=0;
            ky=y[3][i];
        }
        else
        {
            k2=a2/b2;
        }
        if(k1!=inf&&k2!=inf&&k1!=k2)
        {
            kx=(y[3][i]-y[1][i]-k2*x[3][i]+k1*x[1][i])/(k1-k2);
            ky=k1*kx-k1*x[1][i]+y[1][i];
            printf("POINT %.2lf %.2lf\n",kx,ky);
            continue ;
        }
        if(k1==k2&&k1!=inf)
        {
            c1=y[1][i]-k1*x[1][i];
            c2=y[3][i]-k2*x[3][i];
            if(c1!=c2)
            {
                cout<<"NONE"<<endl;
                continue ;
            }
            else
            {
                cout<<"LINE"<<endl;
                continue ;
            }
        }
        if(k1==inf)
        {
            ky=k2*(kx-x[3][i])+y[3][i];
            printf("POINT %.2lf %.2lf\n",kx,ky);
            continue ;
        }
        if(k2==inf)
        {
            ky=k1*(kx-x[1][i])+y[1][i];
            printf("POINT %.2lf %.2lf\n",kx,ky);
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
