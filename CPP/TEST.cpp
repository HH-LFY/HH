#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
bool mark[1050][1050] , vis[1050][1050];
int x , y , n;

struct node
{
    int x , y;
    int step;
};

int dir[4][2] = {{-1 , 0} , {0 , 1} , {1 , 0} , {0 , -1}};

void bfs()
{
    queue<node>Q;
    node u;
    u.x = 500; u.y = 500; u.step = 0;
    Q.push(u);
    vis[u.x ][u.y ] = 1;
    while(!Q.empty())
    {
        node t = Q.front();
        if(t.x == x+500 && t.y == y+500)
        {
            printf("%d\n", t.step);
            return;
        }
        Q.pop();
        node p;
        for(int i=0; i<4; ++i)
        {
            p.x = t.x + dir[i][0];
            p.y = t.y + dir[i][1];
            p.step = t.step + 1;
            if(p.x <= 1000 && p.x >= 0 && p.y <= 1000 && p.y >= 0 && !mark[p.x][p.y] && !vis[p.x][p.y])
            {
                vis[p.x][p.y] = 1;
                Q.push(p);
            }
        }
    }
}

int main()
{
    int a  ,b;
    while(scanf("%d%d%d", &x, &y, &n) != EOF)
    {
        memset(mark, 0, sizeof(mark));
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d", &a, &b);
            mark[a + 500][b + 500] = 1;
            vis[a + 500][b + 500] = 1;
        }
        bfs();
    }
    return 0;
}
