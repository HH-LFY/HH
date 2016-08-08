#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define inf 0x3f3f3f
int map[100+10][100+10];
int vis[100+10];
int n;

int main( )
{
    while(cin>>n&&n)
    {
        for(int i = 0;i <= n; i++)
        {
            vis[i]=0;
            for(int j = i;j <= n;j++)
            {
                if(i==j)
                {
                    map[i][j]=0;
                }
                else
                {
                    map[i][j]=map[j][i]=inf;
                }
            }
        }
        int x,y,d;
        for(int i = 1;i <= n*(n-1)/2;i++)
        {
            scanf("%d%d%d",&x,&y,&d);
            map[x][y]=map[y][x]=d;
        }
        int sum=0;
        vis[1]=1;
        int kx=1;
        int kj;
        int kmin;
        while(1)
        {
            if(kx==n)break;
            kmin=inf;
            for(int i = 1;i <= n; i++)
            {
                if(vis[i])
                {
                    for(int j = 1;j <= n; j++)
                    {
                        if(!vis[j]&&kmin>map[i][j])
                        {
                            kmin=map[i][j];
                            kj=j;
                        }
                    }
                }
            }
            sum+=kmin;
            vis[kj]=1;
            kx++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
