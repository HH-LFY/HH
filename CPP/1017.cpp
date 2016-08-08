#include<stdio.h>
int main()
{
    double p,n,m;
    int i,j,k,t,q,l;
    scanf("%d",&t);
    l=t;
    while(t--)
    {
        k=1;
        while(scanf("%lf%lf",&n,&m)!=EOF)
        {
        if(n==0&&m==0)break;
        q=0;
        for(i=1;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                p=(i*i+j*j+m)/(i*j);
                if((int)p==p) q++;
            }
        }
        printf("Case %d: %d\n",k++,q);
        }
        if(t)printf("\n");
    }
    return 0;
}
