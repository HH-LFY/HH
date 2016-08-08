#include<iostream>
#include<cstring>
using namespace std;

int max(int x, int y)
{
    return x>y?x:y;
}

int v[1010];
int dp[60050];


int main( )
{
    int n;
    while(cin>>n&&n)
    {
        int m;
        int maxx = 0,k;
        memset(dp,0,sizeof(dp));
        for(int o = 1; o <= n; o++)
        {
            cin>>v[o];
            if(maxx<v[o])
            {
                maxx = v[o];
                k = o;
            }
        }
        cin>>m;
        m = m - 5;
        if(m>=0)
        {
        for(int i = 1; i <= n; i++)
        {
            if(i != k)
            for(int j = m; j >= v[i]; j--)
            {
                    dp[j] = max(dp[j],dp[j-v[i]]+v[i]);
            }
        }
        cout<<m+5-maxx-dp[m]<<endl;
        }
        else
        {
            cout<< m + 5 <<endl;
        }
    }
    return 0;
}
