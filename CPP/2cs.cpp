#include<stdio.h>
#include<math.h>
#define f(x)   ((x*x-2)*x-1)
#define eps 0.0001
#define x1  0
#define x2  2
main()
{
	double a,b,y,x;
	int k=0;
	a=x1;b=x2;
	if(f(a)*f(b)>0)
    {
        printf("在此区间内无解！\n");
        return 0;
    }
	y=f(a);
	x=0.5*(a+b);
	printf("k\tx\t\tf(x)\t\ta\t\tb\t\t \n");
	printf("%d\t%f\t%f\t%f\t%f\t\n",k,x,f(x),a,b);
	while (fabs(b-a)>eps)
	{
		if (y*f(x)<0) b=x;
		else a=x;
		x=0.5*(a+b);
		k++;
		printf("%d\t%f\t%f\t%f\t%f\t\n",k,x,f(x),a,b);
	}
	printf("\nThe Root is x=%f\n",x);
}
