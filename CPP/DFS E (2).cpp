#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

int i,j,k,n,t;
char str[20];
int sum;
int p[20];

bool judge()
{
    stack<char>s;
    i=1;
    if(str[0]=='(')
        s.push(str[0]);
    else return 0;
    while(i<k)
    {
        if(str[i]==')'&&s.empty())
            return 0;
        else if(str[i]==')')
        {
            s.pop();
            i++;
        }
        else if(str[i]=='(')
        {
            s.push(str[i]);
            i++;
        }
    }
    if(s.empty()) return 1;
    else return 0;
}

void dfs(int n)
{
    if(n==t)
    {
        if(judge())
        sum++;
        return ;
    }
    str[p[n]]='(';
    dfs(n+1);
    str[p[n]]=')';
    dfs(n+1);
}

int main()
{
    while(cin>>str)
    {
        sum=0;
        k=strlen(str);
        t=0;
 ///       for(i=0;i<k;i++)
 ///           cout<<str[i];
 ///       cout<<endl;
        for(i=0;i<k;i++)
            if(str[i]=='?')p[t++]=i;
        dfs(0);
        printf("%d\n",sum);
    }
    return 0;
}
