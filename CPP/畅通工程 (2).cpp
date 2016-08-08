#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;

const int inf=100010;
bool vis[120];
int map[120][120];
int x,y,z;
int n,m;
int judge,tim,k;

int prim()
{
    tim = 1;
    vis[1] = 1;
    int sum=0;
   while(tim<=m-1)
	{
	    int minn = inf+1;
	    int a = 0,b = 0;
	    for(int i = 1;i <= m;i++)
        {
            if(vis[i])
            {
                for(int j = 1;j <= m;j++)
                {
                    if(vis[j]==0&&minn>map[i][j])
                    {
                        a=i;
                        b=j;
                        minn=map[i][j];
                    }
                }
            }
        }
        if(minn<inf)
        {
            sum+=minn;
            vis[b]=1;
        }
	    tim++;
    }
    for(int i = 1;i <= m;i++)
    {
        if(vis[i]==0)
        {
            judge=1;
            break;
        }
    }
    return sum;
}

int main()
{
    while(cin>>n>>m)
    {
        if(n==0)break;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                map[i][j]=inf;
            }
        }
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            if(map[x][y]>z)
            {
                map[x][y]=z;
            }
        }
        judge=0;
        int ss=prim();
        if(judge) cout<<"?"<<endl;
        else cout<<ss<<endl;
    }
    return 0;
}
