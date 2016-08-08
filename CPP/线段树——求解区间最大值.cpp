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

const int maxx = 2000000 + 10;
struct
{
    int l;
    int r;
    int mid;
    int kmax;
}a[maxx * 3];
int score[maxx];
int n, m;
int kmax;

int build(int l,int r,int num)
{
    a[num].l = l;
    a[num].r = r;
    a[num].mid = (l + r)/2;
    if(l == r) return a[num].kmax = score[l];
    int k1 = build(l,a[num].mid,num*2);
    int k2 = build(a[num].mid + 1, r,2*num + 1);
    return a[num].kmax = max(k1,k2);
}

void update(int x,int y,int num)
{
    if(a[num].l == x && x == a[num].r)
    {
        a[num].kmax = y;
        return ;
    }
    if(x <= a[num].mid)
    {
        update(x,y,2*num);
    }
    else
    {
        update(x,y,2*num + 1);
    }
    a[num].kmax = max(a[num*2].kmax,a[num*2 + 1].kmax);
}

void query(int x,int y,int num)
{
    if(a[num].l >= x && a[num].r <= y)
    {
        kmax = max(a[num].kmax , kmax);
        return ;
    }
    if(x>a[num].mid)
    {
        query(x,y,num*2 + 1);
    }
    else if( y <= a[num].mid)
    {
        query(x,y,num*2);
    }
    else
    {
        query(x,y,num*2);
        query(x,y,num*2 + 1);
    }
}

int main()
{
    while(cin>>n>>m)
    {
        for(int i = 1;i <= n; ++i)
        {
            scanf("%d",&score[i]);
        }
        build(1,n,1); ///build tree
        cout<<"build tree is accept!"<<endl;
        for(int i = 1;i <= m; ++i)
        {
            char str[5];
            int  x, y;
            scanf("%s%d%d",str,&x,&y);
            if(str[0] == 'Q')
            {
                kmax = -inf;
                query(x,y,1); ///search max value
                printf("%d\n",kmax);
            }
            else if(str[0] == 'U')
            {
                update(x,y,1); ///update the max num
            }
        }
    }
    return 0;
}
