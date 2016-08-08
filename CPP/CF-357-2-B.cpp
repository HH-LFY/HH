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

long long h = 1234567;
long long c1 = 123456;
long long c2 = 1234;
long long n;

int main( ){
    cin>>n;
    int judge = 0;
    for(long long i = 0;;++i){
        long long temp = n;
        if(temp<0) break;
        for(long long j = 0;;++j){
            long long ntemp = temp;
            ntemp -= j*c1;
            if(ntemp<0) break;
            if(ntemp == 0 || ntemp%c2 == 0){
                judge = 1;
                //cout<<i<<" "<<j<<" "<<temp/c2<<endl;
                break;
            }
        }
        if(judge){
            break;
        }
        n-=h;
    }
    if(judge){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
