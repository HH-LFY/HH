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

const int mod = 1e9 + 7;
long long k, n;
int T;///count
long long ans;

int main( ){
    cin>>T;
    while(T--){
        cin>>k>>n;
        if(2*k<n*(n+1)){
            puts("-1");
            continue;
        }
        if(k%n == 0){
            long long temp = k/n;
            int len;
            if(n%2==0){
                ans = (temp-1)*(temp+1)%mod;
                len = (n-2)/2;
                //cout<<temp-1<<endl;
                //cout<<temp+1<<endl;
                for(int i = 1;i <= len; ++i){
                    //cout<<temp-i-1<<endl;
                    //cout<<temp+i+1<<endl;
                    ans = (ans * (temp-i-1))%mod;
                    ans = (ans * (temp+i+1))%mod;
                }
            }else{
                ans = temp;
                len = (n-1)/2;
                //cout<<temp<<endl;
                for(int i = 1;i <= len; ++i){
                    //cout<<temp-i<<endl;
                    //cout<<temp+i<<endl;
                    ans = (ans * (temp-i))%mod;
                    ans = (ans * (temp+i))%mod;
                }
            }
        }else{
            long long temp = k/n;
            long long les = k%n;
            if(n%2 == 0){
                ans = temp*(temp+1)%mod;
                int len = (n-2)/2;
                //cout<<temp<<endl;
                //cout<<temp+1<<endl;
                for(int i = 1;i <= len; ++i){
                    //cout<<temp-i<<endl;
                    //cout<<temp+i+1<<endl;
                    ans = (ans * (temp-i))%mod;
                    ans = (ans * (temp+i+1))%mod;
                }
            }else{
               // cout<<"bug1"<<endl;
                ans = 1;
                int len = n/2;
                for(long long i = temp+len;i >= temp-len; --i){
                    if(les){
                        //cout<<i+1<<endl;
                        ans = (ans *(i+1))%mod;
                        les--;
                    }else{
                        //cout<<i<<endl;
                        ans = (ans *i)%mod;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
