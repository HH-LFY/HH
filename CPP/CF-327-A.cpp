#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double l;
double a,b;

int main( ){
    cin>>l>>a>>b;
    double t = (l/(a+b));
    printf("%.5f\n",t*a);
    return 0;
}
