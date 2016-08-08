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

int N;
long long a;

int main( ){
    cin>>N;
    long long sum = 0;
    for(int i = 0;i < N; ++i){
        cin>>a;
        sum = sum|a;
    }
    long long sum1 = 0;
    for(int i = 0;i < N; ++i){
        cin>>a;
        sum1 = sum1|a;
    }
    cout<<sum1+sum<<endl;
    return 0;
}
