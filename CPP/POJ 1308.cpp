#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxx 10010
#define max(x,y) x>y?x:y
int vis[maxx],dis[maxx];
int k=1;

int main( )
{
    int a,b,sum,count;
    while(cin>>a>>b)
    {
        int count = 2,maxn=-maxx;
        maxn = max(maxn,a);
        maxn = max(maxn,b);
        sum = 1;
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        vis[a] = 1;
        vis[b] = 1;
        dis[b]++;
        int judge = 1;
        if(a==0&&b==0)
        {
            printf("Case %d is a tree.\n",k++);
            continue;
        }
        else if(a==-1&&b==-1) break;
        else
        {
            int x,y;
            int t0=0,t1=1;
            while(cin>>x>>y&&x&&y)
            {
                sum++;
                maxn = max(maxn,x);
                maxn = max(maxn,y);
                if(!vis[x]) {count++;vis[x]=1;}
                if(!vis[y]) {count++;vis[y]=1;}
                dis[y]++;
            }
            if(sum>=count)
            {
                printf("Case %d is not a tree.\n",k++);
            }
            else
            {
                for(int i = 1;i <= maxn; i++)
                {
                    if(vis[i])
                    {
                        if(dis[i]==0)
                        {
                            t0++;
                        }
                        else if(dis[i]>1)
                        {
                            judge = 0;
                            break;
                        }
                    }
                }
                if(t0!=1)
                    judge = 0;
                if(judge)
                    printf("Case %d is a tree.\n",k++);
                else
                    printf("Case %d is not a tree.\n",k++);
            }
        }
    }
    return 0;
}
