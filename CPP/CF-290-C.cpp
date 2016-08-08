#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <sstream>
#define PI acos(-1.0)
const int  inf =  (1<<30) - 10;
using namespace std;

int n;
string str[1100];
int kmap[1100][1100];
int num[1100];
int ans[1100];

int scompare(string a,string b)
{
    int ka = a.length();
    int kb = b.length();
    if(!b.compare(a.substr(0,kb))) return 0;
    ///当被比较字符串小于参数字符串时，返回负数
    ///相等时 0
    ///大于时 正整数
    else if(!a.compare(b.substr(0,ka))) return -1;
    else return 1;
}

int init()
{
    for(int i = 0;i < n - 1; ++i)
    {
        int judge = scompare(str[i],str[i + 1]);
        if(!judge)
            return 0;
        else if(judge == 1)
        {
            int ka = str[i].length();
            for(int j = 0;j < ka; ++j)
            {
                if(str[i][j] != str[i + 1][j])
                {
                    int x = str[i][j] - 'a';
                    int y = str[i+1][j] - 'a';
                    if(!kmap[x][y])
                    {
                        kmap[x][y] = 1;
                        num[y]++;
                    }
                    break;
                }
            }
        }
    }
    return 1;
}

void toposort()
{
    int p = 0;
    for(int i = 0;i < 26; ++i)
    {
        int x = -1;
        for(int j = 0;j < 26; ++j)
        {
            if(num[j] == 0)
            {
                num[j] = -1;
                x = j;
                break;
            }
        }
        if(x == -1)
        {
            break;
        }
        ans[p++] = x;
        for(int j = 0;j < 26; ++j)
        {
            if(kmap[x][j] == 1)
            {
                kmap[x][j] = 0;
                num[j]--;
            }
        }
    }
    if(p < 26)
    {
        cout<<"Impossible"<<endl;
    }
    else
    {
        for(int i = 0;i < p; ++i)
        {
            printf("%c",ans[i] + 'a');
        }
        cout<<endl;
    }
}

int main()
{
    cin>>n;
    memset(kmap,0,sizeof(kmap));
    memset(num,0,sizeof(num));
    memset(ans,0,sizeof(ans));
    for(int i = 0;i < n; ++i)
    {
        cin>>str[i];
    }
    if(!init())
    {
        cout<<"Impossible"<<endl;
    }
    else
    {
        toposort();
    }
    return 0;
}
