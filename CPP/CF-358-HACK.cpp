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

long long t1(long long n,long long m){
    long long a[5],b[5];
    for(int i = 0;i < 5; ++i){
        a[i] = n/5;
        b[i] = m/5;
    }
    for(int i = 1;i <= n%5; ++i){
        a[i-1]++;
    }
    for(int i = 1;i <= m%5; ++i){
        b[i-1]++;
    }
    long long s = a[0]*b[3] + a[3]*b[0] + a[4]*b[4] + a[1]*b[2]+b[1]*a[2];
    return s;
}

long long t2(long long n,long long m){
    long long f[5],s[5];
    f[0] = n/5;
    s[0] = m/5;
    for(int i = 1;i < 5; ++i){
        f[i] = n/5 + ((n%5)>=i);
        s[i] = m/5 + ((m%5)>=i);
    }
    long long res = f[0]*s[0];
    for(int i = 1;i < 5; ++i){
        res += f[i]*s[5-i];
    }
    return res;
}

long long t3(long long n,long long m){
    long long ans = (n*m+1)/5;
    return ans;
}

long long t4(long long n,long long m){
    long long t,g,l=0,q,i,j,p,s=0,r;
    p = n/5;
    q = m/5;
    r = n%5;
    s = m%5;
    for(i = 1;i <= r; ++i){
        for(j = 1;j <= s; ++j){
            if((i+j)%5==0){
                l++;
            }
        }
    }
    long long ans = (5*p*q+r*q+s*p+l);
    return ans;
}

long long t5(long long n,long long m){
    long long mn = min(n,m);
    long long mx = max(n,m);
    long long ct = 0,t =mx/5,ex = mx%5;
    for(long long i = 1;i <= mn; ++i){
        ct+=t;
        long long bb = i%5 +ex;
        if(i%5!=0&&bb/5!=0)ct++;
    }
    return ct;
}

long long t(long long n,long long m){
    long long ans = 0;
    long long arr[12];
    for(int i = 0;i < 10; ++i){
        for(int j = 1;j <= m; ++j){
            if((i+j)%5==0) arr[i]++;
        }
    }
    for(int i = 1;i <= n; ++i) ans += arr[i%10];
    return ans;
}

long long me(long long n,long long m){
    long long sum = 0;
    for(int i = 1;i <= n; ++i){
        int ll = i;
        int rr = i+m;
        sum = sum - (ll/5) + (rr/5);
        //cout<<i<<":"<<sum<<endl;
    }
    return sum;
}
const int maxx = 1e3;

bool A(){
    printf("A");
    return true;
}

bool B(){
    printf("B");
    return true;
}

int main( ){
    /*
    long long n,m;
    while(cin>>n>>m){
        cout<<t3(n,m)<<endl;
    }

    for(long long i = 1;i <= maxx; ++i){
        for(long long j = 1;j <= maxx; ++j){
            if(t(i,j)!=me(i,j)){
                cout<<t(i,j)<<" "<<me(i,j)<<" "<<endl;
                getchar();
            }
        }
    }
    cout<<endl;*/

    if(A()||B()){
        cout<<"s"<<endl;
    }
    return 0;
}
