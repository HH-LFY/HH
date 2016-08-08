#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int maxx=5000 + 10;
const int inf=100000+10;

int max(int x,int y)
{
    return x>y?x:y;
}

int min(int x,int y)
{
    return x>y?y:x;
}

struct node
{
    int kmin=inf;
    int kmax=-inf;
}t[3*maxx];

int v[maxx];
int lowbit[3*maxx];
int n,p;

int lb(int x)
{
    return x&(-x);
}

void change(int i,int val)
{
    v[i]=val;
    while(i<=n)
    {
        t[i].kmax=max(t[i].kmax,val);
        t[i].kmin=min(t[i].kmin,val);
        i+=lowbit[i];
    }
}

void check(int x,int y)
{
    int kmaxx=v[y];
    int kminn=v[y];
    while(x!=y)
    {
        for(y--;y-lowbit[y]>=x;y-=lowbit[y])
        {
            kmaxx=max(kmaxx,t[y].kmax);
            kminn=min(kminn,t[y].kmin);
        }
        kmaxx=max(kmaxx,v[y]);
        kminn=min(kminn,v[y]);
    }
    cout<<kmaxx-kminn<<endl;
}

int main( )
{
    for(int i = 0;i < 3*maxx; ++i)
    {
        lowbit[i]=lb(i);
    }
    cin>>n>>p;
    for(int i = 1;i < n; ++i)
    {
        scanf("%d",&v[i]);
        change(i,v[i]);
    }
    int x,y;
    while(p--)
    {
        scanf("%d%d",&x,&y);
        check(x,y);
    }
    return 0;
}
