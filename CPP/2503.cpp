#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n,s;
int a,b,c,d;
int t,k;
int gcb(int x,int y)
{
    if(!x)return y;
    else return gcb(y%x,x);
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        m=b*d;
        n=a*d+b*c;
        for(k=m;;k--)
        {
            if(m%k==0&&n%k==0)
            {
                m/=k;
                n/=k;
                break;
            }
        }
       // s=gcb(m,n);
        cout<<n<<" "<<m<<endl;
    }
    return 0;
}
