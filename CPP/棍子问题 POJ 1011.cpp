#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int sticks[65];///������ӵĳ���
int vis[65];///��ǹ����Ƿ��Ѿ����ù�
int n;///���ӵ�����

int cmd(int x, int y)
{
    return x>y;
}

int dfs(int y,int l,int p) /// y����ǰ�Ѿ���ȥ�Ĺ�������  l��Ŀ����ӵĳ��� p����ǰ�Ѿ�ƥ��Ĺ��ӵĳ���
{
    if(y==n)
        return 1;
    int sam=-1;
    for(int i = 0;i < n; i++)
    {
        if(vis[i]==1||sticks[i]==sam)///��֦2��������һ�ι����޷�ƥ�䣬��ô��������һ�ι��ӳ�����ͬ�Ĺ���Ҳ�޷�ƥ��
            continue;
        vis[i]=1;///���Ϊ�Ѿ��ù�
        if(p+sticks[i]<l)///����ܹ�ƥ�䣬�����ȥ
        {
            if(dfs(y+1,l,p+sticks[i]))
                return 1;
            else
                sam=sticks[i];
        }
        else if(p+sticks[i]==l)///�ɹ�ƥ���һ��Ŀ�곤�ȵĹ��ӣ���� p ����
        {
            if(dfs(y+1,l,0))
                return 1;
            else
                sam=sticks[i];
        }
        vis[i]=0;///����������û�г��ֳɹ�ƥ����������Ҫ�ѱ�ǽ�����Ա��´�����
        if(p==0)///��֦3����ǰ���ȵĹ��Ӿ��޷�ƥ���ʱ����˵��Ŀ������޷��ڵ�ǰ��������
        {
            cout<<"��ʱ�Ĺ��ӳ��ȣ�"<<sticks[i]<<"    ��i�����ӣ�"<<i<<"     Ŀ�곤�ȣ�"<<l<<"  �Ѿ�ƥ��Ĺ�������"<<y<<endl;
            break;
        }
    }
    return 0;
}

int main( )
{
    while(cin>>n&&n)
    {
        int sum=0;///��¼�����ܳ���
        for(int i = 0;i < n; i++)
        {
            scanf("%d",&sticks[i]);
            sum+=sticks[i];
            vis[i]=0;
        }
        sort(sticks,sticks+n,cmd);///�Թ��ӽ��н�������
        int maxx=sticks[0];
        int judge=0;
        for(int i = maxx;i <= sum/2+1;i++)
        {
            if(sum%i==0&&dfs(0,i,0))///��֦1:Ŀ����ӵĳ��ȱ���ɱ��ܳ�������
            {
                cout<<i<<endl;
                judge=1;
                break;
            }
        }
        if(judge==0)
            cout<<sum<<endl;
    }
    return 0;
}
