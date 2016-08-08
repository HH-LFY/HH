#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

const int maxn = 1000 + 10;
struct node{
    int x, y;
    long long s;
}sum[maxn*maxn];
int num[maxn];
int T, n;

struct tree{
    vector<int>p;
    tree* next[2];
    tree(){
        next[0]=next[1]=NULL;
    }
};

long long kis[40];

void init(){
    long long i;
    kis[0] = 1;
    for(i = 1;i <= 33; ++i){
        kis[i] = kis[i-1]*2;
    }
}

bool cmd(node x,node y){
    return x.s>y.s;
}

void t_insert(tree *root,int x){
    tree *p = root;
    long long ks = num[x];
    int kp = 32;
    int zero[33];
    memset(zero,0,sizeof(zero));
    while(ks>0){
        zero[kp--] = ks%2;
        ks/=2;
    }
/**
    for(int i = 0;i <= 33; ++i){
        printf("%d",zero[i]);
    }
    puts("");
*/
    int kt = 0;
    while(kt<33){
        if(p->next[zero[kt]] == NULL){
            p->next[zero[kt]] = new tree();
        }
        p = p->next[zero[kt]];
        p->p.push_back(x);
        kt++;
    }

}

long long t_search(tree* root,node x){
    tree *p = root;
    long long ks = x.s;
    int kp = 32;
    int zero[33];
    memset(zero,0,sizeof(zero));
    long long ans = 0;
    while(ks>0){
        zero[kp--] = ks%2;
        ks/=2;
    }
    /**
    for(int i = 0;i <= 33; ++i){
        printf("%d",zero[i]);
    }
    puts("");
    */
    int kt = 0;
    while(kt<33){
        if(p->next[!zero[kt]] != NULL){
            int judge = 0;
            ///puts("sasas");
            for(int i=0;i<p->next[!zero[kt]]->p.size();i++){
                if(x.x != p->next[!zero[kt]]->p[i] && x.y != p->next[!zero[kt]]->p[i]){
                    judge = 1;
                    break;
                }
            }
            if(!judge){
                goto kkkkkk;
            }
            p = p->next[!zero[kt]];
            ans += kis[32-kt];
            ///printf("%d\n",kt);
        }else{
            kkkkkk:
            p = p->next[zero[kt]];
        }
        kt++;
    }
    return ans;
}

void del(tree *p)
{
    int i=0;
    for(;i < 2;i ++)
    {
        if(p->next[i]!=NULL)
        {
            del(p->next[i]);
        }
    }
    delete p;
}

int main( ){
    cin>>T;
    init();
    while(T--){
        tree* root = new tree();
        scanf("%d",&n);
        for(int i = 1;i <= n; ++i){
            scanf("%d",&num[i]);
            t_insert(root,i);
        }
        int p = 0;long long kmax = -1;long long kna;
        for(int i = 1;i <= n; ++i){
            for(int j = i+1;j <= n; ++j){
                sum[p].x = i;
                sum[p].y = j;
                sum[p++].s = num[i]+num[j];
                if(kmax < (kna = t_search(root,sum[p-1]))){
                    kmax = kna;
                }
            }
        }
        del(root);
        printf("%I64d\n",kmax);
    }
    return 0;
}
