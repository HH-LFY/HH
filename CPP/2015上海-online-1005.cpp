#include <iostream>
#include <cstdio>
using namespace std;

int main( ){
    int x = 1;
    for(int i = 0;i < 12; ++i){
        x *= 2;
    }
    x-=8;
    x-=63;
    x=x*(27-8);
    cout<<x<<endl;
    return 0;
}
