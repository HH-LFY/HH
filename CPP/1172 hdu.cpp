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
#define maxx 110

int main( )
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int flag=0;
        int kmap[maxx*100];
        int c[maxx],b[maxx];
        int a[maxx];
        if(n==0) break;
        for(int i=0;i < n; ++i)
        {
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
            //cout<<a[i]<<b[i]<<c[i]<<endl;
        }
        int k;
        for(k = 1000;k <= 9999; ++k)
        {
            int judge = 1;
            for(int i = 0;i < n; ++i)
            {
                int m = a[i];
                int p = k;
                int t1=0;
                int t2=0;
                int km[4] ,kp[4];
                for(int j = 0;j < 4; ++j)
                {
                    int m1 = m%10;
                    m = m/10;
                    km[j] = m1;
                    int k1 = p%10;
                    p = p/10;
                    kp[j] = k1;
                    if(m1==k1) t2++;
                }
              //  cout<<" a[i] :"<<a[i]<<endl;
                if(t2!=c[i])
                {
                 //   cout<<" t2 :"<<t2<<endl;
                    judge = 0;
                    break;
                }
                for(int j = 0;j < 4; ++j)
                {
                    for(int l = 0;l < 4; ++l)
                    {
                        if(km[l]==kp[j]&&km[l]!=-1)
                        {
                           // cout<<kp[j]<<endl;
                            t1++;
                            km[l]=-1;
                            break;
                        }
                    }
                }
                /*
                for(int j = 0;j < 4; ++j)
                    cout<<"km[j]: "<<j<<" "<<km[j]<<endl;
                    */
                if(t1!=b[i])
                {
                 //   cout<<" t1 :"<<t1<<endl;
                    judge = 0;
                    break;
                }
            }
            if(judge)
            {
                kmap[flag++] = k;
            }
        }
        k++;
        if(flag!=1)
        {
            printf("Not sure\n");
        }
        else
        {
            printf("%d\n",kmap[0]);
        }
    }
    return 0;
}
