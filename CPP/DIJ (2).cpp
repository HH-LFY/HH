#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxx=100000005;
const int maxn=1005;
int map[maxn][maxn];
int dis[maxn];
int vis[maxn];
int n,m;
void init()
{
    int i, j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            map[i][j]=maxx;
        }
    }
}
void dij(int s,int e)
{
    int i,j,k,minn;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
    {
        dis[i]=map[s][i];
    }
    dis[s]=0;
    vis[s]=1;
    for(j=1;j<=n;j++)
    {
        minn=maxx;
        for(i=1;i<=n;i++)
        {
            if(!vis[i]&&minn>dis[i])
            {
                minn=dis[i];
                k=i;
            }
        }
        vis[k]=1;
        for(i=1;i<=n;i++)
        {
            if(!vis[i]&&dis[i]>dis[k]+map[k][i])
            {
                dis[i]=dis[k]+map[k][i];
            }
        }
    }
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
    {
        init();
        memset(dis,0,sizeof(dis));
        int x,y,z;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(map[x][y]>z)
            {
               map[x][y]=map[y][x]=z;
            }
        }
        dij(1,n);
        printf("%d\n",dis[n]);
    }
    return 0;
}

