#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char str[10001][52],s[1000000];
bool vis[10001];

int main( )
{
    int t,m;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cin>>m;
        int sum=0;
        for(int i = 0;i < m; i++)
        {
            cin>>str[i];
        }
        cin>>s;
        for(int i = 0;i < m; i++)
        {
            if(0==vis[i])
            for(int j = i+1;j < m; j++)
            {
                if(strcmp(str[i],str[j])==0)
                {
                    vis[j]=1;
                }
            }
        }
        for(int i = 0;i < m; i++)
        {
            if(strstr(s,str[i])!=0&&vis[i]==0)
            {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

