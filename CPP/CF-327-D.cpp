#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-10
using namespace std;

struct node{
    double x;
    double y;
    void operator = (node kk){
        x = kk.x;
        y = kk.y;
    }
}s,e;
double v, t;
double v1,v2;
double w1,w2;

double juli(node a,node b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int ok(double ans){
    double kans = ans;
    double anst;
    node ks = s;
    node ke = e;
    if(ans >= t){
        ke.x += t*v1;
        ke.y += t*v2;
        ans -= t;
        ke.x += ans*w1;
        ke.y += ans*w2;
        double L = juli(ks,ke);
        anst = L/v;
    }else{
       /// printf("2\n");
        ke.x += ans*v1;
        ke.y += ans*v2;
        double L=juli(ks,ke);
        anst = L/v;
       /// printf("%f %f\n",kans,anst);
    }
    if(fabs(kans-anst)<eps){
        return 0;
    }else if(kans>anst){
        return 1;
    }else {
        return -1;
    }
}

int main( ){
    cin>>s.x>>s.y;
    cin>>e.x>>e.y;
    cin>>v>>t;
    cin>>v1>>v2;
    cin>>w1>>w2;
    v1 = -v1,v2 = -v2, w1 = -w1, w2 = -w2;
    if(fabs(v1-0)<eps) v1 = 0.0;
    if(fabs(v2-0)<eps) v2 = 0.0;
    if(fabs(w1-0)<eps) w1 = 0.0;
    if(fabs(w2-0)<eps) w2 = 0.0;
    ///printf("%f %f %f %f \n",v1,v2,w1,w2);
    double l = 0;
    double r = 1e9;
    while(l <= r){
        double mid = (l+r)/2.0;
        int judge = ok(mid);
        //printf("%f %f\n",l,r);
        //getchar();
        if(judge == 1){
            r = mid;
        }else if(judge == -1){
            l = mid;
        }else if(judge == 0){
            printf("%.13f\n",mid);
            break;
        }
    }
    return 0;
}
