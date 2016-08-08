#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
    node *fail;
    node *next[26];
    int count;
    node( )
    {
        fail = NULL;
        count = 0;
        memset(next,NULL,sizeof(next));
    }
}*q[500001];

char keyw[55];
char str[1000000+10];
int head,tail;
int n,t;

void insert(char *str,node *root)
{
    node *p=root;
    int i = 0;
    int word;
    while(str[i])
    {
        word=str[i]-'a';
        if(p->next[word]==NULL)
        {
            p->next[word]=new node();
        }
        p=p->next[word];
        i++;
    }
    p->count++;
}

void build_ac_trie(node *root)
{
    int i ;
    root->fail=NULL;
    q[head++]=root;
    while(head!=tail)
    {
        node *temp=q[tail++];
        node *p=NULL;
        for(i=0;i < 26;i++)
        {
            if(temp->next[i]!=NULL)
            {
                if(temp==root)
                {
                    temp->next[i]->fail=root;
                }
                else
                {
                    p=temp->fail;
                    while(p!=NULL)
                    {
                        if(p->next[i]!=NULL)
                        {
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL)
                    {
                        temp->next[i]->fail=root;
                    }
                }
                q[head++]=temp->next[i];
            }
        }
    }
}

int query(node *root)
{
    int i = 0;
    int sum=0;
    int word;
    int len=strlen(str);
    node *p=root;
    while(str[i])
    {
        word=str[i]-'a';
        while(p->next[word]==NULL&&p!=root) p=p->fail;
        p=p->next[word];
        if(p==NULL)
        {
            p=root;
        }
        node *temp=p;
        while(temp!=root&&temp->count!=-1)
        {
            sum+=temp->count;
            temp->count=-1;
            temp=temp->fail;
        }
        i++;
    }
    return sum;
}

int main( )
{
    cin>>t;
    while(t--)
    {
        head=tail=0;
        node *root=new node();
        scanf("%d",&n);
        getchar( );
        while(n--)
        {
            gets(keyw);
            insert(keyw,root);
        }
        build_ac_trie(root);
        scanf("%s",str);
        printf("%d\n",query(root));
    }
    return 0;
}
