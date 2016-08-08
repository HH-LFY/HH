#include <stdio.h>
#include <math.h>
#define f(x) x-(x*x*x-x-1)/(3*x*x-1)
const int maxx = 1000;
const double p = 0.5E-5;

int main( )
{
	int i;
	double x = 1.5;
	double d = 1.5;
	printf("\t次数\tx\n");
	for(i = 0;i <= maxx; ++i)
	{
		printf("\t%d\t%f\n",i,x);
		x = f(d);
		if(fabs(x-d) < p)
		{
			printf("\t答 案 是: %f       迭代次数:%d\n",x,i);
			return 0;
		}
		if(x&&fabs(x - d)/fabs(x) < p )
		{
			printf("\t答 案 是: %f       迭代次数:%d\n",x,i);
			return 0;
		}
		d = x;
	}
	printf("After %d repeate ,no solved.\n",maxx);
	return 0;
}
