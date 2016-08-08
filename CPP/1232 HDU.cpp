#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

#define maxx 1010
int pre[maxx];
int n,m;
int a,b;
int sum;

int find(int x)
{
    int r=x;
    while(r!=pre[r])
    {
        r=pre[r];
    }
    return r;
}

void join(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        pre[fx] = fy;
        sum--;
    }
}

int main( )
{
    while(cin>>n)
    {
        sum=n-1;
        if(n == 0) break;
        cin>>m;
        for(int i = 1;i <= n; i++)
        {
            pre[i] = i;
        }
        for(int i = 1;i <= m; i++)
        {
            cin>>a>>b;
            join(a,b);
        }
        cout<<sum<<endl;
    }
    return 0;
}
