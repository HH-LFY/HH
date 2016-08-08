#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
char x,y;
char map[81][81];

int main( )
{
    int p=0;
    while(scanf("%d %c %c",&n,&x,&y)!=EOF)
    {
     //  getchar();
    if(p++) cout<<endl;
        int k1,k2;
        int judge = 1;
        for(k1=1,k2=n;k1!=k2;k1++,k2--)
        {
            for(int i=k1;i<=n-k1+1;i++)
            {
                if(judge%2)
                {
                    map[k1][i]=map[k2][i]=y;
                    map[i][k1]=map[i][k2]=y;
                }
                else
                {
                    map[k1][i]=map[k2][i]=x;
                    map[i][k2]=map[i][k1]=x;
                }
            }
            judge++;
        }
        if(judge%2)
        {
            map[k1][k2]=y;
        for(k1=1,k2=n;k1!=k2;k1++,k2--)
        {
            for(int i=k1;i<=n-k1+1;i++)
            {
                if(judge%2)
                {
                    map[k1][i]=map[k2][i]=x;
                    map[i][k1]=map[i][k2]=x;
                }
                else
                {
                    map[k1][i]=map[k2][i]=y;
                    map[i][k2]=map[i][k1]=y;
                }
            }
            judge++;
        }
        map[k1][k2]=x;
        }
        else
        {
            map[k1][k2]=x;
        }
        map[1][1]=' ';
        map[1][n]=' ';
        map[n][1]=' ';
        map[n][n]=' ';
        if(n==1)
            map[1][1]=x;
        for(int i = 1;i <= n; i++)
        {
            for(int j = 1;j <= n; j++)
            {
                cout<<map[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
