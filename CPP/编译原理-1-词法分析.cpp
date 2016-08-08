#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <vector>
#define bug(x) printf("bug__%d\n",x);
using namespace std;

map<string,int> key;///存储关键字
string str;

void init(){ ///对各类关键字进行初始化
    ///1
    key["if"] = 1;
    key["int"] = 1;
    key["for"] = 1;
    key["while"] = 1;
    key["do"] = 1;
    key["return"] = 1;
    key["break"] = 1;
    key["continue"] = 1;
    key["case"] = 1;
    key["try"] = 1;

    ///4
    key["+"] = 4;
    key["-"] = 4;
    key["*"] = 4;
    key["/"] = 4;
    key["="] = 4;
    key[">"] = 4;
    key["<"] = 4;
    key[">="] = 4;
    key["<="] = 4;
    key["!="] = 4;

    ///5
    key[","] = 5;
    key[";"] = 5;
    key["{"] = 5;
    key["}"] = 5;
    key["("] = 5;
    key[")"] = 5;

}

bool check_letter(char c){
    if((c>='a'&&c<='z') ||('A'<=c && 'Z'>=c)){
        return true;
    }
    return false;
}

bool check_operation(char c){
    if('+' == c) return true;
    if('-' == c) return true;
    if('*' == c) return true;
    if('/' == c) return true;
    if('>' == c) return true;
    if('<' == c) return true;
    if('=' == c) return true;
    return false;
}

bool check_separator(char c){
    if(',' == c) return true;
    if(';' == c) return true;
    if('{' == c) return true;
    if('}' == c) return true;
    if('(' == c) return true;
    if(')' == c) return true;
    return false;
}

bool check_number(char c){
    if('0'<=c && '9'>=c) return true;
    return false;
}

/*** type
    type 1 , letter
    type 3 , number
    type 4 , operation
    type 5 , separator
*/

int check_type(char c){
    if(check_letter(c)) return 1;
    if(check_number(c)) return 3;
    if(check_operation(c)) return 4;
    if(check_separator(c)) return 5;
    return -1;
}

void solve(char word[]){
    if(!strlen(word)) return;
    if(key[word]){
        printf("(%d,\"%s\")\n",key[word],word);
    }else{
        int now = 0;
        int judge = 0;
        if(word[now]=='+' || word[now]=='-' || check_type(word[now]) == 3){
            int dec_count = 1;
            while(word[++now]!='\0'){
                if(dec_count && word[now] == '.'){
                    dec_count--;
                    continue;
                }
                if(check_type(word[now])!=3){
                    judge = 1;
                    break;
                }
            }
            if(!judge){
                printf("(3,\"%s\")\n",word);
            }
        }else if(check_type(word[now])==1 || word[now] == '_'){
            while(word[++now]!='\0'){
                int n_type = check_type(word[now]);
                if(!(n_type == 1|| n_type == 3)){
                    judge = 1;
                    break;
                }
            }
            if(!judge){
                printf("(2,\"%s\")\n",word);
            }
        }else{
            judge = 1;
        }
        if(judge){
            printf("(Error,\"%s\")\n",word);
        }
    }
}


int main( ){
    ///input
    //str="main(){int  a,b;a = +10;b = a + 20; } ";
    str="int main(){int a = 1.1.1;if( a<=0){a >==10;}return 0; }";
    init();
    /**
    char s[100];
    while(scanf("%s",s)!=EOF){
        solve(s);
    }**/
    int now = 0; ///前一个单词类型
    int str_len = str.length();
    for(int i = 0;i < str_len;){
        while(str[i] == ' ')i++;
        char word[100];
        int word_len = 0;
        int type = check_type(str[i]);
        if(type == 5){
            word[word_len++]=str[i];
            word[word_len]='\0';
            now = 0;
        }else if(type == 1){
            while(str[i+word_len]!=' ' && !check_separator(str[i+word_len]) && !check_operation(str[i+word_len])){
                word[word_len] = str[i+word_len];
                word_len++;
            }
            word[word_len]='\0';
            now = 1;
        }else if(type == 3){
            while(str[i+word_len]!=' ' && !check_separator(str[i+word_len]) && !check_operation(str[i+word_len])){
                word[word_len] = str[i+word_len];
                word_len++;
            }
            word[word_len]='\0';
            now = 1;
        }else if(now == 0&&(str[i]=='+'||str[i]=='-')){
            word[word_len] = str[i+word_len];
            word_len++;
            while(str[i+word_len]!=' ' && !check_separator(str[i+word_len]) && !check_operation(str[i+word_len])){
                word[word_len] = str[i+word_len];
                word_len++;
            }
            word[word_len]='\0';
            now = 0;
        }else if(type == 4){
            while(str[i+word_len]!=' ' && !check_separator(str[i+word_len]) &&!check_letter(str[i+word_len]) && !check_number(str[i+word_len])){
                word[word_len] = str[i+word_len];
                word_len++;
            }
            word[word_len]='\0';
            now = 0;
        }else{
            word[word_len]=str[i];
            word_len++;
            word[word_len]='\0';
            now = -0;
        }
        solve(word);
        i+=word_len;
    }
    return 0;
}
