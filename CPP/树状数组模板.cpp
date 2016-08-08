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

int lowbit(int x) ///�����λ
{
    return x&(-x);
}

void add(int k,int val) ///k��ʾ���޸ĵĵ���±꣬val��ʾ���޸ĵ�ֵ
{
    while(k <= maxx)
    {
        c[k] += val;
        k += lowbit(k);
    }
}

int query(int k) ///������ ��1��k���ĺ�
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
