#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf=99999999;
const int maxx=50000+5;
int num[maxx];
int kmaxx;
int kminn;
int n,p;

struct
{
    int l,r;
    int kmin;
    int kmax;
}tree[4*maxx];

void build(int i,int l,int r)
{
    tree[i].l=l;
    tree[i].r=r;
    if(l==r)
    {
        tree[i].kmin=tree[i].kmax=num[l];
        return ;
    }
    int mid=(l+r)/2;

    build(i*2,l,mid);
    build(i*2+1,mid+1,r);

    int a1=tree[i*2].kmax;
    int a2=tree[i*2+1].kmax;
    int b1=tree[i*2].kmin;
    int b2=tree[i*2+1].kmin;
    tree[i].kmax=max(a1,a2);
    tree[i].kmin=min(b1,b2);
}

void query(int i,int a,int b)
{
    if(a>tree[i].r||b<tree[i].l)
        return ;
    if(a<=tree[i].l&&tree[i].r<=b)
    {
        kmaxx=max(kmaxx,tree[i].kmax);
        kminn=min(kminn,tree[i].kmin);
        return ;
    }
    int mid=(tree[i].l+tree[i].r)/2;
    if(a>mid)
    {
        query(i*2+1,a,b);
    }
    else if(b<=mid)
    {
        query(i*2,a,b);
    }
    else
    {
        query(i*2,a,b);
        query(i*2+1,a,b);
    }
}

int main( )
{
    scanf("%d%d",&n,&p);
    for(int i = 1;i <= n; i++)
    {
        scanf("%d",&num[i]);
    }
    build(1,1,n);
    int a,b;
    while(p--)
    {
        kmaxx=-inf;
        kminn=inf;
        scanf("%d%d",&a,&b);
        if(a!=b)
        {
            query(1,a,b);
            cout<<kmaxx-kminn<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }
    return 0;
}
