#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

const int maxx = 600000 + 10;
char str[maxx];
struct node
{
    int isleaf;
    node *next[3];
    node()
    {
        isleaf = 0;
        for(int i = 0;i < 3; ++i)
            next[i] = NULL;
    }
};
node root;

void buildTree(node *p,int i)
{
    if(str[i] == '\0')
    {
        p->isleaf = 1;
        return ;
    }
    if(p->next[str[i] - 'a'] == NULL)
    {
        p->next[str[i] - 'a'] = new node();
    }
    buildTree(p->next[str[i] - 'a'], i + 1);
}

int dfs(node *p,int i,int num)
{
    if(num > 1)
        return 0;
    if(str[i] == '\0' && p->isleaf == 1 && num == 1)
        return 1;
    if(str[i] == '\0')
        return 0;
    int x = str[i] - 'a';
    for(int j = 0;j < 3; ++j)
    {
        if(p->next[j] != NULL)
        {
            if(j == x)
            {
                if(dfs(p->next[j],i + 1, num))
                {
                    return 1;
                }
            }
            else
            {
                if(dfs(p->next[j],i + 1, num + 1))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int n, m;

    cin>>n>>m;
    for(int i = 0;i < n; ++i)
    {
        scanf("%s",str);
        buildTree(&root,0);
    }
    for(int i = 0;i < m; ++i)
    {
        scanf("%s",str);
        int judge = dfs(&root,0,0);
        if(judge)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
