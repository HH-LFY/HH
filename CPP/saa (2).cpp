#include<stdio.h>
int main()
{
    void move(int *str,int n,int m);
	int a,b,c,string[20];
	scanf("%d%d",&a,&b);
	for(c=0;c<a;c++)
	{
	    scanf("%d",string[c]);
	}
	move(string,a,b);
	for(c=0;c<a;c++)
		printf("%d",string[c]);
	printf("\n");
	return 0;
}
void move(int *str,int n,int m)
{
    int *p,end;
	end=*str+n-1;
	for(p=str+n-1;p>*str;p--)
	    *p=*(p-1);
	*str=end;
	m--;
	if(m>0) move(*str,n,m);
}