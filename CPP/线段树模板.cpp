#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

struct
{
    int l;
    int r;
    int sum;
}t[140000];
int a[50010],sum;
int T;
char c[10];

void build(int l,int r,int num)
{
    t[num].l = l;
    t[num].r = r;
    if(l == r) t[num].sum = a[l];
    else
    {
        int mid = (l + r)/2;
        build(l, mid , 2*num );
        build(mid + 1,r,2*num + 1);
        t[num].sum = t[2*num].sum+t[2*num+1].sum;
    }
}

void query(int l,int r,int num)
{
    if(l <= t[num].l && r>=t[num].r)
        sum += t[num].sum;
    else
    {
        int mid = (t[num].l + t[num].r)/2;
        if(l > mid) query(l,r,num*2 + 1);
        else if(r <= mid) query(l,r,num*2);
        else
        {
            query(l,r,num*2);
            query(l,r,num*2+1);
        }
    }
}

void update(int x,int y,int num)
{
    t[num].sum += y;
    if(t[num].l == x && x == t[num].r) return ;
    if(x > (t[num].l + t[num].r)/2) update(x,y,num*2 + 1);
    else update(x,y,num*2);
}

int main()
{
    cin>>T;
    int count = 1;
    while(T--)
    {
        int n;
        int x, y;
        cin>>n;
        a[0] = 0;
        for(int i = 1;i <= n; ++i)
            scanf("%d",&a[i]);
        build(1,n,1);
        printf("Case %d:\n",count++);
        while(scanf("%s",c))
        {
            if(c[0] == 'E') break;
            else if(c[0] == 'Q')
            {
                cin>>x>>y;
                sum = 0;
                query(x,y,1);
                cout<<sum<<endl;
            }
            else if(c[0] == 'A')
            {
                cin>>x>>y;
                update(x,y,1);
            }
            else if(c[0] == 'S')
            {
                cin>>x>>y;
                update(x,-y,1);
            }
        }
    }
    return 0;
}
