#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
long long ans;

int main( ){
    while(cin>>n){
        ans = 0;
        int x;
        int now = 0;
        for(int i = 0;i < n; ++i){
            int x;
            scanf("%d",&x);
            if(x>now){

                ///cout<<"1"<<endl;
                ans = (long long)(ans+x-now);
                now = x;
            }else if(x<now){

                ///cout<<"2"<<endl;
                ans = (long long)(ans + now - x);
                now = x;
            }
            //printf("%I64d\n",ans);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
