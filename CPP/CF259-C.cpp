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
#include <bits/stdc++.h>
using namespace std;

int main( )
{
    double m,n;
    cin>>m>>n;
    double sum=0;
    for(int i=1 ;i <= m; i++)
    {
        sum=sum+i*(pow(i*1.0/m,n)-pow((i-1)*1.0/m,n));
    }
    printf("%.12f\n",sum);
    return 0;
}
