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

int T;
int n;
int a[310];
double ans;

int main( ){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i = 0;i < n; ++i){
            scanf("%d",&a[i]);
        }
        ans = 0;
        double xsum = 0;
        double ysum = 0;
        for(int i = 0;i < n; ++i){
            xsum = n-1;
            ysum = 0;
            for(int j = 0;j < n; ++j){
                if(i!=j && a[i]>a[j]){
                    ysum++;
                }
            }
            ans += ysum/xsum;
            //cout<<ans<<endl;
        }
        ans = ans/n;
        printf("%f\n",ans);
    }
    return 0;
}
