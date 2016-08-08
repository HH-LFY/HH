#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#define bug(x) printf("_bug_%d\n",x);
using namespace std;

const int inf = (1<<16)<<10;
const int maxx = 100;
map<string,vector<string> >p;///�洢�ķ�
map<char,int> vn,vt;///�洢�ս���ͷ��ս��
map<string,char>search_sy;///��Լ
int vn_len,vt_len;///�ս���ͷ��ս������
bool FirstVt[maxx][maxx];///FirstVt ����
bool LastVt[maxx][maxx]; ///LastVt ����
int rt[maxx][maxx];///Relation table
char vn_str[maxx];
char vt_str[maxx];

void show_vn_vt(){///���vn , vt
    cout<<"vn:"<<vn_len<<endl;
    for(auto & i : vn){
        cout<<i.first<<" "<<i.second<<endl;
        vn_str[i.second] = i.first;
    }
    cout<<"vt:"<<vt_len<<endl;
    for(auto & i : vt){
        cout<<i.first<<" "<<i.second<<endl;
        vt_str[i.second] = i.first;
    }
}

void show_grammar(){///����ķ�
    printf("�ķ�:\n");
    for(auto & i : p){
        cout<<i.first;
        for(int j = 0;j < i.second.size(); ++j){
            cout<<" "<<i.second[j];
        }
        puts("");
    }
}

void show_firstvt(){///���FirstVt
    printf("First_vt:\n");
    printf("%3c",' ');
    for(int i = 1;i < vt_len; ++i){
        printf(" %4c",vt_str[i]);
    }
    puts("");
    for(int i = 1;i < vn_len; ++i){
        printf(" %3c",vn_str[i]);
        for(int j = 1;j < vt_len; ++j){
            printf(" %3d ",FirstVt[i][j]);
        }
        puts("");
    }
}

void show_lastvt(){///���LastVt
    printf("last_vt:\n");
    printf("%3c",' ');
    for(int i = 1;i < vt_len; ++i){
        printf(" %4c",vt_str[i]);
    }
    puts("");
    for(int i = 1;i < vn_len; ++i){
        printf(" %3c",vn_str[i]);
        for(int j = 1;j < vt_len; ++j){
            printf(" %3d ",LastVt[i][j]);
        }
        puts("");
    }
}

void show_relation_table(){///���realtion table
    printf("��ϵ��:\n");
    printf("%3c",' ');
    for(int i = 1;i < vt_len; ++i){
        printf(" %4c",vt_str[i]);
    }
    puts("");
    for(int i = 1;i < vt_len; ++i){
        printf("%4c",vt_str[i]);
        for(int j = 1;j < vt_len; ++j){
            if(rt[i][j] == inf) printf(" inf ");
            else printf(" %3d ",rt[i][j]);
        }
        puts("");
    }
}

void show_search_sy(){///�����ԼMap
    printf("��Լ��:\n");
    for(auto & k : search_sy){
        cout<<k.first<<" "<<k.second<<endl;
    }
}

void input_grammar(){///�����ķ�
    printf("���������确 E->A+B ���ķ�(��Ctrl+Z����):\n");
    char str[100];
    while(scanf("%s",str)!=EOF){
        ///printf("%s\n",str);
        char str1[100];
        int len1=0;
        char str2[100];
        int len2=0;

        int i = 0;
        int len = strlen(str);
        for(i = 0;i < len; ++i){///������
            if(str[i] == '-' && str[i+1] == '>'){
                i+=2;
                str1[len1]='\0';
                break;
            }else{
                str1[len1++] = str[i];
            }
        }

        for(;i < len; ++i){///�����Ҳ�
            if(str[i] == '|'){
                if(len2){
                    str2[len2]='\0';
                    p[str1].push_back(str2);
                    len2=0;
                }else{
                    p.erase(str1);
                    printf("������ķ��������������룡\n");
                    break;
                }
            }else{
                str2[len2++]=str[i];
            }
        }
        if(len2){
            str2[len2]='\0';
            p[str1].push_back(str2);
            len2=0;
        }else if(p[str1].size() == 0){
            p.erase(str1);
            printf("������ķ��������������룡\n");
        }
    }
    show_grammar();
}

void get_search_sy(){///��ȡ��ԼMap
    for(auto & k : p){
        for(int i = 0;i < k.second.size(); ++i){
            char kstr[maxx];
            char k_len = 0;
            for(int j = 0;j < k.second[i].length(); ++j){
                char c = k.second[i][j];
                if(vt.count(c)>0){
                    kstr[k_len++] = c;
                }else{
                    kstr[k_len++] = 'E';
                }
            }
            kstr[k_len]='\0';
            search_sy[kstr] = 'E';
        }
    }
}

