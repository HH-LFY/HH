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
#define PI 3.141592653
using namespace std;

struct fruit
{
    string str;
    string ds;
    int count;
};

int cmd(fruit a,fruit b)
{
    if(a.ds!=b.ds)
        return a.ds<b.ds;
    else
        return a.str<b.str;
}

int main( )
{
    int n;
    cin>>n;
    while(n--)
    {
        fruit a[100];
        int m;
        cin>>m;
        int i,j;
        for(i = 0;i < m; ++i)
        {
            a[i].count = 0;
            a[i].str = "";
        }
        string s1,s2;
        int p = 0,x;
        for(i = 0;i < m; ++i)
        {
            cin>>s1>>s2>>x;
           // cout<<s1<<" "<<s2<<" "<<x<<endl;
            int judge = 0;
            for(j = 0; j < p; ++j)
            {
                if(s2==a[j].ds&&s1==a[j].str)
                {
                    a[j].count += x;
                    judge = 1;
                    break;
                }
            }
            if(judge==0)
            {
                a[p].str = s1;
                a[p].ds = s2;
                a[p++].count +=x;
            }
        }
        sort(a,a+p,cmd);
        for(i = 0;i < p; ++i)
        {
            int k = i;
            cout<<a[i].ds<<endl;
         //   cout<<"   |----"<<a[i].str<<"("<<a[i].count<<")"<<endl;

            for(j = i; j < p; ++j)
            {
                if(a[j].ds==a[i].ds)
                {
                    cout<<"   |----"<<a[j].str<<"("<<a[j].count<<")"<<endl;
                }
                else
                    break;
                k++;
            }
            i = k - 1;
        }
        if(n) cout<<endl;
    }
    return 0;
}
