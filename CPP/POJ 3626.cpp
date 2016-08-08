#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cmath>
#define PI 3.141592653
using namespace std;

const int inf = 1e9;
const int maxx = 1010;
int map[maxx][maxx];
int dis[maxx][maxx];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int gx,gy;
int t;

struct kp
{
    int x;
    int y;
};

int bfs( )
{
    int i,j;
    for(i = 0;i < maxx; ++i)
    {
        for(j = 0; j < maxx; ++j)
        {
            dis[i][j] = inf;
        }
    }
    queue<kp> que;
    kp p;
    p.x = 500;
    p.y = 500;
    que.push(p);
    dis[p.x][p.y] = 0;
    gx+=500;
    gy+=500;
    while(que.size())
    {
        kp node = que.front( );
        que.pop( );
        if(node.x==gx&&node.y==gy)
            break;
        for(i = 0;i < 4; ++i)
        {
            int kx = node.x+dx[i];
            int ky = node.y+dy[i];
            if(kx>=0&&kx<=1000&&ky>=0&&ky<=1000&&dis[kx][ky]==inf&&map[kx][ky]==0)
            {
                kp knode;
                knode.x = kx;
                knode.y = ky;
                que.push(knode);
                dis[kx][ky] = dis[node.x][node.y] + 1;
            }
        }
    }

    return dis[gx][gy];
}

int main( )
{
    while(scanf("%d%d%d",&gx,&gy,&t)!=EOF)
    {
        int x,y;
        for(int i = 0;i < maxx; ++i)
        {
            for(int j = 0;j < maxx; ++j)
            {
                map[i][j] = 0;
            }
        }
        while(t--)
        {
            scanf("%d%d",&x,&y);
            map[x+500][y+500] = 1;
        }
        int sum=bfs( );
        cout<<sum<<endl;
    }
    return 0;
}
