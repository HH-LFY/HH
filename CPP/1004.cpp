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

int main(){
    //freopen("input.txt","r",stdin);
    int T;
    int count = 1;
    cin>>T;
    while(T--){
        int n;
        double a, r;
        scanf("%d%lf%lf",&n,&a,&r);
        double du = (n - 2)*180/(2*n);
        du = 2*PI*du/360;
        int judge = 0;
        a= a/2.0;
        if((r/a) <= tan(du)){
            judge = 1;
        }
        printf("Case #%d:\n",count++);
        if(judge){
            printf("Give me a kiss!\n");
        }else{
            printf("I want to kiss you!\n");
        }
    }
    return 0;
}
