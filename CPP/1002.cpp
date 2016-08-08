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
const int  inf =  (1<<30) - 10;
using namespace std;

map<string,bool> p;
int T;
int n;
int a[11];

int ok(int id,int num,int kis[]){
    if(num == 1){
        if(id == 2 || id == 4 || id == 5 || id == 8 || id == 6)
            return 1;
        else if(id == 3 && kis[2])
            return 1;
        else if(id == 7 && kis[4])
            return 1;
        else if(id == 9 && kis[5])
            return 1;
        else return 0;
    }
    else if(num == 2){
        if(id == 1 || id == 3 || id == 4 || id == 5 || id == 6|| id == 7 || id == 9)
            return 1;
        else if(id == 8 && kis[5])
            return 1;
        else return 0;
    }
    else if(num == 3){
        if(id == 2 || id == 4 || id == 5 || id == 8 || id == 6)
            return 1;
        else if(id == 1 && kis[2])
            return 1;
        else if(id == 7 && kis[5])
            return 1;
        else if(id == 9 && kis[6])
            return 1;
        else return 0;
    }
    else if(num == 4){
        if(id == 1 || id == 3 || id == 2 || id == 5 || id == 8|| id == 7 || id == 9)
            return 1;
        else if(id == 6 && kis[5])
            return 1;
        else return 0;
    }
    else if(num == 5){
        return 1;
    }
    else if(num == 6){
        if(id == 1 || id == 3 || id == 2 || id == 5 || id == 8|| id == 7 || id == 9)
            return 1;
        else if(id == 4 && kis[5])
            return 1;
        else return 0;
    }
    else if(num == 7){
        if(id == 2 || id == 4 || id == 5 || id == 8 || id == 6)
            return 1;
        else if(id == 1 && kis[4])
            return 1;
        else if(id == 3 && kis[5])
            return 1;
        else if(id == 9 && kis[8])
            return 1;
        else return 0;
    }
    else if(num == 8){
        if(id == 1 || id == 3 || id == 4 || id == 5 || id == 6|| id == 7 || id == 9)
            return 1;
        else if(id == 2 && kis[5])
            return 1;
        else return 0;
    }
    else if(num == 9){
        if(id == 2 || id == 4 || id == 5 || id == 8 || id == 6)
            return 1;
        else if(id == 1 && kis[5])
            return 1;
        else if(id == 7 && kis[8])
            return 1;
        else if(id == 3 && kis[6])
            return 1;
        else return 0;
    }
}

void dfs(string str,int kis[],int num){
    for(int i = 0;i < n; ++i){
        int id = a[i];
        if(kis[id] == 0 && ok(id,num,kis)){
                char ch[2];
                ch[0] = id + '0';
                string kstr = str + ch;
                if(kstr.length() == n){
                    p[kstr] = 1;
                    return ;
                }
                kis[id] = 1;
                dfs(kstr, kis, id);
                kis[id] = 0;
        }
    }
}

int main()
{

    cin>>T;
    while(T--){
        if(p.size()) p.clear();
        scanf("%d",&n);
        for(int i = 0;i < n; ++i){
            scanf("%d",&a[i]);
        }
        sort(a, a + n);
        int kis[11];
        memset(kis,0,sizeof(kis));
        for(int i = 0;i < n; ++i){
            char ch[2];
            ch[0] = a[i] + '0';
            string str = ch;
            kis[a[i]] = 1;
            dfs(str,kis,a[i]);
            kis[a[i]] = 0;
        }
        cout<<p.size()<<endl;
        map<string,bool>::iterator q;
        for(q = p.begin(); q != p.end(); ++q){
                string  ans = (*q).first;
                for(int i = 0;i < ans.length() - 1; ++i)
                    printf("%c ",ans[i]);
                printf("%c\n",ans[ans.length()-1]);
        }
    }
    return 0;
}
