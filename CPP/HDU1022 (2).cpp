#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

const int maxx=1010;

int main()
{
    stack<char>s;
    int n;
    int i,j,k;
    int result[maxx];
    char str1[maxx],str2[maxx];
    while(cin>>n>>str1>>str2)
    {
        i=0;
        j=0;
        k=1;
        s.push(str1[0]);
        result[0]=1;
        while(i<n&&j<n)
        {
            if(s.size()&&s.top()==str2[j])
            {
                j++;
                result[k++]=0;
                s.pop();
            }
            else
            {
                if(i==n)break;
                s.push(str1[++i]);
                result[k++]=1;
            }
        }
        if(i==n)
            cout<<"No."<<endl;
        else
        {
            cout<<"Yes."<<endl;
            for(i=0;i<k;i++)
                if(result[i])
                cout<<"in"<<endl;
                else
                cout<<"out"<<endl;
        }
        cout<<"FINISH"<<endl;
    }
    return 0;
}
