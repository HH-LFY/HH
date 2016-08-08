#include <iostream>
#include <cstring>
using namespace std;

int n,t,k,p;
int val[30];
int dp[1010];
int vis[30][1010];
int kis[30];

int main( )
{
    while(cin>>n>>t&&n&&t)
    {
        for(int i = 1; i <= t; i++)
        {
            cin>>val[i];
        }
        memset(vis,0,sizeof(vis)); ///对数组初始化
        memset(kis,0,sizeof(kis));
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= t; i++)
        {
            for(int j = n; j >= val[i]; j--)
            {
                if(dp[j]<=(dp[j-val[i]]+val[i])) ///01背包的核心 ， 判断放与不放 ，放则更新数据
                {
                    dp[j]=dp[j-val[i]]+val[i];
                    vis[i][j] = val[i]; ///记录在可放体积为J的情况下，放入的第i件物品的价值
                }
            }
        }
        k = n;
        p = 0;
        for(int i = t; i >= 1 ; i--)
        {
            if(vis[i][k])
            {
                kis[p++] = vis[i][k];
                k -= val[i];  /// 根据01背包求解最优解的过程逆推其路径
            }
        }
        for(int i = p-1; i >= 0 ; i--)
        {
            cout<<kis[i]<<" "; ///根据题目要求，要按‘顺’序输出
        }
        cout<<"sum:"<<dp[n]<<endl;
    }
    return 0;
}
