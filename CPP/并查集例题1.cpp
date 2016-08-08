#include<stdio.h>
int pre[1000];
int find(int a)
{
    while(pre[a]!=a)
	{
	    pre[a]=find(pre[a]);
	}
	return pre[a];
}
void merge(int a,int b)
{
	int fa,fb;
	fa=find(a);
	fb=find(b);
    if(fa!=fb)
		pre[fa]=fb;
}
int main()
{
    int n,m,i,cout,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0) break;
		cout=0;
	    for(i=1;i<=n;i++)
			pre[i]=i;
		for(i=1;i<=m;i++)
		{
		    scanf("%d %d",&a,&b);
			merge(a,b);
		}
		for(i=1;i<=n;i++)
		{
		    if(pre[i]==i) cout++;
		}
		printf("%d\n",cout-1);
	}
	return 0;
}
