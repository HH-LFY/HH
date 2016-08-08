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
    long long x1 , x2, y1, y2;
    long long m, a, b;
    long long h1, h2;
    long long vis1[2] = {0};
    long long vis2[2] = {0};
    long long p1 = 0;
    long long p2 = 0;


    cin>>m;
    cin>>h1>>a;
    cin>>x1>>y1;
    for(long long i = 1;i <= m*2; ++i){
        h1 = ((x1*h1)%m + y1)%m;
        if(h1 == a){
            vis1[p1++] = i;
            if(p1 == 2) break;
        }
    }

    cin>>h2>>b;
    cin>>x2>>y2;
    for(long long i = 1;i <= m*2; ++i){
        h2 = ((x2*h2)%m + y2)%m;
        if(h2 == b){
            vis2[p2++] = i;
            if(p2 == 2) break;
        }
    }


    if(p1 == 0 || p2 == 0){
        cout<<"-1"<<endl;

        return 0;
    }

    int judge = 0;
    long long ans = -1;
    long long sum = vis1[0];
    long long T1 = vis1[1] - vis1[0];
    long long T2 = vis2[1] - vis2[0];
    for(long long i = 0;i < T2; ++i){
        if(sum >= vis2[0] && sum%T2 == vis2[0]%T2){
            judge = 1;
            ans = sum;
            break;
        }
        sum += T1;
    }
    sum = vis2[0];
    for(long long i = 0;i < T1; ++i){
        if(sum >= vis1[0] && sum%T1 == vis1[0]%T1){
            if(judge)ans = min(ans,sum);
            else ans = sum;
            break;
        }
        sum += T2;
    }
    if(judge != inf) cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;
}
