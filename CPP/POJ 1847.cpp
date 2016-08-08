#include<iostream>
using namespace std;
#define INF 5000000
int tu[500][500];
int n,m,k,i,j;
void Floyd(int x,int y)
{
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(tu[i][j]>tu[i][k]+tu[k][j])
                {
                    tu[i][j]=tu[i][k]+tu[k][j];
                }
    if(tu[x][y]==INF)
        cout<<-1<<endl;
    else
        cout<<tu[x][y]<<endl;
}
int main()
{
    int A,B,n,i,j,c,x;
    while(cin>>n>>A>>B)
    {
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                if(i==j)
                    tu[i][j]=0;
                else
                    tu[i][j]=INF;
            }
        for(i=1; i<=n; i++)
        {
            cin>>c;
            for(j=0; j<c; j++)
            {
                cin>>x;
                if(j==0)
                    tu[i][x]=0;
                else
                    tu[i][x]=1;
            }
        }
        Floyd(A,B);
    }
    return 0;
}
