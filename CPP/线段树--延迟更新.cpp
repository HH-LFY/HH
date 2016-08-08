#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxx=100000+10;
int a[maxx];
int n,p;

struct
{
    int l,r;
    __int64 sum;
    __int64 ever;
} tree[maxx*4];

void build(int i,int l,int r)
{
    tree[i].l=l;
    tree[i].r=r;
    tree[i].ever=0;
    if(l==r)
    {
        tree[i].sum=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
}

__int64 query(int i,int a,int b)
{
    if(tree[i].l==a&&tree[i].r==b)
    {
        return tree[i].sum+(__int64)tree[i].ever*(b-a+1);
    }
    if(tree[i].ever!=0)
    {
        tree[i*2].ever+=tree[i].ever;
        tree[i*2+1].ever+=tree[i].ever;
        tree[i].sum+=(__int64)(tree[i].r-tree[i].l+1)*tree[i].ever;
        tree[i].ever=0;
    }
    int mid=(tree[i].l+tree[i].r)/2;
    if(b<=mid)
    {
        return query(i*2,a,b);
    }
    else if(a>mid)
    {
        return query(i*2+1,a,b);
    }
    else
    {
        return query(i*2,a,mid)+query(i*2+1,mid+1,b);
    }
}

void update(int i,int a,int b,int c)
{
    if(tree[i].l==a&&tree[i].r==b)
    {
        tree[i].ever+=c;
        return ;
    }
    int mid=(tree[i].l+tree[i].r)/2;
    tree[i].sum+=(__int64)c*(b-a+1);
    if(b<=mid)
    {
        update(i*2,a,b,c);
    }
    else if(a>mid)
    {
        update(i*2+1,a,b,c);
    }
    else
    {
        update(i*2,a,mid,c);
        update(i*2+1,mid+1,b,c);
    }
}

int main( )
{
    while(scanf("%d%d",&n,&p)!=EOF)
    {
        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        char str[10];
        while(p--)
        {
            int K,b,c;
            getchar( );
            scanf("%s",str);
            if(str[0]=='Q')
            {
                scanf("%d%d",&K,&b);
                printf("%I64d\n",query(1,K,b));
            }
            else if(str[0]=='C')
            {
                scanf("%d%d%d",&K,&b,&c);
                update(1,K,b,c);
            }
        }
    }
    return 0;
}
