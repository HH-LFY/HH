#include <iostream>
#include <cstdio>
using namespace std;

const int maxx=100+10;
int map[maxx][maxx];
int vis[maxx][maxx];
int n;
int i,j;

int max(int x,int y)
{
    return x>y?x:y;
}

int dp(int x,int y)
{
    if(vis[x][y]!=-1)
    {
        return vis[x][y];
    }
    if(x==n)
    {
        vis[x][y]=map[x][y];
    }
    else
    {
        int kx=dp(x+1,y);
        int ky=dp(x+1,y+1);
        vis[x][y]=max(kx,ky)+map[x][y];
    }
    return vis[x][y];
}

int main( )
{
    cin>>n;
    for(i = 1;i <= n; i++)
    {
        for(j=1;j <= i; j++)
        {
            scanf("%d",&map[i][j]);
            vis[i][j]=-1;
        }
    }
    cout<<dp(1,1)<<endl;
    return 0;
}
