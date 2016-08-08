#include<stdio.h>
#include<math.h>
int pow3(int x,int y)
{
    int result=1;
    while(y>0)
    {
        if(y&1)
            {result*=x;}
        x*=x;
        y/=2;
    }
    return result;
}
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
        printf("%d %lf\n",pow3(a,b),pow(a,b));
    return 0;
}
