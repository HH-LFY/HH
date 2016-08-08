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

const int maxx = 1e5 + 10;
__int64 l[maxx];
__int64 r[maxx];
__int64 a[maxx];
int T;
int n;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>T;
    int countt = 1;
    while(T--){
        cin>>n;
        for(int i = 0;i < n; ++i){
            scanf("%I64d",&a[i]);
        }
        __int64 ans = (__int64)((n * (n + 1))/2);
        stack<int> p;
        p.push(-1);
        for(int i = 0;i < n; ++i){
            while(p.top()!=-1 && a[p.top()] >= a[i]) p.pop();
            l[i] =i - p.top();
            p.push(i);
        }
        while(!p.empty()) p.pop();
        p.push(n);
        for(int i = n - 1;i >= 0; --i){
            while(p.top() != n && a[p.top()] > a[i]) p.pop();
            r[i] = p.top() - i;
            p.push(i);
        }

        for(int i = 0;i < n; ++i){
            //printf("%d %d\n",l[i],r[i]);
            ans = ans - (__int64)((l[i] * r[i] - 1) *a[i]);
        }
        ///cout<<endl;

        while(!p.empty()) p.pop();
        p.push(-1);
        for(int i = 0;i < n; ++i){
            while(p.top()!=-1 && a[p.top()] <= a[i]) p.pop();
            l[i] =i - p.top();
            p.push(i);
        }
        while(!p.empty()) p.pop();
        p.push(n);
        for(int i = n - 1;i >= 0; --i){
            while(p.top() != n && a[p.top()] < a[i]) p.pop();
            r[i] = p.top() - i;
            p.push(i);
        }
        for(int i = 0;i < n; ++i){
           // printf("%d %d\n",l[i],r[i]);
            ans = ans + (__int64)((l[i] * r[i] - 1) *a[i]);
        }

        printf("Case %d: %I64d\n",countt++,ans);
    }
    return 0;
}
