#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx=200000+10;
char str1[maxx];
char str3[maxx];
char str2[maxx];


int main( )
{
    gets(str1);
    gets(str3);
    int k1=strlen(str1);
    int k2=strlen(str3);
    int p=0;
    for(int i = k2-1;i >= 0;i--)
    {
        str2[p]=str3[i];
        p++;
    }
    sprintf(str1,"%s%s",str1,str1);
    sprintf(str2,"%s%s",str2,str2);
    int r1;
    int r2;
    int judge=0;
    for(int i = 0;i < k2;i++)
    {
        for(int j = 0;j < k1;j++)
        {
            if(str2[i]==str1[j])
            {

                int m=1;
                int ki=i;
                r1=j+1;
                int kj=j;
                r2=2*k2-(i+k2)+1;
                while(1)
                {
                    if(str2[ki]!=str1[kj])
                    {
                        break;
                    }
                    if(m==k2)
                    {
                        judge=1;
                        break;
                    }
                    if(str2[ki]==str1[kj])
                    {
                        ki++;
                        kj++;
                        m++;
                    }
                }
            }
            if(judge)
                break;
        }
        if(judge)
            break;
    }
    if(judge)
    {
        printf("Yes\n");
        printf("%d %d\n",r1,r2);
    }
    else
    {
        printf("No\n");
    }
    return 0;
}
