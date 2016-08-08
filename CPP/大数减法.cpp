#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1000;
char a[maxn], b[maxn], s[maxn];

void sub(char a[],char b[],char s[])
{
    int i, k1, k2, k;
    k1 = strlen(a);
    k2 = strlen(b);
    s[k1] = '\0';
    k1--;
    for(i = k2 - 1;i >= 0;--i , --k1)
    {
        if(a[k1] - b[i] >= 0)
        {
            s[k1] = a[k1] - b[i] + '0';
        }
        else
        {
            s[k1] = 10 + a[k1] - b[i] + '0';
            a[k1 - 1] = b[k1 - 1] - 1;
        }
    }
    k = k1;
    while(a[k] < 0)
    {
        a[k] += 10;
        a[k-1] -= 1;
        k--;
    }
    while(k1 >= 0)
    {
        s[k1] = a[k1];
        k1--;
    }
    loop:
        if(s[0] == '0')
        {
            k1 = strlen(a);
            for(i = 0;i < k1 - 1; ++i)
            {
                s[i] = s[i + 1];
            }
            s[k1 - 1] = '\0';
            goto loop;
        }
        if(strlen(s) == 0)
        {
            s[0] = '0';
            s[1] = '\0';
        }
}

int main( )
{
    cin>>a>>b;
    sub(a,b,s);
    cout<<s<<endl;
    return 0;
}
