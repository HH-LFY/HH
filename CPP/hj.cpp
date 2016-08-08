#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI 3.141592653
using namespace std;

void fanzhuanhuan(char *str)
{
    char kstr[1000];
    int k = strlen(str);
    int p = 0;
    int i;
    int m = 1;
    for(i = k-1;i >= 0; --i,m++)
    {
        kstr[p++] = str[i];
        if(m%4 == 0) kstr[p++] = ',';
    }
    int q = 0;
    for(i = p-1;i >= 0; --i)
    {
        str[q++] = kstr[i];
    }
    str[p] = '\0';
}

int main( )
{
    char num[1000];
    scanf("%s",num);
    fanzhuanhuan(num);
    cout<<num<<endl;
    return 0;
}
