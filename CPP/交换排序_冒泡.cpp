#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI 3.141592653
using namespace std;

int i, j;

void show(int a[],int n)
{
    for(i = 0;i < n; ++i)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void swapsort(int a[],int n)
{
    for(i = 0;i < n; ++i)
    {
        for(j = i + 1;j < n; ++j)
        {
            if(a[i] > a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}



int main( )
{
    int n;
    int a[100];
    cin>>n;
    for(i = 0;i < n; ++i)
    {
        scanf("%d",&a[i]);
    }
    swapsort(a,n);
    show(a,n);
    return 0;
}
