#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx=500+10;
int line[maxx][maxx];
int used[maxx];
int vis[maxx];
int k,n,m;

int find(int x)
{
    int i,j;
    for(i = 1;i <= m; i++)
    {
        if(used[i]==0&&line[x][i])
        {
            used[i]=1;
            if(vis[i]==0||find(vis[i]))
            {
                vis[i]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main( )
{
    while(cin>>k&&k)
    {
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n; i++)
        {
            for(int j = 1;j <= m; j++)
            {
                line[i][j]=0;
            }
        }
        int x,y;
        while(k--)
        {
            scanf("%d%d",&x,&y);
            line[x][y]=1;
        }
        int sum=0;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= m; j++)
            {
                used[j]=0;
            }
            if(find(i))sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
