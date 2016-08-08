#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int strStr(char *str, char *find)
{
    int len_y = strlen(str);///主串的长度
    int len_f = strlen(find);///模式串的长度
    int next[26] = { 0 };///当匹配不成功的时候，模式串向右移动的距离，每个字母对应一个距离
    for (int i = 0; i < 26; i++)
    {
        next[i] = len_f + 1;///默认为模式串的长度+1
    }
    for (int i = 0; i < len_f; i++)
    {
        next[find[i] - 'a'] = len_f - i;///根据每个字符在模式串中的位置修改移动的距离
    }
    int index = 0;
    while (index <= (len_y - len_f))///开始匹配
    {
        int i = index;
        int j;
        for (j = 0; j < len_f; i++, j++)
        {
            if (str[i] != find[j])///如果该次匹配不成功
            {
                if ((index + len_f) >= len_y)///这里的判别是为了防止移动距离过度，导致数组越界
                    return -1;
                index += next[str[index + len_f] - 'a'];///根据主串匹配的右边那个字符对应next的数组中的位置，模式串向右移动。
                break;
            }
        }
        if (j == len_f)
        {
            return index;
        }
    }
    return -1;
}
int sunday(char *str,char *find)
{
    int len_s = strlen(str);
    int len_f = strlen(find);
    int next[26];
    for(int i = 0; i < 26; ++i) next[i] = len_f + 1;
    for(int i = 0; i < len_f; ++i) next[find[i]-'a'] = len_f - i;
    int now = 0;
    while(now<=(len_s-len_f))
    {
        int i = now, j;
        for(j = 0; j < len_f; ++j,++i)
        {
            if(str[i] != find[j])
            {
                if((now+len_f)>=len_s) return -1;
                now += next[str[now+len_f]-'a'];
                break;
            }
        }
        if(j == len_f) return now;
    }
    return -1;
}

int main( )
{
    return 0;
}
