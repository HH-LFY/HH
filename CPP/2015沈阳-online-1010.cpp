#include<bits/stdc++.h>
using namespace std;
long long p[203000];
long long mod = 530600414;
long long ans[203000];
int main(){
    int t,cas=0;
    p[3]=1;ans[3]=0;
    p[4]=3;ans[4]=0;
    long long len1=1,len2=1,len3;
    long long sum1=3,sum2=5,sum3;
    for(int i=5;i<=201314;i++){
            long long tmp=0;
            tmp=ans[i-2]+ans[i-1];tmp%=mod;
            tmp+=(len1*len2%mod*sum1)%mod+p[i-1]*len1%mod-len2*p[i-2]%mod;
            tmp=tmp%mod;
            while(tmp<0) tmp+=mod;
            ans[i]=tmp;
            p[i]=p[i-1]+sum1*len2%mod+p[i-2];
            p[i]%=mod;
            sum3=sum1+sum2;
            sum1=sum2;
            sum2=sum3;
            sum1%=mod;
            sum2%=mod;
            len3=len1+len2;
            len1=len2;
            len2=len3;
            len1%=mod;
            len2%=mod;
    }
    scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        printf("Case #%d: ",++cas);
        cout<<ans[n]<<endl;
    }
}
