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

int n, k;
int a[1000000 + 10];

int main()
{
    cin>>n>>k;
    for(int i = 0;i < n; ++i)
    {
        scanf("%d",a + i);
    }
    sort(a,a+n);
    int judge = -1;
    int l = 0;
    int r = n - 1;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(a[mid] == k)
        {
            judge = mid;
            break;
        }
        else if(a[mid] > k)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    if(judge != -1)
    {
        cout<<judge+1<<endl;
    }
    else
    {
        cout<<judge<<endl;
    }
    return 0;
}
