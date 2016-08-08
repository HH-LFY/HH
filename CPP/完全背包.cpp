#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxx=100000+100;
int n,m;
int a[maxx];

struct kk
{
    int w,v;
    double vw;
}k[maxx];

int cmp(kk a,kk b)
{
    return a.vw>b.vw;
}

int main( )
{
    cin>>n>>m;
    int i,j;
    memset(a,0,sizeof(a));
    for(i = 0;i < n;i++)
    {
        scanf("%d%d",&k[i].w,&k[i].v);
        k[i].vw=(double)(k[i].v/k[i].w);
    }
    sort(k,k+n,cmp);
    for(i = 0;i < n;i++)
    {
        for()
    }
    return 0;
}
