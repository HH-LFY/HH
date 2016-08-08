#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxx 300100
bool vis[maxx];
int f[maxx],next[maxx];
int link[maxx],dis[maxx];
int t,m,n,p;
int i,j;

int find(int k)
{
    for( i = f[k]; i != -1;i = next[i])
    {
        if(!vis[dis[i]])
        {
            vis[dis[i]]=1;
            if(link[dis[i]]==0||find(link[dis[i]]))
            {
                link[dis[i]]=k;
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
        cin>>p>>n;
        if(p<=n)
        {
            int judge = 1;
            int k = 0;
            memset(f,-1,sizeof(f));
            memset(link,0,sizeof(link));
            for(i = 0; i < p; i++)
            {
                scanf("%d",&m);
                for(j = 0;j < m;j++,k++)
                {
                    scanf("%d",&dis[k]);
                    next[k] = f[i+1];
                    f[i+1 ]= k;
                }
            }
            for(i = 1;i <= p; i++)
            {
                memset(vis,0,sizeof(vis));
                if(!find(i))
                {
                    judge = 0;
                    break;
                }
            }
            if(judge)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
        {
            cout <<"NO"<<endl;
        }
    }
    return 0;
}
