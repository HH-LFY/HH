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
    for(int i = 0; i < 4; i++)//��������ĸ�����
    {
        int tx = kx + dir[i][0];
        int ty = ky + dir[i][1];
        if(!vis[tx][ty])//������һ�������� �� ���м�¼���Ըõ�Ϊ��ʼ���������
        {
            vis[tx][ty] = 1;//�����������ġ�.����¼����ֹ�ظ�����
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
        memset(vis,1,sizeof(vis));//��vis��ʼ��Ϊ1�����������ñ߽磬
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
                    vis[i][j]=0;//����ġ�.����¼Ϊ0����Ϊ����
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
