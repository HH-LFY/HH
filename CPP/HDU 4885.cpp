#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int inf=999999999;
int t;
int n,l;
double map[1010][1010];
int vis[1010];
int dis[1010][2];
int kmin;

double hypot(int x1,int y1,int x2,int y2)
{
    int x=(x1-x2)*(x1-x2);
    int y=(y1-y2)*(y1-y2);
    return sqrt(x+y);
}

void dfs(int p,int t)
{
    int i;
    if(p==n+1)
    {
        kmin=min(kmin,t-1);
    }
    for(i=0;i <= n+1;i++)
    {
        if(vis[i]==0)
        {
            if(map[p][i]==inf)
            {
                map[p][i]=map[i][p]=hypot(dis[p][0],dis[p][1],dis[i][0],dis[i][1]);
            }
            if(map[p][i]<=l)
            {
                vis[i]=1;
                dfs(i,t+1);
                vis[i]=0;
            }
        }
    }
}

int main( )
{
    cin>>t;
    while(t--)
    {
        kmin=inf;
        int i,j;
        cin>>n>>l;
        for(i = 0; i <= n+1; i++)
        {
            vis[i]=0;
            for(j=0;j <= n+1 ;j++)
            {
                map[i][j]=inf;
            }
        }
        cin>>dis[0][0]>>dis[0][1];
        cin>>dis[n+1][0]>>dis[n+1][1];
        map[0][n+1]=map[n+1][0]=hypot(dis[0][0],dis[0][1],dis[n+1][0],dis[n+1][1]);
        for(i=1;i <= n; i++)
        {
            cin>>dis[i][0]>>dis[i][1];
        }
        vis[0]=1;
        dfs(0,0);
        if(kmin!=inf)
            cout<<kmin<<endl;
        else
            cout<<"impossible"<<endl;
    }
    return 0;
}
