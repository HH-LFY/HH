#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int a[100006];
int gys(int a,int b)
{
    if(b==0)return a;
    return gys(b,a%b);
}
int main()
{
    int m,n;
    cin>>n;
    while(n--)
    {
        int k;
        cin>>m>>k;
        for(int i=1;i<m;i++)
        {
        cin>>a[i];
        k=k/gys(k,a[i])*a[i];
        }
        cout<<k<<endl;
    }
    return 0;
}
