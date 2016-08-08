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

struct cmp1 {
    bool operator ()(int &a,int &b) {
        return a>b;//最小值优先
    }
};
const int inf = 1e9;
char ins[] = "insert";
char ge[] = "getMin";
char rem[]= "removeMin";
int n;
int kis[1000100][2];
priority_queue<int,vector<int>,cmp1> p;

int main( ) {
    int len = 0;
    cin>>n;
    char str[20];
    int x;
    while(n--) {
        scanf("%s",str);
        //cout<<str<<endl;
        if(str[0] == 'i') {
            scanf("%d",&x);
            kis[len][0] = 1;
            kis[len++][1] = x;
            p.push(x);
        } else if(str[0] == 'g') {
            scanf("%d",&x);
            while(!p.empty() && x > p.top()) {
                kis[len][0] = 3;
                kis[len++][1] = -1;
                p.pop();
            }
            if(p.empty() || x < p.top()) {
                kis[len][0] = 1;
                kis[len++][1] = x;
                p.push(x);
            }
            kis[len][0] = 2;
            kis[len++][1] = x;
        } else {
            if(p.empty()) {
                kis[len][0] = 1;
                kis[len++][1] = -inf;
                p.push(-inf);
            }
            kis[len][0] = 3;
            kis[len++][1] = -1;
            p.pop();
        }
    }
    cout<<len<<endl;
    for(int i = 0; i < len; ++i) {
        if(kis[i][0] == 1) {
            printf("%s %d\n",ins,kis[i][1]);
        } else if(kis[i][0] == 2) {
            printf("%s %d\n",ge,kis[i][1]);
        } else {
            printf("%s\n",rem);
        }
    }
    return 0;
}
