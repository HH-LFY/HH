#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double dis[1010][2];///��������ÿ����ĺ�������������
bool vis[1010];///����õ�����
int n,i,j,k;

double ff(double x1,double y1,double x2,double y2) ///���������
{
    double x=x1-x2;
    double y=y1-y2;
    return sqrt(x*x+y*y);
}

int main( )
{
    while(cin>>n)
    {
    for(i = 1; i <= n; i++)
    {
        cin>>dis[i][0]>>dis[i][1];
    }
    memset(vis,0,sizeof(vis));
    double sum=0;
    int kn=1;
    k=1;
    vis[1]=1;
    while(1)
    {
        if(kn==n) break;
        double minn=10000000;
        int p=0;
        for(i = 1; i <= n; i++)
        {
            if(!vis[i]&&minn>=ff(dis[i][0],dis[i][1],dis[k][0],dis[k][1]))
            {
                p=i;
                minn=ff(dis[i][0],dis[i][1],dis[k][0],dis[k][1]);
            }
        }
        k=p;
        kn++;
        sum+=minn;
        vis[k]=1;///��Ǳ����ʹ��ĵ�
    }
    printf("%.3lf\n",sum);
    }
    return 0;
}

