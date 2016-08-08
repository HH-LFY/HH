#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<iomanip>
#include<cmath>
#define mst(ss,b) memset((ss),(b),sizeof(ss))
#define maxn 0x3f3f3f3f
#define MAX 1000100
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef unsigned long long ull;
#define INF (1ll<<60)-1
using namespace std;
char s[5];
int a[22];
int vis[110],prime[110];
int main(){
    int cnt=0;
    for(int i=2;i<=100;i++){
        if(!vis[i]) {
            prime[cnt++]=i;
            for(int j=i+i;j<=100;j+=i){
                vis[j]=1;
            }
        }
    }
    /*for(int i=2;i<=100;i++){
        if(!vis[i]) cout<<i<<" ";
    }
    cout<<endl;*/
    int ans=0,n=0;
    while(scanf("%s",&s)!=EOF){
        n++;
        if(s[0]=='y') {
            a[n]=1;
            ans++;
        }
        else a[n]=0;
    }
    if(ans==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1) printf("97\n");
            else printf("2\n");
        }
        printf("prime\n");
    } else {
        for(int i=1;i<=n;i++){
            if(a[i]==1) printf("2\n");
            else printf("97\n");
        }
        printf("composite\n");
    }
    return 0;
}

