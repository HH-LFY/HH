#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define f 0x6ffffff
int a[1000001],b[1000001],c[1000010];
int main()
{
    int n,t,k,m;
    while(scanf("%d",&n)!=EOF)
    {
        t=(n+1)/2;
        k=0;
        m=f;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
        {
            int p=0;
            if(a[i]==f)continue;
            for(int j=1;j<=n;j++)
            {
                if(a[i]==a[j])
                    {
                        p++;
                        if(i!=j) a[j]=f;
                    }
            }
            if(p>=t) {m=a[i];break;}
        }
        printf("%d\n",m);
    }
    return 0;
}
