#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx = 50005;
int dis[maxx];
int vis[maxx][2],kis[maxx][2];
long long pow[maxx];
int n,m;
int resultt[maxx];
int ss=1;

void set( )
{
    for(int i = 0;i < n; i++)
    {
        dis[i] = i;
    }
}

int find(int x)
{
    if(x==dis[x]) return x;
    else return find(dis[x]);
}

void join(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(pow[fx]<pow[fy])
    {
        dis[fx] = fy;
    }
    else if(pow[fx]>pow[fy])
    {
            dis[fy] = fx;
    }
    else if(fx > fy)
    {
            dis[fx] = fy;
    }
    else
    {
            dis[fy] = fx;
    }
}

void destroy(int x,int y)
{
    for(int i = 1;i <= m; i++)
    {
        if((vis[i][0]==x&&vis[i][1]==y)||(vis[i][1]==x&&vis[i][0]==y))
        {
            vis[i][1] = -1;
            vis[i][0] = -1;
            break;
        }
    }
}

int judge(int x)
{
    int fx = find(x);
    if(pow[fx]>pow[x]) return fx;
    else return -1;
}

int main( )
{
    while(cin>>n)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%lld",&pow[i]);
        }
        int x,y;
        cin>>m;
        for(int o = 1; o <= m; o++)
        {
            scanf("%d%d",&x,&y);
            if(x>y)
            {
                int ff=x;
                x=y;
                y=ff;
            }
            vis[o][0] = x;
            vis[o][1] = y;
        }
        int p,kx,ky,k;
        char str[100];
        cin>>p;
        getchar( );
        int result[maxx];
        int q=1,h=1,l=1;
        while(p--)
        {
            scanf("%s",str);
            if(str[1]=='u')
            {
                scanf("%d",&k);
                result[q++]=k;
            }
            else if(str[1]=='e')
            {
                scanf("%d%d",&kx,&ky);
                result[q++]=-1;
                kis[h][0] = kx;
                kis[h][1] = ky;
                h++;
                destroy(kx,ky);
            }
            getchar( );
        }
        set( );
        for(int i = 1;i <= m; i++)
        {
            if(vis[i][0]!=-1)
                join(vis[i][0],vis[i][1]);
        }
        for(int i = q-1; i > 0; i--)
        {
            if(result[i]!=-1)
            {
                resultt[l++]=judge(result[i]);
            }
            else
            {
                h--;
                join(kis[h][0],kis[h][1]);
            }
        }
        if(ss++!=1) cout<<endl;
        for(int i = l-1; i >= 1;i--)
        {
            cout<<resultt[i]<<endl;
        }
    }
    return 0;
}
