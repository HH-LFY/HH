#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI acos(-1.0)
using namespace std;

int T;
int N, M, C;
char x[2];
bool vis[26];
struct node
{
    int str[505];
    int len;
};

void show(node a)
{
    int i;
    for(i = 0; i < a.len; ++i)
    {
        if(a.str[i] <= 9)
        {
            printf("%d",a.str[i]);
        }
        else
        {
            printf("%c",a.str[i] - 10 + 'A');
        }

    }
    printf("\n");
}

int judge(node a)
{
    int flag = 0;
    int i;
    for(i = 0; i < a.len; ++i)
    {
        flag = (flag*C + a.str[i])%N;
    }
    return flag;
}

int BFS()
{
    node a;
    a.len = 0;
    bool kis[5100];
    queue<node> Q;
    int i, j;
    int k;
    for(i = 0; i < 5100; ++i)
    {
        kis[i] = false;
    }
    for(i = 1; i < 16; ++i)
    {
        if(vis[i])
        {
            a.str[0] = i;
            a.len = 1;
            k = judge(a);
            if(k==0)
            {
                show(a);
                return 1;
            }
            else
            {
                if(!kis[k])
                {
                    kis[k] = true;
                    Q.push(a);
                }
            }
        }
    }
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for(i = 0; i < 16; ++i)
        {
            if(vis[i])
            {
                a.str[a.len] = i;
                a.len++;
                k = judge(a);
                if(k==0)
                {
                    show(a);
                    return 1;
                }
                else
                {
                    if(!kis[k]&&a.len<=499)
                    {
                        kis[k] = true;
                        Q.push(a);
                    }
                }
                a.len--;
            }
        }
    }
    return 0;
}

int main( )
{
    cin>>T;
    while(T--)
    {
        scanf("%d%d%d",&N,&C,&M);
        int i, j;
        for(i = 0; i < 26; ++i)
        {
            vis[i] = false;
        }
        for(i = 0; i < M; ++i)
        {
            scanf("%s",x);
            if(x[0]>='0'&& x[0]<='9')
            {
                vis[x[0]-'0'] = true;
            }
            else
            {
                vis[x[0]-'A'+10] = true;
            }
        }
        if(N==0)
        {
            if(vis[0])
            {
                printf("0\n");
            }
            else
            {
                printf("give me the bomb please\n");
            }
        }
        else
        {
            int temp = BFS();
            if(temp == 0)
            {
                printf("give me the bomb please\n");
            }
        }
    }
    return 0;
}
