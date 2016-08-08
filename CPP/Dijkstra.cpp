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
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 1e3 + 10;
int N, M, s, t;
int m[maxx][maxx];
int dis[maxx];
int vis[maxx];

void input()
{
    cin>>N>>M>>s>>t;
    int x, y, z;
    for(int i = 0;i < M; ++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        m[x][y] = m[y][x] = min(m[x][y],z); ///注意重边问题。。。。。。
    }
}

void init()
{
    for(int i = 0;i < maxx; ++i)
    {
        vis[i] = 0;
        for(int j = 0;j < maxx; ++j)
        {
            if(i == j) m[i][j] = 0;
            else m[i][j] = inf;
        }
    }
}

void Dijkstra()
{
    int p = 0;
    vis[s] = 1;

    for(int i = 1;i <= N; ++i)
    {
        dis[i] = m[s][i];
    }

    while(p!=N) ///0 ~ N-1 , 是 N 个点
    {
        int kmin = inf; /// 初始化一下， 用来记录未被标记的点中的与源点的最短边
        int k = -1;     /// 记录该边对应的点
        for(int i = 1;i <= N; ++i)
        {
            if(!vis[i] && kmin>dis[i])
            {
                kmin = dis[i];
                k = i;
            }
        }

        if(k != -1) ///如果 k = -1 ，则说明有些点不可达。
        {
            vis[k] = 1;
            for(int i = 1;i <= N; ++i)
            {
                if(!vis[i])  dis[i] = min(dis[i],dis[k] + m[k][i]);
            }
        }
        else
        {
            break;
        }
        p++;
    }
}

void show()
{
    cout<<dis[t]<<endl;
}

int main()
{
    init();    ///对邻接矩阵进行初始化
    input();   ///输入数据
    Dijkstra();///Dijkstr算法
    show();    ///输出整个邻接矩阵
    return 0;
}
