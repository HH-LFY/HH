#include<iostream>
#include<cstring>
using namespace std;
struct
{
    int a,b,sum;
} t[140000];

int r[50010],SUM;  ///r[50010]�Ǵ��ÿ�����ϵ�������SUM��������Ų�ѯ�Ľ����

void make(int x,int y,int num)
{
    t[num].a=x;
    t[num].b=y;
    if(x==y) t[num].sum=r[y];///���x==y��˵���Ѿ���Ҷ�ӽڵ��ˣ�û�ж��ӽڵ��ˣ������ֳ��쵥��Ӫ�أ���������r[y]
    else
    {
        make(x,(x+y)/2,num+num); ///�����������
        make((x+y)/2+1,y,num+num+1); ///�����Ҷ�����
        t[num].sum=t[num+num].sum+t[num+num+1].sum; ///���ڵ�����������ӽ������֮�ͣ��߶α��ֳ����Ρ�
    }
}
void query(int x,int y,int num)
{
    if(x<=t[num].a&&y>=t[num].b)///�ҵ�Ҫ����߶����䣬������ֵ
        SUM+=t[num].sum;
    else
    {
        int min=(t[num].a+t[num].b)/2;
        if(x>min) query(x,y,num+num+1);  ///Ҫ��ѯ���߶��ڸ��߶��ұߣ���ѯ���߶ε����ӽڵ�
        else if(y<=min) query(x,y,num+num);///Ҫ��ѯ���߶��ڸ��߶���ߣ���ѯ���߶ε����ӽڵ�
        else
        {
            ///Ҫ��ѯ���߶��ڸ��߶��м䣬�ֶβ�ѯ�����ҽڵ㶼�顣
            query(x,y,num+num);
            query(x,y,num+num+1);
        }
    }
}
void add(int x,int y,int num)
{
    ///�Ӹ��ڵ㲻�����¸��ģ�ֻҪ�����õ�x�����䶼������Ӧ������y
    t[num].sum+=y;
    if(t[num].a==x&&t[num].b==x) return; ///�ҵ�x��Ҷ�ӽڵ㡣ֹͣ��
    if(x>(t[num].a+t[num].b)/2) add(x,y,num+num+1);///��x�ڸ��߶ε��ұߣ���ѯ���ӽڵ㡣
    else add(x,y,num+num);///�����ѯ���ӽڵ�
}
void sub(int x,int y,int num)
{
    t[num].sum-=y;
    if(t[num].a==x&&t[num].b==x) return;
    if(x>(t[num].a+t[num].b)/2) sub(x,y,num+num+1);
    else sub(x,y,num+num);
}
int main( )
{
    int n,t,i,j;
    char command[6];
    cin>>t;
    j=0;
    while(t--)
    {
        int temp,a,b;
        cin>>n;
        r[0]=0;
        for(i=1; i<=n; i++)
            cin>>r[i];
        make(1,n,1);
        cout<<"Case "<<++j<<":"<<endl;
        while(cin>>command)
        {
            if(strcmp(command,"End")==0)
                break;
            else if(strcmp(command,"Query")==0)
            {
                cin>>a>>b;
                SUM=0;
                query(a,b,1);
                cout<<SUM<<endl;
            }
            else if(strcmp(command,"Add")==0)
            {
                cin>>a>>b;
                add(a,b,1);
            }
            else if(strcmp(command,"Sub")==0)
            {
                cin>>a>>b;
                sub(a,b,1);
            }
        }
    }
    return 0;
}

