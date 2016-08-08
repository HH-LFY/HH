#include<iostream>
#include<cstring>
#include<cstdio>
using  namespace std;

#define maxx 1020
const int inf=999999;
int map[maxx][maxx];
bool vis[maxx];
int n,m;
int x,y;
int sum;

void prim()
{
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    int k=1;
    sum=0;
    while(k<=n)
    {
        int minn=inf+1;
        int a=0;
        for(int i = 1;i <= n;i++ )
        {
            if(vis[i])
            {
                for(int j = 1;j <= n;j++ )
                {
                    if(vis[j]==0&&minn>map[i][j])
                    {
                        minn=map[i][j];
                        a=j;
                    }
                }
            }
        }
        if(minn<inf)
        {
            vis[a]=1;
            sum += minn;
 ///           cout<<a<<"kao"<<minn<<endl;
        }
        k++;
    }
}

int main()
{
    while(cin>>n)
    {
        if(n==0)break;
        cin>>m;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                map[i][j]=1;
            }
        }
        for(int i = 1;i <= m;i++ )
        {
            cin>>x>>y;
            map[x][y]=map[y][x]=0;
 ///           cout<<x<<","<<y<<"juli:"<<map[x][y]<<endl;
        }
        prim();
 ///       sum = (int)sum/1000;
        cout<<sum<<endl;
    }
    return 0;
}
