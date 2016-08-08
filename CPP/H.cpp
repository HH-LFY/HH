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
#include <vector>
#include <sstream>
#define PI acos(-1.0)
#define eps 1e-8
const int  inf =  (1<<30) - 10;
using namespace std;

int n;
long long x, y, z;
long long ans;
char str1[200];
char str2[200];
char str3[200];

long long get(char test[])
{
	long long sum=0;
	for(int i=0;i<strlen(test);i++)
	{
		sum = sum*10+(test[i]-'0');
	}
	return sum;
}


int main()
{
    while(cin>>n){
        while(n--){
            cin>>str1>>str2>>str3;
            if(str1[0] == '?'){
                y = get(str2);
                z = get(str3);
                ans = z/2 + y;
            }else if(str2[0] == '?'){
                x = get(str1);
                z = get(str3);
                ans = x - z/2;
            }else if(str3[0] == '?'){
                x = get(str1);
                y = get(str2);
                ans = (x - y)*2;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
