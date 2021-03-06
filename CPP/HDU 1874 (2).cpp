#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define maxx 250
const int inf=999999;
int n,m;
int s,t;
int a,b,c;
int map[maxx][maxx];
int dis[maxx];
int vis[maxx];

void dij(int x,int y)
{
    int i,j,k,min;
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    for(i=0;i<n;i++)
    {
        dis[i]=map[x][i];
    }
    vis[x]=1;
    for(i=0;i<n;i++)
    {
        min=inf;
        for(j=0;j<n;j++)
        {
            if(!vis[j]&&min>dis[j])
            {
                min=dis[j];
                k=j;
            }
        }
        vis[k]=1;
        for(j=0;j<n;j++)
        {
            if(!vis[j]&&dis[j]>dis[k]+map[k][j])
                dis[j]=dis[k]+map[k][j];
        }
    }
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            map[i][j]=inf;
        for(int i=0;i<n;i++)
            map[i][i]=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(map[a][b]>c)
            map[a][b]=map[b][a]=c;
        }
        scanf("%d%d",&s,&t);
        dij(s,t);
        if(dis[t]<inf)
            printf("%d\n",dis[t]);
        else
            printf("-1\n");
    }
    return 0;
}
