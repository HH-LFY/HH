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

const int maxx = 1e5 + 100;
int n;
int num[maxx];

int main( ){
    cin>>n;
    for(int i = 0;i < n; ++i){
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    int now = 1;
    for(int i = 0;i < n; ++i){
        if(num[i]>=now){
            now++;
        }
    }
    cout<<now<<endl;
    return 0;
}
