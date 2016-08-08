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

const int maxx = 1e6 + 100;

struct node_vert{
    int id;
    long long value;
};

struct node{
    vector<node_vert> child;
    long long a;
}tree[maxx];
int n;
int ans = 0;

void dfs(int id,long long sum){
    if(sum > tree[id].a){
        return;
    }
    ans++;
    int len = tree[id].child.size();
    for(int i = 0;i < len; ++i){
        node_vert temp=tree[id].child[i];
        long long tempsum = temp.value;
        if(sum > 0){
            tempsum = tempsum + sum;
        }
        dfs(temp.id,tempsum);
    }

}

int main( ){
    cin>>n;
    for(int i = 1;i <= n; ++i){
        scanf("%I64d",&tree[i].a);
        tree[i].child.clear();
    }
    for(int i = 2;i <= n; ++i){
        int p, c;
        node_vert temp;
        scanf("%d%I64d",&p,&c);
        temp.id = i;
        temp.value = c;
        tree[p].child.push_back(temp);
    }
    ans=1;
    int len = tree[1].child.size();
    for(int i = 0;i < len; ++i){
        node_vert temp = tree[1].child[i];
        dfs(temp.id,temp.value);
    }
    cout<<n-ans<<endl;
    return 0;
}
