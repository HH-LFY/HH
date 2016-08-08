#include <iostream>
#include <cstdio>
using namespace std;

const int maxx = 10;
char str[10000][10];

struct node
{
    int count; ///记录该节点被访问的次数
    node *next[maxx];
    node( ) ///使用New时自动调用，对NODE进行初始化
    {
        count = 1;
        for(int i = 0;i < maxx; i++)
        {
            next[i] = NULL;
        }
    }
};

void insert(node *&root,char *str)
{
    node *l=root;
    int i=0,branch;
    while(str[i]!='\0')
    {
        branch=str[i]-'0';
        if(l->next[branch])
        {
            l->next[branch]->count++;
        }
        else
        {
            l->next[branch]=new node; ///动态分配内存
        }
        l=l->next[branch];
        i++;
    }
}

int search(node *&root,char *str)
{
    node *l=root;
    int i=0,branch,sum;
    while(str[i]!='\0')
    {
        branch=str[i]-'0'; ///把字符型数字转换为整型数字
        if(l->next[branch])
        {
            l=l->next[branch];
            sum=l->count;
        }
        else return 0;
        i++;
    }
    return sum;
}

void del(node *p)  ///释放内存的函数
{
    int i=0;
    for(;i < 10;i ++)
    {
        if(p->next[i]!=NULL)  ///假如下一个节点不是NULL则继续寻找下一个节点的空节点
        {
            del(p->next[i]);
        }
    }
    delete p;
}

int main( )
{
    int n,t;
    cin>>t;
    while(t--)
    {
        node *root= new node; ///分配内存
        cin>>n;
        getchar( );
        for(int o=1;o <= n; o++)
        {
            gets(str[o]);
            insert(root,str[o]);
        }
        int judge = 0;
        for(int i=1; i<= n; i++)
        {
            if(search(root,str[i])>1)  ///一旦出现有相同前缀的字符串，则不必继续寻找
            {
                judge=1;
                break;
            }
        }
        if(judge)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        del(root);  ///释放内存
    }
    return 0;
}
