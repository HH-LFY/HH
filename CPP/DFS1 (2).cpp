#include<stdio.h>
#include<string.h>
char str1[10][10],vis[10][10];
void dfs(int kx,int ky,int t)
{
    if(kx<0||ky)
}
int main()
{
    int n,m,t;
    int kx,ky;
    int dx,dy;
    int wall;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        if(n==0&&m==0&&t==0)break;
        wall=0;
        memset(str1,0,sizeof(str1));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            getchar();
            for(int j=1;j<=m;j++)
            {
                scanf("%c",&str1[i][j]);
                if(str1[i][j]=='S')
                {
                    kx=i;
                    ky=j;
                }
                else if(str1[i][j]=='D')
                {
                    dx=i;
                    dy=j;
                }
                else if(str1[i][j]=='X')
                {
                    vis[i][j]=1;
                    wall++;
                }
            }
        }
        for(int i=1;i<=n;i++)
        printf("%s\n",str1[i]);
    }
    return 0;
}
