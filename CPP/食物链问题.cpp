#include <iostream>
#include <cstdio>
using namespace std;

const int maxx=50000+10;
int a[maxx];
int vis[maxx];
int k,n;
int x,y,c;
int sum;

void set( )
{
    for(int i = 1;i <= n; i++)
    {
        a[i]=i;
        vis[i]=0;
    }
}

int find(int x)
{
    if(x==a[x]) return x;
    int t=a[x];
    a[x]=find(t);
    vis[x]=(vis[x]+vis[t])%3;
    return a[x];
}


int main( )
{
    scanf("%d%d",&n,&k);
    set( );
    sum=0;
    while(k--)
    {
        scanf("%d%d%d",&c,&x,&y);
        if(x>n||y>n)
        {
            sum++;
            continue;
        }
        if(x==y && c==2)
        {
            sum++;
            continue;
        }
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy)
        {
            a[fy]=fx;
            vis[fy]=(3+c-1+vis[x]-vis[y])%3;
        }
        else
        {
            if(c==1&&vis[x]!=vis[y])
            {
                sum++;
                continue ;
            }
            if(c==2&&(3-vis[x]+vis[y])%3!=c-1)
            {
                sum++;
                continue ;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
