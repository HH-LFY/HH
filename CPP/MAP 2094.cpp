#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx=2000+10;
char str1[maxx][50],str2[maxx][50];
int vis[maxx];
int n,k;

int main( )
{
    while(cin>>n&&n)
    {
        k=0;
        for(int i = 1;i <= n; i++)
        {
            scanf("%s%s*c",str1[i],str2[i]);
            vis[i]=1;
    ///       cout<<str1[i]<<" "<<str2[i]<<endl;
        }
        for(int i = 1;i <= n; i++)
        {
            int judge;
            if(vis[i]==1)
            {
                judge=1;
            for(int j = 1; j<=n; j++)
            {
                if(strcmp(str1[i],str2[j])==0)
                {
                    judge=0;
                }
                if(i!=j&&strcmp(str1[i],str1[j])==0)
                {
                    vis[j]=0;
                }
            }
            k+=judge;
            }
        }
        if(k==1)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
