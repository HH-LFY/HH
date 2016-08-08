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

typedef __int64 LL;
LL m1 , m2;
LL r1 , r2, r3;

int main( )
{
    while(scanf("%I64d%I64d",&m1,&m2)!=EOF)
    {
        char str[250];
        scanf("%s",str);
        int i = 0;
        r1 = r2 = r3 = 0;
        while(str[i]!='\0')
        {
            if(str[i] == 'A')
            {
                r1 = m1;
              //  m1 = 0;
            }
            else if(str[i]=='B')
            {
                r2 = m2;
              //  m2 = 0;
            }
            else if(str[i] == 'C')
            {
                m1 = r3;
              //  r3 = 0;
            }
            else if(str[i] == 'D')
            {
                m2 = r3;
               // r3 = 0;
            }
            else if(str[i] == 'E')
            {
                r3 = r1+r2;
            }
            else if(str[i] == 'F')
            {
                r3 = r1-r2;
            }
          //  printf("%c :m1= %I64d,m2= %I64d ,r1= %I64d,r2= %I64d,r3= %I64d\n",str[i],m1,m2,r1,r2,r3);
            i++;
        }
        printf("%I64d,%I64d\n",m1,m2);
    }
    return 0;
}
