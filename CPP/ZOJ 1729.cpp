#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxx = 100000 + 10;
char s[maxx*2];///数据要开两倍
int min_str( )///返回字典序最小的字符的位置(下标从0开始)
{
    int les = strlen(s);
    for(int i = 0;i < les; ++i){///s加倍
        s[i+les] = s[i];
    }
    les = 2*les;
    s[les] = '\0';
    int i=0,j=1,k=0;
    while (1) {
        if(i+k>=les||j+k>=les) break ; ///跳出条件
        if(s[i+k]==s[j+k]) k++;  ///相等时自增
        else {
            if(s[i+k]>s[j+k]) i+=k+1; ///想要改为最大表示法则修改本行大于号
            else j+=k+1;
            k=0;
            if (i==j) j++;
        }
    }
    return min(i,j);
}


int main( ){
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%s",s);
        ///printf("%d %s",n,s);
        printf("%d\n",min_str()+1);
    }
    return 0;
}
