#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct mapp
{
    int s;
    int e;
    int d;
};

const int inf=99999999;
mapp map[110*110];
int vis[110];
int p,n;
int a,b,d;

bool cmd(mapp a,mapp b)
{
    return a.d<b.d;
}

int find(int x)
{
    if(x==vis[x])
        return x;
    else
        return vis[x]=find(vis[x]);
}

void add(int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy)
        vis[fx]=fy;
}

int main( )
{
    while(cin>>n)
    {
        int t=0;
        for(int i=1; i <= n; i++)
        {
            vis[i]=i;
            for(int j = 1; j <= n; j++)
            {
                scanf("%d",&d);
                if(j<i)continue;
                map[t].s=i;
                map[t].e=j;
                map[t].d=d;
                t++;
            }
        }
        cin>>p;
        while(p--)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        int sum=0;
        sort(map,map+t,cmd);
        for(int i = 0;i < t; i++)
        {
            if(find(map[i].s)!=find(map[i].e))
            {
                add(map[i].s,map[i].e);
                sum+=map[i].d;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
