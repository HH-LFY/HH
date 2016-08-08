#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int line[150][310];
int used[310];
int vis[310];
int p,n;
int t;

int find(int x)
{
    int i,j;
    for(i=1;i <= n;i++)
    {
        if(vis[i]==0&&line[x][i]==1)
        {
            vis[i]=1;
            if(used[i]==0||find(used[i]))
            {
                used[i]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main( )
{
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&p,&n);
        for(int i = 0; i <= p;i++)
        {
            for(int j = 0; j <= n; j++)
            {
                line[i][j]=0;
            }
        }
        for(int i = 0;i <= n; i++)
        {
            used[i]=0;
        }
        for(int o=1;o <= p; o++)
        {
            int x,y;
            scanf("%d",&x);
            while(x--)
            {
                scanf("%d",&y);
                line[o][y]=1;
            }
        }
        int judge=0;
        for(int i = 1;i <= p; i++)
        {
            memset(vis,0,sizeof(vis));
            if(find(i)) judge++;
        }
        if(judge==p)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
