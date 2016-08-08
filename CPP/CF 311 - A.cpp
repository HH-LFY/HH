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

int n;
int kmin[4];
int kmax[4];
int ans[4];

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i = 1;i < 4; ++i){
        scanf("%d%d",&kmin[i],&kmax[i]);
    }

    ans[1] = min(n - kmin[2] - kmin[3],kmax[1]);
    n -= ans[1];
    ans[2] = min(n - kmin[3],kmax[2]);
    n -= ans[2];
    ans[3] = n;

    for(int i = 1;i < 4; ++i){
        printf("%d\n",ans[i]);
    }
    return 0;
}
