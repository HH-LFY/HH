#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx = 200000+100;
int h,w,n;

int max(int x,int y)
{
    return x>y?x:y;
}

struct
{
    int l;
    int r;
    int mid;
    int kmax;
}tree[maxx*4];

void build(int i,int l,int r)
{
    tree[i].l=l;
    tree[i].r=r;
    tree[i].mid=(l+r)>>1;
    tree[i].kmax=w;

    if(l==r) return ;

    build(i*2,l,tree[i].mid);
    build(i*2+1,tree[i].mid+1,r);
}

int query(int i,int x)
{
    if(tree[i].kmax < x) return -1;
    if(tree[i].l==tree[i].r)
    {
        tree[i].kmax -= x;
        return tree[i].l;
    }

    int t=query(i*2,x);

    if(t==-1) t=query(i*2+1,x);
    if(t!=-1)  tree[i].kmax= max(tree[i*2].kmax,tree[i*2+1].kmax);

    return t;
}

int main( )
{
    while(scanf("%d%d%d",&h,&w,&n)!=EOF)
    {
        if(h>200000) h=200000;
        build(1,1,h);
        int i,j;
        while(n--)
        {
            scanf("%d",&j);
            i=query(1,j);
            printf("%d\n",i);
        }
    }
    return 0;
}
