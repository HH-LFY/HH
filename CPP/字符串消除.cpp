#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

char ch;

int A(int pos, char *st)
{
    int ans;
    bool flag;
    int i, j;
    char str[103];
    bool vis[103];
    int len = strlen(st);

    for(i=0;i<pos;i++)
        str[i] = st[i];
    str[pos] = ch;
    for(i=pos+1;i<=len;i++)
        str[i] = st[i-1];
    flag = true;
    ans = 0;
    len++;
    while(flag == true){
        flag = false;
        memset(vis,false,sizeof(vis));
        for(i=0;i<len-1;i++)
        {
            while(i<len-1 && str[i] == str[i+1]){
                vis[i] = vis[i+1] = true;
                flag = true;
                i++;
            }
        }
        for(i=0;i<len;i++)
            if(vis[i] == true)
                ans++;
        j = 0;
        for(i=0;i<len;i++)
            if(vis[i] == false)
                str[j++] = str[i];
        len = j;
    }
    return ans;
}

int main()
{
    int len;
    int n, i, ans;
    char str[103];

    scanf("%d",&n);
    while(n--){
        scanf("%s",str);
        len = strlen(str);
        ans = 0;
        for(i=0;i<len;i++)
            for(ch='A';ch<='C';ch++)
                ans = max(ans,A(i,str));
        printf("%d\n",ans);
    }
    return 0;
}
