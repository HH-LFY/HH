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

char str[35];   //用来存放 n ，因为数字 n 比较大，所以用字符串类型储存
int f[11][11];  //存放数字 0 - 9 的邻接矩阵
int sum[11];    //存放数字可以变化的情况数，比如sum[0]就是数字 ‘0’可以变化成其他数字的数目
int m;

void init()  //初始化
{
    for(int i = 0;i < 11; ++i)
    {
        sum[i] = 0;
        for(int j = 0;j < 11; ++j)
        {
            if(i == j)
            {
                f[i][j] = 0;
            }
            else
            {
                f[i][j] = inf;
            }
        }
    }
}

void input() //输入
{
    int x, y;
    scanf("%s%d",str,&m);
    for(int i = 0;i < m; ++i)
    {
        scanf("%d%d",&x,&y);
        f[x][y] = 1;
    }
}

void floyd() //求解传递闭包
{
    for(int k = 0;k <= 9; ++k)
    {
        for(int i = 0;i <= 9; ++i)
        {
            if(f[i][k])
            for(int j = 0;j <= 9; ++j)
            {
                f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}

void solved()
{
    for(int i = 0;i <= 9; ++i)
        for(int j = 0;j <= 9; ++j)
            if(f[i][j] < inf)
                sum[i]++;         //只要 i 与 j 之间可达（我这里的判断方法是，距离不为正无穷），sum[i] 便加一

    long long ans = 1;
    for(int i = 0; str[i] != '\0'; ++i)
    {
        ans *= sum[str[i] - '0']; //组合数学，用乘法求解所有可能出现的情况
    }
    cout<<ans<<endl;
}

int main()
{
    init();   ///初始化
    input();  ///输入数据
    floyd();  ///用Floyd算法求解传递闭包
    solved(); ///输出答案
    return 0;
}
