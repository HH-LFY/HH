#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx = 30000 + 10;
int dis[maxx];
int r[maxx];
int sum[maxx];

int find(int x)
{
    if(x==dis[x]) return x;
    int k = dis[x];
    dis[x]=find(dis[x]);
    r[x]+=r[k];
    return dis[x];
}

void join(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
    {
        dis[fx] = fy;
    }
    r[fx]=sum[fy];
    sum[fy]=sum[fx]+sum[fy];

}

int main( )
{
    int p;
    while(cin>>p)
    {
        for(int i = 1;i <= maxx; i++)
        {
            dis[i] = i;
            r[i] = 0;
            sum[i] = 1;
        }
        getchar( );
        char c;
        int x,y;
        while(p--)
        {
            scanf("%c",&c);
            if('M'==c)
            {
                scanf("%d%d",&x,&y);
                getchar( );
                join( x, y);
            }
            else if('C'==c)
            {
                scanf("%d",&x);
                getchar( );
                find(x);
                cout<<r[x]<<endl;
            }
        }
    }
    return 0;
}
