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

int main( )
{
    int x,y;
    int kmin;
    int n;
    int sum=0;
    int judge=0;
    cin>>n;
    cin>>kmin;
    x=kmin;
    n--;
    while(n--)
    {
        cin>>y;
        if(x>y)
        {
            judge++;
            sum++;
        }
        if(judge==1&&x<=y)
        {
            sum++;
        }
        x=y;
    }
    if(judge>=2||(x>kmin&&judge==1))
    {
        cout<<"-1"<<endl;
    }
    else
    {
        cout<<sum<<endl;
    }
    return 0;
}
