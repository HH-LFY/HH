#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int arry[15];
int n,m;

void dfs()
{
    int a[15];
    do
    {
    for(int j = 0; j < n-1; j++)
    for(int i = 1; i <= n-j; i++)
    {
       if(j==0) a[i]=arry[i]+arry[i+1];
       else a[i] = a[i] + a[i+1];
    }
    if(a[1]==m){ break;}
    }while(next_permutation(arry+1,arry+n+1));
}

int main( )
{
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        arry[i]=i;
    dfs();
    for(int i = 1; i < n; i++)
        cout<<arry[i]<<" ";
    cout<<arry[n]<<endl;
    return 0;
}
