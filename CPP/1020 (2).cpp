#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char a[100001],b[100];
int t,c[100];
int main()
{
    cin>>t;
    while(t--)
    {
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        cin>>a;
        int k=strlen(a);
        for(int i=0;i<k;i++)
        {
            if(a[i]==0)continue;
            c[i]=1;
            for(int j=i+1;j<k;j++)
            {
                if(a[i]!=a[j])break;
                c[i]++;
                a[j]=0;
            }
        }
        for(int i=0;i<k;i++)
        {
            if(a[i]!=0)
            {
                if(c[i]==1)
                    cout<<a[i];
                else
                    cout<<c[i]<<a[i];
            }
        }
        cout<<endl;
    }
    return 0;
}
