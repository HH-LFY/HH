#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI 3.141592653
using namespace std;

const int maxx = 100;
int matrix[maxx][maxx];
int kis[maxx][maxx];
int result[maxx];
int a[maxx];
int b[maxx][maxx];
int vis[maxx] ;
int n;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool ok(int x)
{
    if(x>=0&&x<30)
        return true;
    return false;
}

void gauss(){
    for(int i=0;i<30;i++){
        int k=i;
        for(;k<30;k++)
            if(matrix[k][i]!=0)
                break;
        for(int j=0;j<=30;j++)
            swap(matrix[i][j],matrix[k][j]);
        for(int j=0;j<30;j++)
            if(i!=j&&matrix[j][i])
                for(int k=0;k<=30;k++)
                    matrix[j][k]=matrix[i][k]^matrix[j][k];
    }
    for(int j = 0;j < 30; ++j)
    {
        result[j] = matrix[j][30];
    }
}

void show(int x[])
{
    int i;
    for(i = 0;i < 30; ++i)
    {
        if(i%6==5)
        {
            printf("%d\n",x[i]);
        }
        else
        {
            printf("%d ",x[i]);
        }
    }
}

int main( )
{
    int i, j, k;
    cin>>n;
    int count = 1;
    int kx = 5;
    int ky = 6;
    memset(kis,0,sizeof(kis));
    for(int i=0; i<30; i++)
    {
        kis[i][i]=1;
        if(i%6!=0)
            kis[i-1][i]=1;
        if(i%6!=5)
            kis[i+1][i]=1;
        if(i>5)
            kis[i-6][i]=1;
        if(i<24)
            kis[i+6][i]=1;
    }
    while(n--)
    {
        for(i = 0;i < kx; ++i)
        {
            for(j =  0;j < ky; ++j)
            {
                scanf("%d",&b[i][j]);
                matrix[i*6 + j][30] = b[i][j];
            }
        }
        for(i = 0;i < 30; ++i)
        {
            for(j = 0;j < 30; ++j)
            {
                matrix[i][j] = kis[i][j];
            }
        }
        gauss( );
        printf("PUZZLE #%d\n",count++);
        show(result);
    }
    return 0;
}
