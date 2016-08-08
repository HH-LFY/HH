#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int mod=10000;

int n;

struct matrix
{
    int m[2][2];
}sum;

matrix md(matrix a,matrix b)
{
    matrix t;
    int i,j,k;
    for(i=0;i < 2; i++)
    {
        for(j=0;j < 2; j++)
        {
            t.m[i][j]=0;
            for(k = 0; k < 2; k++)
            {
                t.m[i][j]=(t.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
            }
        }
    }
    return t;
}

int fast_mod(int n)
{
    matrix t;
    sum.m[0][0]=sum.m[0][1]=sum.m[1][0]=1;
    sum.m[1][1]=0;
    t.m[0][0]=t.m[1][1]=1;
    t.m[1][0]=t.m[0][1]=0;

    while(n)
    {
        if(n%2==1)
        {
            t=md(t,sum);
        }
        sum=md(sum,sum);
        n=n/2;
    }
    return t.m[0][1];
}

int main( )
{
    while(cin>>n)
    {
        if(n==-1) break;
        cout<<fast_mod(n)<<endl;
    }
    return 0;
}
