#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <vector>
using namespace std;

priority_queue<int> pp;
int N;
long long Q;
int P[100010];

bool check(int mid){
    long long ans = 0;
    for(int i = 0;i < mid ; ++i){
        pp.push(P[i]);
    }
    long long kcount = 1;
    for(int i = mid;i < N; ++i){
        ans += (long long)(kcount*pp.top());
        kcount++;
        //cout<<pp.top()<<endl;
        pp.pop();
        pp.push(P[i]);
    }
    while(!pp.empty()){
        ans += (long long)(kcount*pp.top());
        kcount++;
       // cout<<pp.top()<<endl;
        pp.pop();
    }
    //cout<<"mid ="<<mid<<" ";
    //cout<<ans<<endl;
    if(ans<=Q) return true;
    return false;
}

int main( ){
    cin>>N>>Q;
    for(int i = 0;i < N; ++i){
        scanf("%d",&P[i]);
    }
    int l = 1;
    int r = N;
    int kans = 100000+10;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid-1;
            kans = min(kans,mid);
        }else{
            l = mid+1;
        }
    }
    if(!check(kans)){
        printf("-1\n");
    }else{
        printf("%d\n",kans);
    }
    return 0;
}