void get_first_vt(){ /// get_first_vt
    show_vn_vt();

    for(int i = 1;i < vn_len; ++i){ ///init firstvt
        for(int j = 1;j < vt_len; ++j){
            FirstVt[i][j] = false;
        }
    }

    for(auto & k : p){ ///get firstvt 1
        for(int i = 0;i < k.second.size(); ++i){
            char c1 = k.second[i][0];
            char c2 = ' ';
            char c = k.first[0];
            if(k.second[i].length()>1)
                c2 = k.second[i][1];
            //printf("%c %c %c\n",c,c1,c2);
            if(vt.count(c1)>0){
                //printf("1 %c:%d %c:%d\n",c,vn[c],c1,vt[c1]);
                FirstVt[vn[c]][vt[c1]] = true;
            }else if(vt.count(c2)>0 && vn.count(c1)>0){
                //printf("2 %c:%d %c:%d\n",c,vn[c],c2,vt[c2]);
                FirstVt[vn[c]][vt[c2]] = true;
            }
        }
    }

    //show_firstvt();

    int temp_count = 0;
    while(true){ ///get firstvt 2
        int temp_count2 = temp_count;
        for(auto & k : p){
            for(int i = 0;i < k.second.size(); ++i){
                char c = k.first[0];
                char c1 = k.second[i][0];
                if(c != c1 && vn.count(c)>0 && vn.count(c1)>0 ){
                    for(int j = 1;j < vt_len; ++j){
                        if(FirstVt[vn[c]][j] == false && FirstVt[vn[c1]][j] == true){
                            temp_count2++;
                            FirstVt[vn[c]][j] = FirstVt[vn[c1]][j];
                        }
                    }
                }
            }
        }
        if(temp_count2 == temp_count) break;
        else temp_count = temp_count2;
    }
    //cout<<temp_count<<endl;
    //show_firstvt();
    //show_vn_vt();
}

void get_last_vt(){///get_last_vt

    for(int i = 1;i < vn_len; ++i){ ///init firstvt
        for(int j = 1;j < vt_len; ++j){
            LastVt[i][j] = false;
        }
    }

    for(auto & k : p){ ///get LastVt 1
        for(int i = 0;i < k.second.size(); ++i){
            int now_len = k.second[i].length();
            char c1 = k.second[i][now_len-1];
            char c2 = ' ';
            char c = k.first[0];
            if(k.second[i].length()>1)
            c2 = k.second[i][1];
            //printf("%c %c %c\n",c,c1,c2);
            if(vt.count(c1)>0){
                //printf("1 %c:%d %c:%d\n",c,vn[c],c1,vt[c1]);
                LastVt[vn[c]][vt[c1]] = true;
            }else if(vt.count(c2)>0 && vn.count(c1)>0){
                //printf("2 %c:%d %c:%d\n",c,vn[c],c2,vt[c2]);
                LastVt[vn[c]][vt[c2]] = true;
            }
        }
    }

    //show_LastVt();

    int temp_count = 0;
    while(true){ ///get LastVt 2
        int temp_count2 = temp_count;
        for(auto & k : p){
            for(int i = 0;i < k.second.size(); ++i){
                int now_len = k.second[i].length();
                char c = k.first[0];
                char c1 = k.second[i][now_len-1];
                if(c != c1 && vn.count(c)>0 && vn.count(c1)>0 ){
                    for(int j = 1;j < vt_len; ++j){
                        if(LastVt[vn[c]][j] == false && LastVt[vn[c1]][j] == true){
                            temp_count2++;
                            LastVt[vn[c]][j] = LastVt[vn[c1]][j];
                        }
                    }
                }
            }
        }
        if(temp_count2 == temp_count) break;
        else temp_count = temp_count2;
    }
}

