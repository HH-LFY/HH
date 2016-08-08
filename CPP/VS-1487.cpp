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

int a[11];
int n, x;

int main()
{
    while(cin>>n){
        for(int i = 0;i < n; ++i){
            scanf("%d",&x);
            a[x]++;
        }
        for(int i = 0;i < 11; ++i){
            while(a[i]--){
                printf("%d\n",i);
            }
        }
    }
    return 0;
}
