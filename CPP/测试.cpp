#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI 3.141592653
using namespace std;

const int maxx = 3000 + 10;
int aa[maxx]; ///待排序数组
int bb[1000 + 10]; ///储存答案的数组
int n, m;
void insertsort(int a[],int k, int x)
{
    int i, j;
    if(k > m) k = m;
    a[0] = x;
    for(i = k + 1;i > 0; --i)
    {
        if(x > a[i - 1])
        {
            a[i] = a[i - 1];
        }
        else
        {
            a[i] = x;
            break;
        }
    }
}

/*
void insort(int a[],int n,int b[])
{
    int i, j;
    for(i = 0;i < n; ++i)
        insertsort(b,i + 1,a[i]);
}
*/

void show( )
{
    int i;
    for(i = 1; i < m; ++i)
    {
        printf("%d ",bb[i]);
    }
    if( m )printf("%d\n",bb[m]);
}

int main( )
{
   // freopen("in.txt","r",stdin);
    int i, j;
    while(cin>>n>>m)
    {
        for(i = 0; i <= m+1; ++i)
            bb[i] = 0;
        int k = 1;
        for(i = 0; i < n; ++i)
        {
            scanf("%d",&aa[i]);
        }
        sort(aa,aa + n);
        for(i = n-1; i > 0; --i)
        {
            for(j = i - 1; j >= 0; --j)
            {
                insertsort(bb,k++,aa[i] + aa[j]);
            }
        }
        show();
    }
    return 0;
}
