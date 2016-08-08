#include "stdio.h"
int main()
{
	int a[1001];
	int x,i,n;
	a[1]=1;
	a[2]=1;
		for(x=3;x<1001;x++)
		{
			a[x]=a[x-1]+a[x-2];
		}
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		do
		scanf("%d",&x);
		while(x>1000 || x<1);
		printf("%d\n",a[x]);
	}
	return 0;
}
