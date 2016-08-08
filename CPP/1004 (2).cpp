#include<stdio.h>
int main()
{
    float a[12],s=0.0;
    for(int i=0;i<12;i++)
    {
        scanf("%f",&a[i]);
        s+=a[i];
    }
    printf("$%.2f\n",s/12);
    return 0;
}
