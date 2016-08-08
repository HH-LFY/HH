#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxx=1000+10;
int t;
char vis[maxx];
int a,b;
char str[10];

int main( )
{
    cin>>t;
    while(t--)
    {
        memset(vis,'A'-1,sizeof(vis));
        int n;
        cin>>n;
        while(n--)
        {
            scanf("%s%d%d",str,&a,&b);
            for(int i = a;i < b; i++)
            {
                vis[i]++;
            }
        }
        for(int i = 0;i<=1000;i++)
        {
            if(vis[i]>='A')
            {
                printf("%c",vis[i]);
            }
        }
        cout<<endl;
    }
    return 0;
}
