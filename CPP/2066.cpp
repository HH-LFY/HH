#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define max 1010
const int inf=99999999;
int map[max][max];
int dis[max];
int vis[max];
int t,s,d;
int a,b,c;
int i,j,k;
int x,y;
int D[max];
int a1[max],a2[max];

void dij(int s,int e)
{
    int i,j,k,minn;
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    for(i=1;i<=y;i++)
    {
        dis[i]=map[s][i];
    }
    dis[s]=0;
    vis[s]=1;
    for(j=1;j<=y;j++)
    {
        minn=inf;
        for(i=1;i<=y;i++)
        {
            if(!vis[i]&&minn>dis[i])
            {
                minn=dis[i];
                k=i;
            }
        }
        vis[k]=1;
        for(i=1;i<=y;i++)
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
    while(scanf("%d%d%d",&t,&s,&d)!=EOF)
    {
        int result=inf;
        y=0;
        for(i=0;i<max;i++)
            for(j=0;j<max;j++)
            map[i][j]=inf;
        for(i=0;i<max;i++)
            map[i][i]=0;
        for(i=1;i<=t;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(map[a][b]>c)
                map[a][b]=map[b][a]=c;
            if(y<a) y=a;
            if(y<b) y=b;
        ///    printf("%d %d %d\n",a,b,c);
        }
        for(i=0;i<s;i++)
        {
            scanf("%d",&a2[i]);
            map[0][a2[i]]=map[a2[i]][0]=0;
        ///    printf("%d ",a2[i]);
        }
       /// printf("\n");
        dij(0,y);
        for(i=0;i<d;i++)
        {
            scanf("%d",&a1[i]);
            if(result>dis[a1[i]])
                result=dis[a1[i]];
           /// printf("%d ",a1[i]);
        }
       /// printf("\n");
        printf("%d\n",result);
    }
    return 0;
}
