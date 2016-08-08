/*******************************
****树状数组单点源更新模版****
********************************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx=200010;
int a[maxx],b[maxx];
int n,m;
char c[5];

int max(int x,int y)
{
    return x>y?x:y;
}

int lb(int x)
{
    return x&(-x);
}

void u(int x,int y)
{
    a[x]=y;
    while(x<=n)
    {
        b[x]=max(b[x],y);
        x+=lb(x);
    }
}

int maxxx(int x,int y)
{
    int kmax=a[y];
    while(x!=y)
    {
        for(y--;y-lb(y)>=x;y-=lb(y))
        {
            kmax=max(b[y],kmax);
        }
        kmax=max(kmax,a[y]);
    }
    return kmax;
}

int main( )
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int x,y;
        memset(b,0,sizeof(b));
        for(int i = 1;i <= n; i++)
        {
            scanf("%d",&a[i]);
            u(i,a[i]);
        }
        while(m--)
        {
            scanf("%s%d%d",c,&x,&y);
            if(c[0]=='U')
            {
                u(x,y);
            }
            else if(c[0]=='Q')
            {
                cout<<maxxx(x,y)<<endl;
            }
        }
    }
    return 0;
}
