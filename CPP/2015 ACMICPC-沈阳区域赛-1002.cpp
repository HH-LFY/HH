#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int bm(const char *text, const char *find)
{
    if (text == '\0' || find == '\0')
        return -1;
    int i, j, k;
    int text_len = strlen(text);
    int find_len = strlen(find);
    if (text_len < find_len)
        return -1;
    int delta_1[CHAR_MAX];
    for (i=0; i<CHAR_MAX; i++)
        delta_1[i] = find_len;
    for (i=0; i<find_len; i++)
        delta_1[find[i]] = find_len - i - 1;
    int rpr[find_len];
    rpr[find_len-1] = find_len - 1;
    for (i=find_len-2; i>=0; i--)
    {
        int len = (find_len - 1) - i;
        //find the reoccurence of the right most (len) chars
        for (j=find_len-2; j>=(len-1); j--)
        {
            if (strncmp(find+i+1, find+j-len+1, len) == 0)
            {
                if ((j-len) == -1 || find[i] != find[j-len])
                {
                    rpr[i] = j - len + 1;
                    break;
                }
            }
        }
        for (k=1; j<(len-1) && k<len; k++)
        {
            if (strncmp(find+i+k, find, len-k) == 0)
            {
                rpr[i] = 0 - k;
                break;
            }
        }
        if (j<(len-1) && k == len)
        {
            rpr[i] = 0 - len;
        }
    }
    int delta_2[find_len];
    for (i=0; i<find_len; i++)
        delta_2[i] = find_len - rpr[i];
    i = find_len - 1;
    j = find_len - 1;
    while (i < text_len)
    {
        if (text[i] == find[j])
        {
            i--;
            j--;
        }
        else
        {
            if (delta_1[text[i]] > delta_2[j])
            {
                i += delta_1[text[i]];
            }
            else
            {
                i += delta_2[j];
            }
            j = find_len - 1;
        }
        if (j == -1)
            return i+1;
    }

    return -1;
}

int kmp(const char *text, const char *find)
{
    if (text == '\0' || find == '\0')
        return -1;
    int find_len = strlen(find);
    int text_len = strlen(text);
    if (text_len < find_len)
        return -1;
    int map[find_len];
    memset(map, 0, find_len*sizeof(int));
    //initial the kmp base array: map
    map[0] = 0;
    map[1] = 0;
    int i = 2;
    int j = 0;
    for (i=2; i<find_len; i++)
    {
        while (1)
        {
            if (find[i-1] == find[j])
            {
                j++;
                if (find[i] == find[j])
                {
                    map[i] = map[j];
                }
                else
                {
                    map[i] = j;
                }
                break;
            }
            else
            {
                if (j == 0)
                {
                    map[i] = 0;
                    break;
                }
                j = map[j];
            }
        }
    }
    i = 0;
    j = 0;
    for (i=0; i<text_len;)
    {
        if (text[i] == find[j])
        {
            i++;
            j++;
        }
        else
        {
            j = map[j];
            if (j == 0)
                i++;
        }
        if (j == (find_len))
            return i-j;
    }
    return -1;
}

const int maxx = 500 + 10;
char str[maxx][2010];
bool vis[maxx];
int n;

int main( ){
    int T;
    cin>>T;
    int count = 1;
    while(T--){
        scanf("%d",&n);
        for(int i = 0;i < n; ++i){
            scanf("%s",str[i]);
            vis[i] = 0;
        }
        int ans = -1;
        for(int i = 1;i < n; ++i){
            for(int j = i-1;j >= 0; --j){
                if(vis[j]) continue;
                if(strstr(str[i],str[j]) == NULL){
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
