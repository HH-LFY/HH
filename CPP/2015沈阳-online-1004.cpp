#include<stdio.h>
#include<math.h>
#define f 100000
int main()
{
	int i,j,n,m,s[f],s1,s2,a,b;
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
	long long ans = 1;
	for(i=1;i<=13;i++)
		ans = ans *s[i];
    printf("%lld\n",(ans-1)%13);
	return 0;
}
