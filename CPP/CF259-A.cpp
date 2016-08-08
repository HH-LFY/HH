#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
using namespace std;

char str[110][110];

int main( )
{
    int n,k;
    int l,r,m,d;
    cin>>n;
    memset(str,0,sizeof(str));
    k=n/2+1;
    l=r=k;
    m=n;
    d=1;
    while(l!=0&&r!=n+1)
    {
        for(int i = d;i <= n-d+1; i++)
        {
            str[l][i]='D';
            str[r][i]='D';
        }
        l--;
        r++;
        d++;
    }
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(str[i][j]!='D')
            {
                cout<<'*';
            }
            else
            {
                cout<<str[i][j];
            }
        }
        cout<<endl;
    }
    return 0;
}
