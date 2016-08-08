#include <iostream>
#include <cstdio>
using namespace std;

const int maxx = 10;
char str[10000][10];

struct node
{
    int count; ///��¼�ýڵ㱻���ʵĴ���
    node *next[maxx];
    node( ) ///ʹ��Newʱ�Զ����ã���NODE���г�ʼ��
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
            l->next[branch]=new node; ///��̬�����ڴ�
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
        branch=str[i]-'0'; ///���ַ�������ת��Ϊ��������
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

void del(node *p)  ///�ͷ��ڴ�ĺ���
{
    int i=0;
    for(;i < 10;i ++)
    {
        if(p->next[i]!=NULL)  ///������һ���ڵ㲻��NULL�����Ѱ����һ���ڵ�Ŀսڵ�
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
        node *root= new node; ///�����ڴ�
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
            if(search(root,str[i])>1)  ///һ����������ͬǰ׺���ַ������򲻱ؼ���Ѱ��
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
        del(root);  ///�ͷ��ڴ�
    }
    return 0;
}
