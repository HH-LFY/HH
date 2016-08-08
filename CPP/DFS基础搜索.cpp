#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char map[30][30];
bool vis[30][30];
int w,h,sum;
int kx,ky;

void dfs(int kx,int ky)
{
    for(int i = 0; i < 4; i++)//搜索点的四个方向
    {
        int tx = kx + dir[i][0];
        int ty = ky + dir[i][1];
        if(!vis[tx][ty])//搜索到一个‘，’ ， 进行记录并以该点为起始点继续深搜
        {
            vis[tx][ty] = 1;//把搜索出来的‘.’记录，防止重复计算
            sum++;
            dfs(tx,ty);
        }
    }
}

int main( )
{
    while(cin>>w>>h&&w&&h)
    {
        getchar();
        memset(vis,1,sizeof(vis));//把vis初始化为1，可无需设置边界，
        for(int i = 1; i <= h; i++)
        {
            for(int j = 1; j <= w; j++)
            {
                cin>>map[i][j];
                if('@'==map[i][j])
                {
                    kx = i;
                    ky = j;
                }
                else if('.'==map[i][j])
                {
                    vis[i][j]=0;//输入的‘.’记录为0，意为可走
                }
            }
            getchar();
        }
        sum = 1;
        dfs(kx,ky);
        cout<<sum<<endl;
    }
    return 0;
}
