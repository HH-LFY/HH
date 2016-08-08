#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int sunday(char *str, char *find)
{
    int len_h = strlen(str);//主串的长度
    int len_n = strlen(find);//模式串的长度
    int next[26] = { 0 };//当匹配不成功的时候，模式串向右移动的距离，每个字母对应一个距离
    for (int i = 0; i < 26; i++)
    {
        next[i] = len_n + 1;//默认为模式串的长度+1
    }
    for (int i = 0; i < len_n; i++)
    {
        next[find[i] - 'a'] = len_n - i;//根据每个字符在模式串中的位置修改移动的距离
    }
    int index = 0;
    while (index <= (len_h - len_n))//开始匹配
    {
        int i = index;
        int j;
        for (j = 0; j < len_n; i++, j++)
        {
            if (str[i] != find[j])//如果该次匹配不成功
            {
                if ((index + len_n) >= len_h)//这里的判别是为了防止移动距离过度，导致数组越界
                    return -1;
                index += next[str[index + len_n] - 'a'];//根据主串匹配的右边那个字符对应next的数组中的位置，模式串向右移动。
                break;
            }
        }
        if (j == len_n)
        {
            return index;
        }
    }
    return -1;
}

const int maxx = 500 + 10;
char kstr[maxx][2010];
bool vis[maxx];
int n;

int main( ){
    int T;
    cin>>T;
    int count = 1;
    while(T--){
        scanf("%d",&n);
        for(int i = 0;i < n; ++i){
            scanf("%s",kstr[i]);
            vis[i] = 0;
        }
        int ans = -1;
        for(int i = 1;i < n; ++i){
            for(int j = i-1;j >= 0; --j){
                if(vis[j]) continue;
                if(sunday(kstr[i],kstr[j]) == -1){
                    ans = i;
                }else{
                    vis[j] = 1;
                }
            }
        }
        printf("Case #%d: %d\n",count++,(ans+1)==0?-1:ans+1);
    }
    return 0;
}
