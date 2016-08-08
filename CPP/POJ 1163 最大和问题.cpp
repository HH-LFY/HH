/********************************
*******由下至上求最大解的方法***
**********************************/

#include <iostream>
#include <cstdio>
using namespace std;

const int maxx=100+10;
int map[maxx][maxx];
int n;
int i,j;

int max(int x,int y)
{
    return x>y?x:y;
}

int dp( )
{
    for(i=n-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            map[i][j]=max(map[i+1][j],map[i+1][j+1])+map[i][j];///由下至上选择时，把大三角形看成只有三个数的小三角形，把小三角形的定点加上小三角形中数值最大的支点的和作为下一次的支点，层层递归即可
        }
    }
    return map[1][1];
}

int main( )
{
    cin>>n;
    for(i = 1;i <= n; i++)
    {
        for(j=1;j <= i; j++)
        {
            scanf("%d",&map[i][j]);///当输入的数据很大时，不要用cin 输入，cin 输入是很慢的，因为cin其实是个函数，他在输入的时候会自动匹配所输入数据的格式，匹配成功后才能输入，你可以想象每个输入的数据都要在一个函数中先扫一遍才能输入，这可以有多慢吗？但其实scanf不是最快的，更快的还有getchar，但大多数题目是不要求进行太深的读入优化的
        }
    }
    cout<<dp()<<endl;
    return 0;
}

