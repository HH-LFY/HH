#include<stdio.h>
#include<math.h>
int main()
{
    __int64 n,m;
    while(scanf("%I64d",&n)!=EOF)
    {
        m=0;
        if(n%2==0) {printf("2^? mod %I64d = 1\n",n);continue;}
        __int64 p=2;
        for(int i=1;i<=5000;i++)
        {
            if(p%n==1){m=i;break;}
            else p=(p%n)*2;
        }
        if(m)printf("2^%I64d mod %I64d = 1\n",m,n);
        else printf("2^? mod %I64d = 1\n",n);
    }
    return 0;
}
