#include<stdio.h>
#include<string.h>
#include<math.h>
const int inf=999999;
int map[210][210];
int a,b,c;
int i,j,k;
int n,m;
int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        memset(map,inf,sizeof(map));
        for(i=1;i<=n;i++)
            map[i][i]=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=map[b][a]=c;
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                        map[i][j]=min(map[i][j],map[i][k]+map[j][k]);
                }
            }
        }
        printf("%d\n",map[1][n]);
    }
    return 0;
}
