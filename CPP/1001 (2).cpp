#include<stdio.h>
#include<string.h>
#include<math.h>
char a[201],b[201],c[201],d[250];
char m='+',n='=';
int main()
{
    char t='|';
    scanf("%s",d);
    int k=strlen(d),p=0,x1=0,x2=0,x3=0;
    for(int i=0;i<k;i++)
    {
        if(d[i]=='|'&&p==0){a[x1]=d[i];x1++;}
        if(d[i]=='|'&&p==1){b[x2]=d[i];x2++;}
        if(d[i]=='|'&&p==2){c[x3]=d[i];x3++;}
        if(d[i]=='+')p=1;
        if(d[i]=='=')p=2;
    }
    if((x1+x2+x3)%2==1)printf("Impossible\n");
    else
    {
        if((x1+x2-x3)==0||fabs(x1+x2-x3)==2)
        {
            if((x1+x2)>x3)
                {
                    if(x1>1)
                    {
                        x1--;
                        c[x3]=t;
                        x3++;
                    }
                    else
                    {
                        x2--;
                        c[x3]=t;
                        x3++;
                    }
                }
            else if((x1+x2)<x3)
            {
                    x3--;
                    a[x1]=t;
                    x1++;
            }
            if((x1+x2-x3)==0)
            {
                for(int i=0;i<x1;i++)
                    printf("%c",a[i]);
                printf("%c",m);
                for(int i=0;i<x2;i++)
                    printf("%c",b[i]);
                printf("%c",n);
                for(int i=0;i<x3;i++)
                    printf("%c",c[i]);
                printf("\n");
            }
        }
        else printf("Impossible\n");
    }
    return 0;
}
