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

const int maxx = 1e6 + 10;
struct node {
    int id;
    node* next;
    node() {
        next = NULL;
    }
} a[maxx];
int N;
int Q;
int x, y, z;
set<int> p;
int num[maxx];

void join(int i,int x) {
    node *root = new node();
    node *q = a[x].next;
    root->id = i;
    root->next = q;
    a[x].next = root;
}

void solved(int i) {
    node *q = a[i].next;
    while(q != NULL) {
        if(p.count(q->id) == 0) {
            p.insert(q->id);
        } else {
            p.erase(q->id);
        }
        q = q->next;
    }
}

int main() {
    //freopen("input.txt","r",stdin);
    int T;
    while(cin>>T) {
        int count = 1;
        while(T--) {
            long long ans = 0;
            scanf("%d%d",&N,&Q);
            for(int i = 0; i <= N; ++i) {
                a[i].id = -1;
                a[i].next = NULL;
                num[i] = 1;
            }
            for(int i = 1; i <= Q; ++i) {
                scanf("%d%d%d",&x,&y,&z);
                join(i,x);
                join(i,y+1);
                num[i] = z;
            }
            p.insert(0);
            set<int>::iterator it;
            for(int i = 1; i <= N; ++i) {
                solved(i);
                it = p.end();
                it--;
                printf("i:%d Q:%d num:%d\n",i,*it,num[*it]);
                ans += num[*it];
            }

            /**
            for(int i = 1;i <= N; ++i){
                if(a[i].next == NULL) continue;
                while(a[i].next != NULL){
                    printf("%d %d ",i,a[i].next->id);
                    a[i] = *a[i].next;
                }
                printf(" . \n");
            }
            */
            p.clear();
            printf("Case %d: The total value of the hook is %lld.\n",count++,ans);
        }
    }
    return 0;
}
