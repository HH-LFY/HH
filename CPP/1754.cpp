#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxx 200010
int a[maxx];
int x,y;
int n,m;
int max;
char c;

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        getchar();
        for(int i=1;i<=m;i++)
        {
            scanf("%c %d %d",&c,&x,&y);
            getchar();
            max=0;
            if(x>y)
            {
                int t=x;
                x=y;
                y=t;
            }
            if(c=='Q')
            {
                for(int i=x;i<=y;i++)
                    if(max<a[i])
                    max=a[i];
                printf("%d\n",max);
            }
            else if(c=='U')
            {
                a[x]=y;
            }
        }
    }
    return 0;
}
