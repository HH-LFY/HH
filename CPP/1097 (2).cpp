#include<stdio.h>
__int64 s[10000];
int main()
{
    __int64 a,b;
    while(~scanf("%I64d%I64d",&a,&b))
    {
        s[1]=a%10;
        s[2]=a*a%10;
        s[3]=s[2]*a%10;
        s[0]=s[3]*a%10;
        int p=b%4;
        printf("%I64d\n",s[p]);
    }
    return 0;
}
