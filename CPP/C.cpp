#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx=50000+10;
char str1[maxx];
char str2[maxx];
int next[maxx];

int main( )
{
    while(scanf("%s%s",str1,str2)!=EOF)
    {
        int judge=0;
        int i,j,k;
        i=0;
        next[0]=-1;
        j=-1;
        while(1)
        {
            if(j==-1||str1[i]==str2[j])
            {
                i++;
                j++;
                if(str2[j]=='\0')
                {
                    judge=1;
                    break;
                }
                next[i]=j;
            }
            else
            {
                j=next[j];
            }
            if(str1[i]=='\0')
            {
                break;
            }
        }
        if(judge)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
