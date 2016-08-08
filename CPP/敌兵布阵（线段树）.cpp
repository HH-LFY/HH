#include<iostream>
#include<cstring>
using namespace std;
struct
{
    int a,b,sum;
} t[140000];

int r[50010],SUM;  ///r[50010]是存放每个点上的人数，SUM是用来存放查询的结果。

void make(int x,int y,int num)
{
    t[num].a=x;
    t[num].b=y;
    if(x==y) t[num].sum=r[y];///如果x==y，说明已经是叶子节点了，没有儿子节点了，就显现成熟单个营地，人数就是r[y]
    else
    {
        make(x,(x+y)/2,num+num); ///构造左儿子树
        make((x+y)/2+1,y,num+num+1); ///构造右儿子树
        t[num].sum=t[num+num].sum+t[num+num+1].sum; ///父节点的人数等于子结点人数之和，线段被分成两段。
    }
}
void query(int x,int y,int num)
{
    if(x<=t[num].a&&y>=t[num].b)///找到要求的线段区间，返回其值
        SUM+=t[num].sum;
    else
    {
        int min=(t[num].a+t[num].b)/2;
        if(x>min) query(x,y,num+num+1);  ///要查询的线段在该线段右边，查询该线段的右子节点
        else if(y<=min) query(x,y,num+num);///要查询的线段在该线段左边，查询该线段的左子节点
        else
        {
            ///要查询的线段在该线段中间，分段查询，左右节点都查。
            query(x,y,num+num);
            query(x,y,num+num+1);
        }
    }
}
void add(int x,int y,int num)
{
    ///从根节点不断往下更改，只要包含该点x的区间都增加相应的数量y
    t[num].sum+=y;
    if(t[num].a==x&&t[num].b==x) return; ///找到x的叶子节点。停止。
    if(x>(t[num].a+t[num].b)/2) add(x,y,num+num+1);///点x在该线段的右边，查询右子节点。
    else add(x,y,num+num);///否则查询左子节点
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

