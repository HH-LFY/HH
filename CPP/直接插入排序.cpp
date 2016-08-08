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

void show(int n)
{
    int i;
    for(i = 1; i <= n; ++i)
    {
        printf("%d ",bb[i]);
    }
    printf("\n");
}

void insertsort(int a[],int k, int x)
{
    int i, j;
    a[0] = x; /// 设置哨兵
    for(i = k;i > 0; --i)
    {
        ///如果要进行降序排序则代码如下
        /**
        if( x > a[i - 1])
        {
            a[i] = a[i - 1];
        }
        */
        if(x > a[i - 1]) ///和当前指向的位置的下一个位置进行比较
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

void insort(int a[],int n,int b[])
{
    int i, j;
    for(i = 0;i < n; ++i)
        insertsort(b,i + 1,a[i]);
}

int main( )
{
   // freopen("in.txt","r",stdin);
    int i, j;
    while(cin>>n)
    {
        for(i = 0; i < n; ++i)
        {
            scanf("%d",&aa[i]);
        }
        insort(aa,n,bb);
        show(n);
    }
    return 0;
}
