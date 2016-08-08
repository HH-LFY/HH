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
#include <strstream>
#define PI 3.141592653
using namespace std;

char str[1000];
int a[1000];
int k;

int main( )
{
    gets(str);
    istrstream ks(str);
    k = 0;
    while(ks)
    {
        ks>>a[k++];
    }
    for(int i = 0;i < k - 1; ++i)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
