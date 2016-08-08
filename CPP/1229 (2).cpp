#include<stdio.h>
#include<math.h>
int main()
{
    __int64 a,b,k,a1,b1,a2,b2;
    while(scanf("%I64d%I64d%I64d",&a,&b,&k)!=EOF)
    {
        if(a==0&&b==0)break;
        a2=b2=0;
        a1=a;
        b1=b;
        for(int i=1;i<=k;i++)
        {
            a2+=(a%10)*(pow(10,i-1));
            b2+=(b%10)*(pow(10,i-1));
            a/=10;
            b/=10;
        }
        if(a2==b2)printf("-1\n");
        else printf("%I64d\n",a1+b1);
    }
    return 0;
}
