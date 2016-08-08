#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxx 110
int t;// count
char c;// char
int len;// length.str
char str[maxx];
int vis[maxx];//biao ji

int dfs(int x, char *str)
{
    int k=0;
    char st[maxx];
    int sum=0;
    int judge=1;
    for(int i = 0;i < x; i++)
    {
        st[k++]=str[i];
    }
    st[k++]=c;

    for(int i=x ; i < len; i++)
    {
        st[k++]=str[i];
    }

    while(judge==1)
    {
        judge=0;
        memset(vis,0,sizeof(vis));
        for(int i = 0;i < k-1; i++)
        {
            while(i < k-1&&st[i]==st[i+1])
            {
                vis[i]=vis[i+1]=1;
                judge=1;
                i++;
            }
        }
        for(int i = 0;i < k; i++)
        {
            if(vis[i])
            {
                sum++;
            }
        }
        int j = 0;
        for(int i = 0;i < k; i++)
        {
            if(!vis[i])
            {
                st[j++]=st[i];
            }
        }
        k=j;
    }
    return sum;
}

int main( )
{
    cin>>t;
    while(t--)
    {
        cin>>str;
        len=strlen(str);
        int sum=0;
        for(int i = 0;i < len; i++)
        {
            for(c = 'A';c <= 'C'; c++)
            {
                sum=max(sum,dfs(i,str));
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
