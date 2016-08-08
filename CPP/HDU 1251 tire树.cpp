#include <iostream>
#include <cstdio>
using namespace std;

const int maxx = 26;

struct node
{
    int count;
    node *next[maxx];
    node( )
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
        branch=str[i]-'a';
        if(l->next[branch])
        {
            l->next[branch]->count++;
        }
        else
        {
            l->next[branch]=new node;
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
        branch=str[i]-'a';
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

void del(node *p)
{
    for(int i = 0;i < 26;i ++)
    {
        if(p->next[i]!=NULL)
            del(p->next[i]);
    }
    delete p;
}

int main( )
{
    char str1[101],str2[11];
    node *root= new node;
    while(gets(str1))
    {
        if(str1[0]=='\0')
        {
            break;
        }
        insert(root,str1);
    }
    while(gets(str2))
    {
        cout<<search(root,str2)<<endl;
    }
    del(root);
    return 0;
}
