#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx=100+10;
bool vis[maxx*7];
int line[maxx][maxx];
int used[maxx*7];
int map[maxx*7];
int n,m;
int k;

int find(int x)
{
    int i,j;
    for(i=0;i < k;i++)
    {
        if(i==x)
        {
            vis[i]=1;
            continue;
        }
        if(vis[i]==0&&line[map[x]][map[i]]==1)
        {
            vis[i]=1;
            if(used[i]==-1||(find(used[i])))
            {
                used[i]=x;
                used[x]=i;
                return 1;
            }
        }
    }
    return 0;
}


int main( )
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i = 0;i <= n; i++)
        {
            for(int j = 0;j <= n; j++)
            {
                line[i][j]=0;
            }
        }

        int p;

        k=0;
        for(int i = 1;i <= n; i++)
        {
            scanf("%d",&p);
            for(int j = k;j < (k+p); j++)
            {
                used[j]=-1;
                map[j]=i;
            }
            k=k+p;
        }

        int x,y;
        for(int i = 1;i <= m; i++)
        {
            scanf("%d%d",&x,&y);
            line[x][y]=line[y][x]=1;
        }

        for(int i = 0;i < k; i++)
        {
            if(used[i]!=-1)
                continue;
            for(int j = 0;j < k;j++)
            {
                vis[j]=0;
            }
            find(i);
        }

        for(int i = 0;i < k; i++)
        {
            if(used[i]!=-1)
                continue;
            for(int j = 0;j < k;j++)
            {
                vis[j]=0;
            }
            find(i);
        }

        for(int i = 0;i < k; i++)
        {
            cout<<"used []:"<<i<<"->"<<used[i]<<endl;
        }

        int result=0;
        for(int i = 0;i < k; i++)
        {
            if(used[i]!=-1)
            {
                result++;
            }
        }
        cout<<result/2<<endl;
    }
    return 0;
}
