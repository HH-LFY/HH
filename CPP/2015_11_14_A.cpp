#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int sunday(char *str, char *find)
{
    int len_h = strlen(str);//�����ĳ���
    int len_n = strlen(find);//ģʽ���ĳ���
    int next[26] = { 0 };//��ƥ�䲻�ɹ���ʱ��ģʽ�������ƶ��ľ��룬ÿ����ĸ��Ӧһ������
    for (int i = 0; i < 26; i++)
    {
        next[i] = len_n + 1;//Ĭ��Ϊģʽ���ĳ���+1
    }
    for (int i = 0; i < len_n; i++)
    {
        next[find[i] - 'a'] = len_n - i;//����ÿ���ַ���ģʽ���е�λ���޸��ƶ��ľ���
    }
    int index = 0;
    while (index <= (len_h - len_n))//��ʼƥ��
    {
        int i = index;
        int j;
        for (j = 0; j < len_n; i++, j++)
        {
            if (str[i] != find[j])//����ô�ƥ�䲻�ɹ�
            {
                if ((index + len_n) >= len_h)//������б���Ϊ�˷�ֹ�ƶ�������ȣ���������Խ��
                    return -1;
                index += next[str[index + len_n] - 'a'];//��������ƥ����ұ��Ǹ��ַ���Ӧnext�������е�λ�ã�ģʽ�������ƶ���
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
