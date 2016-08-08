#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[11][11];
int n,si,sj;
int kma;

bool judgee(int si,int sj)
{
    int i,j,kco;
    kco=0;
    for(i=si-1; i >=1; i--)
    {
        if(map[i][sj]!=0)
        {
            kco++;
            if(map[i][sj]==1&&kco==1)
            {
                return 1;
            }
            if(map[i][sj]==2&&kco==2)
            {
                return 1;
            }
        }
    }
    kco=0;
    for(i = si+1;i <= 10; i++)
    {
        if(map[i][sj]!=0)
        {
          kco++;
            if(map[i][sj]==1&&kco==1)
            {
                return 1;
            }
            if(map[i][sj]==2&&kco==2)
            {
                return 1;
            }
        }
    }
    kco=0;
    for(i=sj-1; i >=1; i--)
    {
        if(map[si][i]!=0)
        {
            kco++;
            if(map[si][i]==1&&kco==1)
            {
                return 1;
            }
            if(map[si][i]==2&&kco==2)
            {
                return 1;
            }
        }
    }
    kco=0;
    for(i = sj+1;i <= 10; i++)
    {
        if(map[si][i]!=0)
        {
          kco++;
            if(map[si][i]==1&&kco==1)
            {
                return 1;
            }
            if(map[si][i]==2&&kco==2)
            {
                return 1;
            }
        }
    }
    if(kma)
    {
        if((map[si-1][sj+2]==3||map[si-2][sj+1]==3)&&map[si-1][sj+1]==0)
            return 1;
        if((map[si-1][sj-2]==3||map[si-2][sj-1]==3)&&map[si-1][sj-1]==0)
            return 1;
        if((map[si+1][sj+2]==3||map[si+2][sj+1]==3)&&map[si+1][sj+1]==0)
            return 1;
        if((map[si+2][sj-1]==3||map[si+1][sj-2]==3)&&map[si+1][sj-1]==0)
            return 1;
    }
    return 0;
}


int main( )
{
    while(cin>>n>>si>>sj)
    {
        if(n==0&&si==0&&sj==0) break;
        memset(map,0,sizeof(map));
        kma=0;
        char str[10];
        int x,y;
        for(int i = 1;i <= n; i++)
        {
            scanf("%s%d%d",str,&x,&y);
            if(str[0]=='G'||str[0]=='R') map[x][y]=1;
            if(str[0]=='C') map[x][y]=2;
            if(str[0]=='H') {map[x][y]=3;kma++;}
        }

        if(sj-1>=4)
        {
            if(judgee(si,sj-1)==0)
            {
                cout<<"NO"<<endl;
                continue;
            }
        }

        if(si+1<=3)
        {
            if(judgee(si+1,sj)==0)
            {
                cout<<"NO"<<endl;
                continue;
            }
        }

        if(si-1>=1)
        {
            if(judgee(si-1,sj)==0)
            {
                cout<<"NO"<<endl;
                continue;
            }
        }

        if(sj+1<=6)
        {
            if(judgee(si,sj+1)==0)
            {
                cout<<"NO"<<endl;
                continue;
            }
        }
        cout<<"YES"<<endl;
    }
    return 0;
}
