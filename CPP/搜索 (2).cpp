#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int countt=1;
int n;
int vis[21],a[21];
int prim[50];

int ss(int a)
{
    int i;
    for(i=2;i*i<=a;i++)
        if(a%i==0)return 0;
        return 1;
}

void dfs(int k)
{
    if(k==n&&prim[a[0]+a[n-1]])
    {
        cout<<a[0];
        for(int i = 1; i < n ; i++ )
        {
            cout<<" "<<a[i];
        }
        cout<<endl;
    }
    else
    {
        for(int i = 2; i <= n; i++ )
        {
            if(!vis[i]&&prim[a[k-1]+i])
            {
                a[k]=i;
                vis[i]=1;
                dfs(k+1);
                vis[i]=0;
            }
        }
    }
}

int main()
{
    memset(prim,0,sizeof(prim));
    prim[1]=1;
    for(int i = 2; i <50 ;i++)
    {
        if(ss(i))
        {
            prim[i]=1;
        }
    }
///    for(int i = 0;i < 50;i++)
///        cout<<prim[i]<<",";
    a[0]=1;
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        cout<<"Case "<<countt++<<":"<<endl;
        dfs(1);
        cout<<endl;
        system("pause");
    }
    return 0;
}
