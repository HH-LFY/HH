#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx = 200000+100;
int h,w,n;
int a[maxx];

int main( )
{
    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        int i,j;
        if(h>maxx) h=maxx-99;
        for(i = 1;i <= h; i++)
        {
            a[i] = w;
        }
        int x;
        int judge;
        while(n--)
        {
            judge = 0;
            scanf("%d",&x);
            for(i = 1;i <= h; i++)
            {
                if((a[i]-x)>=0)
                {
                    a[i]=a[i]-x;
                    printf("%d\n",i);
                    judge = 1;
                    break;
                }
            }
            if(judge==0)
                printf("-1\n");
        }
    }
    return 0;
}
