#include <iostream>
#include <cstdio>
using namespace std;

int t;
int n;

int main( )
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int result = 0;
        for(int i = 0;i <=70 ; i++)
        {
            for(int j = 0;j <= 60 ; j++)
            {
                int minn = i * 150 + j * 200;
                if(minn<=n&&minn>result)
                {
                    result = minn;
                }
            }
        }
        cout<<n-result<<endl;
    }
    return 0;
}