void get_relation_table(){///get relation table

    for(int i = 1;i < vt_len; ++i){
        for(int j = 1;j < vt_len; ++j){
            rt[i][j] = inf;
        }
    }

    for(auto & k : p){
        for(int i = 0;i < k.second.size(); ++i){
            for(int j = 0;j < k.second[i].length(); ++j){
                char c = k.second[i][j];
                if(vt.count(c)>0){
                    /// get =
                    int now = j+1;
                    while(now<k.second[i].length()){
                        char now_c = k.second[i][now];
                        if(vt.count(now_c)>0){
                            rt[vt[c]][vt[now_c]] = 0;
                        }
                        now++;
                    }

                    ///get <
                    now = j+1;
                    if(now<k.second[i].length()){
                        char now_c = k.second[i][now];
                        if(vn.count(now_c)>0){
                            for(int g = 1;g < vt_len; ++g){
                                if(FirstVt[vn[now_c]][g]){
                                    rt[vt[c]][g] = -1;
                                }
                            }
                        }
                    }
                }
                if(vn.count(c)>0){
                    ///get >
                    int now = j+1;
                    if(now<k.second[i].length()){
                        char now_c = k.second[i][now];
                        if(vt.count(now_c)>0){
                            for(int g = 1;g < vt_len; ++g){
                                if(LastVt[vn[c]][g]){
                                    rt[g][vt[now_c]] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void init(){///���ķ����д���

    vn_len = 1;
    vt_len = 1;
    for(auto & k : p){///get vn
        vn[k.first[0]]=vn_len++;
    }
    for(auto & k : p){///get vt
        for(int i = 0;i < k.second.size(); ++i){
            for(int j = 0;j < k.second[i].length(); ++j){
                char c = k.second[i][j];
                if( vn.count(c)<=0 && !vt[c]){
                    vt[c]=vt_len++;
                }
            }
        }
    }
    get_search_sy();
    get_first_vt();
    get_last_vt();
    get_relation_table();
    show_search_sy();
    show_firstvt();
    show_lastvt();
    show_relation_table();

}

bool solve(string str){///����
    ///cout<<str<<endl;
    char kstr[maxx];
    int k_len = 0;
    for(int i = 0;i < str.length(); ++i){
        if(vt.count(str[i])>0){
            kstr[k_len++] = str[i];
        }else{
            kstr[k_len++] = 'i';
            while(i<str.length()){
                if(vt.count(str[i])>0){
                    kstr[k_len++] = str[i];
                    break;
                }
                ///cout<<str[i]<<endl;
                i++;
            }
        }
    }
    kstr[k_len] = '\0';
    //cout<<kstr<<endl;
    printf("��Լ�������£�\n");
    kstr[k_len] = '#';
    char op[maxx],op_vt[maxx];
    int op_len = 0;
    int op_vt_len = 0;
    op[op_len] = '#';
    op_vt[op_vt_len]='#';
    printf("%10s %5s %10s  %s\n","ջ","���ȹ�ϵ","��ǰ����","ʣ�����봮");
    for(int i = 0;i <= k_len ; ++i){
        int temp_now = 0;
        int type = rt[vt[op_vt[op_vt_len]]][vt[kstr[i]]];
        op[op_len+1] = '\0';
        printf("%10s",op);
        if(type == 0){
            printf(" %5c %10c",'=',kstr[i]);
            if(kstr[i] == '#'){
                if(op[1] == 'E' && op_len == 1){
                    printf("\n Yes \n");
                }else{
                    printf("\n ���� No\n");
                }
                break;
            }else{
                op[++op_len] = kstr[i];
                op_vt[++op_vt_len] = kstr[i];
            }
        }else if(type == -1){
            op[++op_len] = kstr[i];
            op_vt[++op_vt_len] = kstr[i];
            printf(" %5c %10c",'<',kstr[i]);
        }else if(type == 1){
            temp_now = 1;
            printf(" %5c %10c",'>',kstr[i]);
            int judge = 1;
            for(int j = op_vt_len-1;j >= 0; --j){
                char c1 = op_vt[j];
                char c2 = op_vt[j+1];
                int vt_c1 = vt[c1];
                int vt_c2 = vt[c2];
                int type_now = rt[vt_c1][vt_c2];///��op_vt���ҵ� <
                if(type_now == -1){
                    int k_count = op_vt_len - j;
                    int now_l = op_len;
                    for(;now_l >= 0; --now_l){///��λ��op_vt�е� < �� op �е�λ��
                        if(vt.count(op[now_l])){
                            if(k_count == 0){
                                break;
                            }
                            k_count--;
                        }
                    }
                    now_l++;/// ���ҵ���λ�ò��ᱻ��Լ

                    char word[maxx];
                    int word_len = 0;
                    for(int g = now_l;g <= op_len; ++g){///ȡ����Լ��
                        word[word_len++] = op[g];
                    }
                    word[word_len]='\0';
                    //cout<<"����Լ����"<<word<<endl;
                    if(search_sy.count(word)){
                        op[now_l] = search_sy[word];
                        op_len = now_l;
                        op_vt_len = j;
                        judge = 0;
                        i--;
                    }
                    break;
                }
            }
            if(judge){
                printf("���� No\n");
                break;
            }

        }else{
            printf("���� No\n");
            break;
        }
        printf("     ");
        for(int g = i+1+temp_now;g <= k_len; ++g){
            printf("%c",kstr[g]);
        }
        puts("");
        /**
        printf("i=%d ",i);
        for(int g = 0;g <= op_len; ++g){
            printf("%c",op[g]);
        }
        puts("");*/
    }
}

int main( ){
   // system("color 70");
    input_grammar();///�����ķ�
    init();///���ķ����д���
    char s[100];
    printf("������Ҫ����Ĵ���\n");
    while(scanf("%s",s)!=EOF)solve(s);
    return 0;
}

/** �������� - �ķ�

e->#E#
E->E+T|E-T|T
T->T*F|T/F|F
F->(E)|i

E->#S#
S->(A)|a|b
A->AcS|S

e->#E#
E->E+T
E->T
T->T*F
T->F
F->P^F|P
P->(E)
P->i

12+2*2

���룺1+2;
�������ȷ
���룺(1+2)/3+4-(5+6/7);
�������ȷ
���룺((1-2)/3+4
���������
���룺1+2-3+(*4/5)
���������

*/
