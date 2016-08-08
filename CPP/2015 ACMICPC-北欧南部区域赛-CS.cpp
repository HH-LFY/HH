#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 1e4 + 10;
map<string,queue<int> > p;
map<string,queue<int> >::iterator it;
int n;
char str[maxn*2][110];

const char kstr[]="@bmail.com";
int kp;

void put_in(char ss[],int kx){
    int judge = 1;
    int kq = kp-1;
    for(int i = strlen(ss)-1;kq >= 0 && i >= 0; --i,kq--){
        char kc=ss[i];
        if(kc >= 'A' && kc <= 'Z') kc = kc - 'A' + 'a';
        if(kc != kstr[kq]){
            judge = 0;
            break;
        }
    }
    char kss[110];
    if(judge){
        int kss_len = 0;
        int kjudge = 0;
        int kjudge2 = 0;
        for(int i = 0;i < strlen(ss); ++i){
            if(ss[i] == '@'){
                kss[kss_len++] = '@';
                kjudge = 0;
                kjudge2 = 1;
                continue;
            }else if(kjudge){
                continue;
            }
            if(ss[i] == '+'){
                kjudge=1;
            }else if(ss[i]>='A' && ss[i]<='Z'){
                kss[kss_len++] = ss[i]-'A'+'a';
            }else if(ss[i] == '.'){
                if(kjudge2 == 0) continue;
                else if(kjudge2 == 1){
                    kss[kss_len++] = ss[i];
                }
            }else{
                kss[kss_len++] = ss[i];
            }
        }
        kss[kss_len] = '\0';
    }else{
        int kss_len = 0;
        for(int i = 0;i < strlen(ss); ++i){
            if(ss[i]>='A'&&ss[i]<='Z'){
                kss[kss_len++] = ss[i]-'A'+'a';
            }else{
                kss[kss_len++] = ss[i];
            }
        }
        kss[kss_len] = '\0';
    }
    p[kss].push(kx);
    ///cout<<kss<<endl;
}

void show(){
    printf("%d\n",p.size());
    for(it = p.begin(); it != p.end(); ++it){
        printf("%d",(it->second).size());
        while(!(it->second).empty()){
            printf(" %s",str[(it->second).front()]);
            (it->second).pop();
        }
        printf("\n");
    }
}

int main( ){
    cin>>n;
    kp = strlen(kstr);
    for(int i = 1;i <= n; ++i){
        scanf("%s",str[i]);
        put_in(str[i],i);
    }
    show();
    return 0;
}
