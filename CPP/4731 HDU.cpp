#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define PI 3.1415926
using namespace std;

int t;
int m , n;
char str[9] ={"aababb"};

int main( )
{
   /// freopen("in.txt","r",stdin);
   /// freopen("out2.txt","w",stdout);
    int cas = 1;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&m, &n);
        printf("Case #%d: ",cas++);
        if(m == 1)
        {
            for(int i = 0;i < n; ++i)
                printf("a");
            printf("\n");
        }
        else if(m == 2)
        {
            if(n == 1)
            {
                printf("a\n");
            }
            else if(n == 2)
            {
                printf("ab\n");
            }
            else if(n == 3)
            {
                printf("aab\n");
            }
            else if(n == 4)
            {
                printf("aabb\n");
            }
            else if(n == 5)
            {
                printf("aaaba\n");
            }
            else if(n == 6)
            {
                printf("aaabab\n");
            }
            else if(n == 7)
            {
                printf("aaababb\n");
            }
            else if(n == 8)
            {
                printf("aaababbb\n");
            }
            else if(n == 9)
            {
                printf("aaaababba\n");
            }
            else if(n == 10)
            {
                printf("aaaababbaa\n");
            }
            else if(n == 11)
            {
                printf("aaaababbaaa\n");
            }
            else if(n == 12)
            {
                printf("aaaababbaaaa\n");
            }
            else if(n == 13)
            {
                printf("aaaababbaabab\n");
            }
            else if(n == 14)
            {
                printf("aaaababbaababb\n");
            }
            else if(n == 15)
            {
                printf("aaaababbaababba\n");
            }
            ///aaaaababbbaaababbbaaababb
            ///aaaaababbbaaababbbaaababb
            else
            {
                /***
                printf("a");
                n = n - 2;
                int k = n / 8;
                int kx = n - k*8;
                for(int i = 0; i < k; ++i)
                    printf("%s",str);
                for(int i = 0; i < kx; ++i)
                    printf("%c",str[i]);
                printf("\n");
                */
                printf("aa");
                int num=(n-2)/6;
                for(int i=0; i<num; i++)
                    printf("%s",str);
                int res=(n-2)%6;
                if(res<=4)
                    for(int i=0; i<res; i++)
                        printf("a");
                else if(res==5)
                    printf("aabab");
                printf("\n");
            }
        }
        else
        {/*
            int k = n/3;
            int km = n%3;
            char kstr[4] = "abc";
            for(int i = 0;i < km; ++i)
            {
                printf("%c",kstr[i]);
            }
            for(int i = 0;i < k; ++i)
            {
                printf("%s",kstr);
            }
           */
            for(int i=0;i<n;i++)
                printf("%c",'a'+i%3);
            printf("\n");
        }
    }
    return 0;
}
