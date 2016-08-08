#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxx 10100
int map[maxx];
int vis[maxx];
int cnt,ss;

int find(int x)
{
    int p = x;
    while(p!=map[p])
    {
        p=map[p];
    }
    return p;
}

void join(int x,int y)
{
    int kx = find(x);
    int ky = find(y);
    if(kx!=ky)
        map[kx]=ky;
    else
    {
        map[x] = kx;
        map[y] = ky;
    }
}

int judge()
{
    int judge = 1;
    int kk = find(map[ss]);
    for(int i = 1; i < cnt; i++)
    if(find(map[vis[i]])!=kk) {judge = 0; break;}
    if(judge) return 1;
    else return 0;
}

int main( )
{
    int a,b;
    int k = 1;
    while(cin>>a>>b)
    {
        if(a<0&&b<0) break;
        else
        {
            for(int i = 1; i < maxx; i++)
            {
                map[i] = i;
            }
            vis[1] = a;
            vis[2] = b;
            ss = a;
            cnt = 3;
            map[a] = a;
            map[b] = a;
            int x,y;
            while(cin>>x>>y)
            {

                if(x==0&&y==0)
                {
                      if(judge())
                        printf("Case %d is a tree.\n",k++);
                      else
                        printf("Case %d is not a tree.\n",k++);
                }
                else
                {
                    vis[cnt++] = x;
                    vis[cnt++] = y;
                    join(x,y);
                }
            }
        }
    }
    return 0;
}
