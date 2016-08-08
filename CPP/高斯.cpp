#include<stdio.h>
#include<math.h>
#define N 4
static double aa[N][N+1]={{1,-1,1,-4,-2},{5,-4,3,12,-6},{2,1,1,11,3},{2,-1,7,-1,-7}};
double a[N+1][N+2],x[N+1];

void putout( )
{
    for(int i=1;i<=N ;i++)
    {
        for(int j=1;j<=N+1;j++)
            printf("%15g",a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int gauss()
{
    int i,j,k,r;
    double c;
    putout();
    for(k=1;k<=N-1;k++)
    {
        if(fabs(a[k][k])<1e-17)
        {
            printf("\n pivot element is 0.   fail!  \n");return(0);}
            for(i=k+1;i<=N;i++)
            {
                c=a[i][k]/a[k][k];
                for(j=k;j<=N+1;j++)
                {
                    a[i][j]=a[i][j]-c*a[k][j];}
            }
            putout();
    }
    if(fabs(a[k][k])<1e-17)
        {printf("\n pivot element is 0.   fail!  \n");return(0);}
    for(k=N;k>=1;k--)
    {
        x[k]=a[k][N+1];
        for(j=k+1;j<=N;j++)
        {
            x[k]=x[k]-a[k][j]*x[j];}
            x[k]=x[k]/a[k][k];
    }
    return (1);
}

int main()
{
    int i,j,det;
    for(i=1;i<=N;i++)
    for(j=1;j<=N+1;j++)
    a[i][j]=aa[i-1][j-1];
    det=gauss();
	printf("\t");
    if(det!=0)
        for(i=1;i<=N;i++)
            printf("     x[%d]=%g",i,x[i]);
	printf("\n");
	return 0;
}
