#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
    int sum;
    node *next[26];
    node()
    {
        sum=0;
        for(int i = 0;i < 26;i++)
        {
            next[i]=NULL;
        }
    }
};

void update(node *toot,char *str)
{
    node *root=toot;
    int k=0;
    while(str[k]!='\0')
    {
        int word=str[k]-'a';
        if(root->next[word]==NULL)
        {
            root->next[word]=new node();
            root=root->next[word];
            root->sum++;
        }
        else
        {
            root=root->next[word];
            root->sum++;
        }
        k++;
    }
}

void find(node *toot,char *str)
{
    node *root=toot;
    int k=0;
    int judge=0;
    while(str[k]!='\0')
    {
        int word=str[k]-'a';
        if(root->next[word]!=NULL)
        {
            root=root->next[word];
            judge=root->sum;
        }
        else
        {
            judge=0;
            break;
        }
        k++;
    }
    printf("%d\n",judge);
}

int main ( )
{
    int n,m;
    node *toot=new node ();
    char str[100];
    cin>>n;
    getchar( );
    while(n--)
    {
        gets(str);
        update(toot,str);
    }
    cin>>m;
    getchar( );
    while(m--)
    {
        gets(str);
        find(toot,str);
    }
    delete toot;
    return 0;
}
