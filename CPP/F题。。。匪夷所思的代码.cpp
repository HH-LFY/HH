#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxx=100000+10;
int a[maxx];
int t,n;
int s,e,p;

int main( )
{
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        int kmax=0;
        while(n--)
        {
            scanf("%d%d%d",&s,&e,&p);
            a[s]+=p;
            a[e]-=p;
            kmax=max(kmax,e);
        }
        int sum=0,result=0;
        for(int i = 1;i <= kmax;i++)
        {
            sum+=a[i];
            result=max(result,sum);
        }
        cout<<result<<endl;
    }
    return 0;
}
