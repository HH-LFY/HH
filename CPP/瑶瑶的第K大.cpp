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
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 5000000 + 10;
int n, k;
int a[maxx];

inline int get_int( )
{
    int result=0;
    char c;
    while((c=getchar( ))!=' '&&c!='\n')
        result = result*10 + c - '0';
    return result;
}

inline void out(int x)
{
    if(x>10)
    {
        out(x/10);
    }
    putchar(x % 10 + '0');
}

int part(int a[],int l,int r)
{
    int temp = a[l];
    while(l < r)
    {
        while(l < r && a[r] > temp) r--;
        if(l < r) swap(a[l++] , a[r]);
        while(l < r && a[l] < temp) l++;
        if(l < r) swap(a[r--] , a[l]);
    }
    a[l] = temp;
    return l;
}

inline int qsort(int a[],int l,int r,int k)
{
    if(l < r)
    {
        int mid = part(a,l,r);
        if(mid == k) return a[mid];
        else if(mid < k) return qsort(a,mid + 1,r,k);
        else return qsort(a,l,mid - 1,k);
    }
    return a[l];
}

int main()
{

    while(cin>>n>>k)
    {
        getchar();
        for(int i = 0;i < n; ++i)
            a[i] = get_int();
        int ans = qsort(a,0,n-1,n-k);
        out(ans);
        puts("");
    }
    return 0;
}
