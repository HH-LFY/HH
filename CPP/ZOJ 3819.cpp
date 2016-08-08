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
#include <queue>
#include <stack>
#include <set>
#include <map>
#define PI 3.141592653
using namespace std;

const int inf = 999999;;
int kmax, kmin;
int Asum, Bsum;
int n, m;
int T;

int judge(int x)
{
    double s1 = Asum;
    double s2 = Bsum;
    double ks1 = (s1+x)/n;
    double ks2 = s2/m;
    double ksum1 = s1/(n-1);
    double ksum2 = (s2+x)/(m+1);
    if(ks1 < ksum1&&ks2 < ksum2)
    {
    //  cout<<"ksum1:"<<ksum1<<endl;
    //   cout<<"ksum2:"<<ksum2<<endl;
    //    system("pause");
        return 1;
    }
    return 0;
}

int main( )
{
    cin>>T;
    while(T--)
    {
        int x;
        kmin = inf;
        kmax = -inf;
        Asum = Bsum = 0;
        scanf("%d%d",&n ,&m);
        int i , j;
        for(i = 1;i <= n-1; ++i)
        {
            scanf("%d",&x);
            Asum += x;
        }
        for(i = 1;i <= m; ++i)
        {
            scanf("%d",&x);
            Bsum += x;
        }
        //int count = 0;
        for(i = 0;i <= 100; ++i)
        {
            if(judge(i))
            {
              //  cout<<i<<endl;
                kmax = max(kmax,i);
                kmin = min(kmin,i);
                /*
                if(!count)
                {
                    kmin = min(kmin,i);
                    kmax = max(kmax,i);
                    count++;
                }
                else
                {
                    kmax = max(kmax,i);
                }
                */
            }
        }
        cout<<kmin<<" "<<kmax<<endl;
    }
    return 0;
}
