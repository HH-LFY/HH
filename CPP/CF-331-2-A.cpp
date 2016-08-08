#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int x, y;
int x1,x2,y1,y2;

int abs(int a){
    return a>0?a:-a;
}

int main( ){
    cin>>n;
    int inf = 99999999;
    x1 = inf;
    x2 = -inf;
    y1 = inf;
    y2 = -inf;
    for(int i = 0;i < n; ++i){
        cin>>x>>y;
        x1 = min(x,x1);
        y2 = max(y,y2);
        x2 = max(x,x2);
        y1 = min(y,y1);
    }
    if(x1 == x2 || y1 == y2){
        cout<<-1<<endl;
    }else{
        cout<<abs((y2-y1)*(x2-x1))<<endl;
    }
    return 0;
}
/**

*/
