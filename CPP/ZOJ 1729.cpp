#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxx = 100000 + 10;
char s[maxx*2];///����Ҫ������
int min_str( )///�����ֵ�����С���ַ���λ��(�±��0��ʼ)
{
    int les = strlen(s);
    for(int i = 0;i < les; ++i){///s�ӱ�
        s[i+les] = s[i];
    }
    les = 2*les;
    s[les] = '\0';
    int i=0,j=1,k=0;
    while (1) {
        if(i+k>=les||j+k>=les) break ; ///��������
        if(s[i+k]==s[j+k]) k++;  ///���ʱ����
        else {
            if(s[i+k]>s[j+k]) i+=k+1; ///��Ҫ��Ϊ����ʾ�����޸ı��д��ں�
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
