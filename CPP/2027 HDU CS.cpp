#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,aa,ee,ii,oo,uu,l;
	scanf("%d",&n);
	getchar();
	   while(n--)
	   {
	       char str[105];
		   aa=ee=ii=oo=uu=0;
	       gets(str);
		   l=strlen(str);
		   for(i=0;i<l;i++)
		   {
		       if(str[i]=='a') aa++;
			   if(str[i]=='e') ee++;
			   if(str[i]=='i') ii++;
			   if(str[i]=='o') oo++;
			   if(str[i]=='u') uu++;
		   }
		   printf("a:%d\n",aa);
		   printf("e:%d\n",ee);
		   printf("i:%d\n",ii);
		   printf("o:%d\n",oo);
		   printf("u:%d\n",uu);
		   if(n) printf("\n");
	   }
	return 0;
}
