#include<stdio.h>
#include<string.h>
#include<math.h>
int a[1001][3];
double b[1001];
char s[100][1000];
char s1[1001];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        int m=0,q=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            getchar();
            scanf("%s%d%d",s[i],&a[i][1],&a[i][2]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int k,p;
                if(a[i][1]>=a[j][1])
                {
                    k=a[i][1];a[i][1]=a[j][1];a[j][1]=k;
                    p=a[i][2];a[i][2]=a[j][2];a[j][2]=p;
                    strcpy(s1,s[i]);
                    strcpy(s[i],s[j]);
                    strcpy(s[j],s1);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            m=m+a[i][2];
            if(m>=a[i][1]) q=q+m-a[i][1];
        }
        printf("%d\n",q);
        for(int i=1;i<n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(a[i][1]==a[j][1])
                {
                    if(strcmp(s[i],s[j])>0)
                    {
                        strcpy(s1,s[i]);
                        strcpy(s[i],s[j]);
                        strcpy(s[j],s1);
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
            printf("%s\n",s[i]);
    }
    return 0;
}
