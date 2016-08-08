#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 1e5 + 10;
int a[2][maxx];
int b[maxx];
int t;
int n;

void show(int judge)
{
    int kis[2][maxx];
    int k0 = 0;
    int k1 = 0;
    if(judge == 1||judge == 2)
    {
        int temp = judge - 1;
        for(int i = 1;i <= n;++i)
        {
            if(a[temp][i])
            {
                kis[0][k0++] = i;
            }
            else
            {
                kis[1][k1++] = i;
            }
        }
    }
    else
    {
        for(int i = 1;i <= n; ++i)
        {
            if(a[0][i]&&a[1][i])
            {
                kis[0][k0++] = i;
            }
            else if(!a[0][i]&&!a[1][i])
            {
                kis[1][k1++] = i;
            }
        }
    }
    cout<<k0;
    for(int i = 0;i < k0; ++i)
    {
        printf(" %d",kis[0][i]);
    }
    cout<<endl;

    cout<<k1;
    for(int i = 0;i < k1; ++i)
    {
        printf(" %d",kis[1][i]);
    }
    cout<<endl;
}

int main()
{
    cin>>t;
    while(t--)
    {

        cin>>n;

        for(int i = 0;i <= n + 1; ++i)
        {
            a[0][i] = a[1][i] = 0;
        }

        for(int i = 1;i <= n; ++i)
        {
            scanf("%d",&b[i]);
        }
        int judge = 0;
        for(int k = 0;k <= 1; ++k)
        {
            if(k)
            {
                a[k][1] = k;
                a[k][2] = b[1] - k;
                if(a[k][2] >= 2 || a[k][2] < 0)
                {
                    continue;
                }
            }
            else
            {
                a[k][1] = k;
                a[k][2] = b[1] - k;
                if(a[k][2] >= 2 || a[k][2] < 0)
                {
                    continue;
                }
            }
            int j;
            for(j = 3;j <= n + 1; ++j)
            {
                a[k][j] = b[j - 1] - a[k][j - 2] - a[k][j - 1];
                if(a[k][j] >= 2 || a[k][j] < 0)
                {
                    break;
                }
            }
            /**
            for(int i = 0;i <= n+1; ++i) printf("%d ",a[k][i]);
            cout<<endl;
            */
            if(j <= n || a[k][n+1])
            {
                continue;
            }
            else
            {
                if(judge == 0)
                {
                    judge = k + 1;
                }
                else if(judge == 1)
                {
                    judge = 3;
                }
            }
        }
        show(judge);
    }
    return 0;
}
