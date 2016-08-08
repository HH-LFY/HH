#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

int main()
{
    int n, m;
    int judge;
    while(cin>>n>>m)
    {
        judge = 1;
        for(int i = 1;i <= n; ++i)
        {
            if(i%2)
            {
                for(int j = 1;j <= m; ++j)
                {
                    printf("#");
                }
            }
            else
            {
                if(judge)
                {
                    judge = !judge;
                    for(int j = 1;j < m; ++j)
                    {
                        printf(".");
                    }
                    printf("#");
                }
                else
                {
                    judge = !judge;
                    printf("#");
                    for(int j = 1;j < m; ++j)
                    {
                        printf(".");
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
