#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/**
简要分析：
    L:光标左移，假如已经在最左边则不动
    R:光标右移动，假如已经在右边则不动
    S:切换模式，先是插入模式，后是覆盖模式
    D:删除右边, 或者删除位置C-D
    B:删除左边
    C:复制位置C-C。且两个CC之间不能够存在除L,R以外的字符
    V:粘贴
*/

const int maxx = 10000 + 10;
char s[maxx*2];
char str[maxx*2];
char kstr[maxx*2];
int m;
int p, kp, cur, now;
int T;

void input(char kc,bool judge){

    if(judge == true){ ///覆盖模式
        if(cur>=m) return;
        str[cur++] = kc;
        if(p<cur) p = cur;
    }else{ ///插入模式
        if(p>=m) return ;
        for(int i = p;i > cur; --i){
            str[i] = str[i-1];
        }
        p++;
        str[cur++] = kc;
    }
}

void move_L(){
    if(cur - 1 >= 0) cur--;
}

void move_R(){
    if(cur < p)  cur++;
}

void del1(){
    if(cur-1>=0){
        for(int i = cur-1;i < p-1; ++i){
            str[i] = str[i+1];
        }
        p--;
        cur--;
    }
}

void del2(int judge_c){
    if(judge_c > 0){
        if(now > cur){
            int mn = now - cur;
            for(int i = cur;i < p - mn; ++i){
                str[i] = str[i+mn];
            }
            p = p-mn;
        }else if(now < cur){
            int mn = cur - now;
            for(int i = now;i < p-mn; ++i){
                str[i] = str[i+mn];
            }
            p = p-mn;
            cur = now;
        }
    }
    else{
        if(cur < p){
            for(int i = cur;i < p-1; ++i){
                str[i] = str[i+1];
            }
            p--;
        }
    }
}

void copy_v(bool judge){
    for(int i = 0;i < kp; ++i){
        input(kstr[i],judge);
    }
}

void copy_c(){
    if(now > cur){
        kp = 0;
        for(int i = cur;i < now; ++i){
            kstr[kp++] = str[i];
        }
    }else if(now < cur){
        kp = 0;
        for(int i = now;i < cur; ++i){
            kstr[kp++] = str[i];
        }
    }else{
        kp = 0;
    }
}

int main( ){
    cin>>T;
    while(T--){
        scanf("%d%s",&m,s);
        kstr[0] = '\0';
        str[0]='\0';
        p = 0;
        kp = 0;
        cur = 0;
        bool judge = false;
        int judge_c = 0; ///NOTHING
        now = 0;
        for(int i = 0; s[i] != '\0' ; ++i){
            if(s[i]>='a'&&s[i]<='z'){
                input(s[i],judge);
                judge_c = 0;
            }else{
                if(s[i] == 'B'){
                    del1();
                    judge_c = 0;
                }else if(s[i] == 'D'){
                    del2(judge_c);
                    judge_c = 0;
                }else if(s[i] == 'C'){
                    if(judge_c == 0){
                        now = cur;
                        judge_c++;///start
                    }else{
                        copy_c();
                        judge_c=0;
                    }
                }else if(s[i] == 'V'){
                    copy_v(judge);
                    judge_c = 0;
                }else if(s[i] == 'L'){
                    move_L();
                }else if(s[i] == 'R'){
                    move_R();
                }else if(s[i] == 'S'){
                    judge = !judge;
                    judge_c = 0;
                }
            }
        }
        str[p] = '\0';
        if(p != 0)printf("%s\n",str);
        else printf("NOTHING\n");
    }
    return 0;
}
