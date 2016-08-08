#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int sticks[65];///储存棍子的长度
int vis[65];///标记棍子是否已经被用过
int n;///棍子的数量

int cmd(int x, int y)
{
    return x>y;
}

int dfs(int y,int l,int p) /// y：当前已经用去的棍子数量  l：目标棍子的长度 p：当前已经匹配的棍子的长度
{
    if(y==n)
        return 1;
    int sam=-1;
    for(int i = 0;i < n; i++)
    {
        if(vis[i]==1||sticks[i]==sam)///剪枝2：假如上一次棍子无法匹配，那么后面与上一次棍子长度相同的棍子也无法匹配
            continue;
        vis[i]=1;///标记为已经用过
        if(p+sticks[i]<l)///如果能够匹配，则加上去
        {
            if(dfs(y+1,l,p+sticks[i]))
                return 1;
            else
                sam=sticks[i];
        }
        else if(p+sticks[i]==l)///成功匹配出一条目标长度的棍子，则把 p 清零
        {
            if(dfs(y+1,l,0))
                return 1;
            else
                sam=sticks[i];
        }
        vis[i]=0;///经过搜索后没有出现成功匹配的情况，则要把标记解除，以便下次再用
        if(p==0)///剪枝3：当前长度的棍子均无法匹配的时候则说明目标棍子无法在当前情况下组合
        {
            cout<<"此时的棍子长度："<<sticks[i]<<"    第i根棍子："<<i<<"     目标长度："<<l<<"  已经匹配的棍子数："<<y<<endl;
            break;
        }
    }
    return 0;
}

int main( )
{
    while(cin>>n&&n)
    {
        int sum=0;///记录棍子总长度
        for(int i = 0;i < n; i++)
        {
            scanf("%d",&sticks[i]);
            sum+=sticks[i];
            vis[i]=0;
        }
        sort(sticks,sticks+n,cmd);///对棍子进行降序排序
        int maxx=sticks[0];
        int judge=0;
        for(int i = maxx;i <= sum/2+1;i++)
        {
            if(sum%i==0&&dfs(0,i,0))///剪枝1:目标棍子的长度必须可被总长度整除
            {
                cout<<i<<endl;
                judge=1;
                break;
            }
        }
        if(judge==0)
            cout<<sum<<endl;
    }
    return 0;
}
