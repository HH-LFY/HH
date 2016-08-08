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

const int maxx = 200010;
struct node{
    int x;
    int y;
}a[maxx];
map<int,int> p;
int n;

int cmd1(node t1,node t2){
    return t1.x<t2.x;
}

int cmd2(node t1,node t2){
    if(t1.y == t2.y) return t1.x<t2.x;
    return t1.y<t2.y;
}

void show(){
    for(int i = 0;i < n; ++i)
        cout<<a[i].x<<" "<<a[i].y<<endl;
}

int main( ){
    cin>>n;
    for(int i = 0;i < n; ++i){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    long long ans = 0;
    sort(a,a+n,cmd1);
    for(int i = 0;i < n; ++i){
        int now = i;
        long long sum = 0;
        for(int j = i;; ++j){
            if(j == n){
                i = j;
                break;
            }
            if(a[i].x == a[j].x){
                sum++;
            }else{
                i = j;
                break;
            }
        }
        //cout<<sum<<endl;
        if(now != i && i < n) i--;
        if(sum > 1){
            ans = ans + (sum-1)*sum/2;
        }
    }
    //cout<<ans<<endl<<"2:"<<endl;
    sort(a,a+n,cmd2);
    ///show();
    for(int i = 0;i < n; ++i){
        int now = i;
        long long sum = 0;
        for(int j = i;; ++j){
            //cout<<"i= "<<i<<" "<<a[i].y<<" "<<a[j].y<<endl;
            if(j == n){
                i = j;
                break;
            }
            if(a[j].y == a[i].y){
                sum++;
            }else{
                i = j;
                break;
            }
        }
        if(now != i &&i < n) i--;
        //cout<<sum<<endl;
        if(sum > 1){
            ans = ans + (sum-1)*sum/2;
        }
    }
    //cout<<ans<<endl;
    for(int i = 0;i < n; ++i){
        int now = i;
        long long sum = 0;
        for(int j = i;; ++j){
            if(j == n){
                i = j;
                break;
            }
            if(a[i].y == a[j].y && a[i].x == a[j].x){
                //cout<<a[i].x<<" "<<a[i].y<<endl;
                sum++;
            }else{
                i = j;
                break;
            }
        }
        if(now != i &&i < n) i--;
        if(sum > 1){
            ans = ans - (sum-1)*sum/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
