#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define inf 0x3f3f3f
int map[100+10][100+10];
int vis[100+10];
int n,m;

int main( )
{
    while(cin>>n>>m&&n)
    {
        for(int i = 0;i <= m; i++)
        {
            vis[i]=0;
            for(int j = i;j <= m;j++)
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
        for(int i = 1;i <= n;i++)
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
            if(kx==m)break;
            kmin=inf;
            for(int i = 1;i <= m; i++)
            {
                if(vis[i])
                {
                    for(int j = 1;j <= m; j++)
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
        if(sum>=inf)
            cout<<"?"<<endl;
        else
            cout<<sum<<endl;
    }
    return 0;
}
