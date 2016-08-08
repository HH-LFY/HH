#include <cstdio>
#include <cmath>
#define f(x) pow(2 * x + 1, 1.0 / 3.0)
const int maxx = 1000;
const double p = 0.5E-5;
int main( )
{
	int i;
	double x = 2;
	double d = 2;
	printf("\t次数\tx\n");
	for(i = 0;i <= maxx; ++i)
	{
		printf("\t%d\t%f\n",i,x);
		x = f(x);
		if(fabs(x - d) < p)
		{
			printf("\t答 案 为: %f           次数:%d\n",x,i);
			return 0;
		}
		if(x&&fabs(x - d)/fabs(x) < p )
		{
			printf("\t答 案 为: %f           次数:%d\n",x,i);
			return 0;
		}
		d = x;
	}
	printf("After %d repeate ,no solved.\n",maxx);
	return 0;
}
