#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx=5005;

struct
{
    int l,r;
    int sum;
}tree[maxx*4];

void build(int i,int l,int r)
{
    int mid=(l+r)/2;
    tree[i].l=l;
    tree[i].r=r;
    tree[i].sum=0;
    if(l==r) return ;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}

void update(int i,int k)
{
    if(tree[i].l==k&&tree[i].r==k)
    {
        tree[i].sum=1;
        return ;
    }
    int mid=(tree[i].l+tree[i].r)/2;
    if(k<=mid)
        update(i*2,k);
    else
        update(i*2+1,k);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
}

int getsum(int i,int k)
{
    if(k<=tree[i].l)
    {
        return tree[i].sum;
    }
    else
    {
        int mid=(tree[i].l+tree[i].r)/2;
        int sum1=0;
        int sum2=0;
        int sum3=0;
        if(k<=mid)
        {
            sum2=getsum(i*2,k);
            sum3=getsum(i*2+1,k);
        }
        else
        {
            sum1=getsum(i*2+1,k);
        }
        return sum1+sum2+sum3;
    }
}

int main( )
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[maxx];
        build(1,0,n);
        int ans=0;
        for(int i = 0;i < n; i++)
        {
            scanf("%d",&a[i]);
            ans+=getsum(1,a[i]+1);
            update(1,a[i]);
        }
        int sum=ans;
        int kmin=ans;
        for(int i = 0;i < n; i++)
        {
            sum=sum-2*a[i]+n-1;
            kmin=min(kmin,sum);
        }
        cout<<kmin<<endl;
    }
    return 0;
}
