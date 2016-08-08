/********************
***Ê÷×´Êý×éÄ£°æ*****
*********************/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx=50001;
int n,a[maxx];
char c[10];

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int y)
{
    while(x<=n)
    {
        a[x]+=y;
        x+=lowbit(x);
    }
}

int sum(int x)
{
    int ss=0;
    while(x>0)
    {
        ss+=a[x];
        x-=lowbit(x);
    }
    return ss;
}

int main( )
{
    int t,count=1;
    cin>>t;
    while(t--)
    {
        int x,y;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i = 1;i <= n; i++)
        {
            scanf("%d",&x);
            update(i,x);
        }
        printf("Case %d:\n", count++);
        while(scanf("%s",c))
        {
            if(c[0]=='E')break;
            scanf("%d%d",&x,&y);
            if(c[0]=='Q')
            {
                cout<<sum(y)-sum(x-1)<<endl;
            }
            else if(c[0]=='A') update(x,y);
            else if(c[0]=='S') update(x,-y);
        }
    }
    return 0;
}
