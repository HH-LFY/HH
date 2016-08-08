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

char str[1100];
int k;
int len;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>str;
    cin>>k;
    len = strlen(str);
    if(len%k!=0){
        cout<<"NO"<<endl;
    }else{
        int judge = 0;
        int m = len/k;
        for(int i = 0;i < k; ++i){
            for(int j = 0;j < m/2; ++j){
                if(str[i*m + j] != str[i*m + m - j - 1]){
                    judge = 1;
                    //cout<<i<<" "<<str[i*m + j]<<" "<<str[i*m + m - j]<<endl;
                    break;
                }
            }
            if(judge) break;
        }
        if(judge) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
