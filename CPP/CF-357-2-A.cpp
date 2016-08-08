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

int n;
string str;
int x, y;

int main( ){
    cin>>n;
    int judge = 0;
    while(n--){
        cin>>str>>x>>y;
        if(x>=2400 && y>x){
            judge = 1;
        }
    }
    if(judge){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}
