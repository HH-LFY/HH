#include<iostream>
#include<cstdio>
#define inf 9999999
using namespace std;

void show(int m[][10],int n)
{
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            if(m[i][j] == inf) printf("     # ");
            else printf("%6d ",m[i][j]);
        }
        puts("");
    }
}

int MatrixChainOrder(int p[], int n)
{
    int m[10][10];
    int i, j, k, L, q;
    for(i = 1; i < n; i++)
        for(j = 1;j < n; j++)
            m[i][j] =inf;
    for(i = 1; i < n; i++)
            m[i][i] = 0;
    for(L=2; L<n; L++)
    {
        for(i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            for(k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                m[i][j] = min(q,m[i][j]);
            }
        }
    }
    show(m,n);
    return m[1][n-1];
}

int main()
{
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("最小乘的次数为 %d ",MatrixChainOrder(arr, size));

    getchar();
    return 0;
}
