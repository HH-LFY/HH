#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int maxx = 30;
struct node
{
    int x;
    int y;
};
int t;
int h, w;
int n, m;
bool km[1010][1010];
vector<node> dis[maxx];
vector<node> p;
string str;

int ok(int a,int b){
    if(a>=n||a<0)return false;
    if(b>=m||b<0)return false;
    return true;
}

void solved(){
    for(int i = 1;i <= t; ++i){
        int flag = 0;
        for(int j = 0;j < p.size(); ++j){
            int judge = 0;
            for(int k = 0;k < dis[i].size(); ++k){
                int dx = p[j].x + dis[i][k].x;
                int dy = p[j].y + dis[i][k].y;
                if(false==ok(dx,dy)||0==km[dx][dy]){
                    judge = 1;
                    break;
                }
            }
            if(0==judge){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            puts("Yes");
        }else{
            puts("No");
        }
    }
}

int main()
{
    while(cin>>t)
    {
        memset(km,0,sizeof(km));
        for(int i = 0;i < maxx;++i)dis[i].clear();
        for(int o = 1; o <= t; ++o)
        {
            scanf("%d%d",&h,&w);
            int dx = -1;
            int dy = -1;
            for(int i = 0; i < h; ++i)
            {
                cin>>str;
                for(int j = 0; j < w; ++j)
                {
                    if(str[j] == '#')
                    {
                        if(dx == -1)
                        {
                            dx = i;
                            dy = j;
                        }
                        else
                        {
                            node temp;
                            temp.x = i-dx;
                            temp.y = j-dy;
                            dis[o].push_back(temp);
                        }
                    }
                }
            }
        }
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; ++i)
        {
            cin>>str;
            for(int j = 0; j < m; ++j)
                if(str[j] == '#')
                {
                    km[i][j]=1;
                    node temp;
                    temp.x = i;
                    temp.y = j;
                    p.push_back(temp);
                }else{
                    km[i][j]=0;
                }
        }
        solved();
    }
    return 0;
}

