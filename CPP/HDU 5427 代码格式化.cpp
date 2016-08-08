#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxx = 1000 + 10;
int T;
char str[maxx];
char ans[maxx];
char op[] = "+-*/=!<>";  ///运算符
int p;  ///ans.sizeof()
int it; ///指向当前操作的ans位置
int space; ///how many space in start

void remove_space(){ ///移除空格
    int i = 0;
    p = 0;
    while(str[i]!='\0'){
        if(str[i]==' '){
            i++;
        }else if(str[i] == '\"'){
            ans[p++] = str[i++];
            while(str[i] != '\"'){
                if(str[i] == '\\') ans[p++] = str[i++];
                ans[p++] = str[i++];
            }
            ans[p++] = str[i++];
        }else if(str[i] == '\''){
            ans[p++] = str[i++];
            while(str[i] != '\''){
                if(str[i] == '\\') ans[p++] = str[i++];
                ans[p++] = str[i++];
            }
            ans[p++] = str[i++];
        }else if(p>0 && isalnum(ans[p-1]) && isalnum(str[i]) && str[i-1]==' '){
            ans[p++] = ' ';
            ans[p++] = str[i++];
        }else{
            ans[p++] = str[i++];
        }
    }
    ans[p] = '\0';
}

bool judge_operator(char x){ ///判断是否为运算符
    for(int i = 0;op[i] != '\0'; ++i) if(x == op[i]) return true;
    return false;
}

void newline(){
    if(ans[it]=='}') space-=2;
    puts("");
    for(int i = 0;i < space; ++i){
        putchar(' ');
    }
}

void printf_head(){ ///头部
    while(ans[it] == '#'){
        putchar(ans[it++]);
        while(ans[it] != '>'){
            if(ans[it] == '<')putchar(' ');
            putchar(ans[it++]);
        }
        putchar(ans[it++]);
        newline();
    }
}

void solve(){
    remove_space();
    ///printf("%s\n",ans);
    space = 0;
    it = 0;
    printf_head();
    if(it != 0) newline();
    int judge = 0; ///括号匹配
    while(ans[it] != '\0'){
        if(ans[it] == '('){
            judge++;
            putchar(ans[it++]);
        }else if(ans[it] == ')'){
            judge--;
            putchar(ans[it++]);
        }else if(ans[it] == '{'){
            newline();
            space+=2;
            putchar(ans[it++]);
            newline();
        }else if(ans[it] == '}'){
            putchar(ans[it++]);
            newline();
        }else if(ans[it] == ','){
            putchar(ans[it++]);
            putchar(' ');
        }else if(ans[it] == ';'){
            putchar(ans[it++]);
            if(judge){
                putchar(' ');
            }else{
                newline();
            }
        }else if(ans[it] == '\''){
            putchar(ans[it++]);
            while(ans[it] != '\''){
                if(ans[it] == '\\') putchar(ans[it++]);
                putchar(ans[it++]);
            }
            putchar(ans[it++]);
        }else if(ans[it] == '\"'){
            putchar(ans[it++]);
            while(ans[it] != '\"'){
                if(ans[it] == '\\')putchar(ans[it++]);
                putchar(ans[it++]);
            }
            putchar(ans[it++]);
        }else if(judge_operator(ans[it])){
            putchar(' ');
            while(judge_operator(ans[it])){
                putchar(ans[it++]);
            }
            putchar(' ');
        }else{
            putchar(ans[it++]);
        }
    }
}

int main( ){
    scanf("%d",&T);
    getchar();
    for(int o = 1;o <= T; ++o){
        gets(str);
        printf("Case #%d:\n",o);
        solve();
    }
    return 0;
}
