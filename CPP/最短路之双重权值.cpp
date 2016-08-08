#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf=99999999;
const int maxx=1000+10;
int map[maxx][maxx][2];
int vis[maxx];
int dis[maxx][2];
int n,m;
int x,y,d,p;
int s,t;
int i,j,k;

int min(int x,int y)
{
    return x>y?y:x;
}

void set( )
{
    for(i=1;i <= n ; i++)
    {
        vis[i]=0;
        for(j=i; j <= n; j++)
        {
            if(i==j)
            {
                map[i][j][0]=0;
                map[i][j][1]=0;
            }
            else
            {
                map[i][j][0]=map[j][i][0]=inf;
                map[i][j][1]=map[j][i][1]=inf;
            }
        }
    }
}

int main( )
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        set();
        for(i=1;i <= m; i++)
        {
            scanf("%d%d%d%d",&x,&y,&d,&p);
            if(map[x][y][0]>d)
            {
                map[x][y][1]=map[y][x][1]=p;
                map[x][y][0]=map[y][x][0]=d;
            }
            else if(map[x][y][0]==d)
            {
                map[x][y][1]=map[y][x][1]=min(map[x][y][1],p);
            }
        }
        scanf("%d%d",&s,&t);
        int kv=0;
        for(i = 1; i <= n; i++)
        {
            dis[i][0]=map[s][i][0];
            dis[i][1]=map[s][i][1];
        }
        vis[s]=1;
        int kmin,kx;
        for(i = 1;i <= n; i++)
        {
            kmin=inf;
            for(j = 1;j <= n; j++)
            {
                if(vis[j]!=1&&dis[j][0]<kmin)
                {
                    kmin=dis[j][0];
                    kx=j;
                }
            }
            vis[kx]=1;
            for(j = 1;j <= n; j++)
            {
                if(vis[j]!=1&&dis[j][0]>dis[kx][0]+map[kx][j][0])
                {
                    dis[j][1]=dis[kx][1]+map[kx][j][1];
                    dis[j][0]=dis[kx][0]+map[kx][j][0];
                }
                else if(vis[j]!=1&&dis[j][0]==dis[kx][0]+map[kx][j][0])
                {
                    dis[j][1]=min(dis[kx][1]+map[kx][j][1],dis[j][1]);
                }
            }
        }
        cout<<dis[t][0]<<" "<<dis[t][1]<<endl;
    }
    return 0;
}
