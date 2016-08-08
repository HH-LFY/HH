#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxx=1000+10;
int vis[26];
int c[26];
char str[maxx];
int k;

int main( )
{
    cin>>k;
    scanf("%s",str);
    int l=strlen(str);
    memset(c,0,sizeof(c));
    for(int i = 0;i < l; i++)
    {
        int p=str[i]-'a';
        vis[p]=1;
        c[p]++;
    }
    int judge=1;
    for(int i = 0;i < 26;i++)
    {
        if(vis[i]==1&&c[i]%k!=0)
        {
            judge=0;
            break;
        }
    }
    if(judge==1)
    {
        sort(str,str+l);
        for(int i = 0;i < k; i++)
        {
            for(int j = 0; j < l; j=j+k)
            {
                cout<<str[j];
            }
        }
        cout<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}
