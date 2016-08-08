#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;

int t;
int n;
char m[5];
int x;
char y[5];

int main()
{
    cin>>t;
    while(t--)
    {
        stack<int>s;
        queue<int>q;
        cin>>n>>m;
        {
            if(strcmp(m,"FILO")==0)
            {
                for(int i=0;i<n;i++)
                {
                    cin>>y;
                    if(strcmp(y,"IN")==0)
                    {
                        cin>>x;
                        s.push(x);
                    }
                    else
                    {
                        if(s.empty())
                            cout<<"None"<<endl;
                        else
                        {
                            cout<<s.top()<<endl;
                            s.pop();
                        }
                    }
                }
            }
            else if(strcmp(m,"FIFO")==0)
            {
                for(int i=0;i<n;i++)
                {
                    cin>>y;
                    if(strcmp(y,"IN")==0)
                    {
                        cin>>x;
                        q.push(x);
                    }
                    else
                    {
                        if(q.empty())
                            cout<<"None"<<endl;
                        else
                            {
                                cout<<q.front()<<endl;
                                q.pop();
                            }
                    }
                }
            }
        }
    }
    return 0;
}
