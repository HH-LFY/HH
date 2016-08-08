#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <sstream>
#define PI acos(-1.0)
#define exp 1e-8
const int  inf =  (1<<30) - 10;
using namespace std;

struct Point{
    double x;
    double y;
}edge[200][2], l[400];
int n;

Point setvalue(Point a){
    return a;
}

double mult(Point a,Point b,Point c){
    return (a.x - c.x)*(b.y - c.y) - (b.x - c.x)*(a.y - c.y);
}

int judge(Point a, Point b, Point c,Point d){

    if(mult(c,b,a)*mult(b,d,a)<0){
        return 0;
    }
    return 1;
}

int solved1(Point s){
    int flag = 1;
    for(int i = 0;i < n; ++i){
        if(edge[i][0].x <= s.x && edge[i][1].x>=s.x){
            continue;
        }else{
            flag = 0;
            break;
        }
    }
    if(flag) return 1;

    flag = 1;
    for(int i = 0;i < n; ++i){
        if(edge[i][0].y <= s.y && edge[i][1].y >= s.y){
            continue;
        }else{
            flag = 0;
            break;
        }
    }
    return flag;
}

double ok(Point a,Point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int solved2(Point s,Point e){

    if(ok(s,e) < exp){
        return 0;
    }

    int flag = 1;
    for(int i = 0;i < n; ++i){
        if(judge(s,e,edge[i][0],edge[i][1])){
            continue;
        }else{
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int p = 0;
        scanf("%d",&n);
        for(int i = 0;i < n; ++i){
            scanf("%lf%lf%lf%lf",&edge[i][0].x,&edge[i][0].y,&edge[i][1].x,&edge[i][1].y);
            l[p++] = setvalue(edge[i][0]);
            l[p++] = setvalue(edge[i][1]);
        }
        /*
        for(int i = 0;i < p; ++i){
            printf("%f %f\n",l[i].x,l[i].y);
        }
        */
        int flag;
        for(int i = 0;i < p; ++i){
            flag = 1;
            for(int j = i; j < p; ++j){
                if(i == j){
                    flag = solved1(l[i]);
                }else{
                    flag = solved2(l[i],l[j]);
                }
                if(flag){
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            cout<<"Yes!"<<endl;
        }else{
            cout<<"No!"<<endl;
        }
    }
    return 0;
}
