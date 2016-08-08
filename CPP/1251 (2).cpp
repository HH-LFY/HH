#include<stdio.h>
#include<string.h>
char a[200001][20],b[200],c;
int main()
{
    int k=0,i,j;
    for(i=0;i<20001;i++)
    {
        int o=0;
        for(j=0;j<20;j++)
        {
            scanf("%c",&c);
            a[i][j]=c;
            if(c==' ')o++;
            {
            if(a[i][j]=='\n') break;
            }
        }
        if(o==j){k=i;break;}
    }
    while(scanf("%s",b)!=EOF)
    {
        int p=strlen(b);
        int t=0;
        for(i=0;i<k;i++)
        {
            int q=0;
            for(j=0;j<p;j++)
            {
                if(a[i][j]==b[j])q++;
            }
            if(q==p) t++;
        }
        printf("%d\n",t);
    }
    return 0;
}
