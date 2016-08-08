#include <iostream>
#include <algorithm>
using namespace std;

int main( )
{
    int n;
    while(cin>>n)
    {
        int a[10010];
        for(int i = 0; i < n; i++)
            cin>>a[i];
        sort(a,a+n);
        if(n%2)
        {
            cout<<a[n-1]<<" ";
            for(int i = 0,j = n - 2; j!=n/2 -1 ; i++,j--)
        {
            if(j!=n/2)
                cout<<a[i]<<" "<<a[j]<<" ";
            else
                cout<<a[i]<<" "<<a[j];
        }
        }
        else
        {
            for(int i = 0,j = n - 1; j!=n/2 -1  ; i++,j--)
        {
            if(j!=n/2)
                cout<<a[j]<<" "<<a[i]<<" ";
            else
                cout<<a[j]<<" "<<a[i];

        }
        }
        cout<<endl;
    }
    return 0;
}
