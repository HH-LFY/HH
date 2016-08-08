#include<cstdio>
#include<cstring>
char a[120000];
char b[200000];
int arry[130000];
int k;
int main()
{
    while(scanf("%s",a)!=EOF)
    {
        k=strlen(a);
        //printf("%d\n",k);
        int max=1;
        int count=1;
        b[0]='#';
        for(int i=0;i<k;i++)
        {
            b[count++]=a[i];
            b[count++]='#';
        }
      ///  for(int i=0;i<count;i++)
      ///      printf("%c",b[i]);
        for(int c=0;c<count;c++)
        {
            int result=1;
            for(int i=0;c-i>=0&&i+c<count;i++)
                {
                    if(b[c-i]!=b[c+i])break;
                    if(i>result) result=i;
                }
            if(max<result)max=result;
        }
        printf("%d\n",max);
        printf("\n");
    }
    return 0;
}
