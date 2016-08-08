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

int main( ){
    int a1,  a2;
    cin>>a1>>a2;
    int i;
    for(i = 0;i < 1000;++i){
        if(a1==0 || a2 == 0){
            break;
        }
        if(a1>a2){
            a1-=2;
            a2+=1;
            //if(a2>=100)a2=100;
        }else{
            a1+=1;
            //if(a1>=100)a1=100;
            a2-=2;
        }
        if(a1<0 || a2<0){
            break;
        }
    }
    cout<<i<<endl;
    return 0;
}
