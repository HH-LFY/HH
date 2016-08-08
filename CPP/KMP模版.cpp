#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxx=400000+11;
char str[maxx];
int next[maxx];
int i,j;
int k;// str.length

void build_next( )
{
    i=0;
    next[0]=-1;
    j=-1;
    while(i<k)
    {
        if(j==-1||str[i]==str[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
}

int main( )
{
    while(scanf("%s",str)!=EOF)
    {
        k= strlen(str);
        build_next();
        int p=0;
        int pp[maxx];
        for(i = k;next[i]!=-1;i=next[i])
        {
            pp[p++]=i;
        }
        for(i = p-1;i>0;i--)
        {
            cout<<pp[i]<<" ";
        }
        cout<<pp[0]<<endl;
    }
    return 0;
}
