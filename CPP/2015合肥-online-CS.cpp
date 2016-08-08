#include <cstdio>
#include <algorithm>
using namespace std;
char str[999999];
int main() {
    int T,TT;
    bool lh=true,jw=false;
    scanf("%d\n", &TT);
    #define puts lh=1,puts
    #define putchar lh=0,putchar
    #define ali for(int i=0;i<bgn;i++)putchar(' ');
    for (T=1; T<=TT; T++) {
        gets(str);
        printf("Case #%d:\n", T);
        int bgn=0,kuoh=0;
        for (char*s=str; *s; s++) {
            if(bgn<0 && *s!='#' && *s!=' ')
                putchar(10), bgn=0;
            _:;//fprintf(stderr, "`",jw);
                        switch(*s) {
            case '#':
                s+=8;
                while(*s==' ') s++;
                printf("#include <");
                do{
                    if((*++s)!=32)putchar(*s);
                } while(*s!='>');
                puts("");bgn=-1;
                 break;
            case ',':
                printf(", ");
                break;
            case '{':puts("");
                ali;
                puts("{");
                bgn+=2;
                break;
            case '}'://puts("");
                bgn-=2;
                ali;
                puts("}");
                break;
            case ';':
                //ali;
                if(kuoh){if(s[-1]==';')putchar(32);goto ykh;}
                puts(";");
                break;
            case ' ':goto __;
                break;
            case '\"':if(jw)putchar(32);putchar(*s);
                while(1) {
                    putchar(*++s);
                    if(*s=='\\')
                        putchar(*++s);
                    else if(*s=='\"')
                        break;
                }jw=1;
                goto __;break;
            case '\'':if(jw)putchar(32);putchar(*s);
                while(1) {
                    putchar(*++s);
                    if(*s=='\\')
                        putchar(*++s);
                    else if(*s=='\'')
                        break;
                }jw=1;
                goto __;break;
            case '0' ... '9':
            case 'a' ... 'z':
            case 'A' ... 'Z':
            case '_':

                if(lh)ali;
                if(jw)putchar(32);
                while((*s>='0'&&*s<='9') || (*s>='A'&&*s<='Z') || (*s>='a'&&*s<='z') || *s=='_') {
                    putchar(*s);
                    s++;
                }
                jw=true;
                goto _;
            default:
                if(lh)ali;
                if(jw && s[-1]!='>' && s[-1]!='<' && s[-1]!='=' && s[-1]!='!')putchar(32);
            ykh:
                putchar(*s);
                jw=1;
                goto __;
                break;
            case ')':
                kuoh--;if(s[-1]==';')putchar(32);
                goto ykh;
            case '&':
                putchar(*s);
                break;
            case '(':
                putchar(*s);
                kuoh++;
                break;
            }
            jw=false;
__:;
        }
    }
}
