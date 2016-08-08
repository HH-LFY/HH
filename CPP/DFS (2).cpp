#include<stdio.h>
#include<string.h>
int n,m,t;
int kx,ky;
int dx,dy;
int wall;
int judge;
const int dir[4][2]={{0,1},{ 1, 0 }, { 0, -1 }, { -1, 0 } };
char str1[100][100],vis[100][100];
int fabs(int U)
{
    if(U>0)return U;
    else return -U;
}

void dfs(int kx,int ky,int kt)
{
    if(kx<=0||kx>n||ky<=0||ky>m||kt>t) return ;
    if(str1[kx][ky]=='D'&&kt==t)
    {
        judge=1;
        return ;
    }
    int time=t-fabs(dx-kx)-fabs(dy-ky)-kt;
    if(time<0||time%2)
        return ;
    for(int i=0;i<4;i++)
    {
        int tx=kx+dir[i][0];
        int ty=ky+dir[i][1];
        int test=kt+1;
        if(tx>0&&tx<=n&&ty>0&&ty<=m&&vis[tx][ty]==0)
        {
         vis[tx][ty]=1;
         dfs(tx,ty,test);
         vis[tx][ty]=0;
        }
    }
    return ;
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        if(n==0&&m==0&&t==0)break;
        memset(str1,0,sizeof(str1));
        memset(vis,1,sizeof(vis));
        wall=0;
        getchar();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%c",&str1[i][j]);
                if(str1[i][j]=='S')
                {
                    vis[i][j]=0;
                    kx=i;
                    ky=j;
                }
                else if(str1[i][j]=='D')
                {
                    vis[i][j]=0;
                    dx=i;
                    dy=j;
                }
                else if(str1[i][j]=='X')
                {
                    wall++;
                }
                else if(str1[i][j]=='.')
                {
                    vis[i][j]=0;
                }
            }
            getchar();
        }
        judge=0;
        vis[kx][ky]=1;
        if((n*m-wall)>=t)
        {
            dfs(kx,ky,0);
        }
        if(judge)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
