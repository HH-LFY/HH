#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI 3.141592653
using namespace std;

struct node
{
    int x;
    int y;
    int count;
};

const int maxx = 11;
int vis[maxx][maxx];
int x, y;
char a, b;
int ka, kb;
int dx[] ={2,2,1,1,-1,-1,-2,-2};
int dy[] ={1,-1,2,-2,2,-2,1,-1};

int ok(int x,int y)
{
    if(!(x>=1&&x<=8)) return 0;
    if(!(y>=1&&y<=8)) return 0;
    if(vis[x][y]) return 0;
    return 1;
}

void bfs( )
{
    int sum = 1;
    queue<node> p;
    node k;
    k.x = ka;
    k.y = x;
    k.count = 0;
    vis[ka][x] = 1;
    p.push(k);
    while(!p.empty())
    {
       // cout<<"hehe"<<endl;
        node q;
        q=p.front();
        p.pop( );
        if(q.x==kb&&q.y==y)
        {
            printf("To get from %c%d to %c%d takes %d knight moves.\n",a,x,b,y,q.count);
            return ;
        }
        for(int i = 0;i < 8; ++i)
        {
            int fx = q.x + dx[i];
            int fy = q.y + dy[i];
            if(!ok(fx,fy)) continue;
            if(fx==kb&&fy==y)
            {
                printf("To get from %c%d to %c%d takes %d knight moves.\n",a,x,b,y,q.count + 1);
                return ;
            }
            else
            {
                node l;
                l.x = fx;
                l.y = fy;
                l.count = q.count + 1;
                vis[fx][fy] = 1;
                p.push(l);
            }
        }
    }
}

int main( )
{
    while(scanf("%c%d %c%d",&a,&x,&b,&y)!=EOF)
    {
        getchar( );
        //cout<<a<<x<<b<<y<<endl;
        int i, j;
        for(i = 0;i < maxx; ++i)
        {
            for(j = 0;j < maxx; ++j)
            {
                vis[i][j] = 0;
            }
        }
        ka = a - 'a' + 1;
        kb = b - 'a' + 1;
        bfs( );
    }
    return 0;
}
