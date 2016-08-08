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

char str[35];   //������� n ����Ϊ���� n �Ƚϴ��������ַ������ʹ���
int f[11][11];  //������� 0 - 9 ���ڽӾ���
int sum[11];    //������ֿ��Ա仯�������������sum[0]�������� ��0�����Ա仯���������ֵ���Ŀ
int m;

void init()  //��ʼ��
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

void input() //����
{
    int x, y;
    scanf("%s%d",str,&m);
    for(int i = 0;i < m; ++i)
    {
        scanf("%d%d",&x,&y);
        f[x][y] = 1;
    }
}

void floyd() //��⴫�ݱհ�
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
                sum[i]++;         //ֻҪ i �� j ֮��ɴ��������жϷ����ǣ����벻Ϊ�������sum[i] ���һ

    long long ans = 1;
    for(int i = 0; str[i] != '\0'; ++i)
    {
        ans *= sum[str[i] - '0']; //�����ѧ���ó˷�������п��ܳ��ֵ����
    }
    cout<<ans<<endl;
}

int main()
{
    init();   ///��ʼ��
    input();  ///��������
    floyd();  ///��Floyd�㷨��⴫�ݱհ�
    solved(); ///�����
    return 0;
}
