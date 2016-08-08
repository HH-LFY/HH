#include<stdio.h>
#include<math.h>
int main()
{
    __int64 a,b,t;
    while(~scanf("%I64d%I64d",&a,&b))
    {
        double x=(1+sqrt(5.0))/2;
        if(a>b)
        {
            t=a;
            a=b;
            b=t;
        }
        __int64 k=b-a;
        if(a==(int)(k*x))printf("0\n");
        else printf("1\n");
    }
    return 0;
}
