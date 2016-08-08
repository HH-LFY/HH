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

const int maxx = 32000 + 10;
int c[maxx];
int n;

int lowbit(int x) ///求最低位
{
    return x&(-x);
}

void add(int k,int val) ///k表示被修改的点的下标，val表示被修改的值
{
    while(k <= maxx)
    {
        c[k] += val;
        k += lowbit(k);
    }
}

int query(int k) ///求区间 【1，k】的和
{
    int sum = 0;
    while(k>0)
    {
        sum += c[k];
        k -= lowbit(k);
    }
    return sum;
}

int main()
{
    return 0;
}
