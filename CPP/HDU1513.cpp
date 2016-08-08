#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxx 5010
int dp[3][maxx];
char str[maxx];
int n;

int min(int x,int y)
{
    if(x>y)return y;
    else return x;
}

int main( )
{
    while(cin>>n)
    {
        memset(dp,0,sizeof(dp));
        memset(str,0,sizeof(str));
        cin>>str;
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(str[i]==str[j])
                    dp[i%2][j]=dp[(i+1)%2][j-1];
                else
                    dp[i%2][j]=min(dp[(i+1)%2][j],dp[i%2][j-1])+1;
            }
        }
        printf("%d\n",dp[0][n-1]);
    }
    return 0;
}
