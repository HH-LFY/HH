#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int S[1000010];
int T[10010];
int knext[10010];
int n, m;
void build_knext(int kT[]){
    int len = m;
    int i = 0,j = -1;
    knext[0] = -1;
    while(i<len){
        if(j == -1 || kT[i]==kT[j]) knext[++i]=++j;
        else j = knext[j];
    }
}

int kmp_search(int *kstr,int *kT){
    int i = 0;
    int j = 0;
    int len_s=n;
    int len_f=m;
    while(i<len_s && j<len_f){
        if(j==-1||kstr[i]==kT[j]){
            i++;
            j++;
        }
        else j = knext[j];
    }
    if(j == len_f) return i-len_f;
    else return -1;
}

int KMP_Count()
{
    int ans = 0;
    int i, j = 0;

    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    getNext();
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}

int main( ){
    int cat;
    cin>>cat;
    while(cat--){
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n; ++i) scanf("%d",&S[i]);
        for(int i = 0;i < m; ++i) scanf("%d",&T[i]);
        build_knext(T);
        int ans = kmp_search(S,T);
        printf("%d\n",ans==-1?ans:ans+1);
    }
    return 0;
}
