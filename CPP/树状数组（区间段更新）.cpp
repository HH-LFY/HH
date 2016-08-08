#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
const int maxn=110000;
int s[maxn];
int n,m;
int lowbit(int n)
{
    return n&(-n);
}
void add(int i,int val)
{
    while(i<maxn)
    {
        s[i]=s[i]+val;
  ///      cout<<i<<":"<<s[i]<<endl;
        i=i+lowbit(i);
    }
 ///   cout<<endl;
}
int Sum(int n)
{
    int sum=0;
    while(n>0)
    {
        sum+=s[n];
        cout<<n<<"_n:"<<s[n]<<" _sum:"<<sum<<endl;
        n=n-lowbit(n);
    }
    cout<<endl;
    return sum;
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b,c;
        memset(s,0,sizeof(s));
        scanf("%d",&n);
        int l=1000000,r=-100;
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            l=min(l,a);
            r=max(r,b);
            add(a,c);
            add(b,-c);
        }
        int ans=-100;
      for(i=l;i<=r;i++)
      {
   ///       cout<<i<<":"<<s[i]<<endl;
         ans=max(ans,Sum(i));
      }
  ///    cout<<ans<<endl;
    }
    return 0;
}
