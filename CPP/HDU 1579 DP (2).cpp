#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int w[21][21][21];
int a,b,c;
int s;


///int dp(int a,int b,int c,int s)
///{
///    if(a<=0||b<=0||c<=0) return (s=s+1);
///    else if(a>20||b>20||c>20) return (s+=dp(20,20,20,s));
///    else if(a<b&&b<c) return s+=(dp(a,b,c-1,s)+dp(a,b-1,c-1,s)-dp(a,b-1,c,s));
///    else return s+=(dp(a-1, b, c,s) + dp(a-1, b-1, c,s) + dp(a-1, b, c-1 ,s) - dp(a-1, b-1, c-1, s));
///}

int main( )
{
    while(cin>>a>>b>>c)
    {
        if(-1 == a && -1 == b && -1==c) break;
        for(int i = 0; i <= 20; i++)
        {
            for(int j =0; j <=20; j++)
            {
                w[0][i][j]=1;
                w[i][0][j]=1;
                w[i][j][0]=1;
            }
        }
        for(int i = 1; i <= 20; i++)
        {
            for(int j = 1; j <= 20; j++)
            {
                for(int k = 1; k <= 20; k++)
                {
                    if(i<j&&j<k)
                    {
                        w[i][j][k] = w[i][j][k-1] +w[i][j-1][k-1] -w[i][j-1][k];
                    }
                    else
                    {
                       w[i][j][k] = w[i-1][j][k]+ w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
                    }
           ///         cout <<"w("<<i<<","<<j<<","<<k<<")="<< w[i][j][k]<<" ";
                }
           ///     cout<<endl;
            }
          ///  cout<<endl;
        }
        if(a<=0||b<=0||c<=0)
        {
            s = 1;
        }
        else if(a>20 || b>20 ||c>20)
        {
            s = w[20][20][20];
        }
        else
        {
            s = w[a][b][c];
        }
 ///       int sum = 0;
 ///       sum = dp(a,b,c,s);
        printf("w(%d, %d, %d) = %d\n",a,b,c,s);
    }
    return 0;
}
