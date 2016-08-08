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
#define eps 1e-8
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 1e6 + 10;
int a[maxx*5];
int n, k;

inline int get_int( )//读入优化
{
    int result=0;
    char c;
    while((c=getchar( ))!=' '&&c!='\n')
        result = result*10 + c - '0';
    return result;
}
int part(int a[],int l,int r) ///a：数组 l:左边界 r：有边界 k：
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
inline int qsort(int a[],int l,int r,int k)///a：数组 l:左边界 r：有边界 k：第k小 （若要求第k大，则用n-k）
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

int main(){
    //freopen("input.txt","r",stdin);
    while(cin>>n>>k){
        getchar();
        for(int i = 1;i <= n; ++i){
            a[i] = get_int();
        }
        printf("%d\n",qsort(a,1,n,n+1-k));
    }
    return 0;
}
