#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int strStr(char *str, char *find)
{
    int len_y = strlen(str);///�����ĳ���
    int len_f = strlen(find);///ģʽ���ĳ���
    int next[26] = { 0 };///��ƥ�䲻�ɹ���ʱ��ģʽ�������ƶ��ľ��룬ÿ����ĸ��Ӧһ������
    for (int i = 0; i < 26; i++)
    {
        next[i] = len_f + 1;///Ĭ��Ϊģʽ���ĳ���+1
    }
    for (int i = 0; i < len_f; i++)
    {
        next[find[i] - 'a'] = len_f - i;///����ÿ���ַ���ģʽ���е�λ���޸��ƶ��ľ���
    }
    int index = 0;
    while (index <= (len_y - len_f))///��ʼƥ��
    {
        int i = index;
        int j;
        for (j = 0; j < len_f; i++, j++)
        {
            if (str[i] != find[j])///����ô�ƥ�䲻�ɹ�
            {
                if ((index + len_f) >= len_y)///������б���Ϊ�˷�ֹ�ƶ�������ȣ���������Խ��
                    return -1;
                index += next[str[index + len_f] - 'a'];///��������ƥ����ұ��Ǹ��ַ���Ӧnext�������е�λ�ã�ģʽ�������ƶ���
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
