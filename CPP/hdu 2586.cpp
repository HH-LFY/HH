#pragma comment(linker, "/STACK:102400000,102400000")
#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

const int maxn = 40010;
int pre[maxn][20];
int dp[maxn][20];
bool vis[maxn];
int head[maxn],cnt,deep[maxn];

struct node
{
    int u,v,next,val;
}edge[maxn*2];

void init()
{
    cnt = 0;
    memset(vis,false,sizeof(vis));
    memset(dp,0,sizeof(dp));
    memset(pre,-1,sizeof(pre));
    memset(head,-1,sizeof(head));
}

void add(int u,int v,int val)
{
    edge[++cnt].next = head[u];
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].val = val;
    head[u] = cnt;
}

void dfs(int x,int fa,int de)
{
    vis[x] = 1;
    pre[x][0] = fa;
    deep[x] = de;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v==fa) continue;
        dp[v][0] = edge[i].val;
        dfs(v,x,de+1);
    }
}

void build(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i,0,1);
    }

    for(int k=1;k<20;k++)
        for(int i=1;i<=n;i++)
        if(pre[i][k-1]!=-1){
            pre[i][k] = pre[ pre[i][k-1] ][ k-1 ];
            dp[i][k] = dp[i][k-1] + dp[ pre[i][k-1] ][k-1];
        }
}

void solve(int x,int y)
{
    if(deep[x]<deep[y]) swap(x,y);
    int len = deep[x] - deep[y];
    int ans = 0;
    for(int i=0;len;i++)
    {
        if(len&1){
            ans += dp[x][i];
            x = pre[x][i];
        }
        len/=2;
    }
    if(x==y){
        printf("%d\n",ans);
        return ;
    }
    while(true){
        int j;
        for(j=0;pre[x][j]!=pre[y][j];j++) ;

        if(j==0){
            printf("%d\n",ans+dp[x][j] + dp[y][j]);
            return ;
        }

        x = pre[x][j-1];
        y = pre[y][j-1];

        ans+=dp[x][j-1]+dp[y][j-1];
    }
}

int main()
{
    int T,n,m,a,b,c;
    cin>>T;
    while(T--){
        cin>>n>>m;
        init();
        for(int i=1;i<n;i++)
        {
            cin>>a>>b>>c;
            add(a,b,c);
            add(b,a,c);
        }
        build(n);
        while(m--)
        {
            cin>>a>>b;
            solve(a,b);
        }
    }
    return 0;
}
