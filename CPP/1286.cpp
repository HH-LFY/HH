#include<stdio.h>
#include<math.h>
#define f 50000
int s[f];
void ss()
{
	int i,j,n,m,s1,s2,a,b;
	s[1]=2;
	s[2]=3;
	m=2;
	for(i=6;i<f;i=i+6)
	{
		a=i-1;
		b=i+1;
		s1=1;
		s2=1;
		n=(int)sqrt(m);
		for(j=1;j<=n+1;j++)
			if(a%s[j]==0){s1=0;break;}
		for(j=1;j<=n+1;j++)
			if(b%s[j]==0){s2=0;break;}
		if(s1!=0){m++;s[m]=a;}
		if(s2!=0){m++;s[m]=b;}
	}
}
double rs(int n)
{
    double t=n;
    for(int i=1;s[i]<=n;i++)
    {
        if(n%s[i]==0)t=t*(s[i]-1)/s[i];
    }
    return t;
}
int main()
{
    int n,t;
    scanf("%d",&t);
    ss();
    while(t--)
    {
        scanf("%d",&n);
        if(n==1) {printf("0\n");continue;}
        printf("%.0lf\n",rs(n));
    }
    return 0;
}
