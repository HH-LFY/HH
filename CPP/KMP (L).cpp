#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str1[10000+10];
char str2[1000000+11];
int next[1000000+10];
int n;

int find( )
{
    int sum=0;
    int i=0;
    int j=-1;
    next[0]=-1;
    while(str1[i]!='\0') // build_next[]
    {
        if(j==-1||str1[i]==str1[j])
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
    i=0;
    j=0;
    while(str2[i]!='\0')// find()
    {
        if(str2[i]==str1[j])
        {
            i++;
            j++;
            if(str1[j]=='\0')
            {
                sum++;
            }
        }
        else if(j==-1)
        {
            i++;
            j=0;
        }
        else
        {
            j=next[j];
        }
    }
    return sum;
}

int main( )
{
    cin>>n;
    getchar( );
    while(n--)
    {
        gets(str1);
        gets(str2);
        /*
        for(int i = 0;str1[i]!='\0';i++)
        {
            cout<<i<<"->:"<<next[i]<<endl;
        }
        */
        cout<<find()<<endl;
    }
    return 0;
}
