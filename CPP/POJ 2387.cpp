#include <cstdio>
#include <iostream>
#define inf (1<<30) - 1
using namespace std;

int m,n;
int e[3005][3005];
int vis[3005],d[3005];
int p[3005];

void D( )
{
    int i,j,k;
    for(i=1; i<=n; i++)
    {
        vis[i] = 0;///初始化所有点， 0 表示未被访问， 1 表示已经访问
        d[i] = e[1][i]; ///此时的 d[i] 为起始点‘1’到达点 i 的距离。
    }
    d[1] = 0;
    vis[1] = 1; ///对起始点‘1’ 进行标记
    for(i=1; i < n; i++)
    {
        int kmin = inf;///定义一个储存最小值的变量
        int tag = -1;
        for(j = 1;j <= n; ++j)
        {
            if(!vis[j]&&kmin > d[j]) ///找出未被访问的点中与起始点最近的点，并记录下来
            {
                kmin = d[j];
                tag = j;
            }
        }
        vis[tag] = 1;///对该点进行标记
        for( j = 1;j <= n; ++j)
        {
            if(vis[j]) continue;///如果点 j 已经被访问，那么不再处理直接跳过
            d[j]=min(d[tag]+e[tag][j],d[j]);
            /**
                d[tag] 为起始点到点 tag 的最短路径。

                那么起始点到点 j 的路径要么为 d[j] 要么为 d[tag]+e[tag][j] 取最小即可

                这是一个贪心递推的过程。

                如果不是太理解这个算法的思路，可以自己在纸上画一下这个图的最短路构造过程。

            */
        }
    }
}

int main()
{
    int i,j,u,v,w;
    scanf("%d%d",&m,&n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(i == j) e[i][j] = 0; ///初始化图
            else e[i][j]=inf;
        }
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        e[u][v]=e[v][u]=min(e[u][v],w);///用 min 是为了防止有重边出现。即：当 u 和 v 之间出现重边时，那么取权值最小的那条
    }
    D();
    printf("%d\n",d[n]);
    return 0;
}
