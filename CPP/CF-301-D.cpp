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

const int maxx = 100 + 10;
double dp[maxx][maxx][maxx];
int r, s, p;

void input(){
    cin>>r>>s>>p;
}

double solved(int x,int y,int z){
    if(dp[x][y][z] >= 0) return dp[x][y][z];
    if(x == 0) return 0;
    if(z == 0) return 1;
    double sum = 0;
    double temp = x*y + y*z + z*x;
    if(x && y) sum += solved(x,y-1,z)*(x*y)/(temp*1.0);
    if(z && y) sum += solved(x,y,z-1)*(z*y)/(temp*1.0);
    if(x && z) sum += solved(x-1,y,z)*(x*z)/(temp*1.0);
    dp[x][y][z] = sum;
    return sum;
}

void output(){
    memset((dp),-1,sizeof(dp));
    printf("%.9f\n",solved(r,s,p));
    printf("%.9f\n",solved(s,p,r));
    printf("%.9f\n",solved(p,r,s));
}

int main(){
    //freopen("input.txt","r",stdin);
    input();
    output();
    return 0;
}
