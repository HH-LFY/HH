#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define inf 1e17 + 5
using namespace std;

const int maxx = 1e5 + 10;
struct node{
    long long time[2];
}a[maxx];
vector<int> num[maxx];
set<int> p[maxx];
set<int>::iterator it;
queue<int> kis;
int vis[maxx][3];
long long t[maxx];
int n, m;
int ans[maxx];

struct ktype{
    int id;
    long long ti;
}sort_temp[maxx];

bool cmd(ktype x,ktype y){
    return x.ti < y.ti;
}

void solved(int qi,int flag){
    a[qi].time[flag] = 0;
    vis[qi][flag] = 1;
    kis.push(qi);
    while(!kis.empty()){
        int q = kis.front();
        kis.pop();
        int kp = 0;
        for(int i = 0;i < num[q].size(); ++i){
            int temp = num[q][i];
            sort_temp[kp].id = temp;
            sort_temp[kp++].ti = t[temp];
        }
        sort(sort_temp,sort_temp+kp,cmd);
        for(int i = 0;i < kp; ++i){
            int temp = sort_temp[i].id;
            if(vis[temp][2]) continue;
            for(it = p[temp].begin();it != p[temp].end(); ++it){
                int ktemp = *it;
                if(!vis[ktemp][flag]){
                    a[ktemp].time[flag] = t[temp] + a[q].time[flag];
                    kis.push(ktemp);
                    vis[ktemp][flag] = 1;
                }
            }
            vis[temp][2] = 1;
            break;
        }
    }
}

int main( ){
    int T;
    cin>>T;
    int kcount = 1;
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 0;i < maxx; ++i){
            vis[i][0]=vis[i][1]=vis[i][2]=0;
            ///a[i].time[0]=a[i].time[1]=inf;
        }
        for(int i = 0;i < m; ++i){
            int x, y;
            scanf("%d%d",&x,&y);
            t[i] = x;
            for(int j = 0;j < y; ++j){
                int z;
                scanf("%d",&z);
                p[i].insert(z);
                num[z].push_back(i);
            }
        }
        solved(1,0);
        for(int i = 0;i <= n; ++i)vis[i][2] = 0;
        solved(n,1);
        long long kans = inf;
        ///printf("%I64d\n",kans);
        int kp = 0;
        for(int i = 1;i <= n; ++i){
            if(vis[i][0]&&vis[i][1]){
                printf("%I64d %I64d\n",a[i].time[0],a[i].time[1]);
                long long hhh = max(a[i].time[1],a[i].time[0]);
                if(kans > hhh){
                    kans = hhh;
                    kp = 1;
                    ans[0] = i;
                }else if(kans == hhh){
                    ans[kp++] = i;
                }
            }
        }
        if(kans == inf) printf("Case #%d: Evil John\n",kcount++);
        else {
            printf("Case #%d: %I64d\n",kcount++,kans);
            for(int i = 0;i < kp-1; ++i){
                printf("%d ",ans[i]);
            }
            printf("%d\n",ans[kp-1]);
        }
        for(int i = 0;i < maxx; ++i){
            p[i].clear();
            num[i].clear();
        }
    }
    return 0;
}
/**

5 5
1 2 1 2
2 2 2 3
3 2 3 4
4 2 4 5
6 2 1 5

5 5
1 2 1 2
2 2 2 3
3 2 3 4
0 2 4 5
6 2 1 5

5 5
5 2 1 3
6 3 3 4 1
1 2 1 2
3 2 2 4
1 2 4 5


*/
