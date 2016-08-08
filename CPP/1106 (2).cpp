#include<stdio.h>
#include<string.h>
#include<math.h>
char c[10201],s[1001][1001];
int ks(int *a,int i, int j)
{
int t,l=i,h=j,m;
   m=a[(i+j)/2];
  while (i<=j)
    {
      while (a[i]<m) i=i+1;
      while (a[j]>m) j=j-1;
      if (i<=j)
       { t=a[i]; a[i]=a[j]; a[j]=t; i=i+1; j=j-1;}
    }
  if(i<h) ks(a,i,h);
  if(l<j) ks(a,l,j);
  return 0;
}
int m(int y)
{
    int b=1;
    for(int i=1;i<y;i++)
        b=b*10;
    return b;
}
int ff(char x[1010])
{
    int y=0;
    int l=strlen(x);
    for(int i=0;;i++)
    {
        if(x[i]=='\0')break;
        y=y+(m(l-i)*(x[i]-'0'));
    }
    return y;
}
int main()
{
    int a[1010];
    while(scanf("%s",c)!=EOF)
    {
        memset(s,0,sizeof(s));
        int k=0;
        int p=strlen(c);
        int t=0;
        if(c[0]=='5')k--;
        for(int i=t;i<p;i++)
        {
            if(c[i]!='5'){s[k][t]=c[i];t++;}
            else if(c[i]=='5')
            {
                k++;
                t=0;
                if(c[i+1]=='5')
                for(;;i++)
                    if(c[i]!='5') {i--;break;}
            }
        }
        if(c[p-1]!='5')k++;
        //printf("%d\n",k);
        //for(int i=0;i<k;i++)
            //printf("%s %d ",s[i],strlen(s[i]));
        //printf("\n");
        for(int i=0;i<k;i++)
        {
            a[i]=ff(s[i]);
            //printf("%d",a[i]);
        }
        ks(a,0,k-1);
        for(int i=0;i<k;i++)
        {
            if(i==k-1)printf("%d\n",a[i]);
            else printf("%d ",a[i]);
        }
    }
    return 0;
}
