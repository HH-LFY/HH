#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main( ){
    int T;
    int N;
    cin>>T;
    while(T--){
        scanf("%d",&N);
        printf("%d\n",N%2);
    }
    return 0;
}
