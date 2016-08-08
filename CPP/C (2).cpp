#include <iostream>
#include <cstring>
using namespace std;

int t,n;
int a[100001],vis[100001];
int sum,k,i,j,result;

int main( )
{
    while(cin>>n)
    {
        sum = 0;
        for(i = 1; i <= n; i++)
        {
            cin>>a[i];
            vis[i] = 1;
        }
        for(i = 1; i <= n; i++)
        {
            result = 0;
            k = 1;
            if(a[i]>1)
            {
                for(j = 1; j <= n; j++)
                {
                    if(a[i]==a[j]&&i!=j) { k++; a[j] = 1; vis[j]++; vis[i]++;}
                    else if(a[i]>a[j]&&(a[i]%a[j]!=0)) result += vis[j];
                }
            }
            sum = sum + result*k;
        }
        cout<<sum<<endl;
    }
    return 0;
}
