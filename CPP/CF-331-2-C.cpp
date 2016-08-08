#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int x,y;
    int kmin;
    int id;
    bool operator<(const node a)const{
        if(kmin == a.kmin) {
            if(x == a.x) return y>a.y;
            return x>a.x;
        }
        return kmin>a.kmin;
    }
};
const int  maxx = 4*100010;
int n;
int ans[maxx];
int w[maxx];
node pi[maxx];
priority_queue<node> t[maxx*2];


int main( ){
    cin>>n;
    for(int i = 0;i < n; ++i){
        scanf("%d%d",&pi[i].x,&pi[i].y);
        pi[i].id = i;
        pi[i].kmin=min(pi[i].x,pi[i].y);
        int pw = pi[i].y - pi[i].x + maxx;
        t[pw].push(pi[i]);
    }
    for(int i = 0;i < n; ++i){
        scanf("%d",&w[i]);
    }
    int flag = 1;
    if(t[w[0]+maxx].empty()){
        printf("NO\n");
        return 0;
    }
    int j = w[0]+maxx;
    int now_x = t[j].top().x;
    int now_y = t[j].top().y;
    ans[0] = t[j].top().id;
    t[j].pop();
    for(int i = 1;i < n; ++i){

        j = w[i]+ maxx;
        if(t[j].empty()) break;
        int temp_x = t[j].top().x;
        int temp_y = t[j].top().y;
        if(temp_x>=now_x ||
           temp_y>=now_y ||
           (temp_x == now_x && temp_y >= now_y)||
           (temp_x >= now_x && temp_y == now_y)){
            now_x = max(temp_x,now_x);
            now_y = max(temp_y,now_y);
            ans[flag++] = t[j].top().id;
            ///printf("%d %d %d %d\n",temp_x,temp_y,now_x,now_y);
            //cout<<"x:"<<temp_x<<t[j].top().id<<endl;
            ///cout<<j<<endl;
            t[j].pop();
        }else{
            break;
        }
    }
    if(flag == n){
        printf("YES\n");
        for(int i = 0;i < n; ++i){
            printf("%d %d\n",pi[ans[i]].x,pi[ans[i]].y);
        }
    }else{
        printf("NO\n");
    }
    return 0;
}
