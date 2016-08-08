#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef __int64 LL;
LL l,r;
int t;

bool check(LL x)
{
    LL t=x;
    int sum1=0;
    int sum2=0;
    int p=0;
    while(x)
    {
        if(p%2==0)
        {
            sum1=sum1+x%10;
        }
        else
        {
            sum2=sum2+x%10;
        }
        x/=10;
        p++;
    }
    if((sum1-sum2)==3 && t%11!=3)
        return true;
    if((sum1-sum2)!=3 && t%11==3)
        return true;

    return false;
}

int main( )
{
    cin>>t;
        while(t--)
        {
            scanf("%I64d%I64d",&l,&r);
            int judge=0;
            LL i;
            LL R;
            for(i=l; i<=r; i++)
            {
                if(check(i))
                {
                    judge=1;
                    R=i;
                    break;
                }
            }
            if(judge)
            {
                printf("%I64d\n",R);
            }
            else
            {
                cout<<"-1"<<endl;
            }
        }
    return 0;
}
