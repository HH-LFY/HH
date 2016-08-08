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
#define eps 1e-8
const int  inf =  (1<<30) - 10;
using namespace std;

map<string,int> p;

int judge(int s,int e,int ret){
    int sum = 0;

    int dis = e - s;

    int ks = s%ret;
    int ke = e%ret;

    if(ks == 0 || ke < ks){
        sum = dis/ret + 1;
    }else{
        sum = dis/ret;
    }
    return sum;
}

int ycount(int s,int e){
    int sum = 0;
    sum = judge(s,e,4) - judge(s,e,100) + judge(s,e,400);
    return sum;
}

int main()
{
    p["January"] = 1;
    p["February"] = 2;
    p["March"] = 3;
    p["April"] = 4;
    p["May"] = 5;
    p["June"] = 6;
    p["July"] = 7;
    p["August"] = 8;
    p["September"] = 9;
    p["October"] = 10;
    p["November"] = 11;
    p["December"] = 12;
    string str1, str2;
    int T;
    int d1, d2;
    int m1, m2;
    int y1, y2;
    int kcount = 1;
    char x;
    cin>>T;
    while(T--){
        cin>>str1>>d1>>x>>y1;
        cin>>str2>>d2>>x>>y2;

        m1 = p[str1];
        m2 = p[str2];

        if(m1 > 2){
            y1++;
        }
        if(m2 == 2){
            if(d2 < 29){
                y2--;
            }
        }else if(m2 == 1){
            y2--;
        }
        ///cout<<y1<<" "<<y2<<endl;
        int flag = 0;
        if(y1 > y2){
            printf("Case #%d: %d\n",kcount++,flag);
        }else{
            printf("Case #%d: %d\n",kcount++,ycount(y1,y2));
        }
    }
    return 0;
}
