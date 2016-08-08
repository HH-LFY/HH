#include<iostream>
#include<cstdio>
#include<cstring>
#define N 60
using namespace std;
int main()
{
 ///   freopen("cout","w",stdout);
    int h[101][2*N+1],i,j,k,l,n;
    memset(h,0,sizeof(h));
    h[0][1]=1;h[1][1]=1;
    for(i=2;i<=100;i++)///用I表示第I个卡特兰数，用J储存第I个卡特兰数的第J位
    {
        for(j=0;j<i;j++)
            for(k=1;k<N;k++)
                for(l=1;l<N;l++)
        h[i][k+l-1]+=h[j][k]*h[i-j-1][l];
        for(j=1;j<N;j++)
        {
            h[i][j+1]+=h[i][j]/10;
            h[i][j]%=10;
        }
    }
    while(cin>>n)
    {
        i=N;
        while(h[n][--i]==0);
        for(j=i;j>0;j--)cout<<h[n][j];
        cout<<endl;
    }
    return 0;
}
