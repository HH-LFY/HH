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

const int maxx = 1e2 + 100;
int N, M;
int x, y, s;
int m[maxx][maxx];

void init() ///���ڽӾ�����г�ʼ��
{
    for(int i = 0;i < maxx; ++i)
    {
        for(int j = 0;j < maxx; ++j)
        {
            if(i == j) m[i][j] = 0;
            else m[i][j] = inf;
        }
    }
}

void input() ///��������
{
    cin>>N>>M;
    for(int i = 0;i < M; ++i)
    {
        cin>>x>>y>>s;
        m[x][y] = m[y][x] = min(m[x][y],s); ///������ر���ȡ��С�ı߼���
    }
}

void floyd() ///Floyd�㷨
{
    for(int k = 1;k <= N; ++k)
    {
        for(int i = 1;i <= N; ++i)
        {
            if(i!=k) ///��΢�ļ�С�¼�����
            for(int j = 1;j <= N; ++j)
            {
                m[i][j] = min(m[i][k] + m[k][j], m[i][j]);
            }
        }
    }
}

void show()///��������ڽӾ���
{
    for(int i = 1;i <= N; ++i)
    {
        for(int j = 1;j < N; ++j)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<m[i][N]<<endl;
    }
}

int main()
{
    init(); ///���ڽӾ�����г�ʼ��
    input();///��������
    floyd();///Floyd�㷨
    show(); ///��������ڽӾ���
    return 0;
}
