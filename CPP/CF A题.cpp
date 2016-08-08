#include<iostream>
using namespace std;

int main()
{
    int n,m,minn,maxx;
    while(cin>>n>>m>>minn>>maxx)
    {
        int t;
        int min=10000,max=0;
        for(int i = 1;i <= m;i++)
        {
            cin>>t;
            if(min>t)
            {
                min=t;
            }
            else if(max<t)
            {
                max=t;
            }
        }
        if(n==2&&m==2&&min==minn&&max==maxx)
        {
            cout<<"Correct"<<endl;
        }
        else if(n==2&&m==1&&(min==minn||max==maxx))
        {
            cout<<"Correct"<<endl;
        }
        else if(n==1&&min==minn&&max==maxx&&minn==maxx)
        {
            cout<<"Correct"<<endl;
        }
        else if(n>2&&m>=1&&m<=n&&min>=minn&&max<=maxx)
        {
            cout<<"Correct"<<endl;
        }
        else
        {
            cout<<"Incorrect"<<endl;
        }
    }
    return 0;
}
