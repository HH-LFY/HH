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
        memset(vis,0,sizeof(vis)); ///�������ʼ��
        memset(kis,0,sizeof(kis));
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= t; i++)
        {
            for(int j = n; j >= val[i]; j--)
            {
                if(dp[j]<=(dp[j-val[i]]+val[i])) ///01�����ĺ��� �� �жϷ��벻�� �������������
                {
                    dp[j]=dp[j-val[i]]+val[i];
                    vis[i][j] = val[i]; ///��¼�ڿɷ����ΪJ������£�����ĵ�i����Ʒ�ļ�ֵ
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
                k -= val[i];  /// ����01����������Ž�Ĺ���������·��
            }
        }
        for(int i = p-1; i >= 0 ; i--)
        {
            cout<<kis[i]<<" "; ///������ĿҪ��Ҫ����˳�������
        }
        cout<<"sum:"<<dp[n]<<endl;
    }
    return 0;
}
