#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <ostream>
#include <string>
#include <cstdlib>
using namespace std;

long long n,k;
char c;
long long a_word[26];

int cmd(long long x,long long y)
{
    return x>y;
}

int main( )
{
    cin>>n>>k;
    memset(a_word,0,sizeof(a_word));
    getchar();
    while((c=getchar())!='\n')
    {
        int p=c-'A';
        a_word[p]++;
    }
    sort(a_word,a_word+26,cmd);
    long long sum=0;
    for(int i = 0;i < 26; ++i)
    {
        if(k-a_word[i]>=0)
        {
            sum+=a_word[i]*a_word[i];
            k-=a_word[i];
        }
        else
        {
            sum+=k*k;
            break;
        }
    }
    cout<<sum<<endl;
    return 0;
}
