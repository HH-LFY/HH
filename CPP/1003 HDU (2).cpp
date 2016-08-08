#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

int main()
{
    int s[100010],t,n;
    int x,y,z;
    cin>>t;
    for(int o = 1;o <= t ; o++)
    {
        cin>>n;
        for(int i = 0;i <= n; i++)
        {
            s[i]=0;
        }
        for(int i = 1;i <= n; i++)
        {
            cin>>z;
            s[i] = s[i-1] + z;
        }
        x = -10;
        y = -10;
        int minn = 10000,maxx = -10000,k;
        for(int i = 1;i <= n; i++)
        {
            if(s[i-1]<minn)
            {
                minn=s[i-1];
                k=i;
            }
            if(s[i]-minn>maxx)
            {
                maxx=s[i]-minn;
                x=k;
                y=i;
            }
        }
        cout<<"Case "<<o<<":"<<endl;
        cout<<maxx<<" "<<x<<" "<<y<<endl;
        if(t!=o)
        {
            cout<<endl;
        }
    }
    return 0;
}
