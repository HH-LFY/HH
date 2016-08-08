#include <iostream>
#include <cstdio>
using namespace std;

const int maxx=30000+10;
int a[maxx];
int sum[maxx];
int n,m;
int x,k;
int t;

int find(int x)
{
    if(x!=a[x]) return a[x]=find(a[x]);
    else return x;
}

void set( )
{
    for(int i = 0;i < n;i++)
    {
        a[i]=i;
        sum[i]=1;
    }
}

void add(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        if(fx>fy)
        {
            a[fx]=fy;
            sum[fy]=sum[fy]+sum[fx];
        }
        else
        {
            a[fy]=fx;
            sum[fx]=sum[fx]+sum[fy];
        }
    }
}

int main( )
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        set( );
        for(int i = 0;i < m;++i)
        {
            scanf("%d",&t);
            for(int j=0;j < t; ++j)
            {
                if(j>0)
                {
                    scanf("%d",&x);
                    add(k,x);
                }
                else
                {
                    scanf("%d",&k);
                }
            }
        }
        cout<<sum[0]<<endl;
    }
    return 0;
}
