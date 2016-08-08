#include <cstdio>
#include <iostream>
#define inf (1<<30) - 1
using namespace std;

int m,n;
int e[3005][3005];
int vis[3005],d[3005];
int p[3005];

void D( )
{
    int i,j,k;
    for(i=1; i<=n; i++)
    {
        vis[i] = 0;///��ʼ�����е㣬 0 ��ʾδ�����ʣ� 1 ��ʾ�Ѿ�����
        d[i] = e[1][i]; ///��ʱ�� d[i] Ϊ��ʼ�㡮1������� i �ľ��롣
    }
    d[1] = 0;
    vis[1] = 1; ///����ʼ�㡮1�� ���б��
    for(i=1; i < n; i++)
    {
        int kmin = inf;///����һ��������Сֵ�ı���
        int tag = -1;
        for(j = 1;j <= n; ++j)
        {
            if(!vis[j]&&kmin > d[j]) ///�ҳ�δ�����ʵĵ�������ʼ������ĵ㣬����¼����
            {
                kmin = d[j];
                tag = j;
            }
        }
        vis[tag] = 1;///�Ըõ���б��
        for( j = 1;j <= n; ++j)
        {
            if(vis[j]) continue;///����� j �Ѿ������ʣ���ô���ٴ���ֱ������
            d[j]=min(d[tag]+e[tag][j],d[j]);
            /**
                d[tag] Ϊ��ʼ�㵽�� tag �����·����

                ��ô��ʼ�㵽�� j ��·��ҪôΪ d[j] ҪôΪ d[tag]+e[tag][j] ȡ��С����

                ����һ��̰�ĵ��ƵĹ��̡�

                �������̫�������㷨��˼·�������Լ���ֽ�ϻ�һ�����ͼ�����·������̡�

            */
        }
    }
}

int main()
{
    int i,j,u,v,w;
    scanf("%d%d",&m,&n);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(i == j) e[i][j] = 0; ///��ʼ��ͼ
            else e[i][j]=inf;
        }
    for(i=0; i<m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        e[u][v]=e[v][u]=min(e[u][v],w);///�� min ��Ϊ�˷�ֹ���ر߳��֡������� u �� v ֮������ر�ʱ����ôȡȨֵ��С������
    }
    D();
    printf("%d\n",d[n]);
    return 0;
}
