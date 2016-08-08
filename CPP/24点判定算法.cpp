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

bool dfs(int k,double a[]){
    if(k == 1 && fabs(a[0] - 24) < eps) return true;
    else{
        double b[5];
        for(int i = 0;i < k; ++i){

            for(int j = i + 1; j < k; ++j){
                int len = 0;
                for(int L = 0;L < k; ++L){
                    if(L != i && L != j){
                        b[len++] = a[L];
                    }
                }
                b[len] = a[i] + a[j];
                if(dfs(k - 1,b)) return true;

                b[len] = a[i] - a[j];
                if(dfs(k - 1,b)) return true;

                b[len] = a[j] - a[i];
                if(dfs(k - 1,b)) return true;

                b[len] = a[i] * a[j];
                if(dfs(k - 1,b)) return true;

                if(a[i]){
                    b[len] = a[j]/a[i];
                    if(dfs(k - 1,b)) return true;
                }
                if(a[j]){
                    b[len] = a[i]/a[j];
                    if(dfs(k - 1,b)) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    double a[5];
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]){
        if(dfs(4,a)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
